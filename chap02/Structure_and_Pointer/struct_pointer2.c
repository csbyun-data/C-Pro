// 구조체 활용 예 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person {
  char name[20];
  int age;
};

int main()
{
  struct Person* pa = (struct Person *)malloc(sizeof(struct Person));
  strcpy(pa->name, "name1");  // (*pa).name 동일표현 
  pa->age = 20;               // (*pa).age 동일표현 
  
  printf("name: %s, age: %d \n", pa->name, pa->age);
  
  free(pa);
  
  struct Person p1 = {"name2", 25};
  printf("name: %s, age: %d \n", p1.name, p1.age);
  
  return 0; 
}
