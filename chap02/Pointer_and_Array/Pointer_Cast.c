#include <stdio.h>

int main()
{
  int n = 0x30313233;
  
  printf("%x %c \n", *(char*)&n, *(char*)&n);
  printf("%x %c \n", *((char*)&n+1), *((char*)&n+1));
  printf("%x %c \n", *((char*)&n+2), *((char*)&n+2));
  printf("%x %c \n", *((char*)&n+3), *((char*)&n+3));

 return 0;
}
