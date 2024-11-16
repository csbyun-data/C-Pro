## 01. 문법1
### Index
* 1.문법
  *   1.1 Command line argument in C [here](https://github.com/csbyun-data/C-Programming/blob/main/chap01/CommandLineArgument.c)

* 2.가변인자, 가변함수, Variadic arguments (va_start, va_list, va_end, va_arg) 
  *   2.1 인자 더하기 [Add](https://github.com/csbyun-data/C-Programming/blob/main/chap01/VariableArgument_Add.c) 
  *   2.2 인자 최대값 [Max](https://github.com/csbyun-data/C-Programming/blob/main/chap01/VariableArgument_Max.c) 
  *   2.3 인자 평균값 [Average](https://github.com/csbyun-data/C-Programming/blob/main/chap01/VariableArgument_Average.c)
  *   2.4 인자 logfile 만들기 [Log File](https://github.com/csbyun-data/C-Programming/blob/main/chap01/VariableArgument_Log.c)) 
  ```c
  #include <stdarg.h>
  
  int a_func(int x, ...) {
  	va_list a_list;
  	va_start( a_list, x)
  }
  ```
