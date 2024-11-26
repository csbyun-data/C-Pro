// Strings and Pointers
#include <stdio.h>

int main(void) 
{
  char name[] = "Harry Potter";

  printf("%c", *name);      // H
  printf("%c", *(name+1));  // a
  printf("%c", *(name+7));  // o

  char *namePtr;
  namePtr = name;
  printf("%c", *namePtr);     // H
  printf("%c", *(namePtr+1)); // a
  printf("%c", *(namePtr+7)); // o
}
