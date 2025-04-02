/*Prg 3_2b - Print the names of the month
  by Stephen R. Davis, 1987 

  The following program demonstrates in a simplistic fashion 
  the concept of arrays of pointers. Almost unknown in other 
  languages, this concept can save much code both in terms of size
  and speed. Compare this program to the "Pascal-like" Program 3_2a
  which does the same thing. */ 

#include <stdio.h>
#include <stdlib.h>

unsigned putmonths(unsigned);

/* an array of pointers to the names of the months */
char *months[] = {"Bye bye\n\n", 
 "January\n\n", 
 "February\n\n", 
 "March\n\n", 
 "April\n\n", 
 "May\n\n", 
 "June\n\n", 
 "July\n\n", 
 "August\n\n", 
 "September\n\n", 
 "October\n\n", 
 "November\n\n", 
 "December\n\n"}; 

/* Main - input a number and output the corresponding name of the month */
int main(int argc, char *argv[]) {
  unsigned putmonths();
  unsigned innum;
  
  do {
  	printf("Enter another month: ");
  	scanf("%d", &innum);
  } while(putmonths(innum));
	
  return 0;
}

/* Putmonths - given a number, print the corresponding month, Return
   the number, unless it is out of range, in which case,
   return a 0 */
unsigned putmonths( unsigned month ) {
	if(month > 12)
	  month = 0;
	printf(months[month]);
	
	return(month);
}
