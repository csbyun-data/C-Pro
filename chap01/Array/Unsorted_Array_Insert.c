// C program to implement insert operation in 
// an unsorted array.
#include <stdio.h>

// Inserts a key in arr[] of given capacity
// n is current size of arr[]. This
// function returns n+1 if insertion is scuccessful, else n.

int insertSorted(int arr[], int n, int key, int capacity) {
  // Can not insert more elements if n is 
  // already more than or equal to capacity
  if( n >= capacity)
    return n;

  arr[n] = key;

  return (n+1);
}

int main()
{
  int arr[20] = {12, 16, 20, 40, 50, 70 };
  int capacity = sizeof(arr)/sizeof(arr[0]);
  int n=6;
  int i, key=26;

  printf("\n Before Insertion: ");
  for( i=0; i<n; i++)
    printf("%d ", arr[i]);

  return 0;
}

// Before Insertion: 12  16  20  40  50  70
// After Insertion: 12  16  20  40  50  70  26


