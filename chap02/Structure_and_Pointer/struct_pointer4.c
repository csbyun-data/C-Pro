// 구조체 포인터 예 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person {
  char name[20];
  int age;
};

int main()
{
  struct Person p1;
  struct Person* pa;
  
  pa = &p1; 	// Person *pa = (Person *)malloc(sizeof(Person));
  
  strcpy(pa->name, "name1");  // (*pa).name 동일표현 
  pa->age = 20;               // (*pa).age 동일표현 
  
  printf("name: %s, age: %d \n", pa->name, pa->age);
  
  // free(pa);
  
  return 0; 
}

/*
name: name1, age: 20
*/
