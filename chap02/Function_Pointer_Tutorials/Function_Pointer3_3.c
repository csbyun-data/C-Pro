#include <stdlib.h> // due to: qsort
#include <time.h> // randomize
#include <stdio.h> // printf

#define randomize() srand ( (unsigned int) time ( NULL ) )
#define random( min, max ) ((rand() % ((max)-(min)+1)) + (min))

// comparison-function for the sort-algorithm
// two items are taken by void-pointer, converted and compared
int CmpFunc(const void* _a, const void* _b) {
  // you’ve got to explicitly cast to the correct type
  const float* a = (const float*) _a;
  const float* b = (const float*) _b;

  if(*a > *b) return 1; // first item is bigger than the second one -> return 1
  else
    if(*a == *b) return 0; // equality -> return 0
    else return -1; // second item is bigger than the first one -> return -1
}

// example for the use of qsort()
void QSortExample() {
  float field[100];
  randomize(); // initialize random-number-generator
  
  for(int c=0;c<100;c++) // randomize all elements of the field
    field[c]=random(0, 99);

  // sort using qsort()
  qsort((void*) field, /*number of items*/ 100, /*size of an item*/ sizeof(field[0]),
  /*comparison-function*/ CmpFunc);
  
  // display first ten elements of the sorted field
  printf("The first ten elements of the sorted field are ...\n");
  for(int c=0;c<10;c++)
    printf("element #%2d contains %.0f\n", c+1, field[c]);
  printf("\n");
}

int main() {
  QSortExample();
  return 0;
}
