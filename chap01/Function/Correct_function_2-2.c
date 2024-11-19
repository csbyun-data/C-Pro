// 배열의 크기를 매개변수로 전달, 옳은 예제
// C program to illustrate the use of sizeof operator in C
#include <stdio.h>
 
// function to print array
void printArray(int arr[], int size) {
    printf("Array Elements: ");
    for (int i = 0; i < size; i++) 
        printf("%d ", arr[i]);
}
 
int main()
{
  int arr[8] = { 12, 4, 5, 3, 7, 8, 11, 45 };
 
  // getting the size of array
  int size = sizeof(arr) / sizeof(arr[0]);
 
  printArray(arr, size);
 
  return 0;
}
