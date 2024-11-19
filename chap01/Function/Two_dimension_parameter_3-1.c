// 고정된 행과 열을 2D배열의 매개변수로 전달
#include <stdio.h>
const int M = 3;
const int N = 3;
 
void print(int arr[M][N]) {
  int i, j;
  for (i = 0; i < M; i++)
    for (j = 0; j < N; j++)
      printf("%d ", arr[i][j]);
}
 
int main()
{
  int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  print(arr);
  return 0;
}
