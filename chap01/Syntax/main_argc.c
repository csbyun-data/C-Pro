// argc 명령인자의 갯수 인수갯수가 없을때 기본값=1
// 명령줄 인수를 저장하는 char 포인터 배열 argv[]

// C Program to illustrate the main function with command line arguments
#include <stdio.h>
 
int main(int argc, char* argv[])
{
  // printing the coundt of arguments
  printf("The value of argc is %d\n", argc);

  // prining each argument
  for (int i = 0; i < argc; i++)
    printf("%s \n", argv[i]);

  return 0;
}
