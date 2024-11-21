// A simple C program to introduce a linked list
#include<stdio.h>
#include<stdlib.h>

// Creating Node
struct Node {
  /*Data field*/
  int iData;
  /*Node Pointer*/
  struct Node *pNextNode;
};

// Define the new type Node type and Node pointer
typedef  struct Node  NodeType, * NodePointer;

/* Paas the reference of the head pointer of a list and
   an integer data. This function use to add the node at the beginning*/
int InsertNodeAtBeginning(NodePointer * pHead, int iUserData) {
  int iRetValue = -1;

  // Call malloc to allocate memory in heap for the new node
  NodePointer pNewNode = (NodePointer)malloc(sizeof(NodeType));

  if( pNewNode != NULL) //Check allocated memory {
    pNewNode->iData = iUserData; //put the desire Data
    pNewNode->pNextNode  = *pHead; //Give the Address of first Node
    *pHead = pNewNode; // Assign the Address of New Node to Head
    iRetValue = 0; // Update the return value
  }
  return iRetValue;
}

/* Paas the reference of the tempnode pointer of a list and an integer data*/
int InsertNodeAfterNode(NodePointer * pHead, int iUserData,unsigned int iPosition) {
  int iRetValue = -1;
  NodePointer pTmpNode = NULL;
  unsigned int iCount = 0;

  //Give the Address of first Node
  pTmpNode  = *pHead;

  for( iCount = 1; ((iCount < iPosition) && (pTmpNode!= NULL)) ; iCount++) {
    pTmpNode  = pTmpNode ->pNextNode;
  }

  /* check the pTmpNode*/
  if (pTmpNode == NULL) {
    printf("Enter Position is Invalid\n");
    return iRetValue;
  } else {
    /*  allocate memory for the new node */
    NodePointer pNewNode = (NodePointer)malloc(sizeof(NodeType));

    if( pNewNode != NULL) {
      //put in the data
      pNewNode->iData = iUserData;
      //Assign the address of next node to the new node
      pNewNode->pNextNode = pTmpNode->pNextNode;

      // Assign the address of new node to the previous node
      pTmpNode->pNextNode = pNewNode;

      iRetValue = 0;
    }
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

  if( pNewNode != NULL) //Check allocated memory {
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
  printf("Linked List is: \n");
  while (pNode != NULL) {
    printf("\n %d\n\n",pNode->iData);
    pNode = pNode->pNextNode;
  }
  system("pause");
}

//Create a linked list of certain number of nodes
int CreateLinkedList(NodePointer *pHead, int iNumberofNode) {
  int iData = 0;
  int iRetValue = -1;
  int iCount = 0;

  for(iCount =0; iCount < iNumberofNode; iCount++) {
    /*Enter desire data*/
    printf("Enter the Data = ");
    scanf("%d",&iData);

    if((*pHead) == NULL) {
      //Create First Node
      iRetValue = InsertNodeAtBeginning(pHead,iData);
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
  int iChoice = 0;
  int iNumberNode =0;
  int iData = 0;
  int iPosition =0;

  /*Start with the empty list */
  NodePointer head = NULL;

  while(1) {
    //Select the Choice as per the requirements
    printf("\n\n\
         1: Create the Linked List\n\
         2: Display The Linked List\n\
         3: Insert Node at the begninig of Linked list\n\
         4: Insert Node at the End of Linked List \n\
         5: insert Node After a Node \n\
         6: terminatethe process \n\n\n");

    printf("enter your choice = ");
    scanf("%d",&iChoice);
    switch(iChoice) {
    case 1:
        printf("Enter the number of nodes = ");
        scanf("%d",&iNumberNode);
        CreateLinkedList(&head,iNumberNode);
        break;
    case 2:
        PrintTheList(head);
        break;
    case 3:
        printf("Enter the desired data = ");
        scanf("%d",&iData);
        InsertNodeAtBeginning(&head,iData);
        break;
    case 4:
        printf("Enter the desired data = ");
        scanf("%d",&iData);
        InsertNodeAtEnd(&head,iData);
        break;
    case 5:
        printf("Enter the Position = ");
        scanf("%d",&iPosition);
        printf("\nEnter the desired data = ");
        scanf("%d",&iData);
        InsertNodeAfterNode(&head,iData,iPosition);
        break;
    case 6:
        printf("Free the all Allocated memory\n");
        FreeAllocatedMemory(&head);
        printf("process is terminated\n ");
        exit(1);
        break;
    }
  }
  return 0;
}
