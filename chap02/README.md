## 02. 포인터, 배열, 문자열, 함수포인터
### Index
* 1.포인터와 배열
  * 1.1 void포인터 (void *) [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/void_pointer1.c)
  ```c
  void func (void *ptr1, void *ptr2) { }

  char c1 = 'a', c2 = 'b';
  int num1 = 10, num2 = 20;

  func(&c1, &c2);
  func(&num1, &num2);
  ```
  *  ![image](https://github.com/user-attachments/assets/2df0edbc-d358-4dca-bd7b-72b503d5279d)
  * 1.2 Pointer and dynamic memory allocation in C [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Pointer_and_Dynamic_Allocation/README.md)
  * 1.2.1 포인터선언
  * 1.2.2 포인터 유형
  * 1.2.3 포인터 산술
  * 1.2.4 포인터와 배열
  * 1.2.5 function pointer
  * 1.2.6 포인터를 사용한는 일반적인 실수
    
  * 1.3 Arrays and String in C [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/README.md)
  * 1.3.1 배열과 문자열
  * 1.3.2 배열을 함수 parameter로 전달
  * 1.3.3 pointer를 사용한 2차원 배열 접근
  * 1.3.4 정렬되지 않은 배열 보다 정렬된 배열 처리가 빠른 이유?
* 2.문자열
* 3.메모리 동적할당
* 4.구조체
