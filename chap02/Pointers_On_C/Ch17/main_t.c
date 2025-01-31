//main.c file
/* 17.10-9 & 10 */
#include <stdio.h>
#include "llist_tree.h"

int main( void ) {
  char cmd;
  int value, flag = 1;
  BST **node_ptr;
  
  while( flag ) {
    printf( "* i, d, f: insert(i), delete(d), find(f) a new value to the tree***\n" );
    printf( "* I, p, P: print tree's nodes in in-order(I), pre-order(p), post-order(P)*\n" );
    scanf( " %c", &cmd );
  
    switch( cmd ) {
    case 'i':
      printf( "Enter a value for the new node: " );
      scanf( " %i", &value );
      insert( value );
      break;
    case 'd':
    case 'D':
      printf( "Enter the value to delete: " );
      scanf( " %i", &value );
      delete( value );
      break;
    case 'f':
    case 'F':
      printf( "Enter the value to find: " );
      scanf( " %i", &value );
  
      if( *( node_ptr = find( value ) ) != NULL )
        printf( "The value %i is found\n", (*node_ptr)->value );
      else
        printf( "The value is not found!\n" );
  
      break;
    case 'I':
      in_order_traverse( print_node );
      printf( "\n" );
      break;
    case 'p':
      pre_order_traverse( print_node );
      printf( "\n" );
      break;
    case 'P':
      post_order_traverse( print_node );
      printf( "\n" );
      break;
    default:
      printf( "Illegal cmd detected!\n" );
  
    }
  
    printf( "Do you want to continue: [Y/N] " );
    scanf( " %c", &cmd );
    flag = cmd == 'Y' || cmd == 'y' ? 1 : 0;
  }
  
  destroy_tree();
  return 0;
}
