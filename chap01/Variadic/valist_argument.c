// 가변인자를 사용하지 않은 예제
// 구조체의 같은 메모리크기를 활용, 함수의 파라메터가 stack 메모리에 쌓인 address를 순차적으로 가져옴
// 마지막 parameter를 NULL을 이용 확인

// David Betz. XLISP 0.0. January 6, 1983. USENET distribution and extracted sources.

#include <stdio.h>

enum TYPE {
  TYPE_CHAR, TYPE_INT, TYPE_FLOAT
};

typedef struct {
  void *n_listvalue;
  size_t n_type;
} node;

void func( node *n, ...) {
  size_t n_type;
  node **nptr;
  
  for (nptr = &n; *nptr != NULL; nptr++) {
    n_type = (*nptr)->n_type;
    switch(n_type) {
      case TYPE_CHAR:
        printf("1, %s\n", (*nptr)->n_listvalue);
        break;
      case TYPE_INT:
        printf("2, %d\n",  *(int *)(*nptr)->n_listvalue);
        break;
      case TYPE_FLOAT:
        printf("3, %f\n",  *(float *)(*nptr)->n_listvalue);
        break;				
      //default:
    }
  }	
}

int main()
{
  int num = 1;
  float fnum = 3.14;
  
  node a, b, c;
  
  a.n_type = TYPE_CHAR;
  a.n_listvalue = "abc";
  
  b.n_type = TYPE_INT;
  b.n_listvalue= &num;
  
  c.n_type = TYPE_FLOAT;
  c.n_listvalue = &fnum;
  
  func(&a, &b, &c, NULL);
}
