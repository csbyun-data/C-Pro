// https://aticleworld.com/file-handling-in-c/
// Text파일 fopen 사용 예

#include <stdio.h>

int main()
{
  FILE *fp=NULL;

  fp = fopen("abc.txt", "w");
  if( fp==NULL) {
    printf("File is not created\n");
    exit(1);
  } else {
    printf("File is created\n");
  }

  fclose(fp);

  return 0;
}   
  
