## 1. 구조체와 포인터 (Structure Pointer)
### INDEX
* 1.구조체와 포인터 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structure_and_Pointer/struct_pointer1.c)
    * 1.1 구조체 포인터 사용법
    ```c
    struct student {
      char name[10];
      int age;
    };

    // 구조체 선언 + 변수(st1) 생성
    struct student {
      char name[10];
      int age;
    } st1;

    // 구조체 변수
    struct student st1;

    // 구조체 포인터 변수
    struct student *pst1;
    ```
    * 1.2 구조체 포인터 선언 후 메모리 할당( type def활용) [code1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structure_and_Pointer/struct_pointer2.c), [code2](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structure_and_Pointer/struct_pointer3.c), [code3](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structure_and_Pointer/struct_pointer4.c), [code4](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structure_and_Pointer/struct_pointer5.c)
    ```txt
    [Error] invalid conversion from 'void*' to 'Person*' [-fpermissive] 수정
    ```
    * 1.3 구조체 초기화, 메모리
    
    
  
