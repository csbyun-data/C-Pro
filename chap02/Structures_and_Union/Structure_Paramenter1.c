// Pizza 구조체
// 구조체 포인터를 compare_a(), compare_b()함수의 parameter로 전달
// 배열을 solution()함수에 전달

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Pizza {
  int size;
  int price;
}Pizza;

int compare_a(const void *a, const void *b) {
  Pizza first = *(Pizza *)a;
  Pizza second = *(Pizza *)b;
  if(first.size > second.size)
    return -1;
  else if(first.size < second.size)
    return 1;
  else
    return 0;
}

int compare_b(const void *a, const void *b) {
  Pizza first = *(Pizza *)a;
  Pizza second = *(Pizza *)b;
  if(first.price < second.price)
    return -1;
  else if(first.price > second.price)
    return 1;
  else
    return 0;
}

// 문제점 : Pizza 배열을 메모리 할당하고 풀어주지 않음
int* solution(int size[], int size_len, int price[], int price_len) {
  int* answer = (int *)malloc(sizeof(int) * 2);
  
  int len = size_len;
  Pizza* pizzas = (Pizza *)malloc(sizeof(Pizza) * len);
  
  for(int i = 0; i < len; i++) {
    pizzas[i].size = size[i];
    pizzas[i].price = price[i];
  }

  //pizzas의 제일 큰것의 size를 받음
  qsort(pizzas, len, sizeof(Pizza), compare_a);
  answer[0] = pizzas[0].size;

  // pizzas의 제일 싼 가격을 받음
  qsort(pizzas, len, sizeof(Pizza), compare_b);
  answer[1] = pizzas[0].price;

  // integer 배열 포인터를 return
  return answer;
}


int main() {
  int size[] = {10, 20, 30, 40};
  int size_len = 4;
  int price[] = {3, 1, 5, 4};
  int price_len = 4;
  int* ret = solution(size, size_len, price, price_len);
  
  printf("Ret Value는 {%d, %d} .\n", ret[0], ret[1]);

  // 할당 배열을 풀어줌
  free(ret);
}
