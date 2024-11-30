// 정렬되지 않은 배열 검색
// C Program to implement linear search in unsorted array
// https://www.geeksforgeeks.org/search-insert-and-delete-in-an-unsorted-array/

#include <stdio.h>

// Function to implement search operation
int findElement( int arr[], int n, int key) {
  int i;
  for ( i=0; i<n; i++)
    if( arr[i] == key)
      return i;

  // If the key is not found
  return -1;
}

int main()
{
  int arr[] = { 12, 34, 10, 6, 40 };
  int n = sizeof(arr)/sizeof(arr[0]);

  // Using a last element as search element
  int key=40;

  // Function call
  int position = findElement( arr, n, key);

  if( position == -1)
    printf("Element not found");
  else
    printf("Element found as position: %d", position+1);

  return 0;
}


    
