## 01. Linked List
### Index
[참조: aticleworld.com](https://aticleworld.com/c-programming/#)
* 1.Linked List
  * 1.1 Linked List [Linked List](https://github.com/csbyun-data/C-Programming/blob/main/chap04/Linked_List/Linked_List_ex1.c)
  
  ![image](https://github.com/user-attachments/assets/9e41c1a5-84d0-47df-b274-862cd3f0c511)
  ```c
  int aiSallary[10] = { 400, 1200, 2000, 4500, 5000 };
  // Linked List를 사용하는 이유
  // 메모리 재할당이 없이 요소를 추가, 삭제하기 쉬움

  // Random하게 data를 access할 수 있음
  // Data를 찾기 위해 시간이 소요됨
  ```
  * 1.2 Linked List Insertion( 첫번째 순서에 Node를 추가)
  ```c
  //Linked List에 Node를 insert하는 순서

  //1. new node를 메모리에 생성
  NodePointer pNewNode = malloc(sizeof(NodeType));

  //2. data field에 값을 입력
  if(pNewNode != NULL) {
    pNewNode->iData = Value;
  }

  //3. New Node에 첫번째 Node의 주소를 포인터에 할당
  pNewNode ->pNextNode = head;

  //4. Head 포인터에 생성된 Node의 주소를 할당
  Head = pNewNode;
  ```
  *  1.3 중간의 어느 지점에 node를 삽입하는 경우
  ```c
  // Insert a new node after a node
  //1. Head Pointer에 저장된 값을 Temp Node에 저장
  NodePointer pTmpNode = head;

  //2. New Node를 삽입할 위치를 Node의 주소를 get
  for( iPosition = 1 ; iPosition < specified_Position ; iPosition++)
    pTmpNode = pTmpNode ->pNextNode;

  //3.New Node 생성
  NodePointer pNewNode = malloc(sizeof(NodeType));

  //4. New Node에 Value 입력
  if(pNewNode != NULL) {
    pNewNode->iData = Value;
  }

  //5. New Node의 지시Pointer를 입력
  pNewNode->pNextNode = pTmpNode->pNextNode;

  //6. Temp Node의 지시Pointer에 New Node의 Pointer 할당
  pTmpNode->pNextNode = pNewNode;
  ```
  그림
  ([InsertNodeAfterNode()함수 구현](https://github.com/csbyun-data/C-Programming/blob/main/chap04/Linked_List/InsertNodeAfterNode_func1.c))
  
  *  1.4 마지막 node에 신규 node를 입력
  ```c
  //1. Temp Node에 Head Pointer 할당
  NodePointer pTmpNode = head;

  //2. Last Node의 Pointer를 찾음
  While( pTmpNode ->pNextNode != NULL) {
    pTmpNode = pTmpNode ->pNextNode;
  }

  //3. New Node 메모리 할당
  NodePointer pNewNode = malloc(sizeof(NodeType));

  //4. New Node의 값을 입력
  if(pNewNode != NULL) {
    pNewNode->iData = Value;
  }

  //5. New Node의 POinter를 마지막 Node Pointer에 입력
  pTmpNode->pNextNode = pNewNode;

  //6. New Node의 Pointer는 NULL로 입력
  pNewNode->pNextNode = NULL;
  ```
  그림
  * 1.5 할당된 메모리 전체를 풀어줌
  ```c
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
  
  ```
  1.6 예제를 구현한 Linked List [Ex1](https://github.com/csbyun-data/C-Programming/blob/main/chap04/Linked_List/Linked_List_ex2.c)
* 2.Delete a Linked List node
  *  2.1 시작 node 삭제 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap04/Linked_List/Delete_start_node.c)
  사진

  *  2.2 중간 node 삭제 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap04/Linked_List/Delete_middle_node.c)
  사진  

  *  2.3 끝 node 삭제 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap04/Linked_List/Delete_end_node.c)

* 3.Generic Linked List in C
  *  3.1 Generic Linked List
  *  3.2 Function to add a node at the end of the Generic Linked List
  *  3.3 Free the all allocated memory
  *  3.4 Driver program to create a Generic Linked List
