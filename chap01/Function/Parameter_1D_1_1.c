// 배열의 call by address (pass by address) 활용
#include <stdio.h>
#define ARRAY_SIZE 10

// Function to get n odd numbers
void collectOddNumbers( const int n, int *ptr) {
  int i=0;
  for( i=0; i<n; ++i) {
    // Store odd numbers
    *(ptr+i)=((i*2)+1);
  }
}

int main()
{
  // Array to store odd numbers
  int oddNumbers[ARRAY_SIZE]={0};
  int index=0;

  // Get first 10 odd numbers
  collectOddNumbers( ARRAY_SIZE, oddNumbers);

  // Print all 10 odd numbers
  for( index=0; index<ARRAY_SIZE; ++index) {
    printf("%d ", oddNumbers[index]);
  }
  return 0;
}

// 1 3 5 7 9 11 13 15 17 19
