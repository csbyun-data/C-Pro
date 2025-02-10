/*************************************************************************
**                                                                       **
** EE.C         Expression Evaluator                                     **
**                                                                       **
** AUTHOR:      Mark Morley                                              **
** COPYRIGHT:   (c) 1992 by Mark Morley                                  **
** DATE:        December 1991                                            **
** HISTORY:     Jan 1992 - Made it squash all command line arguments     **
**                         into one big long string.                     **
**                       - It now can set/get VMS symbols as if they     **
**                         were variables.                               **
**                       - Changed max variable name length from 5 to 15 **
**              Jun 1992 - Updated comments and docs                     **
**                                                                       **
** You are free to incorporate this code into your own works, even if it **
** is a commercial application.  However, you may not charge anyone else **
** for the use of this code!  If you intend to distribute your code,     **
** I'd appreciate it if you left this message intact.  I'd like to       **
** receive credit wherever it is appropriate.  Thanks!                   **
**                                                                       **
** I don't promise that this code does what you think it does...         **
**                                                                       **
** Please mail any bug reports/fixes/enhancments to me at:               **
**      morley@camosun.bc.ca                                             **
** or                                                                    **
**      Mark Morley                                                      **
**      3889 Mildred Street                                              **
**      Victoria, BC  Canada                                             **
**      V8Z 7G1                                                          **
**      (604) 479-7861                                                   **
**                                                                       **
 *************************************************************************/

/* #define VAX */             /* Uncomment this line if you're using VMS */

#include <stdlib.h>
#include <math.h>
#include <setjmp.h>

#ifdef VAX
#include <ssdef.h>
#include <descrip.h>
#endif

#include "ee.h"

#define ERR(n) {ERROR=n; ERPOS=expression-ERANC-1; strcpy(ERTOK,token); longjmp(jb,1);}

/* These defines only happen if the values are not already defined!  You may
   want to add more precision here, if your machine supports it. */
#ifndef M_PI
#define M_PI    3.14159265358979323846
#endif
#ifndef M_E
#define M_E     2.71828182845904523536
#endif


/*************************************************************************
**                                                                       **
** PROTOTYPES FOR CUSTOM MATH FUNCTIONS                                  **
**                                                                       **
 *************************************************************************/

double deg( double x );
double rad( double x );


/*************************************************************************
**                                                                       **
** VARIABLE DECLARATIONS                                                 **
**                                                                       **
 *************************************************************************/

int   ERROR;                 /* The error number */
char  ERTOK[TOKLEN + 1];     /* The token that generated the error */
int   ERPOS;                 /* The offset from the start of the expression */
char* ERANC;                 /* Used to calculate ERPOS */

/*
   Add any "constants" here...  These are "read-only" values that are
   provided as a convienence to the user.  Their values can not be
   permanently changed.  The first field is the variable name, the second
   is its value.
*/
VARIABLE Consts[] =
{
   /* name, value */
   { "pi",      M_PI },
   { "e",       M_E },

   { 0 }
};

/*
   Add any math functions that you wish to recognise here...  The first
   field is the name of the function as it would appear in an expression.
   The second field tells how many arguments to expect.  The third is
   a pointer to the actual function to use.
*/
FUNCTION Funcs[] =
{
   /* name, funtion to call */
   { "sin",     1,    sin },
   { "cos",     1,    cos },
   { "tan",     1,    tan },
   { "asin",    1,    asin },
   { "acos",    1,    acos },
   { "atan",    1,    atan },
   { "sinh",    1,    sinh },
   { "cosh",    1,    cosh },
   { "tanh",    1,    tanh },
   { "exp",     1,    exp },
   { "log",     1,    log },
   { "log10",   1,    log10 },
   { "sqrt",    1,    sqrt },
   { "floor",   1,    floor },
   { "ceil",    1,    ceil },
   { "abs",     1,    fabs },
   { "hypot",   2,    hypot },

   { "deg",     1,    deg },
   { "rad",     1,    rad },

   { 0 }
};

