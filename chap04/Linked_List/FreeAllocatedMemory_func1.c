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
        //Free the data
        free(pTmpNode->iData);
        //Free the allocated memory
        free(pTmpNode );
    }
    //Assign NULL to the head pointer
    *pHead = NULL;
}
