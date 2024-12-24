// 포인터 배열과 배열 포인터
#include <stdio.h>

int main(void)
{
  const char *parr[3];  // 포인터 배열, (char *) arr[3];, 배열을 가리키는 포인터 3개
  
  parr[0] = "ABCDEF";
  parr[1] = "BCD";
  parr[2] = "CDEFGHIJK";
  
  for ( int i=0; i < 3; i++)
    printf("parr[%d]->%s\n", i, parr[i]);
  
  char (*arr)[3];        // 배열 포인터 , tmp1[3]를 가르키는 포인터 1개
  char tmp1[3] = {'a','b','c'};
  arr = &tmp1;
  
  for (int i=0; i < (int)sizeof(*arr); i++)
    printf("%c", (*arr)[i]);
  
  printf("\n");
  
  return 0;
}
