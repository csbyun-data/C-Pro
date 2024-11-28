// 1차원 문자열을 return하는 예제
#include <stdio.h>

char *func( char *s) {
  puts(s);

  return s;
}

int main()
{
  char *str;
  str = func("ABCD");
  puts(str);
}

// ABCD
// ABCD
