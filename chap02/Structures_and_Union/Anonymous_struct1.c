//익명의 구조체 사용예 1, C11
#include <stdio.h>
#include<string.h>
struct myData {
  union {  // anonymous union
    short int a;
    short int b;
  };
  short int c;
};

int main()
{
  //Variable of structure
  struct myData sMydata;
  sMydata.a =10; //valid
  sMydata.b = 20;  //valid
  sMydata.c = 40;  //valid
  
  return 0;
}
