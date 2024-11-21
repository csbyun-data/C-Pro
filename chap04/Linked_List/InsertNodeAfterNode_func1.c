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
    NodePointer pNewNode = malloc(sizeof(NodeType));

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
