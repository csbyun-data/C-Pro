//Using the default packing of compiler

#include <stdio.h>

typedef struct {
  double A; // 8-byte
  char B; // 1-byte
  char C;   // 1-byte
} InfoData;

int main(int argc, char *argv[])
{
    printf("\n Size of Structure = %d\n",sizeof(InfoData));
    
    return 0;
}

// 16
