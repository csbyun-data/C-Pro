#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct student {
	char name[10];
	int  age;
};

int main() 
{
	struct student st;
	struct student* pst;
	
	strcpy(st.name, "ABCD");
	st.age = 10;
	
	pst = (struct student*)malloc(sizeof(struct student));
	strcpy(pst->name, "BCDE"); 
	//strcpy((*pst).name, "BCDE");  동일 표현식 
	pst->age = 12;
	
	
	printf("name = %s\n", pst->name);
	printf("age = %d\n", pst->age);
	
	return 0;
}

/*
name = BCDE
age = 12
*/