VARIABLE        Vars[MAXVARS];       /* Array for user-defined variables */
unsigned char*  expression;          /* Pointer to the user's expression */
unsigned char   token[TOKLEN + 1];   /* Holds the current token */
int             type;                /* Type of the current token */
jmp_buf         jb;                  /* jmp_buf for errors */


/*************************************************************************
**                                                                       **
** Some custom math functions...   Note that they must be prototyped     **
** above (if your compiler requires it)                                  **
**                                                                       **
** deg( x )             Converts x radians to degrees.                   **
** rad( x )             Converts x degrees to radians.                   **
**                                                                       **
 *************************************************************************/

double
deg( double x )
{
   return( x * 180.0 / M_PI );
}

double
rad( double x )
{
   return( x * M_PI / 180.0 );
}


/*************************************************************************
**                                                                       **
** GetSymbol( char* s )                                                  **
**                                                                       **
** This routine obtains a value from the program's environment.          **
** This works for DOS and VMS (and other OS's???)
**                                                                       **
 ************************************************************************/

GetSymbol( char* s, TYPE* v )
{
   char* e;

   e = getenv( s );
   if( !e )
      return( 0 );
   *v = atof( e );
   return( 1 );
}


/*************************************************************************
**                                                                       **
** SetSymbol( char* s, char* v )                                         **
**                                                                       **
** This VMS specific routine sets (or updates) a VMS symbol to a given   **
** value                                                                 **
**                                                                       **
 *************************************************************************/

#ifdef VAX
SetSymbol( char* s, char* v )
{
   struct dsc$descriptor_s sym;
   struct dsc$descriptor_s val;
   long                    typ = 1;

   sym.dsc$w_length = strlen( s );
   sym.dsc$a_pointer = s;
   sym.dsc$b_class = DSC$K_CLASS_S;
   sym.dsc$b_dtype = DSC$K_DTYPE_T;
   val.dsc$w_length = strlen( v );
   val.dsc$a_pointer = v;
   val.dsc$b_class = DSC$K_CLASS_S;
   val.dsc$b_dtype = DSC$K_DTYPE_T;
   return( LIB$SET_SYMBOL( &sym, &val, &typ ) );
}
#endif


/*************************************************************************
**                                                                       **
** strlwr( char* s )   Internal use only                                 **
**                                                                       **
** This routine converts a string to lowercase.  I know many compilers   **
** offer their own routine, but my VMS compiler didn't so...             **
** Again, this one is ASCII specific!                                    **
**                                                                       **
 *************************************************************************/

static
strlwr( char* s )
{
   while( *s )
   {
      if( *s >= 'A' && *s <= 'Z' )
         *s += 32;
      s++;
   }
}


/*************************************************************************
**                                                                       **
** ClearAllVars()                                                        **
**                                                                       **
** Erases all user-defined variables from memory. Note that constants    **
** can not be erased or modified in any way by the user.                 **
**                                                                       **
** Returns nothing.                                                      **
**                                                                       **
 *************************************************************************/

ClearAllVars()
{
   int i;

   for( i = 0; i < MAXVARS; i++ )
   {
      *Vars[i].name = 0;
      Vars[i].value = 0;
   }
}


/*************************************************************************
**                                                                       **
** ClearVar( char* name )                                                **
**                                                                       **
** Erases the user-defined variable that is called NAME from memory.     **
** Note that constants are not affected.                                 **
**                                                                       **
** Returns 1 if the variable was found and erased, or 0 if it didn't     **
** exist.                                                                **
**                                                                       **
 *************************************************************************/

ClearVar( char* name )
{
   int i;

   for( i = 0; i < MAXVARS; i++ )
      if( *Vars[i].name && ! strcmp( name, Vars[i].name ) )
      {
         *Vars[i].name = 0;
         Vars[i].value = 0;
         return( 1 );
      }
   return( 0 );
}


