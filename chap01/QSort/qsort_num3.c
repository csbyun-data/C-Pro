#include <stdio.h>
#include <stdlib.h>

int compare( const void *a, const void *b);

const int length = 10;

int main()
{
  int i, intArray[length];

  for ( i=0; i<length ; i++) {
    printf("Enter a number: ");
    scanf("%d", intArray[i]);
  }
  printf("\n");

  qsort( (void *)intArray, length, sizeof(intArray[0]), compare);

  printf("intArray : ");
  for ( i=0; i<length ; i++)
    printf("[%d]", intArray[i]);
  printf("\n");
  printf("Done.\n");

  return 0;
}

int compare( const void *a, const void *b) {
  int ia = *((int *)a);
  int ib = *((int *)b);

  if ( ia<ib)
    return -1;
  if ( ia==ib)
    return 0;
}
