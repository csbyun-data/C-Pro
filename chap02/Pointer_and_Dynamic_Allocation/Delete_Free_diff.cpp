// C++ program to illustrate free() and delete keyword in C++
// delete는 소멸자 호출후 메모리해제지만 free()는 메모리만 해제함

#include "bits/stdc++.h"
using namespace std;
 
class A {
  int a;
 
public:
  int* ptr;
 
  // Constructor of class A
  A() {
    cout << "Constructor was Called!" << endl;
  }
 
  // Destructor of class A
  ~A() {
    cout << "Destructor was Called!" << endl;
  }
};
 
int main()
{
  // Create an object of class A using new operator
  A* a = new A;
  cout << "Object of class A was "
       << "created using new operator!" << endl;
 
  delete (a);
  cout << "Object of class A was "
       << "deleted using delete keyword!" << endl;
 
  cout << endl;
 
  A* b = (A*)malloc(sizeof(A));
  cout << "Object of class A was "
       << "created using malloc()!" << endl;
 
  free(b);
  cout << "Object of class A was "
       << "deleted using free()!" << endl;
 
  return 0;
}
