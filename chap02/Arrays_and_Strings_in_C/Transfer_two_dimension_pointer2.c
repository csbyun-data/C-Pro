#include <stdio.h>

// Size if the created array
#define M 3

// void ReadArray( int piData[][M]) 동일 표현
void ReadArray( int (*piData)[M]) {
  int iRow = 0;
  int iCol = 0;

  for( iRow=0; iRow<M; ++iRow)
    for( iCol=0; iCol<M; ++iCol)
      printf("%d ", piData[iRow][iCol]);
}

int main( int argc, char *argv[])
{
  // Create an 2D array
  int aiData[][M] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

  //Pass array as a parameter
  ReadArray(aiData);

  return 0;
}
