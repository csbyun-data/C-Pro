// C++ program to illustrate malloc() and new operator in C++
// malloc(), new 는 힙 메모리에 할당하고 new는 생성자를 호출 하지만, malloc는 호출하지 않음
#include "bits/stdc++.h"
using namespace std;

class A {
  int a;
public:
  int *ptr;

  // Constructor of class A
  A() {
    cout << "Constructor was Called!" << endl;
  }
};

int main()
{
  // Create an object of class A
  // using new operator
  A *a = new A;
  cout << "Object of class A was "
       << "created using new operator!" << endl;

  A *b = (A *)malloc(sizeof(A));
  cout << "Object of class A was "
       << "created using malloc()!" << endl;

  return 0;
}
