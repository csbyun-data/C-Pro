// A simple C program to delete node from the beginning
#include<stdio.h>
#include<stdlib.h>
 
// Creating Node
struct Node {
  int iData;
  struct Node *pNextNode;
};
 
// Define the new type Node type and Node pointer
typedef  struct Node  NodeType, * NodePointer;

/*Delete node from the beginning.
Paas the reference of the head pointer of a list.
*/
int DeleteFromBeginning(NodePointer  *pHead) {
	int iRetValue = -1;
	NodePointer pTmpNode = NULL;
	
	//If there is no node then perform no operation
	if((*pHead) !=  NULL) {
		pTmpNode = (*pHead)->pNextNode;
		
		//Free the first node
		free((*pHead));
		//Assign the address of second node to head pointer
		(*pHead) = pTmpNode;
		iRetValue =0;
	}
	return iRetValue;
}

/* Paas the reference of the head pointer of a list and 
   an integer data. This function use to add the node at the End*/
int InsertNodeAtEnd(NodePointer * pHead, int iUserData) {
	int iRetValue = -1;
	
	NodePointer pLastNode = NULL;
	NodePointer pNewNode = NULL;
	
	//Give the Address of first Node
	pLastNode  = *pHead;
	
	// Call malloc to allocate memory in heap for the new node
	pNewNode = (NodePointer)malloc(sizeof(NodeType));
	
	if( pNewNode != NULL) { //Check allocated memory
		pNewNode->iData = iUserData; //put the desire Data
		pNewNode->pNextNode  = NULL; //Give the Address of first Node
		iRetValue = 0; // Update the return value
	}

	// If there is no node in beginning
	if(pLastNode == NULL) {
		*pHead = pNewNode;
	} else {
		// Find the address of last node
		while( pLastNode ->pNextNode != NULL) {
			pLastNode  = pLastNode ->pNextNode;
		}
	
	   // Assign last node address
	    pLastNode ->pNextNode = pNewNode;
	}
	return iRetValue;
}

/* Paas the reference of the head pointer of a list. This function use
to free the all allocated memory*/
void FreeAllocatedMemory(NodePointer  *pHead) {
  NodePointer   pTmpNode = NULL;
  NodePointer   pFirstNode = NULL;
  //Assign  the Address of first node
  pFirstNode  = *pHead;
   
  /*check if pFirstNode is NULL, then now list is empty,
  so assign NULL to head and return.*/
  while (pFirstNode  != NULL) {
	 /*Save the pFirstNode in a pTmpNode node pointer*/ 

    pTmpNode = pFirstNode  ;
       
    /*Assign the address of next on your list*/	
    pFirstNode  = pFirstNode->pNextNode;
       
    //Free the allocated memory
    free(pTmpNode );
  }
  //Assign NULL to the head pointer
  *pHead = NULL;
}
 
// This function use to prints the data of the list from the begning
//to the given list.
void PrintTheList(NodePointer pNode) {
	//Clear the screen
  
  printf("\nDisplay Linked List: \n\n");
  while (pNode != NULL) {
     printf(" %d\n",pNode->iData);
     pNode = pNode->pNextNode;
  }
  printf("\n\n"); 
}

int CreateLinkedList(NodePointer *pHead, int iNumberofNode) {
	int iData = 0;
	int iRetValue = -1;
	int iCount = 0;
	NodePointer pNewNode = NULL;
	
	for(iCount =0; iCount < iNumberofNode; iCount++) {
		/*Enter desire data*/
		printf("Enter the Data = ");
		scanf("%d",&iData);
		
		if((*pHead) == NULL) {
			 // Call malloc to allocate memory in heap for the first node
       pNewNode = (NodePointer)malloc(sizeof(NodeType));
       if( pNewNode != NULL) { //Check allocated memory
 		     pNewNode->iData = iData; //put the desire Data
		     pNewNode->pNextNode  = NULL; //Give the Address of first Node
		     *pHead = pNewNode; /*Assign the address of 
		                      first node to the head pointer*/
			   iRetValue = 0; // Update the return value
	    }
		} else {
			//Add the Node at the End
			iRetValue = InsertNodeAtEnd(pHead,iData);
		}
	}
	return iRetValue;
}

/* Driver program to test above functions*/
int main(void)
{
   int iNumberNode =0;
   int iData = 0;
   int iPosition =0;
	
   /*Start with the empty list */
   NodePointer head = NULL;
   
   printf("\n\nEnter the number of nodes = ");
   scanf("%d",&iNumberNode);
   
   //Create a linked list of three node
   CreateLinkedList(&head,iNumberNode);
		
	/*
	pHead
	|
	v
	---------     ---------     ---------
	| 10 | --+--->| 20 |  --+--->| 30 | 0|
	---------     ---------     ---------
	*/

   //Print the created node
   PrintTheList(head);
   
   printf("Delete a Node from the beginning\n");
   // Delete the beginning node
   DeleteFromBeginning(&head);
	/*  
	
	pHead
	|
	+---------------+
				    |
				    v
	---------     ---------     ---------
	| 10 | --+--->| 20 | --+--->| 30 | 0|
	---------     ---------     ---------
	*/
   
    //Print the created node
   PrintTheList(head);
   		   
   FreeAllocatedMemory(&head);
   
  return 0;
}

// output:
// Enter the number of nodes = 3
// Enter the Data = 10
// Enter the Data = 20
// Enter the Data = 30

// Display Linked List:

// 10
// 20
// 30


// Delete a Node from the beginning

// Display Linked List:

// 20
// 30  
