## 01. Structure and Unions in C
### Index
* 1.구조체 (struct)
  * 1.1 구조체 정의, 초기화
  ```c
  // Defining structure in C
  struct MyData {
    int Age;
    float fees;
    char name[4];
  } data;

  // illegal example
  struct MyData {
    int a;
    struct MyData b;
  } data;

  // valid example
  struct MyData {
    int a;
    struct MyData *b;
  } data;

  // valid in C99 and C11
  struct MyData {
    int a;
    int b[];
  };

  // illegal example
  struct MyData {
    int b[];
  };
  ```
  ```c
  // illegal example
  // struct type 선언은 템플릿이고, 선언하지 않으면 구조체 저장 메모리가 없음
  struct Mydata {
    int a=0;    // illegal
    int b=0;    // illegal
  }
  // 초기화 방법1
  struct Mydata InfoData = { 2, 3};

  // 초기화 방법2
  struct Mydata InfoData;
  InfoData.a = 2;
  InfoData.b = 3;

  // 초기화 방법3 C99, C11
  struct Mydata InfoData = {.a=2, .b=3}; or struct Mydata InfoData = { .b=3, .a=2};
  struct Mydata InfoData = { 2, 3};
  ```
  ```c
  // typedef를 사용한 구조체
  - 변수 선언시 struct keyword를 사용하지 않음
  typedef struct {
    char acName[20];
    int iAge;
    int iTotalMarks;
  } sStudentInfo;

  sStudentInfo amlendra;
  ```
   ([구조체 포인터](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Structures_and_Union/Structure_pointer1.c))
  ```
  // 변수와 포인터를 사용한 structure member 접근
  struct Laptop {
    float Price;
    int ProductId;
    char name[24];
  } Laptop1, *Laptop2;

  Laptop1.ProducId
  Laptop2->ProductId or (*Laptop2).ProductId
  ```
  ```c
  // assign memory to the pointer to structure, error example
  Laptop2 = malloc( sizeof( struct Laptop));
  ```
  * 1.2 구조체 크기 계산 ([exam1](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Structures_and_Union/Structure_size1.c), [exam2](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Structures_and_Union/Structure_size2.c), [exam3](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Structures_and_Union/Structure_size3.c) )
  ```c
  #include <stdio.h>

  typedef struct {
    char Name[12];
    int Age;
    float Weight;
    int RollNumber;
  } sStudentInfo;

  int main()
  {
    // create variable of the structure;
    sStudentInfo RamInfo;

    printf("Size of structure = %d\n\n", sizeof(RamInfo));
  }
  //output:
  //Size of structure  =  24
  ```
  ([익명 구조체1](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Structures_and_Union/Anonymous_struct1.c), [익명 구조체2](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Structures_and_Union/Anonymous_struct2.c) )
  ```c
  // 구조체의 중요 형태와 활용, 익명의 구조체 C11사용
  struct { // anonymous struct
    short int b;
  };

  union { // anonymous union
    short int b;
  };
  ```
  * 1.3 구조체 hack ([hack1](), [hack2]())
  ```c
  typedef struct {
    int RollNumber;
    int TotalMarks;
    char Name[0];  // 0 byte
  } sStudentInfo;
  
  ﻿/*포인터를 사용하여 동적 길이 배열을 만들 수도 있지만 문제는 포인터에 추가
  (시스템에 따라 4바이트 또는 8바이트) 메모리가 필요하다는 것.
 구조에 포인터를 만들면 포인터에 메모리를 명시적으로 할당해야 하지만 구조 해킹을
 사용한 경우 어레이에 메모리를 다시 할당할 필요가 없습니다. */
 typedef struct {
   int iLen;
   char *pcName;
 } sNameInfo1;

 typedef struct {
   int iLen;
   char acName[0];
 } sNameInfo2

  //Allocating memory when using sNameInfo1
  sNameInfo1 *psInfo1 = malloc(sizeof(sNameInfo1));
  psInfo1->pcName = malloc(sizeof(char) * Number of character + 1);

  //freeing the allocated memory
  free(psInfo1->pcName);
  free(psInfo1);

  //Allocating memory when using sNameInfo2
  sNameInfo1 *psInfo2 = malloc(sizeof(sNameInfo1)+(sizeof(char) * Number of character + 1));

  //freeing the allocated memory
  free(psInfo2);
  ```
  * 1.4 구조체 내부 배열
  * 1.5 구조체 function pointer
  * 1.6 구조체 pointer 맴버
  * 1.7 구조체 내부 pointer 접근

* 2.공용체 (union)

* 3.Bit field
 

