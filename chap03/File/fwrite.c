// https://aticleworld.com/file-handling-in-c/
// Example code of fwrite

#include <stdio.h>

// Maximum size of the array
#define MAX_SIZE 32

int main()
{
  FILE *fp = NULL;
  char buffer[MAX_SIZE] = {0};

  fp = fopen("abc.txt", "w");
  if( fp == NULL) {
    printf("Error in creating the file\n");
    exit(1);
  }

  fwrite(buffer, sizeof(buffer[0]), MAX_SIZE, fp);
  fclose(fp);

  printf("File has been created successfully\n");

  return 0;
}
