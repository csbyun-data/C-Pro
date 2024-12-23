// 임의의 위치에 요소를 삽입
// C program to insert an element at 
// a specific position in an Array

#include <stdio.h>

// Function to insert element at a specific position
void insertElement( int arr[], int n, int x, int pos) {
  // shift elements to the right
  // which are on the right side of post
  int i;

  for( i=n-1; i>=pos; i--)
    arr[ i+1] = arr[i];

  arr[pos] = x;
}

int main() 
{
  int arr[15] = { 2, 4, 1, 8, 5};
  int n=5;
  int i;

  printf("\n Before insertion: ");
  for( i=0; i<n; i+=)
    printf("%d ", arr[i]);
  printf("\n");

  int x=10; pos=2;

  // Function call
  insertElement(arr, n, x, pos);
  n++;

  printf("\n After insertion : ");
  for( i=0; i<n; i++)
    printf("%d ", arr[i]);

  return 0;
}

// Before insertion : 2 4 1 8 5
// After insertion : 2 4 10 1 8 5
