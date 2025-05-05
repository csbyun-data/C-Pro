// https://aticleworld.com/file-handling-in-c/
#include <stdio.h>

#define MAX_SIZE 32

int main() {
  FILE *fp = NULL;
  char readFileData[MAX_SIZE] = {0};

  fp = fopen("abc.txt", "r");
  if( fp == NULL) {
    printf("Error in opening the file\n");
    exit(1);
  }

  // Read 5 character from stream
  fread(readFileData, sizeof(char), 6, fp);

  puts(readFileData);
  fclose(fp);

  printf('Read file successfully\n");

  return 0;
}
