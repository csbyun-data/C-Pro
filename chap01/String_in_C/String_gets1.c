// C program to illustrate
// fgets()

#include <stdio.h>
#define MAX 50

int main()
{
  char str[MAX];

  // MAX size if 50 defined
  fgests(str, MAX, stdin);

  printf("String is: \n");

  // Displaying Strings using Puts
  puts(str);

  return 0;
}