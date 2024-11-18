## 02. 포인터, 배열, 문자열, 함수포인터
### Index
* 1.포인터와 배열
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

  *  1.3 Address 연산자(&) [사용예제](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Pointer_and_Dynamic_Allocation/Pointer_exam1.c)
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
    iPtr = &data;         // int *iPtr = &data; 동일 표현

    printf("%d", *iPtr);  // output 20
    *iPtr = 5;            // change the value through pointer
    printf("%d", data);   // output 5
  ```
  *  1.4 pointer로 가리킨 주소 안의 값을 변경
    ```c
    int num = 10;
    int *piData = &num;

    *piData = 14;
    printf("*piData=%d, num=%d", *piData, num);
    ```

  * 1.4 void포인터 (void *) [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/void_pointer1.c)
  ```c
  void func (void *ptr1, void *ptr2) { }

  char c1 = 'a', c2 = 'b';
  int num1 = 10, num2 = 20;

  func(&c1, &c2);
  func(&num1, &num2);
  ```
  *  ![image](https://github.com/user-attachments/assets/2df0edbc-d358-4dca-bd7b-72b503d5279d)
 
* 2.(메모리 동적할당) Pointer and dynamic memory allocation in C [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Pointer_and_Dynamic_Allocation/README.md)
  * 2.1 포인터 유형
  * 2.2 포인터 산술
  * 2.3 포인터와 배열
  * 2.4 function pointer
  * 2.5 포인터를 사용한는 일반적인 실수
    
* 3.Arrays and String in C [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/README.md)
  * 3.1 배열과 문자열
  * 3.2 배열을 함수 parameter로 전달
  * 3.3 pointer를 사용한 2차원 배열 접근
  * 3.4 정렬되지 않은 배열 보다 정렬된 배열 처리가 빠른 이유?
    
* 4.Structures and Unions in C [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Structures_and_Union/README.md)
  * 4.1 구조체
  * 4.2 공용체
