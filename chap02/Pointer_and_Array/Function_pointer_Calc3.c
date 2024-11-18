#include <stdio.h>
#include <stdlib.h>

int Add(int iData1,int iData2) {
  return (iData1 + iData2);
}

int Sub(int iData1,int iData2) {
    return (iData1 - iData2);
}

int Mul(int iData1,int iData2) {
    return (iData1 * iData2);
}

int main()
{
  int iRetValue = 0;
  //Declaration of array of function pointer
  int (*apfArithmatics [3])(int,int) = {Add, Sub, Mul};

  // Calling the add function using index of array
  iRetValue = (*apfArithmatics[0])(20, 10);  // Add
  iRetValue = (*apfArithmatics[1])(20, 10);  // Sub
  iRetValue = (*apfArithmatics[2])(20, 10);  // Mul

  printf("multiplication of two number = %d\n", iRetValue);
  
  return 0;
}
