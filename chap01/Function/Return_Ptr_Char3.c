//[Warning] deprecated conversion from string constant to 'char*' [-Wwrite-strings]
//char const *p = "abc"; // valid and safe in either C or C++.
//const char * p == char const * P 

#include <stdio.h>
#include <stdlib.h>

const char * sol(const char * names[], int num) {
	return names[num];
}

int main() {
 const char * names[5] = {"lukas", "james", "levi", "eli", "max"};
 int num = 1;
 
 char const * ret = sol(names, num);
 
 printf("ret values is %s . \n", ret);
}
​
