//type 명령어와 동일한 프로그램 
//getc()함수를 활용한 예, 파일에서 한문자씩 읽어 들임
#include <stdio.h>
int main(int argc, char *argv[]) 
{
  FILE *fp;
  char c;
  
  if (argc == 1) { 
    printf("USAGE : %s filename(1) ...filename(n)\n",*argv);
    return (1);
    }

  while (--argc > 0) { 
    if ((fp = fopen(*++argv, "r")) == NULL) {
      printf("Error: Cannot open %s\n",*argv);
      continue;
      }
    
  printf("\n*** %s ***\n",*argv);
  while ((c = getc(fp)) != EOF)
    putchar(c);
  }
  fclose(fp);
}
