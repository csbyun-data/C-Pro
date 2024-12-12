// Stack을 이용한 infix를 postfix로 변환

#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //isdigit()

#define MAX_SIZE 100

// 스택 정의
struct Stack {
  int top;
  unsigned capacity;
  char* array;
};

// 스택 연산 - push
void push(struct Stack* stack, char item) {
  stack->array[++stack->top] = item;
}

// 스택 연산 - pop
char pop(struct Stack* stack) {
  if (stack->top == -1)
    return '\0';
  return stack->array[stack->top--];
}

// 스택 연산 - top
char peek(struct Stack* stack) {
  return stack->array[stack->top];
}

// 연산자의 우선순위 반환
int precedence(char op) {
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;
  if (op == '^')
    return 3;
  return 0;
}

// infix를 postfix로 변환하는 함수
void infixToPostfix(char* infix, char* postfix) {
  struct Stack stack;
  stack.capacity = MAX_SIZE;
  stack.top = -1;
  stack.array = (char*)malloc(stack.capacity * sizeof(char));
  
  int i, j;
  for (i = 0, j = 0; infix[i]; ++i) {
    printf("\n[%02d] %c ", i, infix[i]);
    // 숫자인 경우 출력
    if (isdigit(infix[i]) || isalpha(infix[i]))
      postfix[j++] = infix[i];
    else if (infix[i] == '(')
      push(&stack, infix[i]);
    else if (infix[i] == ')') {
      // 여는 괄호가 나올 때까지 pop하여 출력
      while (peek(&stack) != '(')
        postfix[j++] = pop(&stack);
      // 여는 괄호 pop
      pop(&stack);
    }
    else {
      // 연산자인 경우
      while (precedence(infix[i]) <= precedence(peek(&stack)) && peek(&stack) != '(')
        postfix[j++] = pop(&stack);
      push(&stack, infix[i]);
    }
    printf(" stack : ");
    for (int n = 0; n <= stack.top; n++) {
      printf("%c ", stack.array[n]);
    }

    printf("\t postfix : %s ", postfix);
    //printf("\n");
  }

  // 스택에 남아있는 모든 연산자를 pop하여 출력
  while (stack.top != -1)
    postfix[j++] = pop(&stack);

  postfix[j] = '\0';

  printf("\n\tlast all pop\t postfix : %s ", postfix);
  // 메모리 해제
  free(stack.array);
}

int main() {
  //char infix[MAX_SIZE]="(A/B-C)*(D/(E-F)^G+H)-I";
  char infix[MAX_SIZE] = "(3+2)+(4*5)+(3/1)";
  char postfix[MAX_SIZE] = { 0 };

  // 사용자로부터 infix 수식 입력
  printf("\n\ninfix expression: ");
  //scanf("%s", infix);
  printf("%s\n\n", infix);

  // infix를 postfix로 변환
  infixToPostfix(infix, postfix);

  // postfix 출력
  printf("\n\nPostfix expression: %s\n", postfix);
}