/*************************************************************************
**                                                                       **
** GetValue( char* name, TYPE* value )                                   **
**                                                                       **
** Looks up the specified variable (or constant) known as NAME and       **
** returns its contents in VALUE.                                        **
**                                                                       **
** First the user-defined variables are searched, then the constants are **
** searched.                                                             **
**                                                                       **
** Returns 1 if the value was found, or 0 if it wasn't.                  **
**                                                                       **
 *************************************************************************/

GetValue( char* name, TYPE* value )
{
   int i;

   /* First check for an environment variable reference... */
   if( *name == '_' )
      return( GetSymbol( name + 1, value ) );

   /* Now check the user-defined variables. */
   for( i = 0; i < MAXVARS; i++ )
      if( *Vars[i].name && ! strcmp( name, Vars[i].name ) )
      {
         *value = Vars[i].value;
         return( 1 );
      }

   /* Now check the programmer-defined constants. */
   for( i = 0; *Consts[i].name; i++ )
      if( *Consts[i].name && ! strcmp( name, Consts[i].name ) )
      {
         *value = Consts[i].value;
         return( 1 );
      }
   return( 0 );
}


/*************************************************************************
**                                                                       **
** SetValue( char* name, TYPE* value )                                   **
**                                                                       **
** First, it erases any user-defined variable that is called NAME.  Then **
** it creates a new variable called NAME and gives it the value VALUE.   **
**                                                                       **
** Returns 1 if the value was added, or 0 if there was no more room.     **
**                                                                       **
 *************************************************************************/

SetValue( char* name, TYPE* value )
{
   char b[30];
   int  i;

#ifdef VAX
   if( *name == '_' )
   {
      sprintf( b, "%g", *value );
      if( SetSymbol( name + 1, b ) != SS$_NORMAL )
         return( 0 );
      return( 1 );
   }
#endif
   ClearVar( name );
   for( i = 0; i < MAXVARS; i++ )
      if( ! *Vars[i].name )
      {
         strcpy( Vars[i].name, name );
         Vars[i].name[VARLEN] = 0;
         Vars[i].value = *value;
         return( 1 );
      }
   return( 0 );
}


/*************************************************************************
**                                                                       **
** Parse()   Internal use only                                           **
**                                                                       **
** This function is used to grab the next token from the expression that **
** is being evaluated.                                                   **
**                                                                       **
 *************************************************************************/

static
Parse()
{
   char* t;

   type = 0;
   t = token;
   while( iswhite( *expression ) )
      expression++;
   if( isdelim( *expression ) )
   {
      type = DEL;
      *t++ = *expression++;
   }
   else if( isnumer( *expression ) )
   {
      type = NUM;
      while( isnumer( *expression ) )
         *t++ = *expression++;
   }
   else if( isalpha( *expression ) )
   {
      type = VAR;
      while( isalpha( *expression ) )
        *t++ = *expression++;
      token[VARLEN] = 0;
   }
   else if( *expression )
   {
      *t++ = *expression++;
      *t = 0;
      ERR( E_SYNTAX );
   }
   *t = 0;
   while( iswhite( *expression ) )
      expression++;
}


/*************************************************************************
**                                                                       **
** Level1( TYPE* r )   Internal use only                                 **
**                                                                       **
** This function handles any variable assignment operations.             **
** It returns a value of 1 if it is a top-level assignment operation,    **
** otherwise it returns 0                                                **
**                                                                       **
 *************************************************************************/

static
Level1( TYPE* r )
{
   char t[VARLEN + 1];

   if( type == VAR )
      if( *expression == '=' )
      {
         strcpy( t, token );
         Parse();
         Parse();
         if( !*token )
         {
            ClearVar( t );
            return(1);
         }
         Level2( r );
         if( ! SetValue( t, r ) )
            ERR( E_MAXVARS );
         return( 1 );
      }
   Level2( r );
   return( 0 );
}


/*************************************************************************
**                                                                       **
** Level2( TYPE* r )   Internal use only                                 **
**                                                                       **
** This function handles any addition and subtraction operations.        **
**                                                                       **
 *************************************************************************/

