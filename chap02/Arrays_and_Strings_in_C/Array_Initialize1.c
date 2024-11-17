#include <stdio.h>
#include <string.h>

// Size of the static array
#define ARRAY_SIZE sizeof(aiData)/sizeof(aiData[0])

int main() 
{
  int aiData[10] = { 1, 2, [4]=40, 5, [7]=70, [8]=80};
  int i=0;

  printf("Stored elements of the array\n");
  for( i=0; i<ARRAY_SIZE; i++) 
    printf(" aiData[%d] = %d\n", i, aiData[i]);

  return 0;
}
