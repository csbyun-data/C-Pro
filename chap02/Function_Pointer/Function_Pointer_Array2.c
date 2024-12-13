#include <stdio.h>

int plus( int a, int b) { return a+b; }
int subtract( int a, int b) { return a-b; }
int multiple( int a, int b) { return a*b; }
int divide( int a, int b) { return a/b; }

int main()
{
  int (*fp[4])( int, int);

  fp[0] = plus;
  fp[1] = subtract;
  fp[2] = multiple;
  fp[3] = divide;

  // int (*fp[4])( int, int) = {plus, subtract, multiple, divide };

  for( int i=0; i<4; i++) {
    printf("no: %d, %d \n", i, fp[i](10, 20));
  }

  return 0;
}

/*
no: 0, 30
no: 1, -10
no: 2, 200
no: 3, 0
*/
