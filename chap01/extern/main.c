#include <stdio.h>
#include "cnt.h"

extern int iCnt;
extern void cnt();

int main(int argc, char *argv[]) 
{
  iCnt = 10;

  cnt();
  printf("iCnt = %d\n", iCnt);

  cnt();
  printf("iCnt = %d\n", iCnt);

  return 0;
}

/*
iCnt = 11
iCnt = 12
*/
