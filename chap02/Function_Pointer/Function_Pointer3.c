// 02. fuction pointer의 초기화 func;
#include <stdio.h>
void func(int a) {
  printf("Value of a is %d\n", a);
}

int main()
{
  void (*func_ptr)(int) = fun; // & removed
  func_ptr(10); // * removed

  return 0;
}

// Value of a is 10
