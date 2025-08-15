
### Tetris Game
* Tetris
    * [Tetris.c](https://github.com/csbyun-data/C-Pro/blob/main/chap06/Tetris/tetris.c)
   ```
   #include <Windows.h>
   #include <conio.h>   
   //get keyboard input.
   int getKeyDown(){
     if(kbhit()) return getch();
     else return -1;
   }
   
   //move cursor.
   void gotoxy(int x, int y){
     COORD P;
     P.X = 2*x;
     P.Y = y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), P);
   }

   //hide cursor
   void hidecursor() {
     HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_CURSOR_INFO info;
     info.dwSize = 100;
     info.bVisible = FALSE;
     SetConsoleCursorInfo(consoleHandle, &info);
   }

   //출력화면 TEXT 속성변경
   void function() {
     HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hand, 11);
     //...
   }
   ```
<img width="401" height="382" alt="image" src="https://github.com/user-attachments/assets/3c46bb16-5a16-45f2-bdbc-62b24c7af1c4" />

    * [참조: [Tetris](https://github.com/BlockDMask/Tetris_Game)]
