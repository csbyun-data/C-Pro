#include <stdio.h>
#pragma pack(push, 1)
typedef struct {
  double A; // 8-byte
  char B; // 1-byte
} InfoData;
#pragma pack(pop)

int main(int argc, char *argv[])
{
    printf("\n Size of Structure = %d\n",sizeof(InfoData));
    return 0;
}
// 9
