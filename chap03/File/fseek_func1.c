// https://aticleworld.com/file-handling-in-c/

#include <stdio.h>

int main() 
{
  FILE *fp = NULL;
  int ch = 0;

  fp = fopen("abc.txt", "r");
  if( fp == NULL) {
    printf("Error in opening the file\n");
    exit(1);
  }
  
  // Shift file position indicator by 1
  fseek(fp, 1, SEEK_SET);

  // Read 1 character
  ch = fgetc(fp);

  printf(" %c\n", ch);
  fclose(fp);

  return 0;
}
