// xlisp.c main() 함수 부분

#include <stdio.h>
#include <string.h> // strcmp()
#include <stdlib.h> // exit()
#include <setjmp.h>
#include <stdbool.h>

jmp_buf jmpbuf;

xlfail(char *err);
fexit();

int main(int argc, char *argv[])
{
  char str[100];
  
  while( true) {
    setjmp(jmpbuf);
    
    printf("문자열 입력(종료:exit) : ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str,"\n")] = '\0';
    
    if (strcmp(str, "exit") == 0 )
      fexit();
    else {
      // xlread();
      // xleval();
      // xlprint();
      
      xlfail(str);
    }
  }
  return 0;
}

/* xlfail - error handling routine */
xlfail(char *err) {
    /* print the error message */
    printf("error: %s\n",err);

    /* restart */
    longjmp(jmpbuf,1);
}

/* fexit - get out of xlisp */
fexit() {
	printf("프로그램 종료.\n");
  exit(1);
}
