
### Function pointer
* Function Pointer
   * 함수 포인터 형식과 사용 예 [[main() code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer/main_function.c), [code1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer/Function_Pointer1.c)], [초기화[code1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer/Function_Pointer2.c), [code2](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer/Function_Pointer3.c)]
  ```txt
  // function pointer는 함수가 메모리에 올라와 있는 주소를 가르키는 포인터 상수
  // (constance pointer)를 가짐.
  void func();

  #include <stdio.h>
  int main() {
    printf("%x\n", main);
  }
  ```
  ```c
  // 01. 사용 예제1
  void (*fptr)();
  fptr = &func;
  (*fptr)();

  // 02. 사용 예제2
  void (*fptr)() = &func;
  (*fptr)();  
  ```
  ```c
  // 03. 사용 예제3
  void (*fptr)();
  fptr = funcc;
  fptr();

  // 04. 사용 예제4
  void (*fptr)() = func;
  fptr();
  ```
    * 사용 예제3, 예제4 [code1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer/Func_Ptr_exam3_1.c), [code2](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer/Func_Ptr_exam3_2.c)  
  ```c
  // 05. 사용 예제5
  double func(double, double);
  double (*fptr)(double, double);
  ptr = &func;
  double a = (*fptr)( 10, 10);
  ```
  
   * 함수 포인터 배열 사용 및 초기화 [code1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer/Function_Pointer_Array1.c), [code2](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer/Function_Pointer_Array2.c), [code3](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer/Function_Pointer_Array3.c)
  ```txt
    int (*fun_ptr_arr[])( int, int) = { add, subtract, multiply, divide};
  
    //동일 표현
    int (*fp[4])( int, int);
    fp[0] = add;
    fp[1] = subtract;
    fp[2] = multiple;
    fp[3] = divide;
  ```
  
   * 함수 포인터 type을 배열에 추가 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer/Function_Pointer_Type1.c)
  ```txt
  배열에 추가후 function을 순서대로 실행
  - 함수 포인터를 typedef를 설정하고, 배열의 요소는 함수 포인터
  ```
   * 함수 포인터를 함수의 parameter로 사용 [code1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer/Function_Pointer_Para1.c), [code2](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer/Function_Pointer_Para2.c)
  ```c
  // 여러개의 함수들을 unitTest하기 위한 logic
  typedef void (*UnitTestFunction)(void);

  static void test_1( void) { printf("run test_1\n"); }
  ...
  static void run_test( UnitTestFunction test) { test(); }
  void run_tests( UnitTestFunction *tests) {
    int i;

    for (i=0; tests[i] != NULL; ++i) { run_test(tests[i]); }
  }
  
  static UnitTestFunction tests[] = { test_1, test_2, NULL };
  int main(int argc, char *argv[]) {
    run_tests(tests);
  }
  ```
   * 함수 포인터와 void포인터를 이용한 qsort()함수 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer/Function_Pointer_qsort1.c)
  ```c
  int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
  }
  ...
  qsort(arr, n, sizeof(int), compare);
  ```

   * 함수 포인터와 void포인터를 이용한 search()함수 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer/Function_Pointer_Search1.c)
  ```c
  bool compare(const void* a, const void* b)
  ...
  int search(void* arr, int arr_size, int ele_size, void* x,
           bool compare(const void*, const void*))
  ```
  * 함수 포인터(Callbacks in C) [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer/Func_Ptr_CallBacks.c)
  ```c
  // callback function
  void B(void (*ptr)()) {
    (*ptr)(); // callback to A
  }
  ```
  ```c
  // Book pointers on C Chap 17 breadth.c Solution 17.6ȱ
  void breadth_first_traversal( void (*callback)( TREE_TYPE value ) )
  {
    int current;
    int child;
  
    /* Insert the root node into the queue. */
    queue_insert( 1 );

    /* While the queue is not empty... */
    while( !is_queue_empty() ){
      /* Take the first value off the queue and process it */
      current = queue_first();
      queue_delete();
      callback( tree[ current ] );

      /* Add the children of the node to the queue. */
      child = left_child( current );
      if( child < ARRAY_SIZE && tree[ child ] != 0 )
         queue_insert( child );
      child = left_child( current );
      if( child < ARRAY_SIZE && tree[ child ] != 0 )
        queue_insert( child ); 
     } 
  } 
  ```
### [Book] Turbo C The Art of Advanced Program Design Optimization and Debugging
* Pointer to Function
    * Trapezoid Rule [code](https://github.com/csbyun-data/C-Pro/tree/main/chap02/Function_Pointer/Prg3_3b.c)
    * Classic Bubble Sort [code](https://github.com/csbyun-data/C-Pro/tree/main/chap02/Function_Pointer/Prg3_4.c)

  
