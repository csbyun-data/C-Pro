//struct has both normal and anonymous unions
#include <stdio.h>

struct Test {
  union { // anonymous union
    int a;
    char b;
  };
  union {
    long c;
    char d;
  } e;
  int value;
} var;

int main()
{
  var.a = 2;   // valid
    
  // invalid: inner union is not anonymous you will get compiler error
  var.c = 3;   //invalid
  var.e.c = 5; // valid

  return 0;
}
