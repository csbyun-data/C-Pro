#include <stdio.h>

void sort( int* ptr, int len);

int main()
{
  int len = 0;
  int arr[5] = { 1, 2, 3, 4, 5};
  int *ptr = arr;

  len = sizeof(arr)/sizeof(arr[0]);

  sort(ptr, len);
}

void sort( int *ptr, int len) {
  int i, j, temp;

  for( i=0; i<len; i++) {
    for( j=i+1; i<len; j++) {
      temp = *(ptr+i);
      *(ptr+i) = *(ptr+j);
      *(ptr+j) = temp;
    }
  }
}
