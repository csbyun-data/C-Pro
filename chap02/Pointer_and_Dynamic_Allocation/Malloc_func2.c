// malloc 메모리 할당, free 메모리 할당 해제
#include <stdio.h>
#include <stdlib.h>

void main()
{
  int *pPoint;

  pPoint = (int *)malloc( sizeof(int)*5);

  pPoint[0] = 25;
  pPoint[1] = 45;
  pPoint[2] = 50;
  pPoint[3] = 70;
  pPoint[4] = 99;

  int i=0;
  for( i=0; i<5; i++)
    printf("pPoint[%d] : %d\n", i, pPoint[i]);

  free(pPoint);
}
