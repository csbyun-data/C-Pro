/* Paas the reference of the head pointer of a list and
   an integer data. This function use to add the node at the End*/
int InsertNodeAtEnd(NodePointer * pHead, void *InputData, int SizeofData) {
    int iRetValue = -1;
    int iOffSet = 0;
    NodePointer pLastNode = NULL;
    NodePointer pNewNode = NULL;
    //Give the Address of first Node
    pLastNode  = *pHead;
    // Call malloc to allocate memory in heap for the new node
    pNewNode = malloc(sizeof(NodeType));
    if( pNewNode != NULL) { //Check allocated memory
        pNewNode->iData = malloc(SizeofData); //put the desire Data
        //Copy the bytes of data as per the data types
        for (iOffSet = 0; iOffSet < SizeofData; iOffSet++)
            *((uint8_t *)(pNewNode->iData  + iOffSet)) =  *((uint8_t *)(InputData + iOffSet));
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
