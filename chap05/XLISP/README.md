
### XLISP Calculation formula analysis
* XLISP code분석
  * text file load or stdin line load [code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XLISP/File/file_load.c), [load.txt](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XLISP/File/load.txt)
  * load.txt content ( > main.exe load.txt 실행)
  ```txt
  1 line
  2 line
  3 line
  ````  
  ![image](https://github.com/user-attachments/assets/9388d55c-56c4-4812-812f-c102abd5bb15)
  * prompt에서 파일을 읽어 들이은 기능 추가 ( >@test.xml) [code]()
  ```c
  function loadFile() 추가
  ```
  ![image](https://github.com/user-attachments/assets/097e5709-c9af-4974-87be-9e80f82dab8b)

  
* XLISP Calculation formula
  * 사칙연산 계산 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XLISP/Calc1.c)  
  ![image](https://github.com/user-attachments/assets/554028d6-3597-438a-9409-717c473792f6)

  * LISP 형식 계산식(+ 2 35 4)을 torken분석 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XLISP/tokenize1.c)

     
