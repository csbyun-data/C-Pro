//fgetc, fputc 함수를 활용한 file 복사 프로그램
// fcopy a.exe b.exe

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *srcfp, *objfp;
  int ch;
  
  if (argc != 3) {
    printf("USAGE : %s sourcefile objectfile\n",*argv);
    exit(-1);
  }
  
  if ((srcfp = fopen(argv[1], "rb")) == NULL) {
    printf("File open error : %s\n\a",argv[1]);
    exit(-1);
  }
  
  if ((objfp = fopen(argv[2], "wb")) == NULL) {
    printf("File creation error : %s\n\a",argv[2]);
    exit(-1);
  }
  
  printf("FileCopy %s to %s\n\n",argv[1],argv[2]);
  while ((ch = fgetc(srcfp)) != EOF)
    fputc(ch,objfp);
  
  fclose(srcfp);
  fclose(objfp);
}
