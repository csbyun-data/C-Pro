// longjmp()가 실행되면 setjmp()로 이동함,
// https://www.tutorialspoint.com/c_standard_library/c_function_longjmp.htm
#include <stdio.h>
#include <string.h>
#include <setjmp.h> // setjmp(), longjmp()

#define TRUE 1
#define FALSE 0

jmp_buf jmpbuf;
char password[32];

void check_size(){
  if(strlen(password)< 8) 
    longjmp(jmpbuf, 1); // -> setjmp로 1 전달
}

void is_possible_word(){
  int i;
  for( i=0; i<strlen(password); i++) {
    if(password[i] == '|' || password[i] == '%' || password[i] == '&') 
      longjmp(jmpbuf,2); // -> setjmp로 2전달
  }
}

void verify_input(){
  check_size();
  is_possible_word();
}

int main(){
  int ret = 0;
  if( (ret = setjmp(jmpbuf)) > 2){  // setjmp는 나중에 longjmp를 통해서 점프되었을때실행되는 부분
                                    // longjmp에서 두번째 인자 val이 ret값이 됨. 
    printf("unknown option\n");
    return -1;
  } else {
    switch(ret){
      case 1:
        printf(" len() >= 8.\n");
        break;
      case 2:
        printf("|, %%, & 사용불가.\n");
        break;
    }
  }

  printf("password:");
  scanf("%s",password);

  verify_input();
  
  return 0;
}
