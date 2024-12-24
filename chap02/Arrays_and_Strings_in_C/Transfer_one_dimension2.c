#include <stdio.h>

#define ARRAY_SIZE 8

// *acData[] == acData[] 동일 표현
void ReadArray(int acData[]) {
  int idx = 0;

  for( idx=0; idx<ARRAY_SIZE; ++idx)
    printf("%d ", acData[idx]);
}

int main( int argc, char *argv[])
{
  // Create an array
  int aiData[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};

  //Pass array as a paramenter
  ReadArray(aiData);

  return 0;
}
