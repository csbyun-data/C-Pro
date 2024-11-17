#include <stdio.h>
#define ROW   3
#define COL   3
typedef int Array2D[ROW][COL]; //New type

int main(void)
{
    // 2d array
    Array2D aiData = { { 9, 6, 1 }, { 144, 70, 50 }, {10, 12, 78} };
    Array2D *p2DArray = NULL; //Pointer to the 2d Array
    int iRow =0, iCol =0; //Row and col

    p2DArray = &aiData; //Assign address of array to the pointer
    for (iRow = 0; iRow < ROW; ++iRow) //Loop of row
    {
        for (iCol = 0; iCol < COL; ++iCol)// Loop for coloumb
        {
            //Read element of 2D array
            printf("aiData[%d][%d] = %d\n",iRow,iCol, (*p2DArray)[iRow][iCol]);
        }
    }

    return 0;
}
