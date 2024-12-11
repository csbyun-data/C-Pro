// C언어 함수포인터 활용예제
// Function pointer를 구조체에 넣어 사용

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Calculator {
  int (*plus)(int, int);
  int (*minus)(int, int);
} Calculator;

int plus(int a, int b) {
  return a + b;
}

int minus(int a, int b) {
  return a - b;
}

int* solution(int a, int b) {
  int *answer = (int *) malloc(sizeof(int) * 2);
  struct Calculator c;

  c.plus = plus;
  c.minus = minus;

  answer[0] = c.plus(a, b);
  answer[1] = c.minus(a, b);
    
  return answer;
}

int main() {
  int a = 3;
  int b = 5;
  int *ret = solution(3, 5);

  printf("Ret Value:  {%d, %d} .\n", ret[0], ret[1]);

  free(ret);
}

/*
Ret Value: {8, -2} .
*/
