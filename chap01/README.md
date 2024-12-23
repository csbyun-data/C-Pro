## 01. 문법 정리

### Index
* 1.문법
  *  1.1 Command line argument in C [exam1](https://github.com/csbyun-data/C-Pro/blob/main/chap01/CommandLineArgument1.c), [exam2](https://github.com/csbyun-data/C-Pro/blob/main/chap01/CommandLineArgument.c)
  *  1.2 증감 연산자
  ```c
  // 후위 증감 연산자
  num2 = num1++;  // 동일 표현 num2 = num1; num1++;
  num2 = num1--;  // num2 = num1; num1--;

  // 전위 증감 연산자
  num2 = ++num1;  // num1++; num2 = num1;
  num2 = --num1;  // num1--; num2 = num1;
  ```

* 2.가변인자, 가변함수, Variadic arguments (va_start, va_list, va_end, va_arg) 
  *  2.1 인자 더하기 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/VariableArgument_Add.c) 
  *  2.2 인자 최대값 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/VariableArgument_Max.c) 
  *  2.3 인자 평균값 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/VariableArgument_Average.c)
  *  2.4 인자 logfile 만들기 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/VariableArgument_Log.c) 
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
  
* 3.Input (scanf, gets, fgets)
  *  3.1 scanf() 사용법 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Input/Input_Scanf.c), (입력 문자열에 공백이 있는 경우 공백뒷글자 잘림 )
  *  3.1.1 fgets() 문자열 한줄 읽어 들임 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Input/Input_fgets.c)
  *  3.2 gets(), puts() 사용법 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Input/Input_gets1.c)
  ```c
  #include <stdio.h>
  #include <stdlib.h>

  int main() {
    char* ptr;

    ptr = (char *)malloc( sizeof(char) * 50);
    fputs("input String : ", stdout); // stdout 표준촐력 stream 

    if(fgets(ptr, 50, stdin) != NULL) // stdin 표준입력 stream 
      fputs(ptr, stdout);            	// stderr 표준에러 stream
	  free(ptr);
    return 0;
  }
  ```    
  *   3.3 fgets, fputs 사용법 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Input/Input_fgets1.c)
  *   3.3.1 fgets 문자열 끝 newline 제거, null terminator로 변경 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Input/Input_fgets2.c), [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Input/Input_fgets3.c)
  ```c
  void strip_newline( char *str, int size ) {
    int i;
 
    /* remove the null terminator */
    for (  i = 0; i < size; ++i ) {
        if ( str[i] == '\n' ) {
            str[i] = '\0';
 
            /* we're done, so just exit the function by returning */
            return;   
        }
    }
    /* if we get all the way to here, there must not have been a newline! */
  }
  ```

* 4.time(), qsort() 사용법 [qsort]()
  *  4.1 실행시간체크 time() [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Running_time.c)
  *  4.2 qsort() 숫자정렬 [1](https://github.com/csbyun-data/C-Pro/blob/main/chap01/QSort/qsort_num1.c), [2](https://github.com/csbyun-data/C-Pro/blob/main/chap01/QSort/qsort_num2.c), [3](https://github.com/csbyun-data/C-Pro/blob/main/chap01/QSort/qsort_num3.c) 문자정렬 [1](https://github.com/csbyun-data/C-Pro/blob/main/chap01/QSort/qsort_word1.c), 구조체 정렬 [1](https://github.com/csbyun-data/C-Pro/blob/main/chap01/QSort/qsort_struct1.c)

* 5.조건문, 반복문
  *  5.1 if~else문장 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Flow/Flow_control1.c)
  *  5.2 for() break [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Flow/Flow_control2.c)
  *  5.3 for() continue [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Flow/Flow_control3.c)
  *  5.4 for() continue, break [here1](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Flow/Flow_control7.c) [here2](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Flow/Flow_control8.c)
  *  5.5 while() continue, break [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Flow/Flow_control4.c)
  *  5.6 do~while() [here1](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Flow/Flow_control5.c) [here2](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Flow/Flow_control6.c)

* 6.배열, 문자열
  * 6.1 배열 초기화
  ```c
  int a[][2] = { {1, 2}, {3, 4}};
  int a[][2][2] = { {{1, 2}, {3, 4}}, {{5, 6}, {7, 8}} };
  int a[2][3] = { {1, 2, 3}, {4, 5, 6} };
  ```
  * 6.2 비정렬 배열 검색, 삽입, 삭제 [검색code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Array/Unsorted_Array_Search.c), [삽입 code1](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Array/Unsorted_Array_Insert.c),[삽입 code2](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Array/Unsorted_Array_Insert2.c) [삭제 code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Array/Unsorted_Array_Delete1.c)
  * 6.3 정렬 배열 검색, 삽입, 삭제 [검색 code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Array/Sorted_Array_Search1.c), [삽입 code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Array/Sorted_Array_Insert1.c), [삭제 code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Array/Sorted_Array_Delete1.c)
  * 6.3 String in C [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/README.md)

* 7.함수 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/README.md)
  * 7.1 함수 parameter 전달 
  * 7.2 1D 배열을 전달 
  * 7.3 2D 배열을 전달
  * 7.4 Struct를 전달
  * 7.5 Reference Variable과 Pointer Variable의 차이
    
* 8.typedef 사용법 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/TypeDef/README.md)
  *  8.1 typedef 사용법, 범위
  *  8.2 struct에 typedef 사용
  *  8.3 typedef를 사용한 범위 점검
  *  8.4 typedef pointer형 변수
  *  8.5 typedef 배열
  *  8.6 typedef function pointer 사용

* 9.Binary Octal Decimal Hexa변환 [code1](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Bin_Oct_Dec_Hexa.c), [code2](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Bin_Oct.c)
* 10.static, extern 사용 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/extern/README.md)
