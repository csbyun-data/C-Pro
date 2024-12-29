#include <stdio.h>

void prt(int (*ptr)[4], int rows, int cols);
void avg(int (*ptr)[4], int rows, int cols);

int main()
{
  int score[3][4] = {{1,2,3},{4,5,6},{7,8,9}};
  int rows, cols;
  
  rows = sizeof(score)/sizeof(score[0]);
  cols = sizeof(score[0])/sizeof(score[0][0]);
  
  prt(score, rows, cols);
  avg(score, rows, cols);
  
  return 0;
}

void prt( int (*ptr)[4], int rows, int cols) {
  int i, j;
  for(i=0; i<rows; i++) {
    for(j=0; j<cols; j++)
    	printf("%d ", *(*(ptr+i)+j));
    printf("\n");
  }
}

void avg(int (*ptr)[4], int rows, int cols) {
  int i, j, avg, total;
  
  for(i=0; i<rows; i++) {
    avg = total = 0;
    for(j=0; j<cols; j++)
      total += *(*(ptr+i)+j); // t += *(ptr[i]+j); or t += ptr[i][j];
    avg = total / cols;
    printf("%d 의 total=%2d, avg=%2d\n", i+1, total, avg);
  }
}
