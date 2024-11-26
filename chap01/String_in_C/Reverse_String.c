// C program to reverse a string using two-pointer technique
#include <stdio.h>
#include <string.h>

void reverse( char *str) {
  // initialize first and last pointers
  int first = 0;
  int last = strlen(str)-1;
  char temp;

  // swap characters till first and last meet
  while (first < last) {
    // swap characters
    temp = str[first];
    str[first] = str[last];
    str[last] = temp;

    // move pointers towards each other
    first++;
    last--;
  }
}

int main()
{
  char str[100] = "Hello World!";

  // reversing str
  reverse(str);

  printf("%s\n", str);

  return 0;
}
