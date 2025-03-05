#include "main.h"
#include "util.h"

int main() {
  init();
  
  while(1) {
    titleDraw();
    int menuCode = menuDraw();
    
    if(menuCode == 0) {
      int n = maplistDraw();
      
      if(n == 0) {
        gLoop(0); // 0: 쉬운맵  
      } else if(n == 1){
        gLoop(1); // 1: 어려운맵  
      } 
    } else if(menuCode == 1) {
      infoDraw(); // 게임정보  
    } else if(menuCode == 2) {
      return 0; // 종료
    }
    system("cls");
    setColor(white, black); // 색 기본값으로 설정  
  }
}
