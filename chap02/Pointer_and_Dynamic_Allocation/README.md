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
 
* 2.포인터 유형
  ```txt
  1) NULL pointer
    int *iPtr = NULL;
  
  2) void pointer
    void *vPtr;
  * 2.1 void pointer
  * 2.1.1 size of a void pointer in c?
  ```c
  void *pvData = NULL;  // sizeof(pvData) -> 8
  int *piData = NULL;   // sizeof(pvData) -> 8
  char *pcData = NULL;  // sizeof(pvData) -> 8
  float *pfData = NULL; // sizeof(pvData) -> 8
  ``` 
  * 2.1.2 void pointer의 역참조
  ```c
  void *pvData;
  int iData = 10;
  pvData = &iData;

  // [Warning] dereferencing 'void' pointer
  // invalid use of void expression
  *pvData;   // -> *(int *)pvData; Error 해결
  ```
  * 2.1.3 void pointer를 사용하는 이유? [exam3](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Pointer_and_Dynamic_Allocation/Void_pointer_exam3.c)
  ```txt
  모든 object의 주소를 저장할 수 있고 적절한 casting으로 긴접 연산자로 사용
  ```
  * 2.1.4 void pointer 산술 연산 [exam4](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Pointer_and_Dynamic_Allocation/Void_pointer_exam4.c)
  * 2.1.5 void pointer 함수에 사용 [exam5](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Pointer_and_Dynamic_Allocation/Void_pointer_exam5.c)
  ```c
  void qsort(void *arr, size_t elements, size_t size, int (*comp)(const void *, const void *));
  ```
  * 2.1.6 void pointer 단점
  ```c
  // 형식 지정을 적절하게 잘 사용해야 됨
  // C standard arithmetic operation에는 비허용, GNU-C는 허용
  #incluse <stdio.h>

  int main() {
    int aiData[3] = { 100, 200, 300 };
    void *pvData = &aiData[1]; // address of 200

    pvData += sizeof(int);
    printf("%d", *(int *)pvData);  // print 300

    return 0;
  }
  ```
  * 2.1.7 void pointer 장점 [exam7]()

* 3.pointer 산술작업
  * 3.1 pointer 산술
  * 3.2 포인터 증가 프로그램
  * 3.3 structure의 size 계산
  * 3.4 pointer 요소간의 거리 계산
  * 3.5 pointer 요소간의 비교
  * 3.6 간접 증가/감소 operator 사용

* 4.pointer와 배열
  * 4.1 pointer와 문자 배열의 관계
  * 4.2 pointer를 이용한 배열의 모든 요소 접근
  * 4.3 배열을 수정하려고 할 떄의 컴파일 error
 
* 5.pointer와 function
  * 5.1 function pointer
  * 5.2 function pointer이용 함수 호출
  * 5.3 function pointer를 인수로 사용
  * 5.4 함수에서 function pointer 반환
  * 5.5 function pointer배열

* 6.pointer를 사용하는 일반적인 실수
  * 6.1 pointer를 초기화하지 않음
  * 6.2 포인터의 비교
  * 6.3 dynamic memory 할당을 이용한 포인터 선언
  * 6.4 유효하지 않은 address를 가리키는 pointer
 
