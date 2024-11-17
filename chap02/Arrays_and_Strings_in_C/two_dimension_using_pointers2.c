#include <stdio.h>

#define ROW 3
#define COL 3
#define TOTAL_CELLS (ROW*COL)

int main(void)
{
  int aiData[ROW][COL] = { {9, 6, 1}, {144, 70, 50}, {10, 12, 78} };
  int *piData = NULL;  // pointer to integer
  int arrayIdx = 0;    // variable for array index

  piData = &aiData[0][0]; // You can also write *aiData

  for( arrayIdx=0; arrayIdx<TOTAL_CELLS; ++arrayIdx)  // loop for row
      printf("Array elements = %d\n", *(piData + arrayIdx));

  return 0;
}
