#include <stdio.h>

int main()
{
  int a[][2] = {{1, 2}, {3, 4}};

  printf("%lu"m sizeof(a)); // 4*sizeof(int)

  return 0;
}
