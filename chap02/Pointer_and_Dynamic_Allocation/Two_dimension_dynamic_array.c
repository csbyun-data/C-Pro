#include <stdio.h>
#include <stdlib.h>
#define FAIL 1

//Free Allocated memory
void freeAllocatedMemory(int **piBuffer, int nRow) {
    int iRow = 0;
    for (iRow =0; iRow < nRow; iRow++) {
        free(piBuffer[iRow]); // free allocated memory
    }
    free(piBuffer);
}

int main(int argc, char *argv[])
{
    int **piBuffer = NULL; //pointer to pointer
    int nRow = 0;          //variable store number of Row
    int nColumn = 0;       //variable store number of Row
    int iRow = 0;          //Variable for looping Row
    int iCol = 0;          //Variable for looping column

    printf("Enter the number of Row = ");
    scanf("%d",&nRow);     //Get input for number of Row
    printf("Enter the number of Column = ");
    scanf("%d",&nColumn);  //Get input for number of Column

    //Allocate memory for row
    piBuffer = (int **)malloc(nRow * sizeof(int*));
    //Check memory validity
    if(piBuffer == NULL)
    {
        return FAIL;
    }

    //Allocate memory for column
    for (iRow =0 ; iRow < nRow ; iRow++)
    {
        piBuffer[iRow] = (int *)malloc(nColumn * sizeof(int));
        //Check memory validity
        if(piBuffer[iRow] == NULL)
        {
            freeAllocatedMemory(piBuffer,iRow);
            return FAIL;
        }
    }

    //Copy the data in 2d Array
    for (iRow =0 ; iRow < nRow ; iRow++)
    {
        for (iCol =0 ; iCol < nColumn ; iCol++)
        {
            piBuffer[iRow][iCol] = 3;
        }
    }

    //Print the content of 2D array
    for (iRow =0 ; iRow < nRow ; iRow++)
    {
        for (iCol =0 ; iCol < nColumn ; iCol++)
        {
            printf("piBuffer[%d][%d] = %d\n",iRow, iCol,piBuffer[iRow][iCol]);
        }
    }
    freeAllocatedMemory(piBuffer,nRow);

    return 0;
}
