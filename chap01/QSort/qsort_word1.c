#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char word[10];
} book;

// strcmp(), 문자열 비교에 사용
int compare ( const book *a, const book *b) {
  return strcmp( a->word, b->word);
}

int main()
{
  book N[10] = { "english", "see", "korea", "hello", "world", "live",
                   "summit", "pizza", "dog", "cat"};
  qsort( N, 10, sizeof(book), compare);

  for ( int i=0; i<10; i++) 
    printf("[%s] ", N[i].word);

  return 0;
}    
