// ☆ invalid conversion from 'void*' to 'int*' [-fpermissive]
//  https://aticleworld.com/dynamically-allocate-2d-array-c/
#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE  10
// Function to get n odd numbers
int * collectOddNumbers(const int n)
{
  int i =0; //Integer variable
  int *ptr = NULL; //Integer pointer
  //Allocate the memory
  ptr = (int *)malloc(sizeof(int)*n);

  // invalid conversion from 'void*' to 'int*' [-fpermissive]
  //ptr = malloc(sizeof(int)*n);
    
  //Check allocated memory
  if(ptr == NULL) {
    return NULL;
  }
  for (i = 0; i < n; i++) {
    // Calculate and store even number in numbers
    *(ptr + i) =  ((i*2) + 1);
  }
  return ptr;
}

int main()
{
  //integer variable
  int index = 0;
  //integer pointer
  int *oddNumbers = NULL;
  //Get first 10 odd numbers
  oddNumbers = collectOddNumbers(ARRAY_SIZE);
  
  // Print all 10 odd numbers
  for (index = 0; index < ARRAY_SIZE; ++index) {
    printf("%d ", oddNumbers[index]);
  }
  
  //free allocated memory
  free(oddNumbers);
  oddNumbers = NULL;

  return 0;
}

// 1 3 5 7 9 11 13 15 17 19
