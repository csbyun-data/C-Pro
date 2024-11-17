#include <stdio.h>

#define ROW 3
#define COL 3

int main(void)
{
  int aiData[ROW][COL] = { {9, 6, 1}, {144, 70, 50}, {10, 12, 78} };
  int *piData = NULL;  // pointer to integer
  int iRow=0, iCol=0;

  piData = &aiData[0][0]; // You can also write *aiData

  for( iRow=0; iRow<ROW; ++iRow) { // loop for row
    for( iCol=0; iCol<COL; ++iCol) { // loop for column
      // Read element of 2D array
      printf("aiData[%d][%d] = %d\n"), iRow, iCol, *(piData + (iRow*COL)+iCol));
    }
  }

  return 0;
}
