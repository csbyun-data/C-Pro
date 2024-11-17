## 01. Pointer and Dynamic memory allocation in C
### Index
* 1.포인터
  * 1.1 포인터 선언
  ```c
  int *iPtr;
  a = *iPtr;
  *iPtr=a;

  char cData;
  char *pcData = NULL;
        pcData = &cData;
  ```
  * 1.2 포인터의 잘못된 사용 조건 및 예 [exam1](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Pointer_and_Dynamic_Allocation/Invalid_pointer_value1.c) [exam4](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Pointer_and_Dynamic_Allocation/Invalid_pointer_value4.c)
  ```txt
  1) 변수의 수명이 완료된 개체의 주소를 참조
  2) NULL 포인터인 방향지시 연산자(*)의 포인터 역참조
  3) 실행 프로그램에서 사용되지 않는 주소를 지정하는 방향지시 연산자(*)의 포인터를 역참조
  4) long 포인터 형태로 정렬되지 않은 메모리를 참조함
  ```

  *  1.3 Address 연산자(&)
  ```txt
  int data = 0;  // declaration of integer variable
  &data // Give the address of the data
  int *pData; // declaration of pointer
  &pData // give the address of the pointer

  1) pointer 선언
    int *iPtr=NULL;
  
  2) pointer에 address 할당
    int *iPtr, data;    // int *iPtr, int data 선언됨
    data = 20;
    iPtr = &data;
  
  3) pointer 호출
    int *iPtr, data;
    data = 20;
    iPtr = &data;

    printf("%d", *iPtr);  // output 20
    *iPtr = 5;            // change the value through pointer
    printf("%d", data);   // output 5
  ```

* 2.포인터
  * 2.1 포인터
  * 2.1.1 포인터
