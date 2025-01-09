#include <stdio.h>

enum TYPE {
  TYPE_CHAR,
  TYPE_INT,
  TYPE_FLOAT
};

typedef struct {
	void *n_listvalue;
	size_t n_type;
} valist;

void func( valist *n, ...) {
	size_t n_type;
	valist **nptr;
	
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
	
	valist a, b, c;
	
	a.n_type = TYPE_CHAR;
	a.n_listvalue = "abc";
	
	b.n_type = TYPE_INT;
	b.n_listvalue= &num;
	
	c.n_type = TYPE_FLOAT;
	c.n_listvalue = &fnum;
	
	func(&a, &b, &c, NULL);
}
