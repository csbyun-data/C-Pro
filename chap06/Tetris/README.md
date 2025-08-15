
### Tetris Game
* Tetris
    * [Tetris.c](https://github.com/csbyun-data/C-Pro/blob/main/chap06/Sokoban/sokoban.c)
    * [game.h](https://github.com/csbyun-data/C-Pro/blob/main/chap06/Sokoban/game.h)
    ```
    // default console screen size
    #define SCREEN_WIDTH 120
    #define SCREEN_HEIGHT 25
    #define SCREEN_SIZE SCREEN_WIDTH * SCREEN_HEIGHT
    // DOS창의 default width size 120을 설정
    ```
    ```
    // screen buffer that replaces stdout
    char screen[SCREEN_SIZE];
   
    // init windows headers
    #include <windows.h>
    #include <stdlib.h>
    HANDLE console;
    CONSOLE_CURSOR_INFO cursor;
    COORD coord;
    DWORD chars_to_write = 0;
   
    void InitScreen() {
      // print directly to screen buffer
      console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);    
      cursor.dwSize = 100;
      cursor.bVisible = FALSE;    
      coord.X = 0;
      coord.Y = 0;
      SetConsoleActiveScreenBuffer(console);
      SetConsoleCursorInfo(console, &cursor);
    }
   
    void RefreshScreen() {
      // might not be needed on windows natively, needed on wine though
      for(int scr_cell = 0; scr_cell < SCREEN_SIZE; scr_cell++)
        if(!screen[scr_cell]) screen[scr_cell] = ' ';
     
      // update screen buffer
      screen[SCREEN_SIZE - 1] = 0;
      WriteConsoleOutputCharacter(console, screen, SCREEN_WIDTH * SCREEN_HEIGHT, coord, &chars_to_write);
    }
   
    void PrintMap(int pos_x, int pos_y, int map_width, int map_height, char *map) {
      for (int row = 0; row < map_height; row++) {
        for (int col = 0; col < map_width; col++) {
          screen[(row + pos_y) * SCREEN_WIDTH + col + pos_x] = map[row * map_width + col];
        }
      }
      RefreshScreen();    
    }        
   
    // getchar() for windows without echoing
    int getch() {
      DWORD mode, chars_to_read;
      HANDLE console = GetStdHandle(STD_INPUT_HANDLE);
         
      GetConsoleMode(console, &mode);
      SetConsoleMode(console, mode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT));
      int key = 0;
      ReadConsole(console, &key, 1, &chars_to_read, NULL);
      SetConsoleMode(console, mode);
     
      return key;
   }
   
   void Leave() {
     cursor.bVisible = TRUE;
     SetConsoleCursorInfo(console, &cursor);
   }
   ```
    ![image](https://github.com/user-attachments/assets/2a3a2b7d-38c7-480d-8542-fa9b74871d47)

    * [참조: [sokoban](https://github.com/maksimKorzh/sokoban)]
