// reference와 pointer 비교

#include <iostrem>
using namespace std;

int main() {
  int a = 10;
  int &ref = a;

  ref = 100;
  cout << "a = " << a << endl;
}
