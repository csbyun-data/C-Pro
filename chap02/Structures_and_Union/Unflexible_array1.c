#include<string.h>
#include<stdio.h>
#include<stdlib.h>

// A structure to store employee information
typedef struct EmpInformation {
  int Emp_id;
  int Salary;
  char Address[30];
} sEmpInformation;

typedef sEmpInformation* psEmpInformation;

// Allocate the memory and initialize struct EmpInformation
psEmpInformation ComposeEmpInfo( int salary,int id, const char *pcAddress) {
  // Allocating memory for sEmpInformation
  psEmpInformation psEmpInfo = (struct EmpInformation *)malloc(sizeof(*psEmpInfo));

  if(psEmpInfo != NULL) {
    psEmpInfo->Emp_id = id;
    psEmpInfo->Salary = salary;
    strcpy(psEmpInfo->Address, pcAddress);
  }
  return psEmpInfo;
}

// Print Employee details
void printEmpInfo(psEmpInformation psEmpInfo) {
  printf("Emp_id : %d \n\
          Salary : %d  \n\
          Address: %s\n",
          psEmpInfo->Emp_id,psEmpInfo->Salary,psEmpInfo->Address);
}

int main()
{
  psEmpInformation Aticleworld = ComposeEmpInfo(210013,1, "Delhi, India");
  if(Aticleworld != NULL) {
    printEmpInfo(Aticleworld);
    free(Aticleworld);
  }

  return 0;
}

// output:
// Emp_id : 1
// Salary : 210013
// Address: Delhi, India
