// C program to demostrate variable length array
#include <stdio.h>

// function to initialize array
// func( int *arr) == func( int arr[]) 동일 표현
void initialize( int *arr, int size) {
  for( int i=0; i<size; i++)
    arr[i] = i+1;
}

// function to print an array
void printArray(int size) {
  // variable length array
  int arr[size];

  initialize( arr, size);

  for( int i=0; i<size; i++) 
    printf("%d ", arr[i]);
}

int main()
{
  int n;

  printf("Enter the size: ");
  scanf("%d", &n);
  printArray(n);

  return 0;
}  
