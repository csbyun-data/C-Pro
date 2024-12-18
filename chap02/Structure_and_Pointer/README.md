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
    
  
