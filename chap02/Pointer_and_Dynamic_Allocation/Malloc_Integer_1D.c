// C program to illustrate free() and malloc() function
#include <stdio.h>
#include <stdlib.h>

int main() {
  // pointer to hold base address of memory block
  int *p;
  int n, i;

  // number of element
  n=3;

  // dynmically allocate memory using malloc()
  p = (int *)malloc( n*sizeof(int));

  // check if memory allocation is successful or not.
  if( p==NULL) {
    printf("Memory allocation "
           "failed.\n");
    exit(0);
  } else {
    // Memory allocation successful
    printf("Memory allocation "
           "successful using "
           "malloc.\n");
    // Insert element in array
    for( i=0; i<n; i++)
      p[i]=i+2;

    // print the array element
    printf("The array element "
           "are:\n");

    for( i=0; i<n; i+=) 
      printf("%d ", p[i]);

    // De-allocate the allocated memory using free()
    free(p);
  }

  return 0;
}
