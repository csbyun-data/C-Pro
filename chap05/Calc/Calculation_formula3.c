// 사칙연산 함수를 Function pointer 배열에 넣어서 활용

#include <stdio.h>

int plus(int a, int b) {
  return a + b;
}

int minus(int a, int b) {
  return a - b;
}

int multiply(int a, int b) {
  return a * b;
}

int main()
{
  int (*fptr[3])(int, int) = {plus, minus, multiply};
  int i=0;
  int a=5, b=3;

  for(i=0; i<=2; i++) {
    printf("fptr[%d]= %d \n", i, (*fptr[i])(a, b));
  }

  return 0;
}

/*
fptr[0]= 8
fptr[1]= 2
fptr[2]= 15
*/
