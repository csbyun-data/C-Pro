## 1.static, extern 사용 방법
### INDEX
* 1.static, extern 사용
  * 1.1. static 변수 사용 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/extern/static1.c)
  ```txt
  파일 내부에서 사용, 함수의 상태를 기록하기 위해 사용
  ```
  * 1.2 extern 변수, 함수 사용 [[cnt.h](https://github.com/csbyun-data/C-Pro/blob/main/chap01/extern/cnt.h), [cnt.c](https://github.com/csbyun-data/C-Pro/blob/main/chap01/extern/cnt.c), [main.c](https://github.com/csbyun-data/C-Pro/blob/main/chap01/extern/main.c)]
  ```txt
  다른 파일에서 접근 가능하고, 전역 변수, 함수 접근 제공
  ```
  * 1.3 static 변수, 함수, extern변수, 함수 사용 [[cnt1.h](https://github.com/csbyun-data/C-Pro/blob/main/chap01/extern/cnt1.h), [cnt1.c](https://github.com/csbyun-data/C-Pro/blob/main/chap01/extern/cnt1.c), [main1.c](https://github.com/csbyun-data/C-Pro/blob/main/chap01/extern/main1.c)]
  ```txt
  1) static 변수를 cnt2()함수는 함수가 선언된 파일 cnt.c 안에서 siCnt의 값은 변경
     main.c 파일 안에서 siCnt의 값은 변경하지 않는다
  2) static 변수가 선언된 "cnt.h"파일을 code파일에 포함해야 error가 발생하지 않는다
     error 예: [Error] 'siCnt' undeclared (first use in this function)
  3) 전역변수는 한개의 변수가 생성되고, 정적변수는 파일마다 한개의 변수가 생성 됨 
   ```  
  ![image](https://github.com/user-attachments/assets/7d964bc5-8ac3-49c0-9c8c-3b815c279a17)

* 2.extern 사용 관련 error발생
  * 2.1  [Error] invalid type argument of '->' (have 'int')
  ```txt
   n = xlevmatch(INT,&args)->n_int;    //  <- Error 발생 부분
   원인: xlevmatch() 함수가 파일 내에 정의되지 않아서 기본값으로 int형을 지정
   해결: xlevmatch() 함수를 head파일을 포함 명시적 함수 프로토타입을 선언
        extern struct node *xlevmatch(); 파일 상단에 code를 추가하여 해결
  ```
  ```c
  // xlisp-plus의 xldmem.c code 안에 Error 발생 점검
  // xlevmatch() 함수의 return 값을 알지 못해 컴파일러에서 해석 불가
  static struct node *fexpand(args)
    struct node *args;
  {
      struct node *val;
      int n,i;
  
      /* get the new number to allocate */
      if (args == NULL)
  	n = 1;
      else
  	n = xlevmatch(INT,&args)->n_int;    //  <- Error 발생 부분
  
      /* make sure there aren't any more arguments */
      if (args != NULL)
  	xlfail("too many arguments");
  
      /* allocate more segments */
      for (i = 0; i < n; i++)
  	if (!addseg())
  	    break;
  
      /* return the number of segments added */
      val = newnode(INT);
      val->n_int = i;
      return (val);
  }
  ```
  ```c
  // xlisp-plus xlsubr.c code에 구현된 xlevmath() 함수

  /* xlevmatch - get an evaluated argument and match its type */
  struct node *xlevmatch(type,pargs)
    int type; struct node **pargs;
  {
      struct node *arg;
  
      /* get the argument */
      arg = xlevarg(pargs);
  
      /* check its type */
      if (type == LIST) {
  	if (arg != NULL && arg->n_type != LIST)
  	    xlfail("bad argument type");
      }
      else {
  	if (arg == NULL || arg->n_type != type)
  	    xlfail("bad argument type");
      }
  
      /* return the argument */
      return (arg);
  }
  ```
  * 2.2 Error 해결 code
  ```c
  // 해결 code
  extern struct node *xlevmatch();  // <- 추가 code
  ....
  static struct node *fexpand(args)
    struct node *args;
  {
      ....
      return (val);
  }
  ```
  * 2.3  [Warning] assignment makes pointer from integer without a cast
  ```txt
  원인: xlsvar() 함수가 파일 내에 정의되지 않아서 기본값으로 int형을 지정
  해결: xlsvar() 함수를 head파일을 포함 명시적 함수 프로토타입을 선언
        head 파일을 생성하여 include <*.h>파일을 추가하여 해결
  ```
  ```c
  // xlisp-plus xlsubr.c code 중에 warning error 점검
  /* xlsvar - define a builtin string variable */
  xlsvar(sname,str)
    char *sname,*str;
  {
      struct node *sym;
  
      /* enter the symbol */
      sym = xlenter(sname);   // <- warning error 위치
  
      /* initialize the value */
      sym->n_symvalue = newnode(STR);
      sym->n_symvalue->n_str = strsave(str);
  }
  // xlisp xlread.c code 안에서
  /* xlenter - enter a symbol into the symbol table */
  struct node *xlenter(sname)
    char *sname;
  {
      ...................
   
      /* return the new symbol */
      return (sptr->n_listvalue);
  }
  ```

  
  

  
