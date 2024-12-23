#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare( const void *a, const void *b) {
  return *(const int*)a - *(const int*)b;
}

int *solution( int numbers[], int numbers_len) {
  int *answer;

  qsort( numbers, numbers_len, sizeif(int), compare);

  answer = numbers;
  return answer;
}

int main() {
  int numbers[] = { 7, 3, 4, 1, 2, 5, 6};
  int numbers_len = 7;
  // int numbers_len = sizeof numbers / sizeif *numbers; , 갯수를 구함 다른 표현식
  
  int *ret = solution(numbers, numbers_len);

  for( int i=0; i < numbers_len; i++) {
    if( i != 0)
      printf(", ");
    printf("%d", ret[i]);
  }
}
