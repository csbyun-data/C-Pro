#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char Name[12];
  int Age;
  float Weight;
  int RollNumber;
} sStudentInfo;

int main(int argc, char *argv[])
{
  //create an array of structure;
  sStudentInfo aiData[2] = {0};
  //Create two pointer to the integer
  sStudentInfo *piData1 = NULL;
  sStudentInfo *piData2 = NULL;
  int iSizeofStructure = 0;

  //Assign the address of array first element to the pointer
  piData1 = &aiData[0];
  //Assign the address of array third element to the pointer
  piData2 = &aiData[1];

  // Subtract the pointer
  iSizeofStructure = (char*)piData2 - (char *)piData1;
  printf("Size of structure  =  %d\n\n",iSizeofStructure);
}

//output:
//Size of structure  =  24
