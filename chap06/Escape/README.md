### Escape Game
* Escape
  * [main.c](https://github.com/csbyun-data/C-Pro/blob/main/chap06/Escape/main.c)
  * [main.h](https://github.com/csbyun-data/C-Pro/blob/main/chap06/Escape/main.h)
  * [game.c](https://github.com/csbyun-data/C-Pro/blob/main/chap06/Escape/game.c)
  * [game.h](https://github.com/csbyun-data/C-Pro/blob/main/chap06/Escape/game.h)
  ```c
  #ifndef KEY_CODE
  #define KEY_CODE
  
  // 키보드 값  
  #define UP 0
  #define DOWN 1
  #define LEFT 2
  #define RIGHT 3
  #define SUBMIT 4 // 선택(스페이스바)  
  
  #endif
  
  void gLoop(int);
  void move(int*, int*, int, int, int*, int*); // x, y, _x, _y, key, playing
  int keyControl();
  void titleDraw();
  int menuDraw(); 
  int maplistDraw();
  void infoDraw();
  void drawMap(int*, int*);
  void drawUI(int*, int*, int*);
  ```
  ```
  // Start Window Draw
  void titleDraw();
  int menuDraw();
  ```
  ![image](https://github.com/user-attachments/assets/51cf080a-02a4-45b4-b711-72297a4a0432)
  ```
  int maplistDraw();
  ```
  ![image](https://github.com/user-attachments/assets/f931a220-7ba6-4025-92c9-944df038630a)
  ```
  void infoDraw();
  ```
  ![image](https://github.com/user-attachments/assets/28f7ea96-802b-4250-a811-7ea9bd55ebe8)
* Move Key : <span style='background-color:$f6f8fa'> w, a, s, d </span>
  ```
  int keyControl(){
    char temp = getch();
    
    if(temp == 'w' || temp == 'W'){
      return UP;
    } else if(temp == 'a' || temp == 'A'){
      return LEFT;
    } else if(temp == 's' || temp == 'S'){
      return DOWN;
    } else if(temp == 'd' || temp == 'D'){
      return RIGHT;
    } else if(temp == ' '){ // 스페이스바(공백)이 선택 버튼  
      return SUBMIT;
    }
  }
  ```


  * [util.c](https://github.com/csbyun-data/C-Pro/blob/main/chap06/Escape/util.c)  
  ```c
  void init(){
    system("mode con cols=56 lines=20 | title 게임제목"); 
    
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0; // false 또는 0 : 숨기기 
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle , &ConsoleCursor);
  }
  
  // 커서 위치 이동함수  
  void gotoxy(int x, int y){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
  } 
  
  // 첫번째: 텍스트, 두번째: 배경  
  void setColor(int forground, int background){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    int code = forground + background * 16; 
    SetConsoleTextAttribute(consoleHandle, code);
  }
  ```
  * [util.h](https://github.com/csbyun-data/C-Pro/blob/main/chap06/Escape/util.h)  
  ![image](https://github.com/user-attachments/assets/fa3a24e4-ed4f-4ca1-b0de-88e39a22d02f)
