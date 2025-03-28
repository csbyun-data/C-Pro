// https://github.com/vonj/snippets.org/blob/master/cfg.c

/* =======================================================================
    CFG.c       Generic configuration file handler.

                A. Reitsma, Delft, The Netherlands.
                v1.00  94-07-09  Public Domain.
 ---------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cfg.h"

#define LINE_LEN_MAX    128                  /* actual max line length  */
#define BUFFERSIZE      LINE_LEN_MAX +2      /* ... including \n and \0 */

struct CfgStrings CfgDemoData[] =
{ { "workpath", NULL },
  { "archiver", NULL },
  { "splitter", NULL },
  { NULL, NULL }         /* array terminator. REQUIRED !!! */
};

enum RetVal {
  NO_PROBLEMS,
  ERR_FOPEN,
  ERR_MEM,
};

FILE *cant(char *fname, char *fmode)
{
      FILE *fp;

      if (NULL == (fp = fopen(fname, fmode)))
      {
            ferrorf(stderr, "Can't open %s", fname);
            exit(EXIT_FAILURE);
      }
      return fp;
}

int CfgRead( char *Filename, struct CfgStrings *CfgInfo ) {
  char Buffer[ BUFFERSIZE ];
  char *WorkPtr ;
  char *CfgName ;
  char *CfgData ;
  
  struct CfgStrings *Cfg ;
  FILE *CfgFile ;

  CfgFile = fopen( Filename, "r" );
  if( NULL == CfgFile ) {
    return ERR_FOPEN ;
  }

  while( NULL != fgets( Buffer, BUFFERSIZE, CfgFile )) {
    /* clip off optional comment tail indicated by a semi-colon */
    
	// printf("buffer : %s", Buffer); // get string line in cfg.ini
	
    if( NULL != (WorkPtr = strchr( Buffer, ';' )))
      *WorkPtr = '\0';
    else
      WorkPtr = Buffer + strlen( Buffer );

    /* clip off trailing and leading white space
    */
    WorkPtr--;
    while( isspace( *WorkPtr ) && WorkPtr >= Buffer )
      *WorkPtr-- = '\0';
    WorkPtr = Buffer;
    while( isspace( *WorkPtr ))
      WorkPtr++;
    if( 0 == strlen( WorkPtr ))
      continue;

    CfgName = strtok( WorkPtr, " =" );
    // printf("CfgName : '%s', ", CfgName);    
    if( NULL != CfgName ) {
      /* Condition the name (lower case required),
         and strip leading white and a 'late' = from data part.
      */
      strlwr( CfgName );  // change to the lower case string
      CfgData = strtok( NULL, "" );
      // printf("CfgData : '%s' ", CfgData);
      
      while( isspace( *CfgData ))
        CfgData++;
      if( '=' == *CfgData )
        CfgData++;
      while( isspace( *CfgData ))
        CfgData++;

	  // printf("-> '%s'\n", CfgData);
	  
      /* look for matching 'name' */
      Cfg = CfgInfo ;
      while( NULL != Cfg->name && 0 != strcmp( Cfg->name, CfgName ))
        Cfg++;

      /* duplicate the data if the name is found. */
      if( NULL != Cfg->name ) {
        Cfg->data = strdup( CfgData ); /* strdup is not ANSI    */
                                       /* memory leaks if Cfg->data */
                                       /* is malloc'ed already      */
        if( NULL == Cfg->data ) {
          fclose( CfgFile );
          return ERR_MEM;
        }
      }   /* undetected error on failure should not be a problem  */
          /* as configuration reading should be done early.       */
    }     /* but test and handle it anyway ...                    */
  }
  fclose( CfgFile );
  
  return NO_PROBLEMS ;
}

int main( int argc, char * argv[] )
{
  int ix ;

  if( argc != 2 ) {
    puts("Usage: cfg cfg.ini\n");
    return ERR_FOPEN ;
  } else
    CfgRead( argv[ 1 ], CfgDemoData );

  for( ix = 0; ix < 4 ; ix++ ) /* intentionally one too much */
    printf( "CfgItem \"%s\" is \"%s\"\n", CfgDemoData[ ix ].name,
                                          CfgDemoData[ ix ].data );
  return NO_PROBLEMS;
}
