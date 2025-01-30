### Programming LISP
* log file [code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/Interpreting-lisp/logFile.c)
  ```
  // 1.log file
  // 2.문자열 분석
  FILE *logfilep;
  char *sout;
  
  void ourprint(char *s) {
    printf("%s", s);
    fflush(stdout);  
    fprintf(logfilep, "%s", s);
    fflush(logfilep);
  }
  
  void initlisp(void) {
    sout= (char *)calloc(80,sizeof(char));
  
    logfilep = fopen("lisp.log", "w");
    if (logfilep == NULL) {
      perror("Cannot open logfile");
      exit(1);
    }
  }
  
  void closelisp(void) {
    if (sout != NULL) { free(sout); }
    if (logfilep != NULL) { fclose(logfilep); }
  }
  //... Driver code
  char input[1024];
  fgets(input, sizeof(input), stdin);

  fprintf(logfilep, "%s", input);
  fflush(logfilep);
  sprintf(sout,"%s\n", str);
  ourprint(sout);
  ```  
  ![image](https://github.com/user-attachments/assets/5a2b40ce-f57b-42df-889b-6762fdb22d4e)  
  ![image](https://github.com/user-attachments/assets/05cef0df-2df4-4db1-a2cc-9422f941a87f)

### Interpreting LISP: Programming and Data Structures
* Interpreting Lisp by Gary D. Knott (Apress, 2017). [here](http://www.apress.com/9781484227060)
  * Apress soruce code [https://github.com/Apress/interpreting-lisp](https://github.com/Apress/interpreting-lisp)
  ```c
  // 수정전 code
  /* Using int16_t and int32_t works on both 32-bit and 64-bit systems
     with newer compilers.  For older 32-bit compilers, use: 
     [#define int16 short int] and [#define int32 long int]. */
  #define int16 int16_t
  #define int32 int32_t
  
  /* turbcenv.h is for all Windows systems with the old, but good, Borland C 
     compiler/linker (without int32_t and int16_t). */
  #if defined(__GNUC__)
  #  include "linuxenv.h"
  #else
  #  include "turbcenv.h"
  #endif
  ```
  ```c
  // 수정된 code
  /* Using int16_t and int32_t works on both 32-bit and 64-bit systems
     with newer compilers.  For older 32-bit compilers, use: 
     [#define int16 short int] and [#define int32 long int]. */
  #define int16 short int
  #define int32 long int
  
  /* turbcenv.h is for all Windows systems with the old, but good, Borland C 
     compiler/linker (without int32_t and int16_t). */
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <setjmp.h>
  #include <math.h>
  ```
  * Dev-C++ Tools [code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/Interpreting-lisp/lisp.c)
  ```c
  /* forward references */
  #define forward extern
  forward int32 seval(int32 i);
  forward void initlisp(void);
  forward int32 sread(void);
  forward void swrite(int32 i);
  forward int32 newloc(int32 x, int32 y);
  forward int32 numatom (double r);
  forward int32 ordatom (char *s);
  forward void gc(void);
  forward void gcmark(int32 p);
  forward char getgchar(void);
  forward char lookgchar(void);
  forward void fillg(void);
  forward int32 e(void);
  forward void error(char *s);
  forward int16 fgetline(char *s, int16 lim, FILE *stream);
  forward void ourprint(char *s);
  ```
  ```
  (SETQ a 10)       <- 변수 a, 값 10 선언
  (ADD a 15)        <- 변수 a + 15 값 계산
  (DIFFERENCE a 5)  <- 변수 a - 5 값 계산 
  ```  
  ![image](https://github.com/user-attachments/assets/b5b713fe-41f4-4f0c-b3e3-b8d3cbd120d4)

  * Programm Driver
  ```c
  // lisp 프로그램 실행 순서
  void main(void)
  /*---------------------------------------------------------------------------
   Here is the main read/eval/print loop.
  ----------------------------------------------------------------------------*/
  {
    int32 r;
    initlisp();
   
    setjmp(env);
    /* calling error() returns to here by longjmp() */
  
    for (;;) {
     ourprint("\n");
     prompt= '*';
     r=sread();
     r=seval(r);
     swrite(r);  /* swrite uses/frees no list-nodes. */
    }
  }
  ```
  
  * builtin function and special forms  
  ```
  // 관련 함수들을 선언하고 계산함수 연결 작업(lists in the atom-table)
  // 문자열 atom-table 생성, 순서는 hash
  void initlisp(void)
  /*---------------------------------------------------------------------------
   This procedure installs all builtin functions and special forms into
   the atom table.  It also initializes the number table and list area.
   --------------------------------------------------------------------------*/
  {int32 i;
  
   static char *BI[]=
      {"CAR","CDR","CONS","LAMBDA","SPECIAL","SETQ","ATOM","NUMBERP","QUOTE",
       "LIST","DO","COND","PLUS","TIMES","DIFFERENCE","QUOTIENT","POWER",
       "FLOOR","MINUS","LESSP","GREATERP","EVAL","EQ","AND","OR","SUM","PRODUCT",
       "PUTPLIST","GETPLIST","READ","PRINT","PRINTCR","MKATOM","BODY","RPLACA",
       "RPLACD","TSETQ", "NULL", "SET"
      };
  
   static char BItype[]=
      {10,10,10,11,11,11,10,10,11,10,
       10,11,10,10,10,10,10,10,10,10,
       10,10,10,11,11,10,10,10,10,10,
       10,10,10,10,10,10,11,10,11
      };
  
   /* number of builtin's in BI[] and BItype[] above */
   #define NBI 39
  
   /* allocate a global character array for messages */
   sout= (char *)calloc(80,sizeof(char));
  
   /* allocate the input string */
   g= (char *)calloc(202,sizeof(char));
  
   /* allocate the list area */
   P= (struct Listarea *)calloc(m,sizeof(struct Listarea));
  
  /* initialize atom table names and the number table */
   for (i= 0; i<n; i++)
      {Atab[i].name[0]='\0'; nmark[i]=0; nx[i]= -1; Ntab[i].nlink=nf; nf=i;}
  
   /* install typed-case numbers for builtin functions and and special forms into
      the atom table */
   for (i= 0; i<NBI; i++)
      {Atab[ptrv(ordatom(BI[i]))].L= tp((((int32)BItype[i])<<28),(i+1));}
  
   nilptr= ordatom("NIL"); Atab[ptrv(nilptr)].L= nilptr;
   tptr= ordatom("T");     Atab[ptrv(tptr)].L= tptr;
   quoteptr= ordatom("QUOTE");
  
   /* Creating these lists in the atom-table ensures that we protect
      them during garbage-collection. Make CURRENTIN and EAL not upper-case
      to keep them private.*/
   currentin= ptrv(ordatom("CURRENTIN")); Atab[currentin].L= nilptr;
   eaL= ptrv(ordatom("EAL")); Atab[eaL].L= nilptr;
   sk= ptrv(ordatom("sreadlist")); Atab[sk].L= nilptr;
  
  #define cilp Atab[currentin].L
  #define eaLp Atab[eaL].L
  #define skp Atab[sk].L
  
   /* initialize the bindlist (bl) and plist fields */
   for (i= 0; i<n; i++) Atab[i].bl= Atab[i].plist= nilptr;
  
   /* set up the list area free-space list */
   for (i= 1; i<m; i++) {B(i)= fp; fp= i;} numf = m-1;
  
   /* Prepare to read in predefined functions and special forms from the
      lispinit file: these include APPEND, REVERSE, EQUAL, APPLY, INTO,
      ONTO, MEMBER, NOT, ZEROP, ASSOC, NPROP, PUTPROP, GETPROP, and REMPROP */
  
   /* open the logfile */
   logfilep= fopen("lisp.log","w");
   ourprint(" ENTERING THE LISP INTERPRETER \n");
  
   /* establish the input buffer and the input stream stack */
   topInsave= NULL;
   strcpy(g,"@lispinit ");
   pg= g; pge= g+strlen(g);/* initialize start & end pointers to string g */
   filep= stdin;
  }
  ```
  
  * 문자열, 숫자를 분석하여 구조체 변수함수에 저장
  ```
  // 숫자를 양수, 음수, 소수점을 확인하여 숫자를 만들어 변수에 저장
  // 문자열을 atom-table의 자료와 비교 확인

  int32 sread(void)
  /*----------------------------------------------------------------------------
    This procedure scans an input string g using a lexical token scanning
    routine, e(), where e() returns
                      1 if the token is '('
                      2 if the token is '''
                      3 if the token is '.'
                      4 if the token is ')'
    or a typed pointer d to an atom or number stored in row ptrv(d) in
    the atom or number tables. Due to the typecode (8 or 9) of d, d is a
    negative 32-bit integer.  The token found by e() is stripped from
    the front of g.
   
    SREAD constructs an S-expression and returns a typed pointer to it
    as its result.
    --------------------------------------------------------------------------*/
  {
    int32 j,k,t,c;
   
    if ((c= e())<=0) return(c);
   
    if (c EQ 1) if ((k= e()) EQ 4) return(nilptr); else pb= k;
    /* to permit recursion, skp is a list of lists. */
    skp= newloc(nilptr,skp);
    A(skp)= j= k= newloc(nilptr,nilptr);
   
    /* we will return k, but we will fill node j first */
    if (c EQ 1) {
      scan: A(j)= sread();
      next: if ((c= e())<=2) {
              t= newloc(nilptr,nilptr); B(j)= t; j= t;
              if (c<=0) {A(j)= c; goto next;}
              pb= c; goto scan;
            }
      if (c!=4) {B(j)= sread(); if (e()!=4) error("syntax error");}
      skp= B(skp); return(k);
    }
    if (c EQ 2) {
      A(j)= quoteptr; B(j)= t= newloc(nilptr,nilptr); A(t)= sread();
      skp= B(skp); return(k);
    }
    error("bad syntax");
  }
  ```

  * 명령line의 문자열을 분석하여 atome-table. number-table 생성
  ```
  int32 e(void)
  /*----------------------------------------------------------------------------
   E is a lexical token scanning routine which has no input and returns
         1 if the token is '('
         2 if the token is '''
         3 if the token is '.'
         4 if the token is ')'
         or a negative typed-pointer to an entry in the atom table or the
         the number table.
  -----------------------------------------------------------------------------*/
  {
   double v,f,k,sign;
   int32 i,t,c;
   char nc[50], *np;
   struct Insave *tb;
  
   #define OPENP '('
   #define CLOSEP ')'
   #define BLANK ' '
   #define SINGLEQ '\''
   #define DOT '.'
   #define PLUS '+'
   #define MINUS '-'
   #define CHVAL(c) (c-'0')
   #define DIGIT(c) ('0'<=(c) AND (c)<='9')
   #define TOUPPER(c) ((c) + 'A'-'a')
   #define ISLOWER(c) ((c)>='a' AND (c)<='z')
   
    if (pb!=0) {t= pb; pb= 0; return(t);}
   
   start:
    while ((c= getgchar()) EQ BLANK);  /* remove blanks */
   
    if (c EQ OPENP) {
      while (lookgchar() EQ BLANK) getgchar(); /* remove blanks */
      if (lookgchar() EQ CLOSEP) {getgchar(); return(nilptr);} else return(1);
    }
    if (c EQ EOS) {
      if (topInsave EQ NULL) {fclose(logfilep); exit(0);}
      /* restore the previous input stream */
      fclose(filep);
      strcpy(g,topInsave->g); pg= topInsave->pg; pge= topInsave->pge;
      filep= topInsave->filep; topInsave= topInsave->link;
      if (prompt EQ '@') prompt= '>';
      goto start;
    }
    if (c EQ SINGLEQ) return(2);
    if (c EQ CLOSEP) return(4);
    if (c EQ DOT) {
      if (DIGIT(lookgchar())) {sign= 1.0; v= 0.0; goto fraction;}
      return(3);
    }
   
    // 문자열 대문자로 변경하고 atom-table에 위치를 확인함
    if (NOT (DIGIT(c) OR ((c EQ PLUS OR c EQ MINUS) AND
      (DIGIT(lookgchar()) OR lookgchar() EQ DOT)))) {
      np= nc; *np++= c;    /* put c in nc[0] */
      for (c= lookgchar();
      c!=BLANK AND c!=DOT AND c!=OPENP AND c!=CLOSEP;
      c= lookgchar())
      *(np++)= getgchar(); /* add a character */
      *np= EOS; /* nc is now a string */
 
      // @file_name 파일의 내용을 읽으들여 line 단위로 실행
     if (*nc EQ '@') {
       /* switch input streams */
       /* save the current input stream */
       tb= (struct Insave *)calloc(1,sizeof(struct Insave));
       tb->link= topInsave; topInsave= tb;
       strcpy(tb->g,g); tb->pg= pg; tb->pge= pge; tb->filep= filep;
 
       /* set up the new input stream */
       *g= EOS; pg= pge= g; prompt= '@';
       filep= fopen(nc+1,"r"); /* skip over the @ */
       if (filep EQ NULL) error("Cannot open @file!");
       goto start;
     }
     /* convert the string nc to upper case */
     for (np= nc; *np!=EOS; np++)
       if (ISLOWER((int16)*np)) *np= (char)TOUPPER((int16)*np);
     printf("e() ordatom nc=%s \n", nc );	  
     return(ordatom(nc));
   }
  
   // -숫자열을 숫자로 변경하여 숫자 number-table에 저장
   if (c EQ MINUS) {v= 0.0; sign= -1.0;} else {v= CHVAL(c); sign= 1.0;}
   while (DIGIT(lookgchar())) v= 10.0*v+CHVAL(getgchar());
  
   // 숫자열에 소수점이 있으면 이하 숫자를 처리함
   if (lookgchar() EQ DOT) {
     getgchar();
     if (DIGIT(lookgchar())) {
       fraction:
       k= 1.0; f= 0.0;
       do {k=10.*k;f=10.*f+CHVAL(getgchar());} while (DIGIT(lookgchar()));
       v= v+f/k;
     }
    }
    printf("e() numatom sign=%-g, v=%-g, \n", sign, v);
      
    return(numatom(sign*v));
  }
  ```

  * 명령라인을 실행하여 결과를 생성
  ```
  int32 seval(int32 p)
  /*---------------------------------------------------------------------------
   Evaluate the S-expression pointed to by the typed-pointer p; construct the
   result value as necessary; return a typed-pointer to the result.
   ---------------------------------------------------------------------------*/
  {
    #define Return(v) {traceprint(v,1); return(v);}
     //..............
    
    Return(v);
  }
  ```

  * 실행결과를 화면에 출력
  ```
  void swrite(int32 j)
  /*----------------------------------------------------------------------------
   The S-expression pointed to by j is typed out.
   ----------------------------------------------------------------------------*/
  {
   int32 i;
   int16 listsw;
  
   i= ptrv(j);
   switch (type(j)) {
     case 0: /* check for a list */
       j= i;
       while (type(B(j)) EQ 0) j= B(j);
       listsw= (B(j) EQ nilptr);
       ourprint("(");
       while (listsw) {swrite(A(i)); if ((i= B(i)) EQ nilptr) goto close; ourprint(" ");}
       swrite(A(i)); ourprint(" . "); swrite(B(i));
  	    close:  ourprint(")");
       break;
  
     case  8: ourprint(Atab[i].name); break;
     case  9: sprintf(sout,"%-g",Ntab[i].num); ourprint(sout); break;
     case 10: sprintf(sout,"{builtin function: %s}",Atab[i].name);
       ourprint(sout); break;
     case 11: sprintf(sout,"{builtin special form: %s}",Atab[i].name);
       ourprint(sout); break;
     case 12: sprintf(sout,"{user defined function: %s}",Atab[i].name);
       ourprint(sout); break;
     case 13: sprintf(sout,"{user defined special form: %s}",Atab[i].name);
       ourprint(sout); break;
     case 14: ourprint("{unnamed function}"); break;
     case 15: ourprint("{unnamed special form}"); break;
    }
  }
  ```

  * List Area 활용
  ```
  #define  m 6000
  struct Listarea {int32 car; int32 cdr;} *P;
  #define A(j)           P[j].car
  #define B(j)           P[j].cdr
  
  /* allocate the list area */
  P= (struct Listarea *)calloc(m,sizeof(struct Listarea));
  ```

  * Atom Table 활용
  ```
  /* The atom table */
  struct Atomtable {char name[16]; int32 L; int32 bl; int32 plist;} Atab[n];
  int32 ordatom (char *s)
  /*----------------------------------------------------------------------------
   The ordinary atom whose name is given as the argument string s is looked-up
   in the atom table and stored there as an atom with the value undefined if it
   is not already present.  The typed-pointer to this ordinary atom is then
   returned.
   ----------------------------------------------------------------------------*/
  {
    int32 j,c;
    #define hashname(s) (abs((s[0]<<16)+(s[(j=strlen(s))-1]<<8)+j) % n)
    j= hashname(s);/* old: c= 0; */ c =j;
    printf("ordatom: `%s' hashes to %d.\n",s,j);
  
    while (Atab[j].name[0]!=EOS) {
      if (strcmp(Atab[j].name,s) EQ 0) goto ret;
      else if (++j >= n) {j= 0; if (j EQ c) /* old: if (++c>1) */ 
        error("atom table is full");}
    }
    strcpy(Atab[j].name,s); Atab[j].L= ud(j);
    ret: return(oa(j));
  }
  ```

  * Number Table 활용
  ```
  /* The number table is used for storing floating point numbers.  The
     field nlink is used for linking number table nodes on the number
     table free space list. */
  union Numbertable {double num; int16 nlink;} Ntab[n];
  
  int32 numatom(double r)
  /*----------------------------------------------------------------------------
   The number r is looked-up in the number table and stored there as a lazy
   number atom if it is not already present.  The typed-pointer to this number
   atom is returned.
   ----------------------------------------------------------------------------*/
  {
    int32 j;
    #define hashnum(r) ((*(1+(int32 *)(&r)) & 0x7fffffff) % n)
    j= hashnum(r);
    printf("numatom: `%d' hashes to %d.\n",r,j);

    while (nx[j]!=-1)
      if (Ntab[nx[j]].num EQ r) {j= nx[j]; goto ret;} else if (++j EQ n) j= 0;
  
    if (nf<0) {gc(); if (nf<0) error("The number table is full");}
    nx[j]= nf;
    j= nf;
    nf= Ntab[nf].nlink;
    Ntab[j].num= r;
    ret: return(nu(j));
  }
  ```
