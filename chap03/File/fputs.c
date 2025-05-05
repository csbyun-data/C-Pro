// https://aticleworld.com/file-handling-in-c/
#include <stdio.h>

int main()
{
  FILE *fp = NULL;
  fp = fopen("abc.txt", "w");
  if( fp == NULL) {
    printf("Error in creating the file\n");
    exit(1);
  }
  fputs("Hello There, I hope this article will help!", fp);
  fclose(fp);

  printf("File has been created successfully\n");

  return 0;
}
