## 01. Structure and Unions in C
### Index
[참조: aticleworld.com/structure-in-c/](https://aticleworld.com/structure-in-c/)

* 1.구조체 (struct)
  * 1.1 구조체 정의, 초기화, 잘못된 사용 예제
  ```c
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
  ([struct 초기화 Example1](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Structures_and_Union/Struct_Initialize1.c))
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

  // 초기화 방법3 in C99, C11
  struct Mydata InfoData = {.a=2, .b=3}; or struct Mydata InfoData = { .b=3, .a=2};
  struct Mydata InfoData = { 2, 3};
  ```
  ([typedef 사용법 참조](https://github.com/csbyun-data/C-Programming/blob/main/chap01/TypeDef/README.md))
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

  // Error수정
  malloc의 변환 void * -> (struct Laptop *) 정적 형변환
  ```
  ![image](https://github.com/user-attachments/assets/088ea95a-2c9b-4d48-a5ac-94168cc9244d)
  
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
  
  * 1.3 구조체 hack ([참조: aticleworld.com/structure-hack-in-c/](https://aticleworld.com/struct-hack-in-c/)), ([hack1](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Structures_and_Union/Structure_hack1.c), [hack2](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Structures_and_Union/Structure_hack2.c))

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
  * ([참조: aticleworld.com/flexible-array-member/](https://aticleworld.com/flexible-array-member/))
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
  ([고정된 배열 사용1 Error](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Structures_and_Union/Unflexible_array1.c), [유연한 배열 사용1](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Structures_and_Union/Flexible_array1.c) )
  
  
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

* 2.공용체 (union)
  * 2.1 공용체 선언, 초기화, 접근
  ```c
  // declaration of union
  union MyData { // Declare a simple union type
    int age;
    float fees;
    char name[4];
  } data, *pData;

  // Using the union keyword and its tag
  #include <stdio.h>
  union MyData {
    int age;
    float fees;
    char name[4];
  };

  union MyData data, *pData;
  ```
  ```c
  //Declaration of C union
  union s {
    int i;
    const int ci;
  };

  //object unqualified
  union s s;
  //object qualified with const
  const union s cs;
  //object qualified with volatile
  volatile union s vs;

  s.i   ->   int
  s.ci  ->   const int
  cs.i  ->   const int
  cs.ci ->   const int
  vs.i  ->   volatile int
  vs.ci ->   volatile const int
  ```
  ([익명Ex1](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Structures_and_Union/Anonymous_union1.c), [익명Ex2](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Structures_and_Union/Anonymous_union2.c) )
  ```c
  // 익명의 union 사용
  ```
  ([Ex1](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Structures_and_Union/Union_ex1.c) )
  ```c
  // Accessing union members
  union Laptop {
    float price;
    int productId;
    char name[24];
  } Laptop1, *Laptop2;

  // Using the laptop1 (union object)
  laptop1.price
  laptop1.productId
  laptop1.name

  // Using the pLaptop2 (pointer to a union)
  pLaptop2->price
  pLaptop2->productId
  pLaptop2->name
  ```
    * 2.2 공용체 초기화 [Ex1](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Structures_and_Union/Union_Initialize1.c) 
  ```c
  union Test obj2 = { .c="Aml" }; <- { .c={Aml"} };
  ```
  ![image](https://github.com/user-attachments/assets/40eb6f2b-1bcf-4e04-b74f-96b6a3a5f269)

  ```c
  #include <stdio.h>

  union Test {
    unsigned char c;
    int x;
  };
  int main()
  {
    union Test obj = {400};
    printf("%d\n", obj.x);

    return 0;
  }
  // output:
  // 144  <-- 400 결과값 X , Logical error
  ```
  ![image](https://github.com/user-attachments/assets/3e2f131c-d4ec-415a-affe-fcf6b380cf2a)
  ```c
  //output would be unspecified, 초기화되지 않은 b에 출력값이 특정되지 않음
  #include <stdio.h>

  union Test {
    char a;
    int b;
  };

  int main( )
  {
    union Test testData;
    testData.a = 'A';
    printf( "testData.a = %c\n", testData.a);    
    printf( "testData.b = %d\n", testData.b);
    
    return 0;
  }
  // output:
  // testData.a = A
  // testData.b = 65 <- 초기화되지 않은 변수에 값이 있음
  ```
  ```c
  // 공용체 필드 초기화 작업
  #include <stdio.h>

  union Data {
    int a;
  };

  int main() {
    //designated initialization of union
    union Data myData = { .a = 4 };
    printf("myData.a= %d\n",myData.a);

    return 0;
  }
  
  // output:
  // myData.a= 4
  ``` 

    * 2.3 공용체 size 계산 [Ex1](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Structures_and_Union/Union_size1.c), [Ex2](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Structures_and_Union/Union_size2.c)

    * 2.4 공용체 활용 [Ex1](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Structures_and_Union/Union_ex2.c)
     ![image](https://github.com/user-attachments/assets/f13e396e-4275-4487-8cd4-ff25a9ce3f3b)
   ```c
    // 컴파일 Error 수정 작업
    //structure variable to store data
    InfoData sInfoData = {0};    <-- InfoData sInfoData = {(eInfoTypes)0};
   
    //structure variable to store read data
    InfoData sReadInfoData = {0}; <-- InfoData sReadInfoData = {(eInfoTypes)0};
   ```
   
* 3.Bit field [참조: aticleworld.com/bit-field-in-c/](https://aticleworld.com/bit-field-in-c/)
  * 3.1 선언, 초기화
  ```c
  //bit field 정의, 초기화 방법
  struct packed_data {
    unsigned int data1:1;
    unsigned int data2:1;
    unsigned int data3:1;
    unsigned int data4:1;
    unsigned int data5:1;
    unsigned int data6:3;
    unsigned int data7:6;
  } sPackData;

  //Way to access the member of bit-field
  sPackData.data6 = 3;
  ```

  ```c
  //bit-field structure to mapping with the micro-controller port.
  typedef union {
    struct {
      uint8_t LED1 : 1;
      uint8_t LED2 : 1;
      uint8_t LED3 : 1;
      uint8_t LED4 : 1;
      uint8_t LED5 : 1;
      uint8_t LED6 : 1;
      uint8_t LED7 : 1;
      uint8_t LED8 : 1;
    };
    uint8_t AllLedState;
  } LED_BAR_STATE;
  
  //변수 선언방법
  volatile LED_BAR_STATE *pLedState = (volatile LED_BAR_STATE *)0xE002C000;
  pLedState->LED1 = 1;
  pLedState->LED2 = 0;
  ```
  ([BitField Ex1](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Structures_and_Union/BitField_ex1.c))
  ```c
  #include <stdio.h>
  #include<string.h>

  struct myData {
    union {  // anonymous union
      short int a;
      short int b;
    };
    short int c;
  };

  int main() {
    //Variable of structure
    struct myData sMydata;
    sMydata.a =10; //valid
    sMydata.b = 20;  //valid
    sMydata.c = 40;  //valid

    return 0;
  }
  ```
  ```c
  #include <stdio.h>
  struct myData {
    union {  // anonymous union
      struct {
        short int a;
      } data; //data is struct variable
      struct { //anonymous struct
        short int b;
      };
    };
    short int c;
  };

  int main() {
    struct myData sMydata; //structure variable
    sMydata.a = 5; //invalid X
    sMydata.data.a =10;
    sMydata.b = 20;
    sMydata.c = 40;

    return 0;
  }
  ```
  ![image](https://github.com/user-attachments/assets/0be5b1fe-cadb-4455-91e9-c9f4d6dae217)

  ```c
  // bit_field를 공용체에 사용
  // create a bit-field using the union.
  #include <stdio.h>

  union Data {
    unsigned int a: 4;
    unsigned int b: 4;
    int c;
  };

  int main() {
    union Data myData;
    myData.a = 5;
    myData.b = 5;
    myData.c = 4;
    printf("myData.a= %d, myData.b = %d, myData.c = %d\n\n",
           myData.a, myData.b, myData.c);

    return 0;
  }
  
  // output:
  // myData.a= 4, myData.b = 4, myData.c = 4  // a=5 ? , b=5 ?
  ```
  
  * 3.2 bit-field Error 예
  ```c
  //변수 a에 0(00), 1(01), 2(11) 만 입력가능한데 5(101)를 입력한 경우->1(01)로 됨
  #include <stdio.h>

  struct sData {
    unsigned int a: 2;
    unsigned int b: 2;
    unsigned int c: 2;
  };

  int main() {
    struct sData data;
    data.a = 5;
    printf("%d", data.a );

    return 0;
  }
  // output:
  // 1
  ```
  ![image](https://github.com/user-attachments/assets/0383c0e8-7db5-4fd1-84f4-3fd645f88f57)
  
  ```c
  // bit field에 대한 포인터를 만들수 없고 bit field member에 연산자 주소(&) 사용 불가
  // 컴파일 error 발생
  #include <stdio.h>

  struct sData {
    unsigned int a: 2;
    unsigned int b: 2;
    unsigned int c: 2;
  };

  int main() {
    struct sData data;
    data.a = 2;
    printf("Address of data.a =  %p", &data.a );

    return 0;
  }
  ```
  ![image](https://github.com/user-attachments/assets/f9101c5f-92a8-4734-9026-6473aaefc2ac)
  ```c
  //bit filed에 배열 정의가 불가함, 컴파일시 Error발생
  #include <stdio.h>

  struct sData {
    unsigned int a: 2;
    unsigned int b[5]: 2;
  };

  int main() {
    struct sData data;
    data.a = 2;

    return 0;
  }
  ```
  ![image](https://github.com/user-attachments/assets/8915f8b2-77fb-4059-9e56-434a2c34863e)
  ```c
  struct sData {
    unsigned int a: 2;
    short b: 17;            // Illegal!
    unsigned int c: 2;
  };
  ```
  ```c
  #include <stdio.h>

  // A structure without forced alignment
  typedef struct {
    unsigned int data1: 5;
    unsigned int data2: 8;
  } sData1;

  // A structure with forced alignment
  typedef struct {
    unsigned int data1: 5;
    unsigned int: 0;
    unsigned int  data2: 8;
  } sData2;

  int main() {
    printf("Size of sData1 = %d\n", sizeof(sData1));
    printf("Size of sData2 = %d\n", sizeof(sData2));

    return 0;
  }

  // output:
  // Size of sData1 = 4
  // Size of sData2 = 8
  ```
  
  ```c
  //변수 a에 0(00), 1(01), 2(11) 만 입력가능한데 5(101)를 입력한 경우->1(01)로 됨
  #include <stdio.h>

  struct sData {
    unsigned int a: 2;
    unsigned int b: 2;
    unsigned int c: 2;
  };

  int main() {
    struct sData data;
    data.a = 5;
    printf("%d", data.a );

    return 0;
  }
  // output:
  // 1
  ```
  ![image](https://github.com/user-attachments/assets/26c004bd-a792-44bd-bb7c-a2f310e88470)
  


  

  
  
 

