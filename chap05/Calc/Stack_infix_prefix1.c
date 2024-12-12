#pragma warning(disable:4996) 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 스택을 나타내는 구조체 정의
struct Stack {
  int top;
  unsigned capacity;
  char* array;
};

// 스택을 생성하는 함수
struct Stack* createStack(unsigned capacity) {
  struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
  stack->top = -1;
  stack->capacity = capacity;
  stack->array = (char*)malloc(stack->capacity * sizeof(char));
  return stack;
}

// 스택이 비어있는지 확인하는 함수
int isEmpty(struct Stack* stack) {
  return stack->top == -1;
}

// 스택이 가득 차있는지 확인하는 함수
int isFull(struct Stack* stack) {
  return stack->top == stack->capacity - 1;
}

// 스택에 원소를 푸시하는 함수
void push(struct Stack* stack, char item) {
  if (isFull(stack))
    return;
  stack->array[++stack->top] = item;
}

// 스택에서 원소를 팝하는 함수
char pop(struct Stack* stack) {
  if (isEmpty(stack))
    return '\0';
  return stack->array[stack->top--];
}

// 연산자의 우선순위를 반환하는 함수
int getPriority(char op) {
  switch (op) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
    return 3;
  }
  return -1;
}

// 중위 표기법을 전위 표기법으로 변환하는 함수
void infixToPrefix(char* infix, char* prefix) {
  struct Stack* stack = createStack(strlen(infix));
  int i, j = 0;

  // 입력된 중위 표기법 수식을 거꾸로 스캔하면서 전위 표기법으로 변환
  for (i = strlen(infix) - 1; i >= 0; i--) {
    char c = infix[i];
    printf("\n[%02d] %c ", strlen(infix)-1-i, infix[i]);
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') | (c >= '0' && c <= '9')) {
      // 피연산자일 경우
      prefix[j++] = c;
    }
    else if (c == ')' || c == ']' || c == '}') {
      // 닫는 괄호일 경우 스택에 푸시
      push(stack, c);
    }
    else if (c == '(' || c == '[' || c == '{') {
      // 여는 괄호일 경우 닫는 괄호를 만날 때까지 스택에서 팝하여 출력
      while (!isEmpty(stack) && stack->array[stack->top] != ')' && stack->array[stack->top] != ']' && stack->array[stack->top] != '}') {
        prefix[j++] = pop(stack);
      }
      // 여는 괄호는 스택에서 팝하여 버림
      pop(stack);
    }
    else {
      // 연산자일 경우
      while (!isEmpty(stack) && getPriority(c) < getPriority(stack->array[stack->top])) {
        prefix[j++] = pop(stack);
      }
      push(stack, c);
    }
    
    printf("\t stack : ");
    for (int n = 0; n <= stack->top; n++) {
      printf("%c", stack->array[n]);
    }
    printf("\t prefix : %s", prefix);
  }

  // 스택에 남아있는 연산자들을 출력
  while (!isEmpty(stack)) {
      prefix[j++] = pop(stack);
  }

  printf("\n\tlast all pop\t prefix : %s ", prefix);
  // 결과 문자열을 역순으로 뒤집어서 전위 표기법으로 만듦
  for (i = 0; i < j / 2; i++) {
    char temp = prefix[i];
    prefix[i] = prefix[j - i - 1];
    prefix[j - i - 1] = temp;
  }

  // 문자열의 끝에 NULL 문자 추가
  prefix[j] = '\0';
  // 동적 할당된 메모리 해제
  free(stack->array);
  free(stack);
}

int main() {
  //char infix[100] = { 0 };
  //char infix[100] = { "(a/b-c)*(d/(e-f)^g+h)-i" };
  char infix[100] = { "(3+2)+(4+5)+(3/1)" };
  char prefix[100] = { 0 };

  // 사용자로부터 중위 표기법 수식 입력 받음
  printf("\n중위 표기법 수식을 입력하세요: ");
  //gets(infix);
  printf("%s\n", infix);

  // 중위 표기법을 전위 표기법으로 변환
  infixToPrefix(infix, prefix);

  // 결과 출력
  printf("\n\n전위 표기법 수식: %s\n\n", prefix);
}
