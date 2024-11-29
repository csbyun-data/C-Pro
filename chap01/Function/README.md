## 01. FUNCTION
### Index
* 1.함수
  *  1.1 함수 parameter 전달
  *  Call by value 방식 [[code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Call_by_value1.c)]
  *  Call by address 방식 [[code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Call_by_address1.c)]
  *  Call by reference 방식 [[code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Call_by_reference1.c)]
  *  Call by pointer 방식 [[code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Call_by_pointer1.c)]

  ```c
  // call by value ( pass by value)
  void swap( int x, int y) { }
  ...
  swap(a, b);
  ```
  ```c
  // call by address (pass by address)
  void swap( int *x, int *y) { }
  ...
  swap( &a, &b);
  ```
  ```c
  // call by reference ( pass by reference)
  // C 사용안됨, C++에서 사용함
  void swap( int &x, int &y) { }
  ...
  swap(a, b);
  ```
  ```c
  // the pass by pointer in function
  void modifyVal ( int *myptr) { }
  ...
  modifyVal(myptr);
  ```

  *  1.2 1D 배열을 전달
  *  배열 전달 call by address 활용 [[code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Parameter_1D_1_1.c)]
  *  포인터 전달 call by address 활용 [[code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Parameter_1D_1_2.c)]
  ```c
  return_type foo ( array_type array_name[크기], ...);
  return_type foo ( array_type array_name[] , ...);
  return_type foo ( array_type *array_name, ...);

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
  [2-1 잘못된 예](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Incorrect_function_2-1.c), [2-1 옳은 예](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Correct_function_2-1.c), [2-2 잘못된 예](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Incorrect_function_2-2.c), [2-2 옳은 예](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Correct_function_2-2.c), [2-3](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Correct_function_2-2.c),[2-4](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Correct_function_2-2.c), [2-5 잘못된 예](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Incorrect_function_2-2.c), [2-5 옳은 예](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Correct_function_2-2.c)  

  ```txt
  2-1) 배열 매개변수에 sizeof()를 사용하지 말것( 배열의 갯수를 찾지 못함)
  2-2) 배열 pointer 붕괴 예제 (방법: 배열의 크기를 매개변수로 전달)
  2-3) 배열의 크기를 찾기위한 #define 매크로 사용
  2-4) pointer 연산사용: (&arr)[1]-arr을 이용 배열 크기 찾기
  2-5) 함수를 이용하여 숫자 배열 출력
  ```
  [2-6예1](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/String_function_2-6-1.c), [2-6예2](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/String_function_2-6-2.c)
  ```txt
  2-6) 함수를 이용하여 문자열 출력, 명령줄 인수 활용
  ```
  * 1.3 함수 return void형
  ```c
  #include <stdio.h>
  void func01() { printf("running function\n"); }
  ```  
  * 1.3 함수 return int형
  ```c
  // call by value( pass by value) 활용
  #include <stdio.h>
  int func01() {
    int a=1;
    return a;
  }

  int func02( int a, int b) { return (a+b); }

  int main() {
    int ret = func01();
    printf("func01 함수의 반환 값은 {%d} \n", ret);

    int sum = func02(5, 10);
    printf("func02() = %d\n", sum);

    return 0;
  }
  ```
  
  * 1.4 return int *예제, static int variable value를 사용
  ```c
  #include <stdio.h>
  int *func() {
    static int n;
    scanf("%d", &n);

    return &n;
  }

  int main() {
    int *ip;
    ip = func();

    printf("%d\n", *ip);
  }
  ```
  * 1.5 return int *예제, (int *)malloc( sizeof(int)*2)를 사용
  ```c
  #include <stdio.h>
  #include <stdlib.h>

  int *solution(int a, int b) {
    int *answer = (int *)malloc(sizeof(int)*2);

    answer[0] = a+b;
    answer[1] = a-b;

    return answer;
  }
  int main() {
    int a=3, b=5;
    int * ret = solution(a, b);

    printf("Ret Value: {%d, %d}.\n", ret[0], ret[1]);
  }
  ```
  * 1.6 return int * 예제 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Return_Ptr_int1.c)
  * 1.7 return int * 예제, malloc 사용하지 않은 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Return_Ptr_int2.c)
  * 1.8 use the dynamic array to return multiple value from the function [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Return_Ptr_Array1.c)
  * 1.9 return 1D 문자열 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Return_Ptr_String1.c)
  * 1.10 return char *예제, static char carr[100] 문자열 활용 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Return_Ptr_String2.c)
  * 1.11 return char *예제, 구조체의 char변수형을 반환 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Return_Ptr_Structure1.c)
  * 1.12 char * 예제 [code1](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Return_Ptr_Char1.c), [code2](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Return_Ptr_Char2.c), [code3](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Return_Ptr_Char3.c)
  ```c
  [Warning] deprecated conversion from string constant to 'char*' [-Wwrite-strings]
  The C++11 Standard (ISO/IEC 14882:2011)
  char* p = "abc"; // valid in C, invalid in C++
  char* p = (char*)"abc"; // OK: cast added
  char const *p = "abc"; // valid and safe in either C or C++.

  char* p = strdup("abc");
  char p[] = "abc";
  ```
  ```c
  // code2 자료
  // [Warning] deprecated conversion from string constant to 'char*' [-Wwrite-strings]
  // char* p = (char*)"abc"; // OK: cast added
  ```
  ```c
  // code3 자료
  // [Warning] deprecated conversion from string constant to 'char*' [-Wwrite-strings]
  char const *p = "abc"; // valid and safe in either C or C++.
  const char * p == char const * P
  ```


  * 1.13 return struc 예제, 결과 값만 반환하고 내부변수를 참조하지 않음 [code1](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Return_Structure1.c), [code2](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Return_Structure2.c)
  ```c
  // code1
  struct _point {
   	int x;
   	int y;
  };

  struct _point func() {
    struct _point s = {10, 10};
   	return s;
  }
  ```
  ```c
  // code2 
  typedef struct Pair{
    int first_num;
    int second_num;
  } Pair;

  Pair func_c(char* exp, int idx){
    Pair ret;
    ...
    ret.first_num = atoi(first_num);
    ret.second_num = atoi(second_num);
    return ret;
  }
  ```
  * 1.14 return multiple values from function using structure [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Return_Structure3.c)
  * 1.15 return struct * 예제, static structure 활용 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Return_Struct_Ptr1.c)
  ```c
  struct _point *func() {
    static struct _point s={ 10, 10};

    return &s;
  }
  ```
  * 1.16 return struct * 예제 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Return_Struct_Ptr2.c)
  ```c
  (int *)malloc( sizeof(int)*(2))
  (_pair *)malloc( sizeof(_pair)*(2))
  ```

  *  1.17 2D 배열을 전달 [3-1](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Parameter_2D_3-1.c), [3-2](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Parameter_2D_3-2.c), [3-2p](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Parameter_2D_3-2p.c), [3-3](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Parameter_2D_3-3.c)
  ```txt
  17-1) 고정된 행과 열을 2D 배열의 매개변수로 전달
  17-2) 행 제외, 열만 2D 배열의 매개변수로 전달
      - 행, 열을 parameter로 전달
  17-3) 행, 열 고정되지 않은 2D배열을 매개변수로 전달
  ```
  *  1.18 Struct를 전달 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Struct_parameter.c)
  *  1.18 Reference Variable과 Pointer Variable의 차이 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Reference_Pointer_diff.cpp)
