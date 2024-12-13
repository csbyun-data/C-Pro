// cnt.c code
#include "cnt.h"

void cnt() {
	iCnt++;
}

void inc() {
	iCnt++;
}

void inc2() {
	siCnt++;
	printf("local siCnt = %d\n", siCnt);
}
