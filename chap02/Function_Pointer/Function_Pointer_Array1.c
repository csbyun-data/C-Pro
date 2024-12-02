#include <stdio.h>

int add( int a, int b) { return a+b; }
int subtract( int a, int b) { return a-b; }

int main()
{
  int (*operation)( int, int);

  int num1, num2;
  char operator1;

  num1 = 1;
  num2 = 2;
  printf("(+, -):");
  scanf(" %c", &operator1);

  if( operator1 = '+') {
    operation = add;
  } else if ( operator1 = '-') {
    operation = subtract;
  } else {
    printf("+, -\n");

    return 1;
  }

  int result = operation( num1, num2);
  printf("result = %d", result);

  return 0;
}
