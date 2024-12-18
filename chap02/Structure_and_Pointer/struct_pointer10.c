// 코딩도장 52.x 구조체 초기화 방법
#include <stdio.h>
#include <stdlib.h>  //malloc, free
#include <string.h>  //memcpy

struct p {
  int x;
  int y;
};

int main()
{
  struct p pa[2];
  
  pa[0].x = 10;
  pa[0].y = 20;
  pa[1].x = 30;
  pa[1].y = 40;
  
  struct p pa2[2]	= {{.x=10, .y=20}, {.x=30, .y=40}};
  struct p pa3[2] = {{10, 20}, {30, 40}};
  
  return 0;
}
