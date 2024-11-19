#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i;
	
  for( i=1; i <= 9; i++)
  {
    if(i == 5) continue;
	  printf("%d", i);	//1, 2, 3, 4, 6, 7 출력 
    if(i == 7) break;
  }
  return 0;
}
