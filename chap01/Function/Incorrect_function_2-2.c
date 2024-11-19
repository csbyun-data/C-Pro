// 배열의 pointer 붕괴 예제, 배열을 매개변수로 전달한 후 크기 확인
// C program to pass the array as a function and check its size
#include <stdio.h>
#include <stdlib.h>
 
// Note that arr[] for fun is just a pointer even if square
// brackets are used. It is same as
// void fun(int *arr) or void fun(int arr[size])
void func(int arr[8]) {
  printf("Size of arr[] in func(): %d bytes", sizeof(arr));
}
 
int main()
{
  int arr[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
 
  printf("Size of arr[] in main(): %dbytes\n", sizeof(arr));
  func(arr);
 
  return 0;
}
