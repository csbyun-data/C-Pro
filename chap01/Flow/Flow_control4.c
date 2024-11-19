#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int i = 1;
  
	while(i <= 10) {
    if( i == 5) {
	   	i++;
			continue;
		}
	  printf("%d", i);    //1, 2, 3, 4, 6, 7 출력
	  
    if( i == 7) break;
	  i++;
	}
  return 0;
}
