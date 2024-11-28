// It can be optimized by stopping the algorithm
// if there is no swapping occur in the inner loop

#include <stdio.h>
#define ARRAY_SIZE(x) sizeof(x)/sizeof(x[0])

// Function to swap element
void Swap( int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// FUnction to sort the array
void BubbleSort( int *aar, int n) {
  int i=0, j=0;
  int swapflag = 0;

  for( i=0; i<n; j++) {
    swapflag = 0;
    for( j=0; j<n-i-1; j++) {
      if(arr[j] > arr[j+1]) {
        Swap( &arr[i], &arr[j+1]);
        swapflag = 1;
      }
    }
    // If inner loop not executed, break the loop
    if( swapflag == 0)
      break;
  }
}

int main()
{
  int i=0;
  int arr[] = { 6, 5, 3, 1, 8, 7, 2, 4};
  int n=ARRAY_SIZE(arr);

  // Function to sort array in ascending order
  BubbleSort( arr, n);
  printf("Array in ascending order: \n");

  for( i=0; i<n; i++)
    printf("%d", arr[i]);

  return 0;
}
  
