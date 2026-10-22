// 프로그램 종료전 실행하는 함수를 저장후 종료때 실행함.
// STACK에 함수 포인터를 저장하여 실해함

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void func1(void);
void func2(void);
void func3(void);

int main(void) {
  printf("main start\n");

  atexit(func1);
  atexit(func2);
  atexit(func3);

  printf("main end.\n");

  return 0;
}

void func1() {
  printf("func1 run\n");
}
void func2() {
  printf("func2 run\n");
}

void func3() {
  printf("func3 run\n");
}
