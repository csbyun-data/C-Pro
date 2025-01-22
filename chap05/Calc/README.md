### Calculation formula analysis
* 계산기 프로그램1 [code](https://github.com/csbyun-data/C-Pro/edit/main/chap05/Calc/Calculation_formula.c)
    ```txt
  1) ChatGPT code, 중위식을 후위식으로 변환,
  2) Stack 구조체를 이용 후위식을 계산, 우선순위, 소수점 처리
  3) 삼각함수 (SIN, COS, TAN), 계산식
       SIN(30)+COS(45) 후위계산식 변경 -> SIN 30 COS 45 +
  ```
  ![image](https://github.com/user-attachments/assets/9532fcba-3fba-4496-b2d4-09dc5f58ace0)

* 함수 포인터를 배열에 넣어 가감 계산 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/Calc/Calculation_formula3.c)
  ```c
  int (*fptr[3])(int, int) = {plus, minus, multiply};
  ```  
* 함수 포인터를 구조체에 넣어 가감 계산 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/Calc/Calculation_formula4.c)
  ```c
  typedef struct Calculator {
    int (*plus)(int, int);
    int (*minus)(int, int);
  } Calculator;

  int plus(int a, int b) { return a + b; }
  int minus(int a, int b) { return a - b; }
  //...
  struct Calculator c;
  c.plus = plus;
  c.minus = minus;

  answer[0] = c.plus(a, b);
  answer[1] = c.minus(a, b);
  ```
    
* 계산기 프로그램2 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/Calc/Calculation_Function_pointer.c)  
  ```txt
  1) ChatGPT code, 중위표기법 계산
  2) Stack 배열을 이용 중위식을 계산, 우선순위, 소수점 처리
  3) 사칙 연산자, 이항 연산자 배열과 Function pointer 매칭
  4) 단항 연산자 배열과 Function pointer 매칭, 삼각, 지수 연산 (SIN, COS, TAN, EXP 함수)
  5) Command Line 반복 계산식 처리, #include <setjmp.h> // setjmp(), longjmp() 사용
  ```
  ![image](https://github.com/user-attachments/assets/fef2af64-b83d-457f-bb4e-80d787b0aeb0)

* 사칙연산 함수를 STL을 이용하여 표현 [C++ [code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/Calc/STL_Calculator1.cpp)]
* 재귀호출 계산기 [C [code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/Calc/desktop_calc.c)], [C++ [code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/Calc/desktop_calc.cc)]
  ```txt
  1) 전위, 후위 연산자 ++a, --a, a++, a--
  2) 변수 값 입력 a=1 , b=2
  3) 변수 이항연산 계산 a+b
  ```
  
