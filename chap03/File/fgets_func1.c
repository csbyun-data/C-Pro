// https://aticleworld.com/file-handling-in-c/
// fgets()

#include <stdio.h>

#define MAX_SIZE 32

int main()
{
  FILE *fp = NULL;
  char readFileData[MAX_SIZE] = {0};

  fp = fopen("abc.txt", "r");
  if( fp == NULL) {
    printf("Error in reading the file\n");
    fclose(fp);
    exit(1);
  }
  puts(readFileData);

  fclose(fp);
  printf("Read file successfully\n");

  return 0;
}