static
Level2( TYPE* r )
{
   TYPE t = 0;
   char o;

   Level3( r );
   while( (o = *token) == '+' || o == '-' )
   {
      Parse();
      Level3( &t );
      if( o == '+' )
         *r = *r + t;
      else if( o == '-' )
         *r = *r - t;
   }
}


/*************************************************************************
**                                                                       **
** Level3( TYPE* r )   Internal use only                                 **
**                                                                       **
** This function handles any multiplication, division, or modulo.        **
**                                                                       **
 *************************************************************************/

static
Level3( TYPE* r )
{
   TYPE t;
   char o;

   Level4( r );
   while( (o = *token) == '*' || o == '/' || o == '%' )
   {
      Parse();
      Level4( &t );
      if( o == '*' )
         *r = *r * t;
      else if( o == '/' )
      {
         if( t == 0 )
            ERR( E_DIVZERO );
         *r = *r / t;
      }
      else if( o == '%' )
      {
         if( t == 0 )
            ERR( E_DIVZERO );
         *r = fmod( *r, t );
      }
   }
}


/*************************************************************************
**                                                                       **
** Level4( TYPE* r )   Internal use only                                 **
**                                                                       **
** This function handles any "to the power of" operations.               **
**                                                                       **
 *************************************************************************/

static
Level4( TYPE* r )
{
   TYPE t;

   Level5( r );
   if( *token == '^' )
   {
      Parse();
      Level5( &t );
      *r = pow( *r, t );
   }
}


/*************************************************************************
**                                                                       **
** Level5( TYPE* r )   Internal use only                                 **
**                                                                       **
** This function handles any unary + or - signs.                         **
**                                                                       **
 *************************************************************************/

static
Level5( TYPE* r )
{
   char o = 0;

   if( *token == '+' || *token == '-' )
   {
      o = *token;
      Parse();
   }
   Level6( r );
   if( o == '-' )
      *r = -*r;
}


/*************************************************************************
**                                                                       **
** Level6( TYPE* r )   Internal use only                                 **
**                                                                       **
** This function handles any literal numbers, variables, or functions.   **
**                                                                       **
 *************************************************************************/

static
Level6( TYPE* r )
{
   int  i;
   int  n;
   TYPE a[3];

   if( *token == '(' )
   {
      Parse();
      if( *token == ')' )
         ERR( E_NOARG );
      Level1( r );
      if( *token != ')' )
         ERR( E_UNBALAN );
      Parse();
   }
   else
   {
      if( type == NUM )
      {
         *r = (TYPE) atof( token );
         Parse();
      }
      else if( type == VAR )
      {
         if( *expression == '(' )
         {
            for( i = 0; *Funcs[i].name; i++ )
               if( ! strcmp( token, Funcs[i].name ) )
               {
                  Parse();
                  n = 0;
                  do
                  {
                     Parse();
                     if( *token == ')' || *token == ',' )
                        ERR( E_NOARG );
                     a[n] = 0;
                     Level1( &a[n] );
                     n++;
                  } while( n < 4 && *token == ',' );
                  Parse();
                  if( n != Funcs[i].args )
                  {
                     strcpy( token, Funcs[i].name );
                     ERR( E_NUMARGS );
                  }
                  *r = Funcs[i].func( a[0], a[1], a[2] );
                  return;
               }
               if( ! *Funcs[i].name )
                  ERR( E_BADFUNC );
            }
            else if( ! GetValue( token, r ) )
               ERR( E_UNKNOWN );
         Parse();
      }
      else
         ERR( E_SYNTAX );
   }
}


/*************************************************************************
**                                                                       **
** Evaluate( char* e, TYPE* result, int* a )                             **
**                                                                       **
** This function is called to evaluate the expression E and return the   **
** answer in RESULT.  If the expression was a top-level assignment, a    **
** value of 1 will be returned in A, otherwise it will contain 0.        **
**                                                                       **
** Returns E_OK if the expression is valid, or an error code.            **
**                                                                       **
 *************************************************************************/

