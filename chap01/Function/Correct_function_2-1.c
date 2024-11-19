//올바르게 작성한 프로그램 예, 배열의 요소수를 전달
// C Program to demonstrate correct usage of sizeof() for arrays

#include <stdio.h>
 
void fun(int arr[], size_t arr_size) {
  int i;
  for (i = 0; i < arr_size; i++) 
    arr[i] = i;
}
 
int main()
{
  int i;
  int arr[] = { 0, 0, 0, 0 };
  size_t n = sizeof(arr) / sizeof(arr[0]);

  fun(arr, n);
 
  printf("The size of the array is: %ld", n);
  printf("\nThe elements are:\n");
  for (i = 0; i < n; i++)
    printf(" %d ", arr[i]);
 
  getchar();
  return 0;
}
