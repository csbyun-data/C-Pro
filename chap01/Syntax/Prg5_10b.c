/*Prg5_10b - Display the Environment 
  by Stephen R. Davis, 1987 

  Display the entire current environment. Use the environment 
  pointer passed to us in main(). 
*/

#include <stdio.h> 
/*Main - dump the environment on the screen*/ 
void main (argc, argv, envptr) 
  unsigned argc; 
  char *argv[]; 
  char *envptr[];   
{
  unsigned count; 
  count = 0; 
  while (*envptr[0]) {
    printf ("entry %d: %s\n", count++, envptr[0]); 
    envptr++; 
  }
}
