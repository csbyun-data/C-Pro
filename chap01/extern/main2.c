#include <stdio.h>
#include "cnt.h"

extern int iCnt;
extern void cnt();
extern void cnt2();

int main(int argc, char *argv[]) {
  iCnt = 10;

  inc();
  printf("global iCnt = %d\n", iCnt);

  inc();
  printf("global iCnt = %d\n", iCnt);
  printf("\n");

  inc2();
  printf("file outside siCnt = %d\n", siCnt);

  inc2();
  printf("file outside siCnt = %d\n", siCnt);

  siCnt++;
  printf("file outside siCnt = %d\n", siCnt);	
  
  return 0;
}
