// 문자열 받아들이는 란은 배열로 선언하여 사용

#include <stdio.h>

int main()
{
  int age;
  char name[10];
  char address[50];

  printf("input name, age : ");
  scanf("%s %d", name, &age);

  printf("input address. :");

  // 문자열이 공백이 있어도 줄 전체를 읽어들임
  fflush(stdin); // Keyboard Buffer를 비움
  fgets(address, 50, stdin); // scanf("%s", address); 제거

  printf("name: %s, age: %d, address:%s \n", name, age, address);

  return 0;
}
