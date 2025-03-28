### Structure and Unions in C
* 1.Structure
  * Reference [structure-in-c](https://aticleworld.com/structure-in-c/)
  * 1.1 구조체 정의, 초기화, 잘못된 사용 예제
  ```c
  // structure는 메모리 할당을 변수 전체를 구분해서 순서대로 할당 함
  // Defining structure in C
  struct MyData {
    int Age;
    float fees;
    char name[4];
  } data;

  struct MyData {
    int a;
    struct MyData b;  // illegal example
  } data;

  struct MyData {
    int a;
    struct MyData *b;  // valid example
  } data;

  struct MyData {
    int a;
    int b[];  // valid in C99 and C11
  };

  struct MyData {
    int b[];  // illegal example
  };
  ```
  ([struct initialize code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Struct_Initialize1.c))
  ```c
  // illegal example
  // struct type 선언은 템플릿이고, 선언하지 않으면 구조체 저장 메모리가 없음
  struct Mydata {
    int a=0;    // illegal
    int b=0;    // illegal
  }
  // 초기화 방법1
  struct Mydata InfoData = { 2, 3};

  struct { int a[3];
           int b;
         } w = {{1, 2, 3}, 4};

  // 초기화 방법2
  struct Mydata InfoData;
  InfoData.a = 2;
  InfoData.b = 3;

  // 초기화 방법3 in C99, C11
  struct Mydata InfoData = {.a=2, .b=3}; or struct Mydata InfoData = { .b=3, .a=2};
  struct Mydata InfoData = { 2, 3};
  ```
  ([typedef 사용법 참조](https://github.com/csbyun-data/C-Pro/blob/main/chap01/TypeDef/README.md))
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
   ([Struct Pointer](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Structure_pointer1.c))
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

  // Error수정
  malloc의 변환 void * -> (struct Laptop *) 정적 형변환
  ```
  ![image](https://github.com/user-attachments/assets/088ea95a-2c9b-4d48-a5ac-94168cc9244d)
  
  * 1.2 구조체 크기 계산 ([code1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Structure_size1.c), [code2](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Structure_size2.c), [code3](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Structure_size3.c) )
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
  ([익명 구조체1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Anonymous_struct1.c), [익명 구조체2](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Anonymous_struct2.c) )
  ```c
  // 구조체의 중요 형태와 활용, 익명의 구조체 C11사용
  struct { // anonymous struct
    short int b;
  };

  union { // anonymous union
    short int b;
  };
  ```
  
  * 1.3 구조체 hack ([hack1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Structure_hack1.c), [hack2](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Structure_hack2.c))
  * Reference [structure-hack-in-c](https://aticleworld.com/struct-hack-in-c/)

  ```c
  // C99에 flexible array가 도입되기전 활용한 기법
  typedef struct {
    int RollNumber;
    int TotalMarks;
    char Name[0];  // 0 byte
  } sStudentInfo;
  
  ﻿// 포인터를 사용하여 동적 길이 배열을 만들 수도 있지만 문제는 포인터에 추가
  // (시스템에 따라 4바이트 또는 8바이트) 메모리가 필요하다는 것.
  // 구조에 포인터를 만들면 포인터에 메모리를 명시적으로 할당해야 하지만 구조 해킹을
  // 사용한 경우 어레이에 메모리를 다시 할당할 필요가 없습니다.
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
  ```txt
  // Error 수정, malloc의 반환 void * -> (struct EmpInformation *) 정적 형변환
  // Allocating memory as per the requirements
  psEmpInformation psEmpInfo = malloc( sizeof(*psEmpInfo)+sizeof(char)*strlen(pcAddress)+1);
     --->
  psEmpInformation psEmpInfo = (struct EmpInformation *)malloc( sizeof(*psEmpInfo)+sizeof(char)*strlen(pcAddress)+1);
  ```
  ![image](https://github.com/user-attachments/assets/9362ff04-dfcd-40ab-bda1-2352438e512b)
  
  * 1.4 구조체 내부 배열사용 (flexible array in C)
  * Reference [flexible-array-member](https://aticleworld.com/flexible-array-member/)
  ```c
  #include <stdio.h>

  struct Score {
    char name[20];
    int kor;
    int mat;
    int eng;
  } S;

  int main()
  {
    struct Score s[2] = {0};

    for(int i = 0; i < 2; i++) {
      scanf("%s", s[i].name);
      scanf("%d", &s[i].kor);
      scanf("%d", &s[i].mat);
      scanf("%d", &s[i].eng);
    }
    return 0;
  }
  ```
  ```c
  //Example of a flexible array member, 유연한 배열
  struct s {
    int n;
    double d[];
  };
  int m = /* some value */;
  struct s *p = malloc(sizeof (struct s) + sizeof (double [m]));
     ---->
  struct {
    int n;
    double d[m];
  } *p;
  // 유연한 배열을 사용하는 이유
  // 정해진 주소의 배열 크기를 넘어서는 문자값을 입력할 경우 Error발생 해결
  ```
  ([고정된 배열 사용1 Error](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Unflexible_array1.c), [유연한 배열 사용1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Flexible_array1.c) )
  
  
  * 1.5 struct와 function pointer결합하여 객체지향 구현
  ```c
  typedef struct {
    int (*OpenSocket)(void);
    int (*CloseSocket)(int);
    int (*ReadFromServer)( int, char *, short);
    int (*WriteToServer)( int, char *, short);
  } sCommStruc;
  ```
  ```c
  // the general-purpose communication library 연결
  sCommStruct *CreateTcpComm (void) {
    sCommStruct *psComTcpIp = malloc(sizeof( sCommStruct));
    if ( pComTcpIp != NULL) {
      psComTcpIp->OpenSocket = &TcpSocketCreate;
      psComTcpIp->CloseSocket = &TcpSocketClose;
      psComTcpIp->ReadSocket = &TcpSocketReceive;
      psComTcpIp->WriteSocket = &TcpSocketSend;
    }
    return psComTcpIp;
  }
  ```
  ```c
  int CommunicationWithTcp(char *Rqst, short lenRqst, char *Rsp,short RvcSize) {
    int  hSocket = -1;
    short shortRetval = -1;
  
    //Call Create TcpComm function for tcp/Ip communication
    sCommStructure *psTcpcomm = CreateTcpComm ();
  
    //Create Socket
    hSocket = psTcpcomm->OpenSocket();
    if(hSocket < 0) {
        printf("Socket Creation Failed: SOCKET_HANDLER = %d", hSocket);
        return SOCKET_FAILED;
    } else {
        printf("Socket Creation Success: SOCKET_HANDLER = %d", hSocket);
    }
  
    //Send data
    shortRetval = psTcpcomm->WriteToServer(hSocket, Rqst, lenRqst);
    ...
    shortRetval = psTcpcomm->ReadFromServer(hSocket, Rsp, RvcSize);
    ...
    psTcpcomm->CloseSocket(hSocket);
    return 0;
  }
  ```
  * 1.6 구조체 pointer 맴버
  * 1.7 구조체 내부 pointer 접근
  * 1.8 구조체 padding [code1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Structure_padding1.c), [code2](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Structure_padding2.c), [code3](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Structure_padding3.c), [code4](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Structure_padding4.c)
  * Reference [data-alignment-and-structure-padding-bytes](https://aticleworld.com/data-alignment-and-structure-padding-bytes/)
  ```txt
  구조체 메모리 할당시 크기의 차이를 점검
  ```
  * 1.9 구조체내 배열을 값으로 전달, func(call by value) [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Structure_InArray_Transfer.c)
  * 1.10 구조체를 배열의 파라메터로 전달 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Structure_Paramenter1.c)
  * 구조체 대신 vector를 이용한 C++ code [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/vector_numbers1.cpp)
  ```c
  int compare_a(const void *a, const void *b) {
      Pizza first = *(Pizza *)a;
      Pizza second = *(Pizza *)b;
      //...
  }

  int len = size_len;
  Pizza* pizzas = (Pizza *)malloc(sizeof(Pizza) * len);

  for(int i = 0; i < len; i++) {
     pizzas[i].size = size[i];
     pizzas[i].price = price[i];
  }
  qsort(pizzas, len, sizeof(Pizza), compare_a);
  //...
   ```
