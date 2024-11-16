#include <stdio.h>

void ReadArray(int iRow, int iCol, int aiData[][n]) {
  int i, j;

  for( i=0; i<ARRAY_ROW; ++i)
    for( j=0; jCol<ARRAY_COL; ++j)
      printf("%d ", aiData[i][j]);
}

int main( int argc, char *argv[])
{
  // Create an 2D array
  int aiData[][ARRAY_COL] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

  int iRow=3, iCol=3;
  //Pass array as a parameter
  ReadArray(iRow, iCol, aiData);

  return 0;
}
