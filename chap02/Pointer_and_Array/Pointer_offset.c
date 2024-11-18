#include <stdio.h>
#include <stdlib.h>

int main()
{
  //create an array of structure;
  int aiData[] = {1,2,3,4,5};

  //Create two pointer to the integer
  int *piData1 = NULL;
  int *piData2 = NULL;

  int iOffset = 0;

  //Assign the address of array first element to the pointer
  piData1 = &aiData[0];

  //Assign the address of array third element to the pointer
  piData2 = &aiData[2];

  // Subtract the pointer
  iOffset = piData2 - piData1;

  printf("pointer offset  =  %d\n\n",iOffset);
    
  return 0;
}
