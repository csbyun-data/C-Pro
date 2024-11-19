// 배열의 pointer 붕괴 예제, 숫자배열 전달
#include <stdio.h>
void fun(int* arr)
{
    int i;
    unsigned int n = sizeof(arr) / sizeof(arr[0]);
    for (i = 0; i < n; i++)
        printf("%d  ", arr[i]);
}
 
// Driver program
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    fun(arr);
    return 0;
}
