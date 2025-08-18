#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000000

long sum_idx( long a[], long n);
long sum_ptr( long a[], long n);

long a[SIZE] = {1};
  
int main() {
  
  clock_t start, end;

  
  start = clock();
  sum_idx(a, SIZE);
  end = clock();
  printf("sum_idx = %lf sec\n", (double)(end-start)/CLOCKS_PER_SEC);

  start = clock();
  sum_ptr(a, SIZE);
  end = clock();
  printf("sum_ptr = %lf sec\n", (double)(end-start)/CLOCKS_PER_SEC);
  
}

// index 표기법, 느림, index를 주소로 변한 후 값을 가져 옴
long sum_idx( long a[], long n) {  
  long i, sum=0;

  for ( i=0; i<n; i++)
    sum += a[i];

  return sum;
}

// pointer 사용, 빠름
long sum_ptr( long a[], long n) {  
  long i, sum=0;
  long *p;

  p = a;
  for ( i=0; i<n; i++)
    sum += *p++;

  return sum;
}
