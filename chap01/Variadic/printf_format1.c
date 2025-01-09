#include <stdio.h>

int main()
{
  double num = 3.141592;
  
  for(int i=2; i<7; i++)
    printf("%.*f\n", i, num);
}
