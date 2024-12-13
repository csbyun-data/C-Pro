// static 함수의 상태르 기록하기 위해 사용함
#include <stdio.h>

void inc() {
	static int cnt = 0;  //지역 변수 선언
	cnt++;
	printf("cnt = %d\n", cnt);
}
int main(int argc, char *argv[]) {
	
	inc();	// 1
	inc();	// 2
	inc();	// 3
	
	return 0;
}

/*
cnt = 1
cnt = 2
cnt = 3
*/
