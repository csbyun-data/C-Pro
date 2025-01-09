// 정수형, 문자 1자만 조건 처리 가능

#include <stdio.h>

void func1() {;}
void func2() {;}

int main()
{
  int num;
  
  printf("num : ");
  scanf("%d", &num);
  switch( num) {
  case 1:
    func1();
    break;
  case 2:
    func2();
    break;
  case 3:
  case 4:
  case 5:
    // condition 3, 4, 5 running
    break;
  default:
    break;
  }
  getchar();
  
  return 0;
}
