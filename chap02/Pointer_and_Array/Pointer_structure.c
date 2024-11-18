#include <stdio.h>
#include<string.h>
#include <stdlib.h>

// structure to store the information of book
typedef struct sBook {
  char Name[20];
  char AuthorName[20];
  int PageNumber;
  int Price;
} sBook;

int main(int argc, char *argv[])
{
  sBook *psCBook = NULL; // create pointer to structure
  psCBook = malloc(sizeof(sBook)); // allocate memory to structure

  strcpy(psCBook->Name,"C world"); // copy the book name
  strcpy(psCBook->AuthorName,"Amlendra Kumar"); // copy author name

  psCBook->PageNumber = 1600; // assign number of page
  psCBook->Price = 1000; // Assign the price

  //Print the store data
  printf("Book Name = %s\n",psCBook->Name);
  printf("Book Author Name = %s\n",psCBook->AuthorName);
  printf("Book PageNumber = %d\n",psCBook->PageNumber);
  printf("Book Price = %d\n",psCBook->Price);

  // free the allocated memory
  free(psCBook);

  psCBook = NULL;

  return 0;
}
