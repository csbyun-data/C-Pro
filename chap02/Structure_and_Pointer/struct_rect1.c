#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Point2D {
  int x;
  int y;
}Point2D;

typedef struct Rectangle{
  Point2D* LeftDown;
  Point2D* RightUp;
}Rectangle;

int solution(int x1, int y1, int x2, int y2, int plus_x, int plus_y){
  Point2D leftdown = {x1, y1};
  Point2D rightup = {x2, y2};
  Rectangle rect = {&leftdown, &rightup};
  
  int first_width = (rect.RightUp->x - rect.LeftDown->x) * 
                    (rect.RightUp->y - rect.LeftDown->y);
  
  rightup.x += plus_x;
  rightup.y += plus_y;
  
  int second_width = (rect.RightUp->x - rect.LeftDown->x) * 
                     (rect.RightUp->y - rect.LeftDown->y);
  
  return second_width - first_width;
}
int main() {
  int x1=1, y1=1,  x2=5, y2=5
  int plus_x=2, plus_y=1
  
  int ret = solution(x1, y1, x2, y2, plus_x, plus_y);
  
  printf("solution 함수의 반환 값은 {%d} \n", ret );
}
