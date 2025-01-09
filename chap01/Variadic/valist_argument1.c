#include <stdio.h>
#include <stdarg.h>

enum TYPE {
  TYPE_CHAR, TYPE_INT, TYPE_FLOAT
};

typedef struct {
  void *n_listvalue;
  size_t n_type;
} node;

void func( node *n, ...) {
  size_t n_type;
  node **nptr, *arg;

  // Declaring pointer to the argument list
  va_list ptr;
  
  // Initializing argument to the list pointer
  va_start(ptr, n);
  
  for (nptr = &n; *nptr != NULL; ) {
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
    }
    // Accessing current variable and pointing to next one
    arg = va_arg(ptr, struct node *);
    nptr = &arg;
  }
  // Ending argument list traversal
  va_end(ptr);
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
