//배열30을 넘는 문자 주소를 해결하기 위해 변경
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

// A structure to store employee information
typedef struct EmpInformation {
  int Emp_id;
  int Salary;
  char Address[];
} sEmpInformation;

typedef sEmpInformation* psEmpInformation;

//Note use string function carefully
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

int main()
{
  psEmpInformation Amlendra = ComposeEmpInfo(210013,1,"Preet vihar street-abcd ,\
                                             block abcxyz, \
                                             New Delhi,\
                                             India");
  if(Amlendra != NULL) {
    printEmpInfo(Amlendra);
    free(Amlendra);
  }
  Amlendra = NULL;
  psEmpInformation Aticleworld = ComposeEmpInfo(13,200013, "New Delhi, India");
  
  if(Aticleworld != NULL) {
    printEmpInfo(Aticleworld);
    free(Aticleworld);
  }

  return 0;
}

output:
Emp_id : 1      Salary : 210013  Address: Preet vihar street-abcd , block abcxyz, New Delhi, India
Emp_id : 200013 Salary : 13      Address: New Delhi, India
