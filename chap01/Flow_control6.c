#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i = 1;
  
	do {
		i++;
		if( i == 5) continue;
		printf("%d", i);	//2,3,4,6,7 출력 
		if(i == 7) break;
	} while(i <= 10);
  
	return 0;
}