Evaluate( char* e, TYPE* result, int* a )
{
   if( setjmp( jb ) )
      return( ERROR );
   expression = e;
   ERANC = e;
   strlwr( expression );
   *result = 0;
   Parse();
   if( ! *token )
      ERR( E_EMPTY );
   *a = Level1( result );
   return( E_OK );
}


/*************************************************************************
**                                                                       **
** What follows is a main() routine that evaluates the command line      **
** arguments one at a time, and displays the results of each expression. **
** Without arguments, it becomes an interactive calculator.              **
**                                                                       **
 *************************************************************************/

#include <stdio.h>

char* ErrMsgs[] =
{
   "Syntax error",
   "Unbalanced parenthesis",
   "Division by zero",
   "Unknown variable",
   "Maximum variables exceeded",
   "Unrecognised funtion",
   "Wrong number of arguments to funtion",
   "Missing an argument",
   "Empty expression"
};

main( int argc, char* argv[] )
{
   TYPE  result;
   int   i;
   int   ec;
   int   a;
   char  line[1024];
   char* v;

   ClearAllVars();
   /* If we have command line arguments then we evaluate them and exit. */
   if( argc > 1 )
   {
      /* Concatenate all arguments into one string. */
      strcpy( line, argv[1] );
      for( i = 2; i < argc; i++ )
         strcat( line, argv[i] );

      /* Call the evaluator. */
      if( (ec = Evaluate( line, &result, &a )) == E_OK )
      {
         /* If we didn't assign a variable, then print the result. */
         if( ! a )
            printf( "%g\n", result );
      }
      else if( ec != E_EMPTY )
      {
         /* Display error info.  In this example, an E_EMPTY error is ignored. */
         printf( "ERROR: %s - %s", ErrMsgs[ERROR - 1], ERTOK );
         printf( "\n%s", ERANC );
         printf( "\n%*s^\n", ERPOS, "" );
      }
      return;
   }

   /* There were no command line arguments, so lets go interactive. */
   printf( "\nEE - Equation Evaluator" );
   printf( "\nBy Mark Morley  December 1991" );
   printf( "\nEnter EXIT to quit.\n" );
   printf( "\nEE> " );

   /* Input one line at a time from the user.  Note that it uses stdin, so on
      DOS or UNIX you could pipe a list of expressions into it... */
   for( gets( line ); !feof( stdin ); gets( line ) )
   {
      strlwr( line );

      /* Did the user ask to exit? */
      if( ! strcmp( line, "exit" ) )
         return;

      /* Did the user ask to see the variables in memory? */
      else if( ! strcmp( line, "vars" ) )
      {
         for( i = 0; i < MAXVARS; i++ )
            if( *Vars[i].name )
               printf( "%s = %g\n", Vars[i].name, Vars[i].value );
      }

      /* Did the user ask to see the constants in memory? */
      else if( ! strcmp( line, "cons" ) )
      {
         for( i = 0; *Consts[i].name; i++ )
            printf( "%s = %g\n", Consts[i].name, Consts[i].value );
      }

      /* Did the user ask to clear all variables? */
      else if( ! strcmp( line, "clr" ) )
         ClearAllVars();

      /* If none of the above, then we attempt to evaluate the user's input. */
      else
      {
         /* Call the evaluator. */
         if( (ec = Evaluate( line, &result, &a )) == E_OK )
         {
            /* Only display the result if it was not an assignment. */
            if( ! a )
               printf( "%g\n", result );
         }
         else if( ec != E_EMPTY )
         {
            /* Display error information.  E_EMPTY is ignored. */
            printf( "ERROR: %s - %s", ErrMsgs[ERROR - 1], ERTOK );
            printf( "\n%s", ERANC );
            printf( "\n%*s^\n", ERPOS, "" );
         }
      }
      printf( "EE> " );
   }
}
