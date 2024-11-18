#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int Age;
  float Weight;
} sInfo;

int main()
{
  //create an array of structure;
  sInfo JhonFamilyInfo[2];
  
  //Create pointer to the structure
  sInfo *psInfo  = NULL;
  int iSizeofStructure = 0;
  
  //Assign the address of array to the pointer
  psInfo = JhonFamilyInfo;
  
  // Subtract the pointer
  iSizeofStructure = (char*)(psInfo + 1) - (char*)(psInfo);
  printf("Size of structure  =  %d\n\n",iSizeofStructure);
    
  return 0;
}
