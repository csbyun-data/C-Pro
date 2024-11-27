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
    int nRow = 0; //variable store number of Row
    int iRow = 0; //Variable for looping Row
    int iCol = 0; //Variable for looping column

    printf("\nEnter the number of Row = ");
    scanf("%d",&nRow); //Get input for number of Row

    //Allocate memory for row
    piBuffer = (int **)malloc(nRow * sizeof(int *));
    //Check memory validity
    if(piBuffer == NULL)
      return FAIL;

    //Allocate memory for column
    for (iRow =0 ; iRow < nRow ; iRow++) {
        piBuffer[iRow] = (int *)malloc((iRow+1) * sizeof(int));
        //Check memory validity
        if(piBuffer[iRow] == NULL) {
            freeAllocatedMemory(piBuffer,iRow);
            return FAIL;
        }
    }

    //Copy the data in 2d Array
    for (iRow =0 ; iRow < nRow ; iRow++) {
        for (iCol =0 ; iCol <= iRow ; iCol++)
          piBuffer[iRow][iCol] = 27;
    }

    //Display the stored data
    for (iRow =0 ; iRow < nRow ; iRow++) {
        for (iCol =0 ; iCol <= iRow ; iCol++)
          printf("\npiBuffer[%d][%d] = %d\n",iRow, iCol,piBuffer[iRow][iCol]);
    }
  
    //Free Allocated memory
    freeAllocatedMemory(piBuffer,iRow);

    return 0;
}
