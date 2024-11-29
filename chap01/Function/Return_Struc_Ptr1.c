#include <stdio.h>

struct _point {
	int x;
	int y;
};

struct _point * func() {
	static struct _point s = {10, 10};
	
	return &s;
}

int main() {
	struct _point *ps;
	
	ps = func();
	printf("%d, %d\n", ps->x, ps->y);
}

// 10, 10
