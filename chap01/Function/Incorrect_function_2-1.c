// C Program to demonstrate incorrect usage of sizeof() for arrays
// 함수로 배열이 매개변수로 전달되면 포인터로 처리되어 문제점 발생됨
// 배열 매개변수에 sizeof 사용하지 말것
// https://www.geeksforgeeks.org/using-sizof-operator-with-array-paratmeters-in-c/

#include <stdio.h>
 
void fun(int arr[])
{
  int i;
 
  // sizeof should not be used here to get number of elements in array
  // sizeof(int *)/sizeof(int) 
  int arr_size = sizeof(arr) / sizeof(arr[0]);      // (주소 Size)/(Int size) -> 8/4
 
  for (i = 0; i < arr_size; i++) {
    arr[i] = i;
  }
  // executed two times only
}
 
// Driver Code
int main()
{
  int i;
  int arr[4] = { 0, 0, 0, 0 };
  fun(arr);
 
  // use of sizeof is fine here
  for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
      printf(" %d ", arr[i]);
 
  getchar();
}
