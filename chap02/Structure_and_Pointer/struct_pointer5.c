// C언어 코딩도장 49.1 참조
#include <stdio.h>
#include <stdlib.h>

struct Data {
  char c1;
  int *numPtr;
};

int main()
{
  int n1 = 10;
  struct Data d1;
  struct Data* d2 = (struct Data *)malloc(sizeof(struct Data));
  
  d1.numPtr = &n1;
  d2->numPtr = &n1;
  
  printf("d1.numPtr = %d, d2.numPtr = %d \n", *d1.numPtr, *d2->numPtr);
  
  d2->c1 = 'a';
  printf("d2->c1 = %c, d2->numPtr = %d \n", (*d2).c1, *(*d2).numPtr);
  
  free(d2);
  
  return 0;
}

/*
d1.numPtr = 10, d2.numPtr = 10
d2->c1 = a, d2->numPtr = 10
*/
