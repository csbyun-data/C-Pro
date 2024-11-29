
// ** Error와 해결 방법
// [Warning] deprecated conversion from string constant to 'char*' [-Wwrite-strings]

// The C++11 Standard (ISO/IEC 14882:2011) 
// char* p = "abc"; // valid in C, invalid in C++
// char* p = (char*)"abc"; // OK: cast added
// char const *p = "abc"; // valid and safe in either C or C++.

// char* p = strdup("abc");
// char p[] = "abc";
//[Warning] deprecated conversion from string constant to 'char*' [-Wwrite-strings]
//char* p = (char*)"abc"; // OK: cast added

#include <stdio.h>
#include <stdlib.h>

char* sol(char* names[], int num) {
	return names[num];
}

int main() {
 char* names[5] = {(char*)"lukas", (char*)"james", (char*)"levi", (char*)"eli", (char*)"max"};
 int num = 1;
 
 char* ret = sol(names, num);
 
 printf("ret values is %s . \n", ret);
}
