#include <stdio.h>

union Test {
  int x;
  char c[4];
};

int main()
{
  /* makes obj1.x active with value 1 */
  union Test obj1 = {1};
  printf("%d\n", obj1.x);
  
  /*  Designated initialize   */
  /* makes obj2.c active with value {'A','m','l','\0'} */
  union Test obj2 = { .c="Aml" }; //C99 <- { .c={"Aml"} };
  printf("%s\n", obj2.c);

  return 0;
}

// output;
// 1
// Aml
