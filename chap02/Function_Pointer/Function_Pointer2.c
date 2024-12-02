// 01. function pointer의 초기화 &func;
#include <stdio.h>

// a normal function with an int parameter and void return type
void func( int a) {
  printf("Value of a is %d\n", a);
}

int main()
{
  // fun_ptr is a pointer to function func()
  void (*func_ptr)(int) = &func;

  /* The above line is equivalent of following two
  void (*func_ptr)(int);
  func_ptr = &func;
  */

  // Invoking fun() using func_ptr
  (*func_ptr)(10);

  return 0;
}
