#include <iostream>

using namespace std;

float Plus (float a, float b) { return a+b; }
float Minus (float a, float b) { return a-b; }
float Multiply(float a, float b) { return a*b; }
float Divide (float a, float b) { return a/b; }

// ’Plus’ and ’Minus’ are defined above. They return a float and take two float
// Direct solution: Function takes a char and returns a pointer to a
// function which is taking two floats and returns a float. <opCode>
// specifies which function to return
float (*GetPtr1(const char opCode))(float, float){
  if(opCode == '+')
    return &Plus;
  else
    return &Minus;
} // default if invalid operator was passed

// Solution using a typedef: Define a pointer to a function which is taking
// two floats and returns a float
typedef float(*pt2Func)(float, float);

// Function takes a char and returns a function pointer which is defined
// with the typedef above. <opCode> specifies which function to return
pt2Func GetPtr2(const char opCode) {
  if(opCode == '+')
    return &Plus;
  else
    return &Minus; // default if invalid operator was passed
}

// Execute example code
void Return_A_Function_Pointer() {
  cout << endl << "Executing ’Return_A_Function_Pointer’" << endl;

  // define a function pointer and initialize it to NULL
  float (*pt2Function)(float, float) = NULL;
  
  pt2Function=GetPtr1('+'); // get function pointer from function ’GetPtr1’
  cout << (*pt2Function)(2, 4) << endl; // call function using the pointer
  
  pt2Function=GetPtr2('-'); // get function pointer from function ’GetPtr2’
  cout << (*pt2Function)(2, 4) << endl; // call function using the pointer
}


int main()
{
  Return_A_Function_Pointer();
  
  return 0;
}
