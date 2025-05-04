// https://aticleworld.com/file-handling-in-c/
// Example code to explain the working of fprintf function
// ask the student name 3 times and writes them to abc.txt

#include <stdio.h>

int main() 
{
  FILE *fp = NULL;
  int i = 0;
  char name[40] = {0};

  fp = fopen("abc.txt", "w");
  if( fp = NULL) {
    printf("File is not creaded\n");
    exit(1);
  }
  // three times asking for student name
  for( i=1; i<4; i++) {
    puts("Enter the student name: ");
    gets(name);
    fprintf("fp, "%d. Name = [%s]\n", i, name);
  }
  fclose(fp);

  return 0;
}
