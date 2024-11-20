## 01. 문법1
## https://aticleworld.com/typedef-in-c/
### Index
* 1.typedef 사용법, 범위
  *   1.1 struct에 typedef 사용
  ```c
  // struct선언
  struct sStudentInfo {
    char acName[30];
    int iTotalMarks;
  };

  struct sStudentInfo sInfo;
  ```
  ```c
  // typedef를 이용한 struct
  typedef struct sStudentInfo {
    char acName[30];
    int iTotalMarks;
  } sStudentInfo;

  sStudentInfo sInfo;
  ```
  ```c
  // struct tag를 제거한 typedef, 위의 예와 동일하게 사용이 가능
  typedef struct {
    char acName[30];
    int iTotalMarks;
  } sStudentInfo;
  
  sStudentInfo sInfo;  
  ```
  ```c
  // 위의 예제에서 아래 code처럼 사용할때는 Error발생
  typedef struct {
    char acName[30];
    int iTotalMarks;
    struct sStudInfo *psList;  // <- Error 
  } sStudInfo;

  // 해결 방법
  typedef struct sStudentInfo {
    char acName[30];
    int iTotalMarks;
    struct sStudentInfo *psList;  // <- fine
  } sStudInfo;

  // 동일 해결 방법
  typedef struct sStudentInfo sStudInfo;
  
  struct sStudentInfo {
    char acName[30];
    int iTotalMarks;
    struct sStudInfo *psList;  // find
  };

  // 동일 해결 방법
  typedef struct sStudentInfo {
    char acName[30];
    int iTotalMarks;
    struct sStudentInfo *psList;
  } sStudInfo, *psStudInfo;

  psStudInfo Ram;
  sStudInfo Shyam;
  ```    
  
  *   1.2 typedef를 사용한 범위 점검
  ```c
  // typedef의 범위 점검
  #include <stdio.h>
  
  typedef int TYPE;

  int add(void) {
    TYPE a=0, b=0;

    printf("Enter two num: \n\n");
    scanf("%d %d", &a, &b);
    return (a+b);
  }

  int main() {
    typedef char * TYPE;
    TYPE pcMsg = "Hello World!";
    printf("\n\nDisplay Message = %s\n\n", pcMsg);

    int n = add();
    printf("addition of two number = %d\n\n", n);
  }
  ```
  ```c
  // 같은 범위 안에서 동일명의 TYPE을 선언하면 error발생
  {
    typedef char * TYPE;
    typedef int TYPE;  // error
  }
  // [Error] conflicting types for 'TYPE'
  ```
  
  *   1.3 typedef pointer형 변수
  ```c
  // use of typedef with pointers
  #include <stdio.h>

  typedef int * intPtr;
  typedef char * charPtr;

  int main()
  {
    int data = 27;
    intPtr iPtr = NULL;
    iPtr = &data;

    charPtr cPtr = "Hello World!";

    printf("%u\n", *iPtr);
    printf("%s\n", cPtr);

    return 0;
  }
  ```
  
  *   1.4 typedef 배열
  ```c
  #include <stdio.h>
  typedef int Brick_Price[3];

  void InitBrickPrice ( Brick_Price *paPrice) {
    (*paPrice)[0] = 10;
    (*paPrice)[1] = 20;
    (*paPrice([2] = 30;
  }

  int main() {
    int i=0;
    Brick_Price price;

    InitBrickPrice(&price);
    while (i<3)
      printf("Brick Price[%d] : %d\n\n", i, price[i++]);
  
    return 0;
  }
  ```
  
  *   1.5 typedef function pointer 사용
  ```c
  // typedef of array of function pointers
  typedef int (*apfArithmatics[3])( int, int);
  
  apfArithmatics aArithmaticOperation = { add, sub, mul };
  ```
  ```c
  void *pvHandle = NULL;
  int (*pf)(int) = (int (*)(int)) pvHandle;

  // typedef를 사용한 code 변경
  typedef int (*pf)(int);
  pf JumptoApp = (pf)pvHandle;
  ```
  *   1.6 typedef enum 사용
  ```c
  #include <stdio.h>

  typedef enum {
    NoError = 0,
    ReadError,
    WriteError,
    FlashError,
    LogError
  } eErrorList;

  eErrorList flashState;

  int main () {
    flashState = NoError;
    while(1) {
      // code
    }
    return 0;
  }
  ``` 
