### Flow-Statement
* conditional, repeating statement
    * if~else문장 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Flow/Flow_control1.c)
    * switch~case문장 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Flow/switch-case.c)
    * for() break [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Flow/Flow_control2.c)
    * for() continue [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Flow/Flow_control3.c)
    * for() continue, break [code1](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Flow/Flow_control7.c) [code2](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Flow/Flow_control8.c)
    * while() continue, break [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Flow/Flow_control4.c), [wc.c](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Flow/wc.c)
    ```txt
    File wc.c - a sample word count program
    ```
    * do~while() [code1](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Flow/Flow_control5.c) [code2](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Flow/Flow_control6.c)

* setjmp(). longjmp() 활용 [[code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Flow/setjmp.c), [xlisp code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Flow/xlisp_setjmp.c)]  
   ```
   #include <setjmp.h> 
    
   jmp_buf jbuf; 
    
   void  set_buffer() { 
     setjmp( jbuf ); 
   } 
    
   int main( int ac, char **av ) { 
     int a = atoi( av[1] ); 
     int b = atoi( av[2] ); 
    
     set_buffer(); 
     printf( "%d plus %d equals %d\n", a, b, a + b ); 
     longjmp( jbuf, 1 ); 
     printf( "After longjmp\n" ); 
     return EXIT_SUCCESS; 
   }
   ```
