#include <stdio.h>

// Size of the created array
#define ARRAY_SIZE 5

// Note that paData[] for fun is just a pointer even if square
// brackets are used. It is same as
// void fun(int *paData) or void fun(int paData[size])

// Function to read array element
void ReadArray(int *paData) {
  int idx = 0;

  for( idx=0; idx<ARRAY_SIZE; ++idx)
    printf("%d ", paData[idx]);
}

int main( int argc, char *argv[])
{
  //Create an array
  int aiData[ARRAY_SIZE] = {1, 2, 3, 4, 5};

  //Pass array as a parameter
  ReadArray( aiData);

  return 0;
}
