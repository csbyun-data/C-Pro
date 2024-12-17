#include <stdio.h>

int Set(int i, double d) {
  printf("%d, %f\n", i, d);
  return 0;
}

void main()
{
  int (*p)(int, double); // 동일 표현 int(int, double) *p;
  p = Set;
  p(2, 3.7);
}

// 2, 3.7
