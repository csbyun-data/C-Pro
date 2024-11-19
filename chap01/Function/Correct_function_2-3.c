// C Program to demonstrate usage of macros to find the size of arrays
#include <stdio.h>
 
#define SIZEOF(arr) sizeof(arr) / sizeof(*arr)
 
void fun(int arr[], size_t arr_size) {
  int i;
  for (i = 0; i < arr_size; i++) 
    arr[i] = i;
}

int main()
{
  int i;
  int arr[] = { 0, 0, 0, 0, 0 };
  size_t n = SIZEOF(arr);
  fun(arr, n);
 
  printf("The size of the array is: %ld", n);
  printf("\nThe elements are:\n");
  for (i = 0; i < n; i++)
      printf(" %d ", arr[i]);
 
  return 0;
}
