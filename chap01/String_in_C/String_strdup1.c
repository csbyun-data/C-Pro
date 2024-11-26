//문자열 복사 기능, strdup() 함수
#include <stdio.h>
#include <stdlib.h>

#include <conio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	
	char *ap = "ABCD";
	char *bp;
	
//  bp = (char*)malloc(strlen(ap)+1); strcpy(bp, ap); 
	bp = strdup(ap);
	
	puts(ap);
	puts(bp);
	
	printf("ap = %u, bp=%u \n", ap, bp);
	
	// strdup로 문자열을 복사한 경우 메모리 free를 해야함 
	free(bp);
	
	return 0;
}
