### 가변인자, 가변함수, Variadic arguments (va_start, va_list, va_end, va_arg) 
* Factor
    * 인자 더하기 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/VariableArgument_Add.c) 
    * 인자 최대값 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/VariableArgument_Max.c) 
    * 인자 평균값 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/VariableArgument_Average.c)
    * 인자 logfile 만들기 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/VariableArgument_Log.c) 
    ```c
    #include <stdarg.h>
    
    int a_func(int x, ...) {
      va_list a_list;
      va_start( a_list, x)
      for (...) {
        va_arg(ptr, int); // Accessing current variable and pointing to next one
      }
      va_end(ptr); // Ending argument list traversal
    }
    ```
* printf() function
    ```c
    int a;
    int *pa = &a;
    printf("%c, %d, %g, %x", 'a', 10, 3.1415, pa);
    ```
* 가변함수를 사용하지 않은 예 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Variadic/valist_argment.c)

    
