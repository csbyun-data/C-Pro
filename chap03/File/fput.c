// https://aticleworld.com/file-handling-in-c/
// writing A-Z in the newly created file (abc.txt)  using the fputc function.

#include <stdio.h>

int main()
{
  int ch = 0;
  FILE *fp = NULL;
  fp = fopen("abc.txt", "w");
  if( fp == NULL) {
    printf("Error in creating the file\n");
    exit(1);
  }

  for( ch=65; ch <= 90; ++ch) {
    fputc(ch, fp);
  }
  fclose(fp);

  printf("A to Z written to the created file\n");

  return 0;
}
