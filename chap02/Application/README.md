### Structure, Array Pointer 활용
* 구조체, 문자열 Pointer 활용
    * 구조체(이름, 점수), 문자열 Pointer 활용 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Application/Student_order1.c), [code c++](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Application/Student_order1.cpp)
    ```c
    typedef struct Student{
      char name[20];
      int score;
    } Student;
    ```
    * 구조체의 맴버 void형 포언터, 공용체와 결합한 구조체 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Application/structure_void_pointer.c)
    ```c
    typedef enum {INT, DOUBLE, STRING} ENUMTYPE;

    typedef struct _sData {
       ENUMTYPE type; // 1:정수, 2:실수, 3:문자열
       void *vp;
    } DATA, *PDATA;
    ```
    ![image](https://github.com/user-attachments/assets/52519cb1-4036-47a9-a241-f7686ce9a571)

    
