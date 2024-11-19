#include <stdio.h>
#include <string.h>
 
void fun(char* arr) {
  int i;
  unsigned int n = strlen(arr);
  
  printf("n = %d\n", n);
  for (i = 0; i < n; i++)
    printf("%c  ", arr[i]);
}
 
int main()
{
    char arr[] = "abcdefgh";
    fun(arr);
    return 0;
}
