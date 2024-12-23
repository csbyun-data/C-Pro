// struct를 parameter로 전달하는 방법
//call by address 
#include <stdio.h>

struct Rect {
  int length;
  int width;
};

void changeLength (struct Rect *p, int l) {
  p->length = l;
}

int main() 
{
  struct Rect r = {10, 5};
  changeLength(&r, 20);
  
  printf("Area = %d", r.length*r.width);
  
  return 0;
}
