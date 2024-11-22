#include <stdio.h>

// Maximum size of the array
#define MAX_SIZE 32

int main() {
  FILE *fp=NULL;
  char readFileDaa[MAX_SIZE+MAX_SIZE] = {0}

  fp = fopen("abc.txt", "r");
  if( fp==NULL) {
    printf("Error in creating the file\n");
  }

  // read file data
  fscanf(fp, "%s", readFileData);

  // display read data
  puts(readFileData);

  fclose(fp);

  printf("Read file successfully\n");

  return 0;
}
