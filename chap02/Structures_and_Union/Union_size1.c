#include <stdio.h>

union Test1 {
  int data;
  char ch;
} Obj1;

union Test2 {
  int data1;
  int data2;
} Obj2;

union Test3 {
  float data1;
  int data2;
} Obj3;

union Test4 {
  char ch[24];
  int data;
} Obj4;

int main()
{
  printf("sizeof(Obj1) = %lu\n", sizeof(Obj1));
  printf("sizeof(Obj2) = %lu\n", sizeof(Obj2));
  printf("sizeof(Obj3) = %lu\n", sizeof(Obj3));
  printf("sizeof(Obj4) = %lu\n", sizeof(Obj4));
    
  return 0;
}

// output:
// sizeof(Obj1) = 4
// sizeof(Obj2) = 4
// sizeof(Obj3) = 4
// sizeof(Obj4) = 24
