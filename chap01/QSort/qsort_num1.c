#include <stdio.h>
#include <stdlib.h>

int compare (const int *a, const int *b) {
  return (*a - *b);  // asending
}

int main() {
  int N[10] = { 21, 10, 41, 33, 25, 17, 68, 27, 14, 29 };

  // 배열 주소, 요소 갯수, 요소 크기, 기준 함수
  qsort ( N, 10, sizeof(int), compare);

  for (int i=0; i < 10; i++) 
    printf("[%d] ", N[i]);

  return 0;
}
