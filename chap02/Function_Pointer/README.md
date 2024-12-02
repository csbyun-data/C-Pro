
## 01. Function pointer
### Index

* 1.함수 포인터
   * 1.1 함수 포인터 형식과 사용 예 [code1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer/Function_Pointer1.c), [초기화[code1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer/Function_Pointer2.c), [code2](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer/Function_Pointer3.c)]
  ```txt
  // function pointer는 함수가 메모리에 올라와 있는 주소를 가르키는 포인터 상수
  // (constance pointer)를 가짐.
  void func();
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
  ```c
  // 05. 사용 예제5
  double func(double, double);
  double (*fptr)(double, double);
  ptr = &func;
  double a = (*fptr)( 10, 10);
  ```
  
   * 1.2 함수 포인터 배열 사용 및 초기화 [code1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer/Function_Pointer_Array1.c), [code2](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer/Function_Pointer_Array2.c), [code3](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer/Function_Pointer_Array3.c) 
   * 1.3 함수 포인터 type을 배열에 추가 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer/Function_Pointer_Type1.c)
  ```txt
  배열에 추가후 function을 순서대로 실행
  - 함수 포인터를 typedef를 설정하고, 배열의 요소는 함수 포인터
  ```
   * 1.4 함수 포인터를 함수의 parameter로 사용 [code1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer/Function_Pointer_Para1.c)
   * 1.5 함수 포인터와 void포인터를 이용한 qsort()함수
   * 1.6 함수 포인터와 void포인터를 이용한 search()함수
