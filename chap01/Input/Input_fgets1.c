// stream : 순서를 가진 연속된 문자열
#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *ptr;

  ptr = (char *)malloc(sizeof(char)*50);
  fputs("input String : ", stdout);  // stdout 표준촐력 stream 

  if(fgets(ptr, 50, stdin) != NULL)  // stdin 표준입력 stream 
    fputs(ptr, stdout);            // stderr 표준에러 stream
    free(ptr);

  return 0;
}
