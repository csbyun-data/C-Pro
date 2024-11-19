#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // int i;
    // for( i=1; i <= 9; i++)
    // [Error] 'for' loop initial declarations are only allowed in C99 or C11 mode
    // [Note] use option -std=c99, -std=gnu99, -std=c11 or -std=gnu11 to compile your code
	for(int i=1; i <= 9; i++) {
		if(i == 5) continue;
		printf("%d", i);	//1, 2, 3, 4, 6, 7 출력 
		if(i == 7) break;
	}
	return 0;
}
