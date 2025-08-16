// reference와 pointer 비교

#include <iostrem>
using namespace std;

int main() {
  int a = 10;
  int *ptr = &a;

  *ptr = 100;
  cout << "a = " << a << endl;
}
