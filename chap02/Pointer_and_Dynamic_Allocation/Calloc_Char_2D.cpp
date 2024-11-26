#include <cstdlib>
#include <cstring>
#include <iostream>

// Function to sort the value
void sort( char **names, int n) {
  int i, j;

  // Perform sort operation using bubble sort
  for( i=0; i<n-1; i++)
    for( j=0; j<n-1; j++)
      if( strcmp(names[j], names[j+1]) > 0) {
        char *temp;
        temp = (char *)calloc(30, sizeof(char));
        strcpy( temp, names[j]);
        strcpy( names[j], names[j+1]);
        strcpy( names[j+1], temp);

        free(temp);
      }
}

int main()
{
  char **names;
  int n, i;
  std::cout << "Enter the number of names to be printed: ";
  std::cin >> n;

  // Allocating memory for 1st dimension
  names = (char **)calloc( n, sizeof(char *));

  // Allocating memory for 2nd dimension
  for( i=0; i<n; i++) {
    names[i] = (char *)calloc( 30, sizeof(char));
    std::cin >> names[i];
  }

  sort( names, n);

  std::cout << "\nArray after sorting:\n";
  for( i=0; i<n; i++)
    std::cout << names[i] << std::endl;

  // Delete the array created
  for( i=0; i<n; i++) // To delete the inner arrays
    free(names[i]);
  free(names); // To delete the outer array which contained the pointers
               // of all the inner arrays
  return 0;
}
