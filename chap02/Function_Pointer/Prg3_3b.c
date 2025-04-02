/*Prg 3 3b -- Integration of a user function using Trapezoid Rule 
  by Stephen R. Davis 
  This program demostrates how by allowing a function to be passed 
  to another function, C allows some very general purpose routines 
  to be designed. This is a more general routine than that of 3_3a 
  since it makes no restrictions on the name of the user function. 
  This is the type of function which could be included in a C library 
  for later use. 
*/

#include <stdio.h> 

/*prototype definitions --*/ 
double integrate (double (*)(double), double, double, unsigned); 
double func (double), answer (double); 

int main (void); 
/*Integrate - evaluate the definite integral of the function pointed a 
  by 'fn' by applying the trapezoid rule to the function 
  over the range 'a' to 'b' by dividing it into 'steps' 
  number of intervals.*/ 
double integrate (fn, a, b, steps) 
  double (*fn) () ,a,b; 
  unsigned steps; 
{
  unsigned i; 
  double integral,spacing,x; 
  
  spacing = (b - a) / steps; 
  integral = ( (*fn) (b) + (*fn) (a)) / 2; 
  for (i = 1, x = a; i < steps; i++) { 
    x += spacing; 
    integral += (*fn) (x); 
  }
  return (integral* spacing); 
}

/*Experiment - a sample user program to integrate. (It has renamed
  from 'func' to avoid any confusion with the pointer 
  to a function 'fn' in 'Integrate')*/ 
double experiment (x) 
  double x; 
{
  return (x*x); 
}

double answer (x) 
  double x; 
{
  return x*x*x/3.; 
}

/*Main - same as before*/ 
int main () 
{ 
  float a,b; 
  unsigned steps; 
  
  printf ("Enter starting x, ending x and number of steps\n"); 
  printf (" (exit by entering starting x equal ending x)\n"); 
  for (;;) { 
    printf (">"); 
    scanf ( "%f %f %d", &a, &b, &steps); 
    printf ("a= %f, b = %f, steps= %d\n", a, b, steps); 
    if (a == b)
       break; 
    printf ("Integral is %f\n", integrate(experiment, 
                                          (double) a, (double) b, steps)); 
    printf ("(actual value is %f)\n", answer (b) - answer (a));
  }
}
