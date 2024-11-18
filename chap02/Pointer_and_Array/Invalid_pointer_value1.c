// 지역변수를 참조하게되면 논리Error가 발생함
#include <stdio.h>

int *fun() {
  // local variable
  int data = 5;

  // address of local variable
  return &data;
}

int main()
{
  // Returning address of the local variable
  int *piData = fun();

  // Use of indirection operator with pointer
  printf("%d", *piData);

  return 0;
}
