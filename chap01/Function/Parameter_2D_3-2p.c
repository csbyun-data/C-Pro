// 2D배열 매개변수 전달, row, column을 parameter로 전달
// row별 sum, average 구한는 예제
#include <stdio.h>

void avg(int (*ptr)[4], int rows, int cols);

int main()
{
	int score[3][4] = {{1,2,3},{4,5,6},{7,8,9}};
	int rows, cols;
	
	rows = sizeof(score)/sizeof(score[0]);
	cols = sizeof(score[0])/sizeof(score[0][0]);
	avg(score, rows, cols);
	
	return 0;
}

void avg(int (*ptr)[4], int rows, int cols) {
	int i, j, a, t;
	
	for(i=0; i<rows; i++) {
		a = t = 0;
		for(j=0; j<cols; j++)
			t += *(*(ptr+i)+j); // t += *(ptr[i]+j); or t += ptr[i][j];
    a = t/cols;
		printf("%d 의 t=%d, a=%d\n", i+1, t, a);
	}
}
