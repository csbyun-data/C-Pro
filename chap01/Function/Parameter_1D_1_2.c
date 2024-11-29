// Return multiple values from a function in C using the pointer
// 단일 변수의 call by address (pass by address) 활용

#include <stdio.h>
#include <stdlib.h>

// function to get user info
void Getinfo( int *age, float *height, char *name) {
  printf("\n\n Enter User age = ");
  scanf("%d",age);
  
  printf("\n\n Enter User height = ");
  scanf("%f",height);
  
  printf("\n\n Enter User name = ");
  scanf("%s",name);
}

int main()
{
  // variable to store age, height, name
  int age=0;
  float height=0.0f;
  char name[24] = {0};

  // Get user info
  Getinfo( &age, &height, name);
  printf("\n User age = %d", age);
  printf("\n User height = %d", height);
  printf("\n User name = %s", name);

  return 0;
}

// run result
// Enter User age = 10
// Enter User height = 180
// Enter User name = C.S.Byun

// User age = 10
// User height = 180.000000
// User name = C.S.Byun
​
