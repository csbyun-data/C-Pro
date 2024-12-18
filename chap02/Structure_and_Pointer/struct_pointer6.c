// 코딩도장 52.1, 구조체 초기화
#include <stdio.h>
#include <string.h>

struct p {
  int x;
  int y;
};

int main()
{
  struct p p1;
  memset(&p1, 0, sizeof(struct p));
  
  printf("%d, %d\n", p1.x, p1.y);
  
  return 0;
}

/*
0, 0
*/
