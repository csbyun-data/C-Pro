#include <stdio.h>

struct _point {
	int x;
	int y;
};

struct _point func() {
	struct _point s = {10, 10};
	return s;
}

int main() {
	struct _point p1;
	
	p1 = func();
	
	printf("%d, %d\n", p1.x, p1.y);
}
//결과값 : 10, 10
