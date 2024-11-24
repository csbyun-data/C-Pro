// fscanf 함수 예제
#include <stdio.h>

int main() 
{
  FILE *fp;
  int i;
  int no=0;
  long int sum=0l;

  if( (fp=fopen("data.dat","r")) == NULL) {
    printf("Error: can't open data.dat\n");
    return(1);
  }

  while( fscanf(fp, "%d", &i) != EOF) {
    sum += i;
    ++no;
  }

  if( no==0)
    printf("no data.\n");
  else {
    printf("Total %d numbers.\n", no);
    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", (float)sum/(float)no);
  }
  fclose(fp);
}

// run result
// Total 10 numbers.
// Sum = 654
// Average = 65.40

    

  
