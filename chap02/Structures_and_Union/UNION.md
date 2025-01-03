### Structure and Unions in C
* 공용체 (union)
  * 2.1 공용체 선언, 초기화, 접근
  ```c
  // union은 메모리를 공유하며 변수 중에 크기가 제일 큰 변수의 메모리를 할당하고,
  // 공유해서 한가지의 자료만 입력된다.
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
  ([익명Ex1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Anonymous_union1.c), [익명Ex2](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Anonymous_union2.c) )
  ```c
  // 익명의 union 사용
  ```
  ([Ex1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Union_ex1.c) )
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
    * 2.2 공용체 초기화 [Ex1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Union_Initialize1.c) 
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

    * 2.3 공용체 size 계산 [Ex1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Union_size1.c), [Ex2](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Union_size2.c)

    * 2.4 공용체 활용 [Ex1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Union_ex2.c)  
     ![image](https://github.com/user-attachments/assets/f13e396e-4275-4487-8cd4-ff25a9ce3f3b)
   ```c
    // 컴파일 Error 수정 작업
    //structure variable to store data
    InfoData sInfoData = {0};    <-- InfoData sInfoData = {(eInfoTypes)0};
   
    //structure variable to store read data
    InfoData sReadInfoData = {0}; <-- InfoData sReadInfoData = {(eInfoTypes)0};
   ```
   * 2.5 struct와 union 사용법 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/Union.c)
   ```c
   //xlisp-plus의 xlisp.h의 code 중에
   /* node structure */
   struct node {
     char n_type;		/* type of node */
     char n_flags;		/* flag bits */
     union {			/* value */
    	  struct xsym n_xsym;	/*     symbol node */
       struct xsubr n_xsubr;	/*     subr node */
       struct xlist n_xlist;	/*     list node */
       struct xint n_xint;	/*     integer node */
       struct xstr n_xstr;	/*     string node */
       struct xdbptr n_xdbptr;	/*     database pointer node */
       struct xkmap n_xkmap;	/*     key map node */
       struct xfun n_xfun;	/*     function node */
       struct xobj n_xobj;	/*     object node */
     } n_info;
   };
   - structure는 메모리 할당을 변수 전체를 구분해서 순서대로 할당 함
     { n_type, n_flags, n_info} 순으로 할당.
   - union은 메모리를 공유하며 변수 중에 크기가 제일 큰 변수의 메모리를 할당하고, 공유해서
     한가지의 자료만 입력된다.
   ```
   
* 3.Bit field
  * Reference [bit-field-in-c](https://aticleworld.com/bit-field-in-c/)
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
  ([BitField Ex1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/BitField_ex1.c))
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
