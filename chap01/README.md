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

    if(fgets(ptr, 50, stdin) != NULL)         // stdin 표준입력 stream 
      fputs(ptr, stdout);      // stderr 표준에러 stream
	  free(ptr);
    return 0;
  }
  ```    
  *   3.3 fgets, fputs 사용법 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Input_fgets1.c)
  *   3.3.1 fgets 문자열 끝 newline 제거, null terminator로 변경 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Input_fgets2.c), [here](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Input_fgets3.c)
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
  *   4.1 실행시간체크 time() [here](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Running_time.c)
  *   4.2 qsort() 숫자정렬 [1](https://github.com/csbyun-data/C-Programming/blob/main/chap01/QSort/qsort_num1.c), [2](https://github.com/csbyun-data/C-Programming/blob/main/chap01/QSort/qsort_num2.c), [3](https://github.com/csbyun-data/C-Programming/blob/main/chap01/QSort/qsort_num3.c) 문자정렬 [1](https://github.com/csbyun-data/C-Programming/blob/main/chap01/QSort/qsort_word1.c), 구조체 정렬 [1](https://github.com/csbyun-data/C-Programming/blob/main/chap01/QSort/qsort_struct1.c)

* 5.조건문, 반복문
  *   5.1 if~else문장 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Flow/Flow_control1.c)
  *   5.2 for() break [here](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Flow/Flow_control2.c)
  *   5.3 for() continue [here](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Flow/Flow_control3.c)
  *   5.4 for() continue, break [here1](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Flow/Flow_control7.c) [here2](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Flow/Flow_control8.c)
  *   5.5 while() continue, break [here](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Flow/Flow_control4.c)
  *   5.6 do~while() [here1](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Flow/Flow_control5.c) [here2](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Flow/Flow_control6.c)

* 6.배열
  *   6.1 배열 초기화
  ```c
  int a[][2] = { {1, 2}, {3, 4}};
  int a[][2][2] = { {{1, 2}, {3, 4}}, {{5, 6}, {7, 8}} };
  int a[2][3] = { {1, 2, 3}, {4, 5, 6} };
  ```
* 7.함수
  *  7.1 함수 parameter 전달 ([Call by value](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Call_by_value1.c), [Call by address](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Call_by_address1.c), [Call by reference](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Call_by_reference1.c) [Call by pointer](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Call_by_pointer1.c) )
  *  7.2 1D 배열을 전달 
  ```c
  return_type foo ( array_type array_name[크기], ...);
  return_type foo ( array_type array_name[] , ...);
  return_type foo ( array_type* array_name, ...);

  //배열의 크기를 함수에 전달하지 않으면 크기를 알수 없다

  //Passing Array to Function in C
  //매개변수의 크기를 전달
  void func(int a[], int size) {}
  // void func(int* a, int size) {} 동일 표현

  int main() {
    int n = 5;
    int arr[5] = {1, 2, 3, 4, 5};
    func(arr, n);

    return 0;
  }
  ```
  [2-1 잘못된 예](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Incorrect_function_2-1.c), [2-1 옳은 예](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Correct_function_2-1.c), [2-2 잘못된 예](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Incorrect_function_2-2.c), [2-2 옳은 예](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Correct_function_2-2.c), [2-3](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Correct_function_2-2.c),[2-4](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Correct_function_2-2.c), [2-5 잘못된 예](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Incorrect_function_2-2.c), [2-5 옳은 예](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Correct_function_2-2.c)  

  ```txt
  2-1) 배열 매개변수에 sizeof()를 사용하지 말것( 배열의 갯수를 찾지 못함)
  2-2) 배열 pointer 붕괴 예제 (방법: 배열의 크기를 매개변수로 전달)
  2-3) 배열의 크기를 찾기위한 #define 매크로 사용
  2-4) pointer 연산사용: (&arr)[1]-arr을 이용 배열 크기 찾기
  2-5) 함수를 이용하여 숫자 배열 출력
  2-6) 함수를 이용하여 문자열 출력, 명령줄 인수 활용
  ```
  *  7.3 2D 배열을 전달 [here]()
  *  7.4 Struct를 전달 [here]()
  *  7.5 Reference Variable과 Pointer Variable의 차이 [here]()
