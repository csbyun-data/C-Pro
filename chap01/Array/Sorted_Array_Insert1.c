// C program to implement insert operation in an sorted array
#include <stdio.h>

// Inserts a key in arr[] of given capacity. n is current size of arr[].
// This function returns n+1 if insertion is successful, else n.

insertSorted( int arr[], int n, int key, int capacity) {
  // Can not insert more element if n is alrealy
  // more than or equal to capacity
  if( n>=capacity )
    return n;

  int i;
  for( i=n-1; (i>=0 && arr[i]>key); i--)
    arr[i+1] = arr[i];

  arr[i+1]=key;
  return (n+1);
}

int main()
{
  int arr[20] = { 12, 16, 20, 40, 50, 70 };
  int capacity = sizeof(arr)/sizeof(arr[0]);
  int n=6;
  int i, key=26;

  printf("\nBefore Insertion: ");
  for( i=0; i<n; i++)
    printf("%d ", arr[i]);

  return 0;
}

// Before Insertion: 12, 16, 20, 40, 50, 70
// Afer Inesertion ,12, 16, 20, 26, 40, 50, 70

