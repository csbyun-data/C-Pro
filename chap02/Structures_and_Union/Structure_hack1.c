#include <stdio.h>

// Structure in c
typedef struct {
  int RollNumber; //Size of int 4 bytes
  float Fees; //Size of float 4 bytes
  int TotalMarks; //Size of int 4 bytes
  char Name[0]; //Size of int 0 bytes
} sStudentInfo;

int main()
{
  printf("Size of structure = %d\n",sizeof(sStudentInfo));

  return 0;
}
// output:
// Size of structure = 12
