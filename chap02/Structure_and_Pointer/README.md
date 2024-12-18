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
    * 1.3 구조체 초기화, 메모리 [code1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structure_and_Pointer/struct_pointer6.c), [code2](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structure_and_Pointer/struct_pointer7.c), [code3](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structure_and_Pointer/struct_pointer8.c), [code4](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structure_and_Pointer/struct_pointer9.c), [code5](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structure_and_Pointer/struct_pointer10.c)
    ```c
    // 구조체 변수, 포인터 변수 할당및 복사 예
    struct p p1;
    struct p* p2 = malloc(sizeof(struct p));
    memcpy(p2, &p1, sizeof(struct p));

    struct p* p1 = malloc(sizeof(struct p));
    struct p p2;
    memcpy(&p2, p1, sizeof(struct p));
    ```
    ```c
    // 구조체 선언 예1 
   struct Phone {
      int areacode;
      usingned long long number;
   };
   
   struct Person {
      char name[20];
      int age;
      struct Phone p;
   };
   
   // 구조체 선언 예2
   struct Person {
      char name[20];
      int age;
      struct Phone {
         int areaCode;
         usinged long long number;
      };
   };
   
   //초기화 예
   struct Person p1 = {.name = "name1", .age = 25, {.areacode = 82, .number = 12345678}};
   struct Person p2 = {"name2", 20, {82, 12345678}};
    ```

    
    
  
