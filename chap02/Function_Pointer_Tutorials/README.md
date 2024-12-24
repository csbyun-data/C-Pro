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
  * 1.2 Introductory Example or How to Replace a Switch-Statement
  ```
  // Task: Perform one of the four basic arithmetic operations specified by the
  // characters ’+’, ’-’, ’*’ or ’/’.
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
      case ’+’ : result = Plus (a, b); break;
      case ’-’ : result = Minus (a, b); break;
      case ’*’ : result = Multiply (a, b); break;
      case ’/’ : result = Divide (a, b); break;
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
  * 2 The Syntax of C and C++ Function Pointers
  * 2.1 define a function pointer and initialize to NULL
  * 2.2 define the calling convention
  * 2.3 assign an address to the function pointer
  * 2.4 comparing function pointers
  * 2.5 calling a function using a function pointer
  * 2.6 How to Pass a Function Pointer
  * 2.7 How to Return a Function Pointer
  * 2.8 How to Use Arrays of Function Pointers
  * 3.2 How to Implement a Callback in C ?
  * 3.3 How to make a callback in C by the means of the sort function qsort
  * 3.5 Example A: Callback to member function using an additional argument
  * 3.5 Example B: Callback to member function using a global variable
  * 4 C 및 C++ 함수 포인터를 캡슐화하는 펑터
    
