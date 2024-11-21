// A simple C program to introduce a linked list
#include<stdio.h>
#include<stdlib.h>

// Creating Node
 struct Node {
  int iData;
  struct Node *pNextNode;
};

// Define the new type Node type and Node pointer
typedef  struct Node  NodeType, * NodePointer;

// This function use to prints the data of the list from the begning to the given list.
void PrintTheList(struct Node *pNode) {
  int iCountOfNode = 0;

  while (pNode != NULL) {
     printf("Value of %d Node = %d\n", ++iCountOfNode , pNode->iData);
     pNode = pNode->pNextNode;
  }
}
 
// Program to create linked-list of 4 node
int main(void)
{
  NodePointer pHead = NULL;
  NodePointer pFirstNode = NULL;
  NodePointer pSecondNode = NULL;
  NodePointer pThirdNode = NULL;
  NodePointer pFourthNode = NULL;
 
  // allocate 4 nodes in the heap  
  pFirstNode =  malloc(sizeof(NodeType)); 
  pSecondNode = malloc(sizeof(NodeType));
  pThirdNode =  malloc(sizeof(NodeType));
  pFourthNode =  malloc(sizeof(NodeType));
 
  /* Four blocks have been allocated  dynamically using the malloc and
     these allocated block are pointed by the node pointters pFirstNode, pSecondNode , pThirdNode
	and pFourthNode. 

	 pFirstNode           pSecondNode      
          |                    |
    +-----+-------+      +-----+---------+  
    |Data | Address|     | Data | Address| 
    +-----+-------+      +------+--------+  		

		pThirdNode         pFourthNode      
          |                    |
    +-----+-------+      +-----+---------+  
    |Data | Address|     | Data | Address| 
    +-----+-------+      +------+--------+  
	*/
	 
  pFirstNode->iData = 3; //assign 3 in iData of first node
  pFirstNode->pNextNode = pSecondNode; // Assign Address of Second Node
  pHead = pFirstNode; // Assign Address of first node to head pointer
  
  /*
      		       pFirstNode               pSecondNode      
				 	    |                      |
				  +-----+-------+      +-----+---------+  
  pHead---------->|   3 |       |----->| Data | Address| 
				  +-----+-------+      +------+--------+  
  */

  pSecondNode->iData = 10; //assign 10 in iData of second node
  pSecondNode->pNextNode = pThirdNode; //Assign Address of third Node
  
  /*
				   pFirstNode         pSecondNode                pThirdNode      
				 	  |                    |                         |
				  +-----+-------+      +------+------+       +-----+---------+  
  pHead---------->|3    |       |----->|  10  |      |------>| Data | Address| 
				  +-----+-------+      +------+------+       +------+--------+  
  */
  
  pThirdNode->iData = 2; //assign 2 in iData of third node
  pThirdNode->pNextNode = pFourthNode; //Assign Address of fourth Node
  
  /*
				   pFirstNode         pSecondNode                pThirdNode             pSecondNode      
				 	  |                    |                         |                      |
				  +-----+-------+      +------+--------+       +-----+------+      +-----+---------+      
  pHead---------->|3    |       |----->|  10  |        |------>| 2   |      |----->| Data | Address| 
				  +-----+-------+      +------+--------+       +------+-----+      +------+--------+   
  */
  
  pFourthNode->iData = 1; //assign 1 in iData of fourth node
  pFourthNode->pNextNode = NULL; //Assign NULL to indicate that linked list is terminated here.
  
  /* 
  			   pFirstNode         pSecondNode                pThirdNode           pSecondNode          
				 	  |                    |                         |                   |
				  +-----+-------+      +------+--------+       +-----+------+      +-----+--------+      
  pHead---------->|3    |       |----->|  10  |        |------>| 2   |      |----->| 1   |    NULL|    
				  +-----+-------+      +------+--------+       +------+-----+      +------+-------+   
  */
  
  PrintTheList(pHead);   
	
 // After the use of linked-list explicitly delete the all nodes
 free(pFirstNode);
 pFirstNode = NULL;
 
 free(pSecondNode);
 pSecondNode = NULL;
 
 free(pThirdNode);
 pThirdNode = NULL;
 
 free(pFourthNode);
 pFourthNode = NULL;
 
 pHead = NULL;
  
  return 0;
}

// output:
// Value of 1 Node = 3
// Value of 2 Node = 10
// Value of 3 Node = 2
// Value of 4 Node = 1
