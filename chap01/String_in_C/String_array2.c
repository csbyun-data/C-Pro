#include <stdio.h>

int main()
{
	char* str1 = "ABC";      // const string, 변경 불가함 
	char  str2[10] = "ABCD"; //문자열이 10을 넘을 경우 overflow 발생 
	char  str3[] = "ABCDEF"; //변수 선언시 메모리 할당 
	
	printf("str1 = %s \n", str1);
	printf("str2 = %s \n", str2);
	printf("str3 = %s \n", str3);
	
	return 0;
}
