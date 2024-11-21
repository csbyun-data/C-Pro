#include <stdio.h>

// C program to demonstrate designated initializers with structures
struct Point {
  int a, b, c;
};

int main() {
  // Examples of initialization using designated initialization
  struct Point p1 = { .b=0, .c=1, .a=2 };
  struct Point p2 = { .a=20 };

  printf("p1 {%d, %d, %d}\n", p1.a, p1.b, p1.c);
  printf("p2.a = %d\n", p2.a);

  return 0;
}
