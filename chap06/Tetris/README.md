
### Tetris Game
* Tetris
    * [tetris.c](https://github.com/csbyun-data/C-Pro/blob/main/chap06/Tetris/tetris.c)
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
  
   ```
   //Modify code
   void rotate(MData map[MAP_SIZE_H][MAP_SIZE_W],int blockShape[4][4], Location * curLoc){
     int i, j;
     int tmp[4][4] = {0};  // <- tmp[4][4]; 배열이 초기화 되지 않아 rotation shape이 바르게 생성되지 않아 수정함
     int leftW, rightW, bottomH;
   
     for(i=0; i<4;i++){
       for(j=0; j<4;j++){
         if(blockShape[i][j] == BLOCK){
           tmp[3-j][i] = blockShape[i][j]; // <- tmp[j][3-i] = blockShape[i][j]; 회전을 시계 반시계 방향으로 변경
           blockShape[i][j] = EMPTY;
         }
       }
     }
   ```
   ```
   // 최고 점수를 file에 저장 및 읽기
   int GameOver(MData map[MAP_SIZE_H][MAP_SIZE_W],int score, int bestScore){
     FILE * wfp;
     
     if(score >= bestScore){
       wfp = fopen("score.txt", "w");
       fprintf(wfp, "%d", score);
       fclose(wfp);
     }
   }
   
   int GameStart(MData map[MAP_SIZE_H][MAP_SIZE_W]){
     int score =0, bestScore =0;
     FILE * rfp;
     if((rfp = fopen("score.txt", "r")) == NULL){
       FILE * wfp;
       wfp = fopen("score.txt", "w");
       fprintf(wfp, "%d", 0);
       fclose(wfp);
     }
     fscanf(rfp, "%d", &bestScore);
   }
   ```
   * [참조: [https://github.com/BlockDMask/Tetris_Game](https://github.com/BlockDMask/Tetris_Game)]
