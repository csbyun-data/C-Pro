#include <stdio.h>

void ReadArray(int *piData, int iRow, int iCol) {
  int i, j;

  for( i=0; i<iRow; i++)
    for( j=0; j<iCol; j++)
      printf("%d ", *((piData+i*iRow)+j) );
}

int main( int argc, char *argv[])
{
  // Create an 2D array
  int aiData[][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

  int iRow=3, iCol=3;

  // We can also use "ReadArray( &aiData, iRow, iCol);"
  // and "ReadArray( (int *)aiData[0], iRow, iCol);"
  //Pass array as a parameter
  ReadArray((int *)aiData, iRow, iCol);

  return 0;
}
