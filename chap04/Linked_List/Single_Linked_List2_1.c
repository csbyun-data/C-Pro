/*
1) 프로그램 종료 전에 메모리 할당된 노드 전체를 해제하는 로직이 없다
2) 데이터를 출력하는 로직이 없다
3) main() 함수에서 할당된 NODE를 드라이빙 할 수있는 변수가 없다
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define INSERT 1
#define REMOVE 2

struct NODE {
  struct NODE *next;
  int data;
};

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

int solution(int cmd[][2], int cmd_len) {
	//헤드 노드 생성
  struct NODE *head = (struct NODE*)malloc(sizeof(struct NODE));
  head->next = NULL;
  
  for(int i = 0; i < cmd_len; i++){
    if(cmd[i][0] == INSERT)
      insertNode(head, cmd[i][1]);
    else if(cmd[i][0] == REMOVE)
      removeNode(head, cmd[i][1]);
  }
  
  int count = 0;
  struct NODE *currNode = head -> next;
  while (currNode != NULL){
    count += 1;
    currNode = currNode->next;
  }
  
  return count;
}

int main() {
  int cmd[7][2] = {{1,1},{1,4},{1,2},{1,3},{1,1},{2,2},{2,1}};
  int cmd_len = 7;
  int ret = solution(cmd, cmd_len);
  
  printf("Ret Node갯수: %d .\n", ret);
}
