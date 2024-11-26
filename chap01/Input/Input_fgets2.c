// char *fgets(char *str, int size, FILE* file);
#include <stdio.h>
#include <stdlib.h>

int main()
{
  char string[256];
	
  printf("enter a string : ");
  fgets(string, 256, stdin);  // stdin 표준입력 stream 
	
  // newline character('\n')를 제거하고 문자열 끝에 null terminator '\0' 입력 
  for(int i=0; i<256; i++) {
	  if(string[i] == '\n') {
	    string[i] = '\0';
	    break;
    }
  }

  printf("string : %s", string);
  getchar();
	
  return 0;
}
