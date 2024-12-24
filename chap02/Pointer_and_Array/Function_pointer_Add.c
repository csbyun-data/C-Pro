  #include <stdio.h>
  #include <stdlib.h>

  int AddTwoNumber(int iData1,int iData2) {
    return (iData1 + iData2);
  }

  int main(int argc, char *argv[])
  {
    int iRetValue = 0;
    int (*pfAddTwoNumber)(int,int) = NULL;

    pfAddTwoNumber = AddTwoNumber;

    // iRetValue = pfAddTwoNumber(10, 20);
    iRetValue = (*pfAddTwoNumber)(10, 20);
    printf("\n\nAddition of two number = %d\n\n",iRetValue);

    return 0;
  }
