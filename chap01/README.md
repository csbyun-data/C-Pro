## 01. 문법1
### Index
* 1.문법
  *   1.1 Command line argument in C [here](https://github.com/csbyun-data/C-Programming/blob/main/chap01/CommandLineArgument.c)

* 2.가변인자, 가변함수, Variadic arguments (va_start, va_list, va_end, va_arg) 
  *   2.1 인자 더하기 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap01/VariableArgument_Add.c) 
  *   2.2 인자 최대값 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap01/VariableArgument_Max.c) 
  *   2.3 인자 평균값 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap01/VariableArgument_Average.c)
  *   2.4 인자 logfile 만들기 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap01/VariableArgument_Log.c) 
  ```c
  #include <stdarg.h>
  
  int a_func(int x, ...) {
  	va_list a_list;
  	va_start( a_list, x)
  }
  ```
* 3.Input (scanf, gets, fgets)
  *   3.1 scanf 사용법 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Input_Scanf.c)
  *   3.1.1 문자열 한줄 읽어 들임 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Input_fgets.c)
  *   3.2 gets, puts 사용법 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Input_gets1.c)
  ```c
  #include <stdio.h>
  #include <stdlib.h>

  int main() {
    char* ptr;

    ptr = (char*)malloc(sizeof(char)*50);
	   fputs("input String : ", stdout);  // stdout 표준촐력 stream 

    if(fgets(ptr, 50, stdin) != NULL)  // stdin 표준입력 stream 
		     fputs(ptr, stdout);            // stderr 표준에러 stream
	   free(ptr);
    return 0;
  }
  ```    
  *   3.3 fgets 사용법 [here]()

