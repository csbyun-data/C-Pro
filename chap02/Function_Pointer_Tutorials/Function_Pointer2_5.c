#include <stdio.h>

int DoIt (float a, char b, char c) {
  printf("DoIt\n"); 
  return a+b+c; 
}

int DoMore(float a, char b, char c) { 
  printf("DoMore\n"); 
  return a-b+c; 
}

int main()
{
  int (*pt2Function)(float, char, char) = NULL;
  
  pt2Function = DoIt; // short form
  //pt2Function = &DoMore; // correct assignment using address operator
  
  if(pt2Function >0){ // check if initialized
    if(pt2Function == &DoIt)
      printf("Pointer points to DoIt\n");
    else
      printf("Pointer not initialized!!\n");	
  }	
  
  int result1 = pt2Function (12, 'a', 'b'); // C short way
  int result2 = (*pt2Function) (12, 'a', 'b'); // C
  
  return 0;
}
