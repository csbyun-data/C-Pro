// 포인터 변수와 문자열의 활용 예
#include <stdio.h>

int main()
{
	char arr[] = "ABCDEFG";
	char *ptr = arr;
	int i;
	
	printf("arr = %s \n", arr);
	printf("ptr = %s \n", ptr);
	
	for(i=0; i<strlen(ptr); i++) {
		putchar(*(ptr+i));
	}
	putchar('\n');
	
	for(; *ptr; ptr++) {
		putchar(*ptr);
	}
	putchar('\n');
	
	ptr = arr;

	return 0;
}
