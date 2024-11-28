 /*
 *
 * Quick-sort C++ snippet using vector and iterator in STL.
 *
 * By Jianbao Tao @ SSL, UC Berkeley.
 * 
 * Variable names follow conventions in CLRS.
 *    
 * Interface:
 * 1. partition(A, p, r): Return an index q so that each element in A[p:q-1] is less
 *                        than A[q] and each element in A[q+1:r] is greater than A[q].
 * 2. quickSort(A, p, r): No return.
 * 
 * Operation flow in *partition*:
 * 1. Randomly pick an index irandom in [p, r], and swap A[r] with A[irandom].
 * 2. Use the new A[r] to be the pivot.
 * 3. Make a marching index iless so that it points to the last element that is
 *    less than the pivot and A[ismall+1] is greater than the pivot.
 * 4. Loop over A[p:r-1] with index j. If j > iless and A[j] is less than the pivot,
 *    then swap A[j] and A[iless+1].
 * 5. After the loop, swap A[r] and A[iless+1]
 * 6. Return iless+1 as q, i.e., q is the new position of the pivot.
 * 
 * Operation flow in *quickSort*.
 * if p < r:
 *         q = partition(A, p, r);
 *         quickSort(A, p, q-1);
 *         quickSort(A, q+1, r);
 *
 * Compile command:
 *   clang++ -stdlib=libc++ -std=c++ -o a.out main.cpp
 *
 * Sample output:
 * --------------
 * Original order:
 * 32 37 16 33 57 81 14 4 73 3
 * Sorted order:
 * 3 4 14 16 32 33 37 57 73 81
 *
 */
// https://www.cprogramming.com/snippets/source-code/quick-sort-using-vector-and-iterator-stl

#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using std::cout;
using std::endl;
using std::vector;

vector<int>::iterator partition( const vector<int> &A,
                                 const vector<int>::iterator &p,
                                 const vector<int>::iterator &r) {
  // Get a random element within A[p:r].
  auto seed = clock() * clock() * clock();
  std::default_random_engine dre(seed);
  std::uniform_int_distribution<size_t> di( 0, r-p);

  auto random_it=p;
  random_it = p+di(dre);

  // swap values of random_it and r.
  auto tmp = *random_it;
  *random_it = *r;
  *r = tmp;

  auto pivot=*r;

  int iless=-1;
  for( int i=0; i<r-p; i++) {
    if( *(p+i) <= pivot) {
      iless++;
      if(iless != i) {
        // Swap *(p+iless) and *(p+i)
        tmp = *(p+iless);
        *(p+iless) = *(p+i);
        *(p+i) = tmp;
      }
    }
  }
  // Swap *(p+iless+1) and *r
  *r = *(p+iless+1);
  *(p+iless+1) = pivot;

  return p+iless+1;
}

void quickSort( const vector<int> &A, const vector<int>::iterator &p,
                                      const vector<int>::iterator &r) {
  if( p<r ) {
    auto q = partition( A, p, r);
    quickSort( A, p, q-1);
    quickSort( A, q+1, r);
  }
}

int main( int argc, char *argv[]) {
  // Make a vector to hold a sample array
  vector<int> A;

  // Set up random number generator
  auto seed = clock() * clock() * clock();
  std::default_random_engine dre(seed); // engine
  std::uniform_int_distribution<int> di(0, 100); // distribution

  // Populate A with 10 random number in [0, 100].
  int num=10;
  for( int i=0; i!=num; i++) A.push_back( di(dre)); // Roll the die.

  // Original order.
  cout << "Original order:" << endl;
  for( auto it=A.begin(); it != A.end(); it++)
    cout << *it << " ";
  cout << endl;

  // Sort.
  auto p = A.begin();
  auto r = A.end()-1;
  quickSort( A, p, r);

  cout << "Sorted order:" << endl;
  for( auto it=A.begin(); it != A.end(); it++)
    cout << *it << " ";
  cout << endl;

  return 0;
}
