// C++ program to dynamically allocate the memory for 3D array in C++
// using new operator

#include <iostream>
using namespace std;

int main()
{
  // Dimensions of the 3D array
  int x=2, y=3, z=4;
  int count =0;

  // Allocate memory blocks of size x i.e., no of 2D arrays
  int ***a = new int**[x];

  for( int i=0; i<x; i++) {
    // Allocate memory blocks for rows of each 2D array
    a[i] = new int*[y];
    for( int j=0; j<y; j++) {
      // Allocate memory blocks for
      // columns of each 2D array
      a[i][j] = new int[z];
    }
  }

  for( int i=0; i<x; i++) {
    for( int j=0; j<y; j++) {
      for( int k=0; k<z; k++) {
        a[i][j][k] = ++count;
      }
    }
  }

  for( int i=0; i<x; i++) {
    for( int j=0; j<y; j++) {
      for( int k=0; k<z; k++) {
        // Print values of the memory blocks created
        cout << a[i][j][k] << " ";
      }
      cout << endl;
    }
    cout <<endl;
  }

  // Deallocate memory
  for( int i=0; i<x; i++) {
    for( int j=0; j<y; j++) {
      delete[] a[i][j];
    }
    delete[] a[i];
  }
  delete[] a;

  return 0;
}
