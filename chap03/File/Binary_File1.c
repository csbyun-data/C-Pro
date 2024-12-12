// Text파일, Binary파일 사용법 중 Binary파일
// Binary file I/O fread and fwrite

// size_t fread(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file)
// size_t fwirte(const void *ptr, size_t size_of_elements, size_t numbeR_of_elements,
// FILE *a_file)

#include <stdio.h>

int main()
{
  FILE *fp;

  char x[10] = "ABCDEFGHI";

  fp = fopen("test.bin", "wb");

  if(fp != NULL) {
    fwrite(x, sizeof(x[0]), sizeof(x)/sizeof(x[0]), fp);
  } else {
    printf("Failed file open!\n");
  }
  fclose(fp);

  return 0;
}
