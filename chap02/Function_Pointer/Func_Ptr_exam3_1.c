#include <stdio.h>

void Hello() { 
  printf("Hello, World!\n");
}

void main()
{
  void (*p)(); // 동일 표현 void() *p;
  p = Hello;
  p();
}
