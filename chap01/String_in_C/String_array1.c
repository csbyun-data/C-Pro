// C Program to print Array of strings
#include <stdio.h>

int main()
{
  char arr[3][10] = {"abcd", "abcdef", "ghijkl"};

  // arr[0] = "GFG";  Error 발생됨
  // strcpy(arr[0], "GFG"); 사용해야 됨
  printf("String array Elements are:\n");
  
  for (int i = 0; i < 3; i++) {
    printf("%s\n", arr[i]);
  }

  return 0;
}
