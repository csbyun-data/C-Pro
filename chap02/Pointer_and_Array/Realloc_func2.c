#include <stdio.h>
#include <stdlib.h>

int main()
{
  // this marks pointer hold the base address of the block created
  int index=0, i=0, n, *marks; 
  int ans;

  // dynamically allocate memory using malloc check
  // if the memory is successfully allocated by malloc or not ?
  marks = (int *)malloc( sizeof(int));
  if( marks == NULL) {
    printf("memory cannot be allocated");
  } else {
    // memory has successfully allocated
    printf("Memory has been successfully allocated by "
           "using malloc\n");
    // print the base or beginning address of allocated memory
    printf("\n marks = %pc\n", marks);

    do {
      printf("\n Enter Marks\n");
      scanf("%d", &marks[ index]); // Get the marks
      printf("would you like to add more(1/0): ");
      scanf("%d", &ans);

      if( ans == 1) {
        index++;
      
        // Dynamically reallocate memory by using realloc
        // check if the memory is successfully allocated by realloc or not ?
        marks = (int *)realloc( marks, (index+1)*sizeof(int)); 
        if( marks==NULL) {
          printf("memory cannot be allocated");
        } else {
          // print the base or baginning address of allocated memory
          printf("\n base address of marks are:%pc", marks);
        }
      }
    } while( ans==1);

    // print the marks of the students
    for( i=0; i<=index; i++) {
        printf("marks of students %d are: %d\n", i, marks[i]);
    }

    free(marks[i]);
  }
  return 0;
}
