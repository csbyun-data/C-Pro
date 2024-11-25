// https://www.cprogramming.com/tutorial/c/lesson18.html

#include <stdio.h>
#include <stdlib.h>

struct node {
	int key_value;
	struct node *left;
	struct node *right;
};

struct node *root = 0;

void destroy_tree(struct node *leaf) {
	if(leaf != 0) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		free(leaf);
	}
}

struct node *insert(int key, struct node **leaf) {
    if( *leaf == 0 ) {
        *leaf = (struct node *) malloc( sizeof( struct node ) );
        (*leaf)->key_value = key;
        /* initialize the children to null */
        (*leaf)->left = 0;    
        (*leaf)->right = 0;  
    } else if(key < (*leaf)->key_value) {
        insert( key, &(*leaf)->left );
    } else if(key > (*leaf)->key_value) {
        insert( key, &(*leaf)->right );
    }
    return (*leaf);
}

struct node *search(int key, struct node *leaf) {
  if( leaf != 0 ) {
      if(key==leaf->key_value) {
          return leaf;
      } else if(key<leaf->key_value) {
          return search(key, leaf->left);
      } else {
          return search(key, leaf->right);
      }
  } else return 0;
}
void printInorder(struct node *leaf) {
  if(leaf != 0) {
    printInorder(leaf->left);
    printf("inorder = %d\n", leaf->data);
    printInorder(leaf->right);
  }
}

struct node *create() {
    struct node * pr = insert(4, 0);
    insert(1, pr);
    insert(2, pr);
    insert(3, pr);
    insert(5, pr);
    insert(6, pr);
 
    return pr;
}
    
int main(void)
{
  struct node *pr;
  
  pr = create();
  printInorder();
  
  return 0;
}
