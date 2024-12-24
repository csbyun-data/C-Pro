#include <stdio.h>

// Passing string to a Function
void displayString(char str[]);

int main()
{
  char str[50];
  printf("Enter string: ");
  fgets(str, sizeof(str), stdin);

  // str은 문자열의 첫번째 address, 동일 표현 &a[0], func( &a[0]);
  displayString(str); // Passing string to a function
}

// str[] == *str 표현
void displayString( char str[]) {
  printf("String Output: ");
  puts(str);
}
