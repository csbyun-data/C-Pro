//두개의 구조체 배열에서 뒷배열과 앞배열의 차이를 구함
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
  sStudentInfo RamInfo[2] = {0};
  
  //Create pointer to the structure
  sStudentInfo *psInfo  = NULL;
  int iSizeofStructure = 0;
    
  //Assign the address of array to the pointer
  psInfo = RamInfo;
  
  // Subtract the pointer
  iSizeofStructure = (char*)(psInfo + 1) - (char*)(psInfo);
  printf("Size of structure  =  %d\n\n",iSizeofStructure);
    
  return 0;
}

//output:
//Size of structure  =  24
