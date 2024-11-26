// C++ program to dynamically allocate
// the memory for 2D array in C++ using new operator
#include <iostream>
using namespace std;

int main()
{
  // Dimensions of the array
  int m=3, n=4, c=0;

  // Declare memory block of size M
  int **a = new int*[m];

  for( int i=0; i<m; i++) {
    // Declare a memory block of size n
    a[i] = new int[n];
  }

  // Traverse the 2D array
  for( int i=0; i<m; i++) {
    for( int j=0; j<n; j++) {
      // Assign values to the memory blocks created
      a[i][j] = ++c;
    }
  }

  // Traverse the 2D array
  for( int i=0; i<m; i++) {
    for( int j=0; j<n; j++) {
      // Assign values to the memory blocks created
      cout << a[i][j] << " ";
    }
    cout << endl;
  }

  // Deleted the array created
  for( int i=0; i<m; i++)  // to delete the inner arrays
    delete[] a[i];
  delete[] a; // to delete the outer array
              // which contained the pointers
              // of all the inner arrays
  return 0;
}
    
