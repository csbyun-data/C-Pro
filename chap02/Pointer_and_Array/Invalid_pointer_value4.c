#include <stdio.h>

int main()
{
  long ldata = 0x12345678;
  void *vptr = (char *)&ldata +1;
  long *lptr = vptr;  // address not aligned with long

  ldata = *lptr;

  printf("%lx\n", ldata);

  return 0;
}
