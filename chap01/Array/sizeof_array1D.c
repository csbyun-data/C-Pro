// 배열의 이름 ints는 sizeof(ints) == sizeof(int)*6 -> 24 배열의 크기를 반환.
// ints는 배열의 첫번째 address를 가르킨다. &ints[0], address는 동일하지만 sizeof의 값은 다름

// *ints -> ints[0]를 표시한 것
// *(ints+1) -> ints[1]
// *(ints+2) -> ints[2] 

#include <stdio.h>
 
int main(void)
{
  int ints[] = {-2, 99, 0, -743, 2, 4};
  int num;
  int size = sizeof ints / sizeof *ints;
 
  for (int i = 0; i < size; i++) {
    num = *(ints + i);
    printf("%5d, %5d \n", ints[i], num);
  }
}
