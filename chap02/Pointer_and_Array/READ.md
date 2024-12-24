## 01. 포인터와 배열, 문자열, 함수포인터, 포인터 구조체
### Index
* 1.포인터와 배열
  * 1.1 포인터 선언, 초기화
  ```c
  // 간접 참조 연산자(dereferencing indirection) *
  // 연산자 & , 변수의 주소를 구함
  // 연산자 * , 포인터가 가리키는 주소에 저장된 내용
  
  int *iPtr;
  a = *iPtr;
  *iPtr=a;

  char cData;
  char *pcData = NULL;
        pcData = &cData;
  ```
  ```c
  char *ps = "Hello, World!"; // RAM CODE영역에 저장, read only 속성
  char s[] = "Hello, World!"; // RAM DATA영역에 저장, read/write 속성

  char *s = NUUL;
  s = "Hello, World!"; //OK
  char s[15];
  s = "Hello, World!"; // Error, s == s[0]를 가르키는 변수
  ```
  * 1.1.1 Variable Pointer, NULL 포인터
  ```c
  // pointer 선언시 주의사항, NULL선언
  #include <stdio.h>
  int main()
  {
    int a, b;
    a = 2;
    int* pa, pb;  // int *pa, int pb를 선언한 표현, -> int* pa, *pb; 표현해야됨
    pa = &a;
    pb = &a;      // Compile Error

    *pa = 27;
    int tmp = *pa;  //동일 표현 int tmp = *&a;
    printf("%d, %d\n", *pa, *&a);

    return 0;
  }
  ```
  ```c
  int i=10;
  int *p;  // 포인터를 선언할때는 int *p = NULL; , stdio.h의 #define NULL 0
  p=&i;
  ```
  ```c
  // NULL의 선언, 사용 방법
  #define NULL (char*)0

  // 포인터 변수의 초기화
  char* ptr = NULL;

  // 포인터 변수의 값을 확인
  if(ptr == NULL) {} else if {}
  if(ptr != NULL) // if(!ptr) 동일 표현식

  // 메모리 할당 실패 점검
  int* ptr = (int*)malloc(5*sizeof(int));

  if(ptr == NULL) {
    // memory allocation 실패
  }

  if(fopen("data.dat", "r") == NULL} {
    // file open 실패
  }
  ```
  ![image](https://github.com/user-attachments/assets/82c9e6ea-c0da-4474-b2b5-61f095ce3d46)

  * 1.1.2 ASCII code 및 cast 연산자 표현 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Array/Pointer_Cast.c)
  ```c
  //ASCii code 및 cast 연산자 표현
  #include <stdio.h>

  int main()
  {
  	int n = 0x30313233;

  	printf("%x %c \n", *(char*)&n, *(char*)&n);
  	printf("%x %c \n", *((char*)&n+1), *((char*)&n+1));
  	printf("%x %c \n", *((char*)&n+2), *((char*)&n+2));
  	printf("%x %c \n", *((char*)&n+3), *((char*)&n+3));

   return 0;
  }
  ```
  ![image](https://github.com/user-attachments/assets/99bc6573-fe27-4104-b4ad-2339e9233198)


  * 1.2 포인터의 잘못된 사용 조건 및 예 [exam1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Array/Invalid_pointer_value1.c) [exam4](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Array/Invalid_pointer_value4.c)
  ```txt
  1) 변수의 수명이 완료된 개체의 주소를 참조 (포인터 반환)
     int *add(int x, int y) {
       int result;
       result = x+y;
       return &result;
     }
       
  2) NULL 포인터인 방향지시 연산자(*)의 포인터 역참조
  3) 실행 프로그램에서 사용되지 않는 주소를 지정하는 방향지시 연산자(*)의 포인터를 역참조
  4) long 포인터 형태로 정렬되지 않은 메모리를 참조함
  ```

  *  1.3 Address 연산자(&) [exam1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Array/Pointer_exam1.c)
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

  * 1.5 void포인터 (void *) [here](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Array/Void_pointer1.c)
  ```c
  void func (void *ptr1, void *ptr2) { }

  char c1 = 'a', c2 = 'b';
  int num1 = 10, num2 = 20;

  func(&c1, &c2);
  func(&num1, &num2);
  ```
  *  ![image](https://github.com/user-attachments/assets/2df0edbc-d358-4dca-bd7b-72b503d5279d)
 
* 2.포인터 유형
  ```txt
  1) NULL pointer
    int *iPtr = NULL;
  ```
  * 2.1 void pointer [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Array/void_ptr1.c)
  ```txt
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
  * 2.1.3 void pointer를 사용하는 이유? [exam3](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Array/Void_pointer_exam3.c)
  ```txt
  모든 object의 주소를 저장할 수 있고 적절한 casting으로 긴접 연산자로 사용
  ```
  * 2.1.4 void pointer 산술 연산 [exam4](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Array/Void_pointer_exam4.c)
  * 2.1.5 void pointer 함수에 사용 [exam5](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Array/Void_pointer_exam5.c)
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
  * 2.1.7 void pointer 장점 [exam7](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Array/Void_pointer_exam7.c) [exam8](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Array/Void_pointer_exam8.c)
  * 2.2 wild pointer
   ```c
   int *ptr; //pointer value를 초기화 하지 않음
   ```
  * 2.3 dangling pointer
  ```txt
  참조된 개체가 삭제되거나 할당이 해제된 메모리를 가리키는 ponter
  ```

* 3.pointer 산술작업
  * 3.1 pointer 산술
  ```c
  char *pcData = NULL;
  float *pfData = NULL;

  pcData++;  // pcData 1 , character pointer 증가
  pfData++;  // PfData 4 , float pointer 증가
  ```
  * 3.2 포인터 증가 프로그램
  * 3.3 structure의 size 계산 [exam3](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Array/Structure_size.c)
  * 3.4 pointer 요소간의 거리 계산 [exam4](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Array/Pointer_offset.c)
  * 3.5 pointer 요소간의 비교
  ```c
  //the same array or memory block -> legal
  char acBuffer[10] = “aticleworld”;
  char *pc1, *pc2;

  pc1 = &acBuffer[0]; // Address of first element
  pc2 = &acBuffer[2]; // Address of third element
  Now we can compare the pointers if required.
  if( pc1 > pc2) {}// Legal statement

  // 2 different memory block -> illegal
  char acBuffer1[10] = “aticle”;
  char acBuffer2[10] = “world”;
  char *pc1, *pc2;

  pc1 = acBuffer1;
  pc2 = acBuffer2;
  if( pc1 > pc2) {} // illegal statement
  ```
  * 3.6 간접 참조 연산자 증가/감소 operator 사용
  ```c
  v = *p++;     // p가 가리키는 위치의 값을 가져온 후 v에 대입, p가 가리키는 위치 증가 이동
  v = (*p)++;   // p가 가리키는 위치의 값을 가져온 후 v에 대입, p가 가리키는 위치의 값을 증가
  v = *++p;     // p가 가리키는 위치를 증가 후 증가된 위치의 값을 v에 대입
  v = ++*p;     // P가 가리키는 위치의 값을 가져온 후, 그 값을 증가하여 v에 대입
  ```
  ```c
  // indirection operator with pre-increment operator
  #include <stdio.h>
  int main(void)
  {
     int aiData[5] = {100,200,300,400,500};
     int *piData = aiData;
     ++*piData; //expression ++*p is equivalent to ++ (*p)
     printf("aiData[0] = %d, aiData[1] = %d, *piData = %d", aiData[0], aiData[1], *piData);
  
     return 0;
  }
  // oupput: aiData[0] = 101, aiData[1] = 200, *piData = 101
  ```
  ```c
  #include <stdio.h>
  int main(void)
  {
    int aiData[5] = {100,200,30,40,50};
    int *piData = aiData; //expression *++p is equivalent to *(++p)
    *++piData;
    printf("aiData[0] = %d, aiData[1] = %d, *piData = %d", aiData[0], aiData[1], *piData);

    return 0;
  }
  // ouput : aiData[0] = 100, aiData[1] = 200, *piData = 200
  ```
  ```c
  // indirection operator with post-increment operator
  #include <stdio.h>
  int main(void)
  {
    int aiData[5] = {100,200,30,40,50};
    int *piData = aiData;
    *piData++;  //expression *p++ will be equivalent to *(p++)
    printf("aiData[0] = %d, aiData[1] = %d, *piData = %d", aiData[0], aiData[1], *piData);
  
    return 0;
  }
  //ouput: aiData[0] = 100, aiData[1] = 200, *piData = 200
  ```
  * 3.7 간접 참조 연산자와 증감 연산자
  ```txt
  포인터 * 연산자는 단항연산자로서 괄호 다음으로 높은 우선 순위를 가진다.

  *p++; 위 문장은 p가 가리키는 위치에서 값을 가져온 후에 포인터 p를 증가한다.
   ++의 우선 순위가 *보다 높지만 ++가 포인터의 뒤에 붙어 있으므로 *p를 먼저 수행한 후에 p에 대하여 ++가 수행된다.
  (*p)++; 만일 포인터가 가리키는 대상의 값을 증가하려고 했으면 위와 같이 하여야 한다.
  이 문장에서 괄호가 * 연산자를 먼저 수행하게 만든다. 뺄셈에 대해서도 마찬가지다.

  v = *p++ p가 가리키는 값을 v에 대입한 후에 ​p를 증가
  v = (*p)++ p가 가리키는 값을 v에 대입한 후에 ​p가 가리키는 값을 증가
  v = *++p p를 증가시킨 후에 p가 가리키는 값을 v에 대입
  v = ++(*p) p가 가리키는 값을 증가시킨 후에 p가 가리키는 값을 v에 대입

  후치는 대입을 먼저 하고 증가, 전치는 증가를 먼저 하고 대입을 한다.
  [출처] (C언어) '포인터' 개념 정리|작성자 써밋
  ```
* 4.pointer와 배열
  * 4.0 Array pointer(1차원 배열), 배열과 포인터
  ```c
  #include <stdio.h>
  void main()
  {
    char array[3] = {'A','B','C'}
    char* pa;
    pa = array;
  }
  ```
  ![image](https://github.com/user-attachments/assets/70496436-3348-424b-a22c-bd5645c46a2e)
  
  * 4.1 pointer와 문자 배열의 관계
  ```c
  #include <stdio.h>

  int main()
  {
    int i=0;
    char acBuffer[] = {'a','b','c','d','e'};

    for( i=0; i < sizeof(acBuffer); ++i)
      printf("&acBuffer[%d] = %p\n", i, &acBuffer[i]);

    printf("\nAddress of array acBuffer: %p\n\n", acBuffer);

    return 0;
  }
  ```

  ```txt
  &acBuffer[0] == acBuffer
  acBuffer[0] == *acBuffer

  *(acBuffer + i) == acBuffer[i];
  (acBuffer + i) == &acBuffer[i];

  char *pcBuffer = NULL;
  pcBuffer = acBuffer;  // character pointer point the address of first element
  ```
  * 4.2 pointer를 이용한 배열의 모든 요소 접근
  ```c
  #include <stdio.h>

  int main(int argc, char *argv[])
  {
    char acBuffer [] = {'a','b','c','d','e}; // array of character
    int i = 0;
    char *pcBuffer = NULL; // character pointer

    pcBuffer = acBuffer;

    for( i=0 ; i<5 ; i++) { // access the array element using the pointer
      printf("pcBuffer[%d] = %c or *(pcBuffer+%d) = %c \n\n",i,pcBuffer[i],i, *(pcBuffer+i));

    return 0;
  }
  ```
  ```c
  #include <stdio.h>
  #include <stdlib.h>

  int main(int argc, char *argv[])
  {
    char acBuffer[] = {'a','b','c','d','e'};
    acBuffer++;  // Error, lvalue required as increment operand

    printf("%d\n", *acBuffer);

    return 0;
  }
  ```
  * 4.3 pointer를 이용한 방법의 장점 (index표기법, 포인터 사용)
  ```c
  // index 표기법, 느림, index를 주소로 변한 후 값을 가져 옴
  int sum( int a[], int n) {  
    int i, sum=0;

    for ( i=0; i<n; i++)
      sum += a[i];

    return sum;
  }
  ```
  ```c
  // pointer 사용, 빠름
  int sum( int a[], int n) {  
    int i, sum=0;
    int *p;

    p = a;
    for ( i=0; i<n; i++)
      sum += *p++;

    return sum;
  }
  ```
  * 4.4 Array pointer(2차원 배열), 배열과 포인터
  ```c
  #include <stdio.h>
  void main()
  {
    int array[2][3] = {{0,1,2},{3,4,5}};
    int (*pa)[3]; //동일표현 int[3] *pa;
    pa = array;
  }
  ```
  ![image](https://github.com/user-attachments/assets/4c53d2f7-da1e-41bd-9c0a-4f24918785fd)

  * 4.5 포인터와 배열
  ```txt
  배열과 포인터는 아주 밀접한 관계를 가지고 있다.
  왜냐하면 배열 이름이 바로 포인터이기 때문이다.
  배열 이름은 배열이 시작되는 주소와 같다.

  int a[] = { 10, 20 };
  printf("%u",&a[0]); //출력값:1245008
  printf("%u",a); //출력값:1245008 &a[0]와 a의 값은 같음을 알 수 있다.

  printf("%u",&a[1]); //출력값:1245012 a가 int형 배열이므로 주소에서 +4된 값이 &a[1]이다.
  int a[] = { 10, 20, 30, 40, 50}; 이 있다고 가정했을 때

  배열의 요소들이 메모리에서 연속된 공간을 차지하게 된다.
  a  //배열의 이름을 포인터처럼 사용할 수 있다. 주소가 출력된다.
  a+1 a+1의 값은 a보다 4가 크며 a[1]의 주소와 같다.
  *a 배열의 이름이 가리키는 곳의 내용 *a를 출력하면 a[0]와 같다.
  *(a+1) *(a+1)은 a[1]과 같다.
  a+i
  &a[i]
  *(a+i)
  a[i] -> 배열의 이름은 '포인터 상수'여서 그 값(주소)을 변경할 수는 없다.
  ( 여기 저기 a+1해서 위치를 참조 할 수는 있어도
  ++a 해서 가리키는 곳을 바꿔버리면 명백한 오류이다.)
  [출처] (C언어) '포인터' 개념 정리|작성자 써밋
  ```
  * 4.6 포인터를 배열처럼 사용
   ```txt
   배열 이름이 포인터가 되고 역으로 포인터도 배열처럼 사용할 수 있다. 아래 예제를 참고
   
   #include <stdio.h>
   int main(void) {
     int a[] = {10, 20, 30, 40, 50 };
     int *p; // a 는 포인터 상수이므로 값을 변경할 수 없는데 반해 p는 포인터 변수이므로 값을 변경할 수 있다.
     p = a;  // p와 a는 똑같은 곳을 가리키게 된다.

     p[0] = 60; // 포인터를 마치 배열의 이름처럼 사용하여 배열 요소에 값을 대입한다.
     p[1] = 70;
     p[2] = 80;

     printf("%d %d %d\n",a[0],a[1],a[2]); //60 70 80이 출력된다.
     printf("%d %d %d\n",p[0],p[1],p[2]); //60 70 80이 출력된다.

     return 0;
   }
   [출처] (C언어) '포인터' 개념 정리|작성자 써밋
   ```
   * 4.7 배열 매개 변수
   ```txt
   int main(void) {
    int a[3]={1,2,3};
    sub(a, 3); // 배열의 이름은 포인터. a == &a[0]

   void sub(int b[], int size) {   // 동일 표현 sub(int *b, int size)
    //실제 b가 생성되지는 않는다. b는 배열을 가리키는 포인터로서 외부에서 전달된 배열의 주소가 전달된다.
    *b = 4; //포인터 b를 통하여 원본 배열을 변경할 수 있다.
    *(b+1) = 5;
    *(b+2) = 6;
   매개 변수로 배열을 선언할 때 포인터로 선언할 수도 있다.
   void sub(int b[], int size) {} 이든 void sub(int *b, int size) {} 이든 동일하다.
   [출처] (C언어) '포인터' 개념 정리|작성자 써밋
   ```
  
* 5.가변 배열과 Dynamic배열
  * 5.1 가변 배열 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Array/Jagged_Arrays.c)
  * 5.2 Dynamic 배열 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Array/Dynamic_Jagged_Array.c)
  
* 6.fucntion pointer
  * 6.1 function pointer 선언
  ```c
  void (*fpData)(void);
  int* (*fpData)(int , int (*paIndex)[3] , int (* fpMsg) (const char *));
  int* (*fpData[2])(int (* fpCalculation[3]) (const char *));
  int* (*(*fpData)(const char *))(int (*paIndex)[3] , int (* fpMsg) (const char *), int (* fpCalculation[3]) (const char *));
  ```
  ```c
  #include <stdio.h>

  void DisplayMessage(const char *msg) {
    printf("Message  =>>  %s\n", msg);
  }

  int main()
  {
    void ( *pfDisplayMessage) (const char *) = &DisplayMessage;
    (*pfDisplayMessage)("Hello world!");

    return 0;
  }
  ```
  * 6.2 function pointer이용 함수 호출
  ```c
  #include <stdio.h>
  #include <stdlib.h>

  int AddTwoNumber(int iData1,int iData2) {
    return (iData1 + iData2);
  }

  int main(int argc, char *argv[])
  {
    int iRetValue = 0;
    int (*pfAddTwoNumber)(int,int) = NULL;

    pfAddTwoNumber = AddTwoNumber;

    // iRetValue = pfAddTwoNumber(10, 20);
    iRetValue = (*pfAddTwoNumber)(10, 20);
    printf("\n\nAddition of two number = %d\n\n",iRetValue);

    return 0;
  }
  ```
  * 6.3 function pointer를 인수로 사용 [exam3](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Array/Function_pointer_Calc.c)
  ```c
  typedef  int (*pfunctPtr)(int, int); /* function pointer */

  int ArithMaticOperation(int iData1,int iData2, pfunctPtr Calculation) {
    int iRet =0;
    iRet = Calculation(iData1,iData2);

    return iRet;
  }
  // ...
  ```

  * 6.4 함수에서 function pointer 반환 [exam4](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Array/Function_pointer_Calc2.c)
  ```c
  typedef  int (*pfunctPtr)(int, int); /* function pointer */

  int Add(int iData1,int iData2) {
    return (iData1 + iData2);
  }
  //...
  //Return function pointer
  pfunctPtr ArithMaticOperation(int iChoice) {
    //function pointer
    pfunctPtr pArithmaticFunction = NULL;
    switch(iChoice) {
      case 1:
        pArithmaticFunction = AddTwoNumber;
        break;
      //...
    }


  * 6.5 function pointer배열 [exam5](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Array/Function_pointer_Calc3.c)
    
* 7.pointer와 structure
  * 7.1 Book 자료 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Array/Pointer_structure.c)

* 8.pointer를 사용하는 일반적인 실수
  * 8.1 pointer를 초기화하지 않음
  ```c
  // Error는 발생하지 않지만, logic error 발생
  int *piData;
  *piData = 10;    // assining value to the pointer

  printf("%d\n", piData);
  ```
  * 8.2 포인터의 비교
  ```c
  // pointer 비교는 동일 배열을 가르키는 경우만 가능
  char acBuffer1[10] = "Hello";
  char acBuffer2[10] = "Bye";
  char *pc1, *pc2;

  // assining the address of acBuffer1 to pc1 and acBuffer2 to the pc2.
  pc1 = acBuffer1;
  pc2 = acBuffer2;

  // compare the both the pointer
  if ( pc1 > pc2 ) { } // illegal statement
  ```
  8.3 dynamic memory 할당을 이용한 포인터 선언
  ```c
  char *pcBuffer = malloc(10); // valid statement

  char *pcBuffer;
    pcBuffer = malloc(10); // invalid statement
  ```
  * 8.4 유효하지 않은 address를 가리키는 pointer
  ```c
  // 메모리 할당이 해제된 주소에 포인터 값 입력
  #include <stdio.h>
  #include <stdlib.h>

  int main( int argc, char *argv[]) {
    int *piData = malloc(sizeof(int));
    free(piData);

    *piData = 10;
    printf("%d\n", *piData);
  }
  ```
  ```c
  // local 변수의 활용 해제된 변수의 주소를 반환
  #include <stdio.h>

  int *calc(int a, int b) {
    int iData;
    iData = a+b;
    return &iData;
  }

  int main( int argc, char *argv[])
  {
    int *piData = NULL;
    piData = calc( 4, 5);
    printf("%d\n", *piData);
  }
  ```
