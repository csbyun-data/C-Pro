//익명의 구조체 사용예2, C11
#include <stdio.h>
struct myData {
  union {  // anonymous union
    struct {
      short int a;
    } data; // data is struct variable
    struct { // anonymous struct
      short int b;
    };
  };
  short int c;
};

int main()
{
    struct myData sMydata; //struct variable
    sMydata.a = 5; //invalid
    sMydata.data.a =10; //valid
    sMydata.b = 20; //valid
    sMydata.c = 40; //valid
}
