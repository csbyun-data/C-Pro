// COS Pro1 5-3문제
// return int * 예제, malloc() 활용하지 않은

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void swap(int numbers[], int i, int j) {
	int tmp = numbers[i];
	numbers[i] = numbers[j];
	numbers[j] = tmp;
}

int compare(const void* a, const void* b) {
	return *(const int*)a - *(const int*)b;
}

int* solution(int numbers[], int numbers_len) {
	int* answer;

  qsort(numbers, numbers_len, sizeof(int), compare);
  int mid = (numbers_len - 1) / 2;
  swap(numbers, mid, numbers_len-1);

  int left = mid + 1;
  int right = numbers_len - 2;
  while(left <= right) {
  	swap(numbers, left, right);
  	left = left + 1;
   	right = right - 1;
  }

  answer = numbers;
  return answer;
}

int main() {
	int numbers[] = {7, 3, 4, 1, 2, 5, 6};
	int numbers_len = 7;
	int* ret = solution(numbers, numbers_len);

	for(int i = 0; i < numbers_len; i++) {
		if(i != 0)
			printf(", ");
		printf("%d", ret[i]);
	}
}

// solution 함수의 반환 값은 {1, 2, 3, 7, 6, 5, 4} 입니다.
