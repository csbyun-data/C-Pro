
### XLISP Calculation formula analysis
* XLISP code분석
  * text file load or stdin line load [code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XLISP/File/file_load.c), [load.txt](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XLISP/File/load.txt)
  * load.txt content ( > main.exe load.txt 실행)
  ```txt
  1 line
  2 line
  3 line
  ````
  ```txt
  - global 함수 포인터를 사용하여 문자를 읽어들일 함수를 지정하여 변경
  int (*xlgetc)();
  파일에서 문자를 읽어 들일때 :  xlgetc = fgetc를 사용
  terminal로 문자를 읽어 들일때 : xlgetc = tgetc를 사용
  ```
  ![image](https://github.com/user-attachments/assets/9388d55c-56c4-4812-812f-c102abd5bb15)
  * prompt에서 파일을 읽어 들이는 기능 추가 ( >@load.txt) [code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XLISP/File/file_load1.c)
  ```c
  function loadFile() 추가
  ```
  ![image](https://github.com/user-attachments/assets/22400111-b219-4b8b-8e96-734a5c7288d9)
  
* XLISP Calculation formula
  * 사칙연산 계산, ChatGPT [code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XLISP/Calc1.c)  
  ![image](https://github.com/user-attachments/assets/554028d6-3597-438a-9409-717c473792f6)

  * LISP 형식 계산식(+ 2 35 4)을 torken분석 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XLISP/tokenize1.c)


* XLISP function pointer를 활용 Builtin-functions
  * Builtin-functions (exit)실행  
  ![image](https://github.com/user-attachments/assets/c51eb562-0c12-4aed-bf3a-a6ec10686c65)
  ```c
  // 1.  'exit', 함수의 연결 정의
  xlsubr.c code
  /* fexit - get out of xlisp */
  void fexit() { exit(0); }

  /* xlinit - xlisp initialization routine */
  xlinit() { xlsubr("exit",fexit); }

  // 2. (exit) parser() 작업하여 node 생성
  /* read an expression */
  expr.n_ptr = xlread();

  // 3.  builtin function exit를 실행
  /* evaluate the expression */
  expr.n_ptr = xleval(expr.n_ptr);
  ```
  ```c
  /* evlist - evaluate a list */
  struct node *evlist(struct node *nptr) {
    struct node *oldstk,fun,args,*val;
  
    /* create a stack frame */
    oldstk = xlsave(&fun,&args,NULL);
  
    /* get the function and the argument list */
    fun.n_ptr = nptr->n_listvalue;
    args.n_ptr = nptr->n_listnext;
  
    /* evaluate the first expression */
    if ((fun.n_ptr = xleval(fun.n_ptr)) == NULL)
        xlfail("null function");
  
    /* evaluate the function */
    // fexit() 함수를 아래 SUBR logic에서 실행 함
    switch (fun.n_ptr->n_type) {
       case SUBR:
          val = (*fun.n_ptr->n_subr)(args.n_ptr);
          break;
       case FUN:
       case LIST:
          //val = evfun(fun.n_ptr,args.n_ptr);
          break;
       case OBJ:
          //val = xlsend(fun.n_ptr,args.n_ptr);
          break;
       default:
          xlfail("bad function");
    }
  
    /* restore the previous stack frame */
    xlstack = oldstk;
  
    /* return the result value */
    return (val);
  }
  ```
  
  * Function pointer, '+' xadd(val, arg)  
  ![image](https://github.com/user-attachments/assets/e61fc4e5-5f91-40e6-a479-11f269c79793)  
  <img src = "https://github.com/user-attachments/assets/43776492-f73b-45fa-abdb-2cbaeb650232" width="100%" height="100%">  

  ```c
  // 1. '+', add함수연결 정의
  /* xlminit - xlisp math initialization routine */
  xlminit() {
    xlsubr("+",add);
  }
  
  // 2. (+ 1 2) 입력 받아 순서대로 실행, parser() 작업하여 node 생성
  /* read an expression */
  expr.n_ptr = xlread();
  
  // 3. 수식을 순차적으로 실행	
  /* evaluate the expression */
  expr.n_ptr = xleval(expr.n_ptr);
  ```
  ```c
  /* evlist - evaluate a list */
  struct node *evlist(struct node *nptr) {
    struct node *oldstk,fun,args,*val;
  
    /* create a stack frame */
    oldstk = xlsave(&fun,&args,NULL);
  
    /* get the function and the argument list */
    fun.n_ptr = nptr->n_listvalue;
    args.n_ptr = nptr->n_listnext;
  
    /* evaluate the first expression */
    // '+'의 함수 add()를 찾는 loginc
    if ((fun.n_ptr = xleval(fun.n_ptr)) == NULL)
      xlfail("null function");
  
    /* evaluate the function */
    // add() 함수는 SUBR type임으로 하기 참조, 아래 부분에서 add(args.n_ptr)을 실행함
    switch (fun.n_ptr->n_type) {
      case SUBR:
        val = (*fun.n_ptr->n_subr)(args.n_ptr);
        break;
      case FUN:
      case LIST:
        //val = evfun(fun.n_ptr,args.n_ptr);
        break;
      case OBJ:
        //val = xlsend(fun.n_ptr,args.n_ptr);
        break;
      default:
        xlfail("bad function");
    }
  
    /* restore the previous stack frame */
    xlstack = oldstk;
  
    /* return the result value */
    return (val);
  } 
  ```
  
  * xlisp0.0 code [xldmem.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XLISP/SRC0/xldmem.c), [xldmem.h](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XLISP/SRC0/xldmem.h), [xleval.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XLISP/SRC0/xleval.c), [xleval.h](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XLISP/SRC0/xleval.h), [xlio.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XLISP/SRC0/xlio.c), [xlisp.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XLISP/SRC0/xlisp.c), [xlisp.h](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XLISP/SRC0/xlisp.h), [xlmath.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XLISP/SRC0/xlmath.c), [xlprin.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XLISP/SRC0/xlprin.c), [xlread.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XLISP/SRC0/xlread.c), [xlread.h](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XLISP/SRC0/xlread.h), [xlsubr.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XLISP/SRC0/xlsubr.c), [xlsubr.h](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XLISP/SRC0/xlsubr.h)

  ```txt
  // xlisp0.0 code에서 exit(), '+'기능만 남긴 짧은 code
  1. xlsubr.c Builtin-functions 
  2. xlmatn.c Function pointer, '+' xadd(val, arg)
  3. xlmem.c gc() - garbage collect
  4. xlio.c tgetc() - get a character from the terminal
  5. xlprint.c xlprint()
  ```
  
  * XLISP main.c driver 순서
  ```c
  // xlisp.c code 중에서
  /* xlisp - a small subset of lisp */
  ......
  main(int argc, char *argv[]) {
    struct node expr;
  
    xldmeminit();                <- 메모리할당 xldmem.c
    xlinit();   // (routine)     <- routin할당 xlsubr.c
    xlminit();  // (math)        <- 수식할당 xlmath.c
    xltin();                     <- 터미널 입력 xlio.c
  
    while (TRUE) {
      xlstack = NULL;
      xlsave(&expr, NULL);               <- xleval.c
      expr.n_ptr = xlread();             <- 터미널 입력 xlread.c
      expr.n_ptr = xleval(expr.n_ptr);   <- 수식분석 xleval.c
      xlprint(expr.n_ptr);               <- 결과출력 xlprint.c
    }
  }
  ```
  <img src = "https://github.com/user-attachments/assets/ee4fa3f4-661e-4f6e-b4c7-7d5e9389ffae" width="60%" height="60%">  
  
  * Builtin-functions (setq a 10) 실행
  ```txt
  // (setq a 10) 변수 선언, 초기값 설정
  > (setq a 10)  <- define variable a  , 초기값 10
  > (+ a 15)     <- 25
  > (setq a 15)  <- variable a, change value 15
  > (+ a 20)     <- 35
  ```
  ```txt
  - xlsubr() <- define builtin function
  xlsubr("setq", setq) <- string "setq", setq() function 연결
  xlenter("setq")      <- symbol table에 "setq" symbol을 등록
  ```
  ```c
  xlread.c code 중에서 symbol table 생성 구조체 변수
  /* global variables */
  struct node *oblist;
  ```
  ```c
  // xlsubr.c code 부분

  /* xlsubr - define a builtin function */
  xlsubr(sname,subr)
    char *sname; int (*subr)();
  {
      struct node *sym;
  
      /* enter the symbol */
      sym = xlenter(sname);
  
      /* initialize the value */
      sym->n_symvalue = newnode(SUBR);
      sym->n_symvalue->n_subr = subr;
  }
  
  /* xlenter - enter a symbol into the symbol table */
  struct node *xlenter(sname)
    char *sname;
  {
      struct node *sptr;
  	
      /* check for nil */
      if (strcmp(sname,"nil") == 0)
  		return (NULL);
  
      /* check for symbol already in table */
      for (sptr = oblist; sptr != NULL; sptr = sptr->n_listnext) 
  		if (sptr->n_listvalue == NULL)
  		    printf("bad oblist\n");
  		else if (sptr->n_listvalue->n_symname == NULL)
  		    printf("bad oblist symbol\n");
  		else
  		if (strcmp(sptr->n_listvalue->n_symname,sname) == 0)
  		    return (sptr->n_listvalue);
      
      /* enter a new symbol and link it into the symbol list */
      sptr = newnode(LIST);
      sptr->n_listnext = oblist;
      oblist = sptr;
      sptr->n_listvalue = newnode(SYM);
      sptr->n_listvalue->n_symname = strsave(sname);
  
      /* return the new symbol */
      return (sptr->n_listvalue);
  }
  
  ....
  /* xlinit - xlisp initialization routine */
  xlinit()
  {
  	xlsubr("setq",setq);
      xlsubr("exit",fexit);
  
  }
  ```
  ```c
  // setq() function, symbol에 number value를 저장하는 기능
  // (setq a 10)  <- a는 10을 가진 symbol 생성
  // xlsubr.c code 부분
  
  /* setq - builtin function setq */
  static struct node *setq(args)
    struct node *args;
  {
      struct node *oldstk,arg,sym,val;
  
      /* create a new stack frame */
      oldstk = xlsave(&arg,&sym,&val,NULL);
  
      /* initialize */
      arg.n_ptr = args;
  
      /* get the symbol */
      sym.n_ptr = xlmatch(SYM,&arg.n_ptr);
  
      /* get the new value */
      val.n_ptr = xlevarg(&arg.n_ptr);
  
      /* make sure there aren't any more arguments */
      if (arg.n_ptr != NULL)
  	xlfail("too many arguments");
  
      /* assign the symbol the value of argument 2 and the return value */
      assign(sym.n_ptr,val.n_ptr);
  
      /* restore the previous stack frame */
      xlstack = oldstk;
  
      /* return the result value */
      return (val.n_ptr);
  }
  ```
  ```c
  // a 10 symbol node를 생성
  // + 함수 xadd()를 실행하면서 a를 만나면 symbol를 10으로 변경하여 계산 작업
  > (setq a 10)
  10
  > (+ a 15)
  25
  
  (+ a 15)
  1. + -> LIST -> SYM으로 xadd() 진행
  2. xadd() 함수 뒤에 a symbol을 10로 변경
  3. xadd() 함수에  0 10을 입력하여 계산
  3. xadd() 함수에 10 15를 입력하여 계산
  4. 결과 25를 return
  ```  

  ![image](https://github.com/user-attachments/assets/e83aa2c7-50be-495c-8b18-740d2bc71b47)

  ```
  (+ 10 15)
  1. + -> LIST -> SYM으로 xadd() 진행
  2. xadd() 함수에  0 10을 입력하여 계산
  3. xadd() 함수에 10 15를 입력하여 계산
  4. 결과 25를 return
  ```

  ![image](https://github.com/user-attachments/assets/427393cc-3bff-4c08-b34b-0651cf69ad6b)
  * xlisp0.0 code 
  ```
  setq(), exit() implementation code
  ```
  


  
  * [참조 XLISP-PLUS: [https://almy.us/xlisp.html](https://almy.us/xlisp.html)]
  * [참조 XLISP : [https://www.softwarepreservation.org/projects/LISP/xlisp](https://www.softwarepreservation.org/projects/LISP/xlisp)]
