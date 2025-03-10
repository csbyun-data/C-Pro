// https://github.com/vonj/snippets.org/blob/master/cmdline.c
/*
**  CMDLINE.C - Demonstrates accessing command line arguments
*/

#include <stdio.h>
#include <stdlib.h>

/*
**  Macros to print proper plurals by Bob Stout
*/

#define plural_text(n) &"s"[(1 == (n))]
#define plural_text2(n) &"es"[(1 == (n)) << 1]
#define plural_text3(n) &"y\0ies"[(1 != (n)) << 1]


int main(int argc, char *argv[])
{
  int i, n = argc - 1;

  printf("You passed %d argument%s on the command line.",
        n, plural_text(n));

  if (argc > 1) {
    puts(" They are:");
    for (i = 1; i < argc; ++i) {
      printf("\nArgument #%d:\n  Text: \"%s\"\n  Value: %d\n",
            i, argv[i], atoi(argv[i]));
    }
  }
  else  putchar('\n');
  return 0;
}
