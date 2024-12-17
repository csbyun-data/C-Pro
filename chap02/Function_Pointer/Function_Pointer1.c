#include <stdio.h>

void func();
int rect(int);

int main()
{
  void (*fptr1)();
  int (*fptr2)(int);
  int len, area;

  fptr1 = &func;
  (*fptr1)();

  fptr2 = &rect;
  len=10;
  area = (*fptr2)(len);

  printf("Area = %d\n", area);

  return 0;
}

void func() {
  printf("call func()\n");
}

int rect(int len) {
  int area = (len*len);

  return area;
}

// call func()
// Area = 100
  
