// C program to reverse a astring using another array
#include <stdio.h>
#include <string.h>

void reverse( char *str) {
  // temporary array asuming the max size of the
  // original string as 100
  char temp[100];

  // size pointer of the temp array
  int t_size = -1;
  int len = strlen(str);

  // push all characters of the string onto the temp
  for ( int i=0; i<len; i++) {
    str[i] = temp[t_size--];
  }
}

int main() 
{
  char str[100] = "Hello World";

  // reversing str
  reverse(str);
  printf("%s", str);

  return 0;
}

  
