#include <stdio.h>
#include <stdlib.h>

char* sol(char* names[], int num) {
	return names[num];
}

int main() {
 char* names[5] = {"lukas", "james", "levi", "eli", "max"};
 int num = 1;
 
 char* ret = sol(names, num);
 
 printf("ret values is %s . \n", ret);
}
//결과 : ret values is james .
