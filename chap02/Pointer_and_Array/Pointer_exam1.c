#include <stdio.h>

int main(void)
{
  int data = 20;     // declaration of variable
  int *iPtr = NULL;  // declaration of pointer
  iPtr = &data;      // assign address of data to the pointer

  // address sotred in pointer
  printf("address of data: %p \n\n", iPtr);
  
  // read value from the stored address with help of pointer
  printf("value of *iPtr = %d \n\n", *iPtr);
  
  // assign value to the stored address with help of pointer
  *iPtr = 5;

  // again read value from the stored address with help of pointer
  printf("New value of *iPtr = %d\n\n", *iPtr);
  printf("data = %d\n\n", data);

  return 0;
}
