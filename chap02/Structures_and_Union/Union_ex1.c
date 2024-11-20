#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Declaration of C union
union Laptop {
  float price;
  int productId;
  char name[24];
};

int main( )
{
  //creation union object
  union Laptop laptop1;
  //creation pointer to the union
  union Laptop *pLaptop2;

  //Access members using the union object
  printf("Access Members of Union using the union object\n");
  laptop1.price = 20045.56;
  printf( "Laptop price : %f\n", laptop1.price);
  laptop1.productId = 345;
  printf( "Laptop product Id : %d\n", laptop1.productId);
  strcpy( laptop1.name, "Lenovo");
  printf( "Laptop name : %s\n", laptop1.name);
  
  //Access members using the pointer to union
  printf("\n\nAccess Members of Union using the pointer to union\n");

  //Assign memory to the pointer to union
  pLaptop2 = (unoin Laptop *)malloc(sizeof(union Laptop ));
  if(pLaptop2 == NULL) {
    printf("Failed to allocate the memory");
    return -1;
  }
  pLaptop2->price = 10045.56;
  printf( "Laptop price : %f\n",  pLaptop2->price);
  pLaptop2->productId = 245;
  printf( "Laptop product Id : %d\n",  pLaptop2->productId);
  strcpy(  pLaptop2->name, "Dell");
  printf( "Laptop name : %s\n",  pLaptop2->name);

  //Now free the allocated memory
  free(pLaptop2);
  pLaptop2 = NULL;

  return 0;
}

// output:
// Access Members of Union using the union object
// Laptop price : 20045.560547
// Laptop product Id : 345
// Laptop name : Lenovo

// Access Members of Union using the pointer to union
// Laptop price : 10045.559570
// Laptop product Id : 245
// Laptop name : Dell
