// Text파일, Binary파일 사용법 중 Text파일
// FILE *fopen(const cahr *name, const char *mode)
// r  - open for reading
// w  - open for writing (file need not exist)
// a  - open for appending (file need not exist)
// r+ - open for reading and writing, start at beginning
// w+ - open for reading and writing (overwrite file)
// a+ - open for reading and writing (append if file exists)

#include <stdio.h>

int main()
{
	FILE *fp;
	
	fp = fopen("test.txt", "w");
	
	if(fp != NULL) {
		fprintf(fp, "Tesing...\n");
	} else {
		printf("Failed file open!\n");
	}
	
	fclose(fp);
	
	return 0;
}
