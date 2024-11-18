#include <stdio.h>

typedef  int (*pfunctPtr)(int, int); /* function pointer */

int Add(int iData1,int iData2) {
  return (iData1 + iData2);
}

int Sub(int iData1,int iData2) {
    return (iData1 - iData2);
}

int Mul(int iData1,int iData2) {
    return (iData1 * iData2);
}

//Return function pointer
pfunctPtr ArithMaticOperation(int iChoice) {
  //function pointer
  pfunctPtr pArithmaticFunction = NULL;
  switch(iChoice) {
  case 1:
      pArithmaticFunction = AddTwoNumber;
      break;
  case 2:
      pArithmaticFunction = SubTwoNumber;
      break;
  case 3:
      pArithmaticFunction = MulTwoNumber;
      break;
  }
  return pArithmaticFunction;
}

int main()
{
  int iData1 = 0, iData2 = 0;
  int iChoice = 0;
  int Result = 0;

  pfunctPtr pArithmaticFunction = NULL; //function pointer

  printf("Enter two Integer Data \n");
  scanf("%d%d",&iData1,&iData2);
  printf("Enter number for Addition(1), Subtraction(2), Multiplication(3) \n");
  printf("User choice :");
  scanf("%d",&iChoice);
  
  pArithmaticFunction = ArithMaticOperation(iChoice);

  // verify the pointers
  if ( pArithmaticFunction != NULL ) {
    Result = (*pArithmaticFunction)(iData1, iData2);
    printf("Result  = %d\n",Result);
  } else {
    printf("Please enter the valid choice\n");
  }
  
  return 0;
}
