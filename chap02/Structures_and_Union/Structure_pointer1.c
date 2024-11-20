#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Declaration of structure in c
struct Laptop {
  float price;
  int ProductId;
  char name[24];
} Laptop1, *Laptop2;

int main( )
{
  printf("Access members using the variable of struct\n\n");
  Laptop1.price = 20045.56;
  Laptop1.ProductId = 345;
  strcpy( Laptop1.name, "Lenovo");

  printf( "Laptop price : %f\n", Laptop1.price);
  printf( "Laptop product Id : %d\n", Laptop1.ProductId);
  printf( "Laptop name : %s\n", Laptop1.name);
  printf("\n\nAccess members using the pointer to struct\n\n");

  //Assign memory to the pointer to structure
  Laptop2 = (struct Laptop *)malloc(sizeof(struct Laptop ));
  if(Laptop2 == NULL) {
    printf("Failed to allocate the memory");
    return -1;
  }
  Laptop2->price = 10045.56;
  Laptop2->ProductId = 245;
  strcpy(  Laptop2->name, "Dell");
  printf( "Laptop price : %f\n",  Laptop2->price);
  printf( "Laptop product Id : %d\n",  Laptop2->ProductId);
  printf( "Laptop name : %s\n",  Laptop2->name);

  //Now free the allocated memory
  free(Laptop2);
  Laptop2 = NULL;

  return 0;
}
