#include <stdio.h>

int main() 
{
  int aiData[3] = { 100, 200, 300 };

  // assigned first element address to the void pointer
  void *pvData = &aiData[0];  // aiData == aiData[0]

  printf(" pvData = %lu\n", pvData);
  printf(" pvData+1 = %lu , incorrect\n", pvData+1);
  printf(" pvData+1 = %lu , correct\n", (int *)pvData+1);

  return 0;
}
