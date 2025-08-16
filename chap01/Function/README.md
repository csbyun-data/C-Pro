### Function
* Variable
  * 1.1 reference 와 pointer 비교 [reference code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/reference.cpp), [pointer code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/pointer.cpp)
  <img width="480" height="350" alt="image" src="https://github.com/user-attachments/assets/991e8748-2764-4fe4-b579-c850b0a56991" />

* Function
   *  1.1 함수 parameter 전달
   *  C언어 Call by value 방식 [[code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Call_by_value1.c)]
   *  C언어 호칭 Call by address (Call by reference), C++호칭 (Call by pointer) 방식 [[code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Call_by_address1.c)]
   *  C++언어 호칭 Call by reference 방식 [[code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Call_by_reference1.c)]  
   ![image](https://github.com/user-attachments/assets/ad9a04fb-516c-49e4-9deb-9730aced3551)
 
   ```c
   // call by value ( pass by value)
   void swap( int x, int y) { }
   ...
   swap(a, b);
   ```
   ```c
   // call by address (pass by address), call by pointer
   void swap( int *x, int *y) { }
   ...
   swap( &a, &b);
   ```
   ```txt
   포인터와 함수
   함수가 외부로부터 매개 변수를 통하여 데이터를 받는 방법은 크게 두 가지가 있다.
   
   값에 의한 호출(call-by-value): 복사본이 전달된다. (기본적인 방법)
   참조에 의한 호출(call-by-reference): 원본이 전달된다. (포인터를 이용)
   함수가 외부에서 선언된 변수의 값을 변경할 필요가 있다면 참조에 의한 호출을 사용해야 한다.
   
   대표적인 swap예시 (두 수를 바꾸는 함수)
   // call by address
   int main()
   {
     int a = 100, b = 200;
     swap(&a, &b);
     printf("%d %d",a,b);
 
     return 0;
   }
   void swap(int *px, int *py) {
     int tmp;
     tmp = *px;
     *px = *py;
     *py = tmp;
   }
   //실행 결과 200 100 으로 두개의 변수의 값이 제대로 교환된 것을 알 수 있다.
   함수가 포인터를 통하여 값을 변경할 수 없게 하려면 const지정자를 쓰면 된다.
   
   void sub(const int *p)
   { *p = 0; } //오류! const로 선언되면 매개 변수 p를 통하여 값을 변경할 수 없다.
   -> 만약 함수가 하나 이상의 값을 반환하여야 한다면 포인터를 사용하는 것이 가장 좋은 방법이다.
   ​
   [출처] (C언어) '포인터' 개념 정리|작성자 써밋
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
   void modifyVal ( int *myptr) {
     *myptr = 200;
   }

   int main(void) {
     int a = 100;
     int *myptr = &a;
     modifyVal(myptr);

     printf("%d", a);
     return 0;
   }
   ```
 
   *  1.2 1D 배열을 전달

   *  배열 전달 call by address 활용 [[code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Parameter_1D_1_1.c)]
   *  포인터 전달 call by address 활용 [[code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Parameter_1D_1_2.c)]
   ```c
   // https://www.geeksforgeeks.org/how-arrays-are-passed-to-functions-in-cc/
   return_type foo ( array_type array_name[크기], ...);
   return_type foo ( array_type array_name[] , ...);
   return_type foo ( array_type *array_name, ...);
 
   //배열의 크기를 함수에 전달하지 않으면 크기를 알수 없다
 
   //Passing Array to Function in C
   //매개변수의 크기를 전달
   void func(int a[], int size) {}
   // void func(int *a, int size) {} 동일 표현
 
   int main() {
     int n = 5;
     int arr[5] = {1, 2, 3, 4, 5};
     func(arr, n);
 
     return 0;
   }
   ```
   * [2-1 잘못된 code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Incorrect_function_2-1.c), [2-1 옳은 code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Correct_function_2-1.c), [2-2 잘못된 code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Incorrect_function_2-2.c), [2-2 옳은 code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Correct_function_2-2.c), [2-3 code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Correct_function_2-2.c)
   * [2-4 code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Correct_function_2-2.c), [2-5 잘못된 code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Incorrect_function_2-2.c), [2-5 옳은 code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Correct_function_2-2.c)  
 
   ```txt
   2-1) 배열 매개변수에 sizeof()를 사용하지 말것( 배열의 갯수를 찾지 못함)
   2-2) 배열 pointer 붕괴 예제 (방법: 배열의 크기를 매개변수로 전달)
   2-3) 배열의 크기를 찾기위한 #define 매크로 사용
   2-4) pointer 연산사용: (&arr)[1]-arr을 이용 배열 크기 찾기
   2-5) 함수를 이용하여 숫자 배열 출력
   ```
   * [2-6 code1](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/String_function_2-6-1.c), [2-6 code2](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/String_function_2-6-2.c)
   ```txt
   2-6) 함수를 이용하여 문자열 출력, 명령줄 인수 활용
   void fun(char *arr) { } // 동일 표현 void fun(char arr[])
  
   // char arr[] = {'a','b','c','d','e','f','g','h','\0' }; 동일 표현  
   char arr[] = "abcdefgh";
   fun(arr);
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
   *  1.18 Struct를 전달 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Struct_parameter.c)
   ```c
   struct Rect {...};
   void changeLength (struct Rect *p, int l) {
     p->length = l;
   }
   struct Rect r = {10, 5};
   changeLength(&r, 20);
   ```
 
   *  1.19 Reference Variable과 Pointer Variable의 차이 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/Reference_Pointer_diff.cpp)
   ```c
   int a = 10;
   int *p = &a; // 포인터 변수, 주소값 할당
   int &r = a;  // 레퍼런스 변수, 대상을 직접 할당
   
   struct person { int birthday; };
   struct person *peter = NULL; //포인터 변수, NULL 입력가능
   if (peter != NULL) //포인터 변수는 NULL 값인지 반드시 확인 필요
     peter->birthday = 1220;
   else
     printf("peter is null\n");
   ```
   ```c
   void FuncByPointer(struct person*);
   // 포인터 매개변수는 사용시 반드시 NULL 확인 필요
   void FuncByReference(struct person&);
   // 참조 매개변수는 NULL확인 필요하지 않음

   int main(void) {
     struct person peter;
     FuncByPointer(&peter);  // pointer parameter 사용법
     FuncByReference(peter); // reference parameter 사용법
   }
   ```

