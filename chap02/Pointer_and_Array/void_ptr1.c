// void pointer 활용 예
// void 선언후 char, int형으로 변형해서 사용가능

#include <stdio.h>

int main() 
{
	char c;
	int n;
	
	void* ptr;
	
	c = 'a';
	ptr = &c;
	printf("%c \n", *(char*)ptr);
	
	n= 1;
	ptr = &n;
	printf("%d \n",*(int*)ptr);
		
	return 0;
}
// run result
a
1
