// C program to print string using Pointers
#include <stdio.h>

int main()
{
  char str[20] = "abcdef";

  // Pointer variable which stores
  // the starting address of the charcter array str
  char *ptr = str;

  // While loop will run till the character value is not
  // equal to null character
  while ( *ptr != '\0') {
    printf("%c", *ptr);

    // moving pointer to the next character.
  }
 
  return 0;
}
