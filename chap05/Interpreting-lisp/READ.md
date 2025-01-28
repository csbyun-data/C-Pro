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
  * [code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/Interpreting-lisp/lisp.c)
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
  
