// strcpy() 구현

#include <stdio.h>
#include <string.h>

char *my_strcpy( char *dest, const char *src ) {
  char *s = dest;
  for( ; *src ; dest++, src++ )
    *dest = *src;
  *dest = '₩0';
  
  return s;
}

int main(void)
{
  char buffer[100];
  char *s = "Hello, world!";
  my_strcpy( buffer, s );
  printf("buffer = %s₩n", buffer );
  
  return 0;
}
