#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INSERT 1
#define REMOVE 2

struct NODE {
  struct NODE *next;
  int data;
};

// count 변수를 Global 변수선언 
static int count = 0;

void insertNode(struct NODE *target, int data){
  struct NODE *newNode = (struct NODE*)malloc(sizeof(struct NODE));
  newNode->next = target->next;
  newNode->data = data;
  target->next = newNode;
}

void removeNode(struct NODE *head, int data){
  struct NODE *currNode = head;
  while(currNode->next != NULL){
    if(currNode->next->data == data){
      struct NODE *tempNode = currNode->next;
      currNode->next = currNode->next->next;
      free(tempNode);
    }
    else
      currNode = currNode->next;
  }
}

//add print_node function 
void print_node(struct NODE *head ) { 
  /* recursively print node's value */
	if( head != NULL ) {
		printf( "-> %d", head->data );
		print_node( head->next );
	}
}

//add free_node function
void free_node(struct NODE *head){ 
  /* recursively free memory */
  if(head->next != NULL)
      free_node(head->next);
  printf("freed node's value: %d\n", head->data);
  free(head);
}

//int solution(int cmd[][2], int cmd_len) {	
struct NODE* solution(struct NODE *head, int cmd[][2], int cmd_len) {

	//헤드 노드 생성
  head = (struct NODE*)malloc(sizeof(struct NODE));
  head->next = NULL;
  head->data = -1;
  
  for(int i = 0; i < cmd_len; i++){
    if(cmd[i][0] == INSERT) {
      insertNode(head, cmd[i][1]);
      print_node(head);
      printf("\n");
    }
    else if(cmd[i][0] == REMOVE) {	
      removeNode(head, cmd[i][1]);
      print_node(head);
      printf("\n");            
    }
  }
    
  struct NODE *currNode = head -> next;
  while (currNode != NULL){
    count += 1;
    currNode = currNode->next;
  }
  
  return head;
}

int main() {
  int cmd[7][2] = {{1,1},{1,4},{1,2},{1,3},{1,1},{2,2},{2,1}};
  int cmd_len = 7;
  
  //addition code, main() funtion에 변수선언 
  struct NODE *head;
   
  head = solution(head, cmd, cmd_len);
  printf("\nRet Node갯수: %d .\n", count);
  
//program 종료전에 할당 메모리 해제    
  free_node(head);
  
  return 0;
}
