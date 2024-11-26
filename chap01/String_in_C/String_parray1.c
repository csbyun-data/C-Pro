// C Program to print Array of Pointers
#include <stdio.h>

// Driver code
int main()
{
  char *arr[] = {"abcd", "abcde", "abcdefgh"};
  printf("String array Elements are:\n");
  
  for (int i = 0; i < 3; i++) 
  {
    printf("%s\n", arr[i]);
  }
  return 0;
}
