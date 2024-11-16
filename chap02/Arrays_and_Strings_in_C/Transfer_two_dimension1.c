#include <stdio.h>

#define ARRAY_COL 3

void ReadArray(int iRow, int iCol, int aiData[][iCol]) {
  int i, j;

  for( i=0; i<iRow; ++i)
    for( j=0; j<iCol; ++j)
      printf("%d ", aiData[i][j]);
}

int main( int argc, char *argv[])
{
  // Create an 2D array
  int aiData[][ARRAY_COL] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

  int iRow=3, iCol=ARRAY_COL;
  //Pass array as a parameter
  ReadArray(iRow, iCol, aiData);

  return 0;
}
