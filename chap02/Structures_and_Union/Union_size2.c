#include <stdio.h>

union Test {
  char ProdName[10];
  int iAmount;
};

int main()
{
  printf("Size of Union = %ld\n", sizeof(union Test));
    
  return 0;
}

// output:
// Size of Union = 12
