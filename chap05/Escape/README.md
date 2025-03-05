### Escape Game
* Escape
  * [main.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/Escape/main.c)
  * [main.h](https://github.com/csbyun-data/C-Pro/blob/main/chap05/Escape/main.h)
  * [game.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/Escape/game.c)
  * [game.h](https://github.com/csbyun-data/C-Pro/blob/main/chap05/Escape/game.h)
  * [util.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/Escape/util.c)  
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
  * [util.h](https://github.com/csbyun-data/C-Pro/blob/main/chap05/Escape/util.h)  
  ![image](https://github.com/user-attachments/assets/fa3a24e4-ed4f-4ca1-b0de-88e39a22d02f)
