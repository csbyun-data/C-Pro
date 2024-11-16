#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start_time, end_time;
    double execution_time;
	
    start_time = clock();
	
    long long total = 0;
	
    for ( int i=1; i<=100000000; i++ ) {
        total += i;
    }
	
    end_time = clock();
	
    execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("execution time : %f \n", execution_time);
	
    return 0;
}
