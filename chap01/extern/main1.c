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

/* 
global iCnt = 11  <- 전역 변수증가
global iCnt = 12  <- 전역 변수증가

cnt.c siCnt = 11   <- cnt.c 지역 static 변수 증가
main.c siCnt = 10  <- main.c 지역 static 변수
cnt.c siCnt = 12   <- cnt.c 지역 static 변수 증가
main.c siCnt = 10  <- main.c 지역 static 변수 
main.c siCnt = 11  <- main.c 지역 static 변수 증가
*/
