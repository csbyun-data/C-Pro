// creating an unsorted array and analyzing the processing time

#include <stdio.h>
#include <stdlib.h> // rand()
#include <time.h>   // time()

int main()
{
    // Generate data
    const unsigned arraySize = 10000;
    int data[arraySize];
    for (unsigned c = 0; c < arraySize; ++c)
    {
        data[c] = rand() % 256;
    }
    
    // Test timing
    clock_t start_time, end_time;
    double execution_time;
    
    start_time = clock();
    long long sum = 0;
    for (unsigned i = 0; i < 10000; ++i)
    {
        // Primary loop
        for (unsigned c = 0; c < arraySize; ++c)
        {
            int t = (data[c] - 128) >> 31;
            sum += ~t & data[c];
		}
    }
    
    execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("execution time : %f \n", execution_time);
    printf("sum : %ld \n", sum);
   
    return 0;
}
