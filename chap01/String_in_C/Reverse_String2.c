// C program to reverse a string using recursion
#include <stdio.h>
#include <string.h>

void reverse( char *str, int first, int last) {
  // base case is when first becomes greater than last
  if ( first >= last) {
    return ;
  }

  // swap characters
  char temp = str[first];
  str[first] = str[last];
  str[last] = temp;

  // recursively call the function with updated
  // index pointers
  reverse( str, first+1, last-1);
}

int main()
{
  char str[100] = "Hello World";

  reverse( str, 0, strlen(str)-1);

  printf("%s", str);

  return 0;
}
    
