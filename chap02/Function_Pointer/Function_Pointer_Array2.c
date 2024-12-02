#include <stdio.h>

int add( int a, int b) { return a+b; }
int substr( int a, int b) { return a-b; }

int main()
{
  int (*fp[2])( int, int);

  fp[0] = add;
  fp[1] = subtract;

  for( int i=0; i<2; i++) {
    printf("no: %d, %d \n", i, fp[i](10, 20));
  }

  return 0;
}

// no: 0, 30
// no: 1, -10
