#include <iostream>

using namespace std;

// Task: The function ’DoItA’ makes something which implies a callback to
// the member function ’Display’. Therefore the wrapper function
// ’Wrapper_To_Call_Display is used.
class TClassA {
  public:
   	void Display(const char* text) { cout << text << endl; };
   	static void Wrapper_To_Call_Display(void* pt2Object, char* text);
   	/* more of TClassA */
};

// static wrapper function to be able to callback the member function Display()
void TClassA::Wrapper_To_Call_Display(void* pt2Object, char* string) {
  // explicitly cast to a pointer to TClassA
  TClassA* mySelf = (TClassA*) pt2Object;

  // call member
  mySelf->Display(string);
}

// function does something which implies a callback
// note: of course this function can also be a member function
void DoItA(void* pt2Object, void (*pt2Function)(void* pt2Object, char* text)) {
  /* do something */
  pt2Function(pt2Object, "hi, i’m calling back using a argument ;-)"); // make callback
}

// execute example code
void Callback_Using_Argument() {
  // 1. instantiate object of TClassA
  TClassA objA;

  // 2. call ’DoItA’ for <objA>
  DoItA((void*) &objA, TClassA::Wrapper_To_Call_Display);
}

int main()
{
  Callback_Using_Argument();
  return 0;
}
