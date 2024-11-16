Chapter 01. 문법1
* 1.문법
  	* 1.1 Command line argument in C [here](https://github.com/csbyun-data/C-Programming/blob/main/chap01/CommandLineArgument.c) 
* 2.가변인자, 가변함수, Variadic arguments (va_start, va_list, va_end, va_arg) 
	* 2.1 인자 더하기 [Add](https://github.com/csbyun-data/C-Programming/blob/main/chap01/VariableArgument_Add.c) 
     	* 2.2 인자 최대값 [Max]()
     
  * 
```c
#include <stdio.h>

int main(int argc, char *argv[])
{
	if( argc != 2) {
		printf("usage: %s filename", argv[0]);
	} else {
		FILE *file = fopen(argv[1], "r");
		
		// fopen return 0, the NULL pointer, on failure
		if( file == 0) {
			printf("Could not open file\n");
		} else {
			int x;
			/* read one character at a time from file, stopping at EOF, which
			   indicates the end of the file. Note that the idiom of "assign
			   to a variable, check the value" used below works because
			   the assignment statement evaluates to the value assigned. */ 
			while (( x = fgetc(file))!= EOF ) {
				printf("%c", x);
			}
		}
		
		fclose(file);
	}
	
  	return 0;
}
```
