// 문자열 포인터배열 사용 예
#include <stdio.h>
#include <string.h>
#include <malloc.h>

char* strdup2(const char* src);

int main()
{
	int i;
	char* str[4];
	
	str[0] = strdup2("A");
	str[1] = strdup2("BC");
	str[2] = strdup2("CDE");
	str[3] = strdup2("DEFG");
	
	for(i=0; i<4; i++) {
		printf("%s \n", str[i]);
	}
	
	for(i=0; i<4; i++) {
		free(str[i]);
	}
	
	return 0;
}

char* strdup2(const char* src) {
	char* ptr = NULL;
	ptr = (char *)malloc(sizeof(char)*strlen(src)+1);
	strcpy(ptr, src);
	
	return ptr;
}
