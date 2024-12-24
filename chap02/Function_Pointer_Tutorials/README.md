## Function Pointer
### INDEX

* 2.Function Pointer Tutorials [book.pdf](https://github.com/csbyun-data/C-Pro/blob/main/chap02/The%20Function%20Pointer%20Tutorials.pdf)
  * 2.0 contents 
  ```txt
  1 Introduction to Function Pointers 
  1.1 What is a Function Pointer ?
  1.2 Introductory Example or How to Replace a Switch-Statement 

  2 The Syntax of C and C++ Function Pointers 
  2.1 Define a Function Pointer 
  2.2 Calling Convention 
  2.3 Assign an Address to a Function Pointer 
  2.4 Comparing Function Pointers 
  2.5 Calling a Function using a Function Pointer 
  2.6 How to Pass a Function Pointer as an Argument ? 
  2.7 How to Return a Function Pointer ? 
  2.8 How to Use Arrays of Function Pointers ? 
  
  3 How to Implement Callback Functions in C and C++ 
  3.1 Introduction to the Concept of Callback Functions 
  3.2 How to Implement a Callback in C ? 
  3.3 Example Code of the Usage of qsort 
  3.4 How to Implement a Callback to a static C++ Member Function ? 
  3.5 How to Implement a Callback to a non-static C++ Member Function ? 
  
  4 Functors to encapsulate C and C++ Function Pointers 
  4.1 What are Functors ? 
  4.2 How to Implement Functors ? 
  4.3 Example of How to Use Functors 
  ```
  
  * 1.2 Introductory Example or How to Replace a Switch-Statement [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer_Tutorials/Function_Pointer1.c)
  ```
  // Task: Perform one of the four basic arithmetic operations specified by the
  // characters '+', '-', '*' or '/'.
  // The four arithmetic operations ... one of these functions is selected
  // at runtime with a swicth or a function pointer
  
  float Plus (float a, float b) { return a+b; }
  float Minus (float a, float b) { return a-b; }
  float Multiply(float a, float b) { return a*b; }
  float Divide (float a, float b) { return a/b; }
  
  // Solution with a switch-statement - <opCode> specifies which operation to execute
  void Switch(float a, float b, char opCode) {
    float result;

    // execute operation
    switch(opCode){
      case '+' : result = Plus (a, b); break;
      case '-' : result = Minus (a, b); break;
      case '*' : result = Multiply (a, b); break;
      case '/' : result = Divide (a, b); break;
     }
  
     cout << "Switch: 2+5=" << result << endl; // display result
  }
  
  // Solution with a function pointer - <pt2Func> is a function pointer and points to
  // a function which takes two floats and returns a float. The function pointer
  // "specifies" which operation shall be executed.
  void Switch_With_Function_Pointer(float a, float b, float (*pt2Func)(float, float)) {
    float result = pt2Func(a, b); // call using function pointer
    cout << "Switch replaced by function pointer: 2-5="; // display result
    cout << result << endl;
  }
  
  // Execute example code
  void Replace_A_Switch() {
    cout << endl << "Executing function ’Replace_A_Switch’" << endl;
    Switch(2, 5, /* ’+’ specifies function ’Plus’ to be executed */ ’+’);
    Switch_With_Function_Pointer(2, 5, /* pointer to function ’Minus’ */ &Minus);
  }
  ```
  ![image](https://github.com/user-attachments/assets/102c2709-af9e-4e69-9436-b37d6704eb38)

  * 2 The Syntax of C and C++ Function Pointers
  * 2.1 define a function pointer and initialize to NULL
  ```c
  int (*pt2Function)(float, char, char) = NULL; // C
  int (TMyClass::*pt2Member)(float, char, char) = NULL; // C++
  int (TMyClass::*pt2ConstMember)(float, char, char) const = NULL; // C++
  ```
  * 2.2 define the calling convention
  ```c
  void __cdecl DoIt(float a, char b, char c); // Borland and Microsoft
  void DoIt(float a, char b, char c) __attribute__((cdecl)); // GNU GCC
  ```
  * 2.3 assign an address to the function pointer
  ```c
  // Note: Although you may ommit the address operator on most compilers
  // you should always use the correct way in order to write portable code.
  
  // C
  int DoIt (float a, char b, char c){ printf("DoIt\n"); return a+b+c; }
  int DoMore(float a, char b, char c)const{ printf("DoMore\n"); return a-b+c; }
  pt2Function = DoIt; // short form
  pt2Function = &DoMore; // correct assignment using address operator
  
  // C++
  class TMyClass {
    public:
      int DoIt(float a, char b, char c){ cout << "TMyClass::DoIt"<< endl; return a+b+c;};
      int DoMore(float a, char b, char c) const
      { cout << "TMyClass::DoMore" << endl; return a-b+c; };
    /* more of TMyClass */
  };
  ```
  * 2.4 comparing function pointers [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer_Tutorials/Function_Pointer2_4.c)
  ```c
  // C
  if(pt2Function >0){ // check if initialized
  	 if(pt2Function == &DoIt)
  		  printf("Pointer points to DoIt\n");
  	  else
  		  printf("Pointer not initialized!!\n");
  }
  // C++
  if(pt2ConstMember == &TMyClass::DoMore)
  	cout << "Pointer points to TMyClass::DoMore" << endl;
  ```
  ![image](https://github.com/user-attachments/assets/63ba9f0e-d048-4304-a64f-00ee38c12913)
  * 2.5 calling a function using a function pointer [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer_Tutorials/Function_Pointer2_5.c)
  ```c
  int result1 = pt2Function (12, 'a', 'b'); // C short way
  int result2 = (*pt2Function) (12, 'a', 'b'); // C
  
  TMyClass instance1;
  
  int result3 = (instance1.*pt2Member)(12, 'a', 'b'); // C++
  int result4 = (*this.*pt2Member)(12, 'a', 'b'); // C++ if this-pointer can be used
  
  TMyClass* instance2 = new TMyClass;
  int result4 = (instance2->*pt2Member)(12, 'a', 'b'); // C++, instance2 is a pointer
  
  delete instance2;
  ```
  ![image](https://github.com/user-attachments/assets/8e5a23dd-b317-4ef1-9283-76aea3ee8ca1)

  * 2.6 How to Pass a Function Pointer [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer_Tutorials/Function_Pointer2_6.cpp)
  ```c
  // <pt2Func> is a pointer to a function which returns an int and takes a float and two char
  void PassPtr(int (*pt2Func)(float, char, char)) {
    int result = (*pt2Func)(12, 'a', 'b'); // call using function pointer
    cout << result << endl;
  }
  
  // execute example code - ’DoIt’ is a suitable function like defined above in 2.1-4
  void Pass_A_Function_Pointer() {
    cout << endl << "Executing ’Pass_A_Function_Pointer’" << endl;
    PassPtr(&DoIt);
  }
  ```
  ![image](https://github.com/user-attachments/assets/33de9189-4297-42c0-a6af-62d01c86b261)

  * 2.7 How to Return a Function Pointer
  ```c
  // ’Plus’ and ’Minus’ are defined above. They return a float and take two float
  // Direct solution: Function takes a char and returns a pointer to a
  // function which is taking two floats and returns a float. <opCode>
  // specifies which function to return
  float (*GetPtr1(const char opCode))(float, float){
    if(opCode == '+')
      return &Plus;
    else
      return &Minus;} // default if invalid operator was passed
  
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
  ```
  * 2.8 How to Use Arrays of Function Pointers
  ```c
  // C 
  // type-definition: ’pt2Function’ now can be used as type
  typedef int (*pt2Function)(float, char, char);
  
  // illustrate how to work with an array of function pointers
  void Array_Of_Function_Pointers() {
   	printf("\nExecuting ’Array_Of_Function_Pointers’\n");
   
   	// define arrays and ini each element to NULL, <funcArr1> and <funcArr2> are arrays
   	// with 10 pointers to functions which return an int and take a float and two char
   	// first way using the typedef
   	pt2Function funcArr1[10] = {NULL};
   
   	// 2nd way directly defining the array
   	int (*funcArr2[10])(float, char, char) = {NULL};
   
   	// assign the function’s address - ’DoIt’ and ’DoMore’ are suitable functions
   	// like defined above in 2.1-4
   	funcArr1[0] = funcArr2[1] = &DoIt;
   	funcArr1[1] = funcArr2[0] = &DoMore;
   
   	/* more assignments */
   	// calling a function using an index to address the function pointer
   	printf("%d\n", funcArr1[1](12, ’a’, ’b’)); // short form
   	printf("%d\n", (*funcArr1[0])(12, ’a’, ’b’)); // "correct" way of calling
   	printf("%d\n", (*funcArr2[1])(56, ’a’, ’b’));
   	printf("%d\n", (*funcArr2[0])(34, ’a’, ’b’));
  }
  
  // C++ 
  // type-definition: ’pt2Member’ now can be used as type
  typedef int (TMyClass::*pt2Member)(float, char, char);
  
  // illustrate how to work with an array of member function pointers
  void Array_Of_Member_Function_Pointers() {
   	cout << endl << "Executing ’Array_Of_Member_Function_Pointers’" << endl;
   
   	// define arrays and ini each element to NULL, <funcArr1> and <funcArr2> are
   	// arrays with 10 pointers to member functions which return an int and take
   	// a float and two char
   	// first way using the typedef
   	pt2Member funcArr1[10] = {NULL};
   
   	// 2nd way of directly defining the array
   	int (TMyClass::*funcArr2[10])(float, char, char) = {NULL};
   
   	// assign the function’s address - ’DoIt’ and ’DoMore’ are suitable member
   	// functions of class TMyClass like defined above in 2.1-4
   	funcArr1[0] = funcArr2[1] = &TMyClass::DoIt;
   	funcArr1[1] = funcArr2[0] = &TMyClass::DoMore;
   
   	/* more assignments */
   	// calling a function using an index to address the member function pointer
   	// note: an instance of TMyClass is needed to call the member functions
   	TMyClass instance;
   	cout << (instance.*funcArr1[1])(12, ’a’, ’b’) << endl;
   	cout << (instance.*funcArr1[0])(12, ’a’, ’b’) << endl;
   	cout << (instance.*funcArr2[1])(34, ’a’, ’b’) << endl;
   	cout << (instance.*funcArr2[0])(89, ’a’, ’b’) << endl;
  }
  ```
  * 3.2 How to Implement a Callback in C ?
  ```c
  void qsort( ... , int(_USERENTRY *cmpFunc)(const void*, const void*)) {
    /* sort algorithm - note: item1 and item2 are void-pointers */
    int bigger=cmpFunc(item1, item2); // make callback
    /* use the result */
  }
  ```
  * 3.3 How to make a callback in C by the means of the sort function qsort
  ```c
  #include <stdlib.h> // due to: qsort
  #include <time.h> // randomize
  #include <stdio.h> // printf
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
   	::randomize(); // initialize random-number-generator
   	for(int c=0;c<100;c++) // randomize all elements of the field
    		field[c]=random(99);
   
   	// sort using qsort()
   	qsort((void*) field, /*number of items*/ 100, /*size of an item*/ sizeof(field[0]),
   
   	/*comparison-function*/ CmpFunc);
   	// display first ten elements of the sorted field
   	printf("The first ten elements of the sorted field are ...\n");
   	for(int c=0;c<10;c++)
    		printf("element #%d contains %.0f\n", c+1, field[c]);
   	printf("\n");
  }
  ```
  * 3.5 Example A: Callback to member function using an additional argument
  ```c
  // Task: The function ’DoItA’ makes something which implies a callback to
  // the member function ’Display’. Therefore the wrapper function
  // ’Wrapper_To_Call_Display is used.
  #include <iostream.h> // due to: cout
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
  ```
  * 3.5 Example B: Callback to member function using a global variable
  ```c
  // Task: The function ’DoItB’ makes something which implies a callback to
  // the member function ’Display’. Therefore the wrapper function
  // ’Wrapper_To_Call_Display is used.
  #include <iostream.h> // due to: cout
  void* pt2Object; // global variable which points to an arbitrary object
  class TClassB {
    public:
     	void Display(const char* text) { cout << text << endl; };
     	static void Wrapper_To_Call_Display(char* text);
     	/* more of TClassB */
  };
  
  // static wrapper function to be able to callback the member function Display()
  void TClassB::Wrapper_To_Call_Display(char* string) {
   	// explicitly cast global variable <pt2Object> to a pointer to TClassB
   	// warning: <pt2Object> MUST point to an appropriate object!
   	TClassB* mySelf = (TClassB*) pt2Object;
   
   	// call member
   	mySelf->Display(string);
  }
  
  // function does something which implies a callback
  // note: of course this function can also be a member function
  void DoItB(void (*pt2Function)(char* text)) {
   	/* do something */
   	pt2Function("hi, i’m calling back using a global ;-)"); // make callback
  }
  
  // execute example code
  void Callback_Using_Global() {
   	// 1. instantiate object of TClassB
   	TClassB objB;
   
   	// 2. assign global variable which is used in the static wrapper function
   	// important: never forget to do this!!
   	pt2Object = (void*) &objB;
   
   	// 3. call ’DoItB’ for <objB>
   	DoItB(TClassB::Wrapper_To_Call_Display);
  }
  ```
  
  * 4 C 및 C++ 함수 포인터를 캡슐화하는 펑터 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer_Tutorials/Functor1.cpp)
  ```c
  #include <iostream>
  
  using namespace std;
  
  class TFunctor {
    public:
     	// two possible functions to call member function. virtual cause derived
     	// classes will use a pointer to an object and a pointer to a member function
     	// to make the function call
     	virtual void operator()(const char* string)=0; // call using operator
     	virtual void Call(const char* string)=0; // call using function
  };
  
  // derived template class
  template <class TClass> class TSpecificFunctor : public TFunctor {
   private:
    	void (TClass::*fpt)(const char*); // pointer to member function
    	TClass* pt2Object; // pointer to object
   public:
    	// constructor - takes pointer to an object and pointer to a member and stores
    	// them in two private variables
    	TSpecificFunctor(TClass* _pt2Object, void(TClass::*_fpt)(const char*))
    	{ pt2Object = _pt2Object; fpt=_fpt; };
    	
    	// override operator "()"
    	virtual void operator()(const char* string)
    	{ (*pt2Object.*fpt)(string);}; // execute member function
    	
    	// override function "Call"
    	virtual void Call(const char* string)
    	{ (*pt2Object.*fpt)(string);}; // execute member function
  };
  
  class TClassA {
    public:
    	TClassA(){};
    	void Display(const char* text) { cout << text << endl; };
    	/* more of TClassA */
  };
  
  // dummy class B
  class TClassB{
    public:
     	TClassB(){};
     	void Display(const char* text) { cout << text << endl; };
     	/* more of TClassB */
  };
  
  // main program
  int main(int argc, char* argv[]) {
    // 1. instantiate objects of TClassA and TClassB
    TClassA objA;
    TClassB objB;
   
    // 2. instantiate TSpecificFunctor objects ...
    // a ) functor which encapsulates pointer to object and to member of TClassA
    TSpecificFunctor<TClassA> specFuncA(&objA, TClassA::Display);
   
    // b) functor which encapsulates pointer to object and to member of TClassB
    TSpecificFunctor<TClassB> specFuncB(&objB, &TClassB::Display);
   
    // 3. make array with pointers to TFunctor, the base class, and initialize it
    TFunctor* vTable[] = { &specFuncA, &specFuncB };
   
    // 4. use array to call member functions without the need of an object
    vTable[0]->Call("TClassA::Display called!"); // via function "Call"
    (*vTable[1]) ("TClassB::Display called!"); // via operator "()"
    cout << endl << "Hit Enter to terminate!" << endl;
    cin.get();
    
    return 0;
  }
  ```
  ![image](https://github.com/user-attachments/assets/6a268582-8e4b-4b8c-90a7-0f3b23320f21)

