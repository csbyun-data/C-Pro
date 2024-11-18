#include <stdio.h>

typedef  int (*pfunctPtr)(int, int); /* function pointer */

int ArithMaticOperation(int iData1,int iData2, pfunctPtr Calculation) {
  int iRet =0;
  iRet = Calculation(iData1,iData2);
  
  return iRet;
}

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
  int iData1 = 0, iData2 = 0;
  int iChoice = 0;
  int Result = 0;

  printf("Enter two Integer Data \n");
  scanf("%d%d",&iData1,&iData2);
  printf("Enter number for Addition(1), Subtraction(2), Multiplication(3) \n");
  printf("User choice :");
  scanf("%d",&iChoice);
  
  switch(iChoice) {
  case 1:
      Result = ArithMaticOperation(iData1,iData2,Add);
      break;
  case 2:
      Result = ArithMaticOperation(iData1,iData2,Sub);
      break;
  case 3:
      Result = ArithMaticOperation(iData1,iData2,Mul);
      break;
  default:
      printf("Enter Wrong Choice\n");
  }
  printf("Result  = %d\n",Result);
  
  return 0;
}
