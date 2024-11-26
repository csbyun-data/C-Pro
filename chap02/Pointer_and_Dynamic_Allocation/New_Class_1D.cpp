#include <iostream>

using namespace std;

class Test 
{
private:
  int _data;
public:
  Test() : _data(0) {}
  Test( int data) { this->_data = data; }

  int getData() { return _data; }
};

int main()
{
  Test *pMemory=0;
  int size;

  cout << "할당된 메모리 크기? == ";
  cin >> size;

  // 객체 size만큼 생성
  pMemory = new Test[size];

  //...
  cout << "할당된 메모리 해제." << endl;
  delete[] pMemory;

  // 객체 1개 생성
  pMemory = new Test(10);
  cout << "getData = " << pMemory->getData() << endl;
  delete pMemory;
}
