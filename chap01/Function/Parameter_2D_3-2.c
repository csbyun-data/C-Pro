// 열만 2D배열의 매개변수로 전달
#include <stdio.h>
const int N = 3;
 
void print(int arr[][N], int m)
{
    int i, j;
    for (i = 0; i < m; i++)
      for (j = 0; j < N; j++)
        printf("%d ", arr[i][j]);
}
 
int main()
{
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int irow = 3
    print(arr, irow);
    return 0;
}
