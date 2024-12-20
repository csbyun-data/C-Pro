// CPP code for recursive function of Quicksort
#include <bits/stdc++.h>
using namespace std;

/* This function takes last element as pivot, places the pivot element
   at its correct position in sorted array, and places all smaller
   (smaller than pivot) to left of pivot and all greater elements to
   right of pivot */
int partition( int arr[], int l, int h) {
  int x = arr[h];
  int i = (l-1);

  for( int j=l; j<=h-1; j++) {
    if( arr[j]<=x) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap( arr[i+1], arr[h]);
  return (i+1);
}

/* A[] --> Array to be sorted, l --> Starting index,
   h --> Ending index */
void quickSort( int A[], int l, int h)
{
  if( l<h)  {
    // Partitioning index
    int p = partition( A, l, h);
    quickSort( A, l, p-1);
    quickSort(A, p+1, h);
  }
}

int main()
{
  int n=5;
  int arr[n] = { 4, 2, 6, 9, 2 };

  quickSort( arr, 0, n-1);

  for( int i=0; i<n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}

