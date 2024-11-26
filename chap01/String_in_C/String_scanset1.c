// C program to take string separated by whitespace using
// scanset characters
#include <stdio.h>

int main()
{
  char str[20];

  // using scanset in scanf
  scanf("%[^\n]s", str);

  // printing read string
  printf("%s", str);

  return 0;
}
