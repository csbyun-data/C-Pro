// 코딩도장 52.1 , 구조체 포인터 변수 복사
#include <stdio.h>
#include <stdlib.h>  //malloc, free
#include <string.h>  //memcpy

struct p {
  int x;
  int y;
};

int main()
{
  struct p* p1 = (struct p*)malloc(sizeof(struct p));
  struct p* p2 = (struct p*)malloc(sizeof(struct p));
  
  p1->x = 10;
  p1->y = 20;
  
  memcpy(p2, p1, sizeof(struct p));
  
  printf("%d, %d\n", p2->x, p2->y);
  
  free(p2);
  free(p1);
  
  return 0;
}
