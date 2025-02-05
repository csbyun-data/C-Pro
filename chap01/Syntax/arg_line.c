#include <stdio.h>
#include <stdlib.h>

unsigned int    linenum = 20;

/*
**  Get the number of lines to display at the "tail" of each file from
**  the command line.
*/

void getlinenum(int n, char * str[])
{
  for (--n; n; --n) {
    ++str;
    if ((**str == '/') || (**str == '-')) {
      linenum = atoi(*(str) + 1);
      if (linenum <= 0)
        linenum = 20;
    }
  }
}

int main(int argc, char **argv)
{
  getlinenum(argc, argv);

  printf("linenum = %d\n", linenum);
  return EXIT_SUCCESS;
}
