#include <stdio.h>
#include <stdlib.h>

void modifyVal ( int *myptr) {
  *myptr = 200;
}

int main(void) {
  int a = 100;
  int *myptr = &a;
  modifyVal(myptr);

  printf("%d", a);
  return 0;
}
