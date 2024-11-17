// sorting the array using the sort function and analyzing 
// the processing time of sorted array.

#include <stdio.h>
#include <stdlib.h> // rand(), qsort()
#include <time.h>   // time()

int compare(const void *a, const void *b) {
	return (*(int *)a - *(int *)b); //asendig
	// return (*(int *)b - *(int *)a); desending
}

int main()
{
    // Generate data
    const unsigned arraySize = 10000;
    int data[arraySize];
    for (unsigned c = 0; c < arraySize; ++c)
    {
        data[c] = rand() % 256;
    }
    
    // Sorting the array
    int n = sizeof(data)/sizeof(data[0]);
    qsort(data, n, sizeof(int), compare);
    
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
            if (data[c] >= 128)
                sum += data[c];
        }
    }
    
    execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("execution time : %f \n", execution_time);
    printf("sum : %ld \n", sum);
   
    return 0;
}
