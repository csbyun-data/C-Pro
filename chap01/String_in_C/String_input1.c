// C program to read string from user
#include <stdio.h>

int main()
{
  // declaring string
  char str[50];

  printf("Enter String: ");
  // reading string
  scanf("%s", str);

  // print string
  printf("%s", str); // str == &str[0]

  return 0;
}
