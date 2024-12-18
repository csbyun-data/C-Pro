// typedef struct 활용 예
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char name[20];
  int age;
} Person;

int main()
{
  Person* pa = (Person *)malloc(sizeof(Person));
  strcpy(pa->name, "name1");  // (*pa).name 동일표현 
  pa->age = 20;               // (*pa).age 동일표현 
  
  printf("name: %s, age: %d \n", pa->name, pa->age);
  
  free(pa);
  
  return 0; 
}

/*
name: name1, age: 20
*/
