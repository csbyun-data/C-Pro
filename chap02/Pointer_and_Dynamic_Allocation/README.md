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
  * 1.2 포인터의 잘못된 사용 조건 및 예 [here]()
  ```txt
  1) 변수의 수명이 완료된 개체의 주소를 참조
  2) NULL 포인터인 방향지시 연산자(*)의 포인터 역참조
  3) 실행 프로그램에서 사용되지 않는 주소를 지정하는 방향지시 연산자(*)의 포인터를 역참조
  4) long 포인터 형태로 정렬되지 않은 메모리를 참조함
  ```

  *  변수의 수명이 완료된 개체의 주소를 참조
  * 

* 2.포인터
  * 2.1 포인터
  * 2.1.1 포인터
