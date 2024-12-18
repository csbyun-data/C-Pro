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
    * 1.4 구조체 포인터 사용 예 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structure_and_Pointer/struct_rect1.c)
    ```txt
    직사각형의 왼쪽 아래 꼭지점의 좌표, 오른쪽 위꼭지점의 좌표 (x1, y1, x2, y2)   오른쪽 위 꼭지점의
    좌표를 x축 방향으로 plus_x만큼, y축 방향으로 plus_y만큼 이동했을 때 사각형의   넓이가 얼마나
    증가하는지 구하려 합니다.
   
      typedef struct Point2D {
        int x;
        int y;
      } Point2D;
      
      typedef struct Rectangle{
        Point2D* LeftDown;
        Point2D* RightUp;
      } Rectangle;

    1. 절차적  순서 
    1. 점과 직사각형을 나타내는 변수를 생성 및 초기화 합니다.
    2. 1단계에서 만든 직사각형의 넓이 first_width를 구합니다.
    3. 직사각형의 오른쪽 위 꼭지점의 좌표를 주어진 값(plus_x, plus_y) 만큼 이동합니다.
    4. 좌표를 이동한 후 직사각형의 넓이 second_width를 구합니다.
    5. 4단계에서 구한 직사각형의 넓이 second_width에서 2단계에서 구한 직사각형의 넓이 first_width를 
       뺀 값을 return 합니다.
    ```
    |x1|y1|x2|y2|plus_x|plus_y|return|
    |--|--|--|--|--|--|--|
    |1|2|5|5|2|1|14|
    ```txt
    첫 번째 사각형의 넓이는 4 x 4 = 16
    오른쪽 위 꼭지점의 좌표를 x축으로 2 만큼, y 축으로 1 만큼 이동 하면 오른쪽 위 꼭지점의 좌표는 (7, 6)
    따라서 두 번째 사각형의 넓이는 6 x 5 = 30 이 되며, 두 사각형의 넓이 차이 30 - 16 = 14를 return 하면 됩니다.
    ```
    
    
      

    
    
  
