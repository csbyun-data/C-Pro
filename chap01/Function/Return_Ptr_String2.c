// char * 예제
// static carr[100] 문자열 활용

#include <stdio.h>

char *func() {
  static char carr[100];
  gets(carr);

  return carr;
}

int main()
{
  char *str;

  str = func();
  puts(str);
}

// ASDF
// ASDF
