#include<string.h>
#include<stdio.h>
#include<stdlib.h>

// A structure to store employee information
typedef struct EmpInformation {
  int Emp_id;
  int Salary;
  char Address[0];
} sEmpInformation;

typedef sEmpInformation* psEmpInformation;

// Allocate the memory and initialize the structure
psEmpInformation ComposeEmpInfo( int salary,int id, const char *pcAddress) {
  // Allocating memory as per the requirements
  psEmpInformation psEmpInfo = (struct EmpInformation *)malloc( sizeof(*psEmpInfo) + sizeof(char) * strlen(pcAddress) + 1);
  if(psEmpInfo != NULL) {
    psEmpInfo->Emp_id = id;
    psEmpInfo->Salary = salary;
    strcpy(psEmpInfo->Address, pcAddress);
  }
  return psEmpInfo;
}

// Print student details
void printEmpInfo(psEmpInformation psEmpInfo) {
    printf("Emp_id : %d \
            Salary : %d  \
            Address: %s\n",
           psEmpInfo->Emp_id,psEmpInfo->Salary,psEmpInfo->Address);
}

// Driver main Code
int main()
{
  //variable to store information more than 30 bytes
  psEmpInformation Amlendra = ComposeEmpInfo(1,100013, "Preet vihar street-abcd ,block abcxyz, New Delhi, India");
  if(Amlendra != NULL) {
    printEmpInfo(Amlendra);
    free(Amlendra);
  }
  
  //variable to store information less than 30 bytes
  psEmpInformation Aticleworld = ComposeEmpInfo(13,200013, "New Delhi, India");
  if(Aticleworld != NULL) {
      printEmpInfo(Aticleworld);
      free(Aticleworld);
  }
  return 0;
}
