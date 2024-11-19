// Program to calculate the sum of numbers (10 numbers max)
// If the user enters a negative number, the loop terminates

#include <stdio.h>

int main()
{
  int i;
  double num, sum=0;
	
  for(i=1; i <= 10; ++i) {
    printf("Enter n%d: ", i);
    scanf("%lf", &num);
		
    if(num < 0.0) 
      break;
		
		sum += num;
	}
	printf("Sum = %.2lf", sum);
	
	return 0;
}
