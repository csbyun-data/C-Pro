// 코딩도장 52.1, 구조체 변수 초기화
#include <stdio.h>
#include <string.h>

struct p {
  int x;
  int y;
};

int main()
{
  struct p p1, p2;
  p1.x = 10;
  p1.y = 20;
  
  memcpy(&p2, &p1, sizeof(struct p));
  
  printf("%d, %d\n", p2.x, p2.y);
  
  return 0;
}

/*
10, 20
*/
