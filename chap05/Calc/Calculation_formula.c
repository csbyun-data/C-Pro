// Calculation Formula
// ChatGPT code, 중위표기법 -> 후위표기법, Stack 구조체 사용, 우선순위, 소숫점 처리
// 삼각함수 (SIN, COS, TAN), 계산식 추가

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 100
#define PI 3.14

// Stack
// ========================================
typedef struct {
  double items[MAX_SIZE];
  int top;
} Stack;

// 스택 함수들
void initStack(Stack *stack) {
  stack->top = -1;
}

int isEmpty(Stack *stack) {
  return stack->top == -1;
}

int isFull(Stack *stack) {
  return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, double value) {
  if (!isFull(stack)) {
    stack->items[++(stack->top)] = value;
  } else {
    printf("Stack overflow\n");
  }
}

double pop(Stack *stack) {
  if (!isEmpty(stack)) {
    return stack->items[(stack->top)--];
  } else {
    printf("Stack underflow\n");
    return -1;
  }
}
// ========================================

// Operator Priority Return Function
int precedence(char op) {
  switch (op) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '^':
      return 3;
    default:
      return 0;
  }
}

// Priorities and computational functions of trigonometric functions
int isFunction(char* func) {
  return (strcmp(func, "sin") == 0 || strcmp(func, "cos") == 0 || strcmp(func, "tan") == 0);
}

// Calculate trigonometric functions
double evaluateFunction(char* func, double value) {
  double radian;
  if (strcmp(func, "sin") == 0) {
  	radian = value * PI / 180.0;
    return sin(radian);
  } else if (strcmp(func, "cos") == 0) {
  	radian = value * PI / 180.0;
    return cos(radian);
  } else if (strcmp(func, "tan") == 0) {
  	radian = value * PI / 180.0;
    return tan(radian);
  }
  
  return 0;
}

// Functions that convert the infix notation to the postfix notation
void infixToPostfix(char *infix, char *postfix) {
  Stack stack;
  initStack(&stack);
  int i = 0, k = 0;
  char token[10];
  int token_index = 0;

  while (infix[i] != '\0') {
    char c = infix[i];

    if (c == ' ') {
        i++;
        continue;
    }

    if (isdigit(c) || c == '.') { // Numbers or Decimals
      while (isdigit(infix[i]) || infix[i] == '.') {
        postfix[k++] = infix[i++];
      }
      postfix[k++] = ' ';
    }
    else if (isalpha(c)) { // Trigonometric functions
      token_index = 0;
      while (isalpha(infix[i])) {
        token[token_index++] = infix[i++];
      }
      token[token_index] = '\0';
      if (isFunction(token)) {
      	token_index = 0;
      	while (token[token_index] != '\0') 
      	  postfix[k++] = token[token_index++];	
    	  postfix[k++] = ' ';
      }
    }
    // 여는 괄호 처리
    else if (c == '(') {
        push(&stack, c);
        i++;
    }
    // 닫는 괄호 처리
    else if (c == ')') {
      while (!isEmpty(&stack) && stack.items[stack.top] != '(') {
          postfix[k++] = pop(&stack);
          postfix[k++] = ' ';
      }
      pop(&stack); // '('를 pop
      i++;
    }
    // 연산자 처리
    else {
      while (!isEmpty(&stack) && precedence(stack.items[stack.top]) >= precedence(c)) {
          postfix[k++] = pop(&stack);
          postfix[k++] = ' ';
      }
      push(&stack, c);
      i++;
    }
  }

  // 남은 연산자들을 후위 표기법에 추가
  while (!isEmpty(&stack)) {
    postfix[k++] = pop(&stack);
    postfix[k++] = ' ';
  }
  postfix[k] = '\0'; // 문자열 끝에 NULL 추가
}

// 후위 표기법 계산함수
double evaluatePostfix(char *postfix) {
  Stack stack;
  int i = 0;
  char c;
  double num;
  bool dot = false;
  bool bFunction = false;
  char func[10];
  
  initStack(&stack);

  while (postfix[i] != '\0') {
  	c = postfix[i];

    if (isdigit(c) || c == '.') { // number
      num = 0;
      double decimalPlace = 1;
      dot = false;
      while (isdigit(postfix[i]) || postfix[i] == '.') {
      	if (postfix[i] == '.') {
          i++;
          dot = true;
          continue;
        }
        num = num * 10 + (postfix[i] - '0');
        if( dot == true)
          decimalPlace *= 0.1;
        i++;
      }
      num = num * decimalPlace;
      
      push(&stack, num);
      
      if(bFunction == true) {
        double operand = pop(&stack);
        printf("%s, %g\n", func, operand);
        push(&stack, evaluateFunction(func, operand));
        bFunction = false;
	  }
    } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') { // 연산자인 경우
      double b = pop(&stack);
      double a = pop(&stack);
      switch (c) {
      	case '+': push(&stack, a + b); break;
	    case '-': push(&stack, a - b); break;
	    case '*': push(&stack, a * b); break;
	    case '/': push(&stack, a / b); break;
	    case '^': push(&stack, pow(a, b)); break;
      }
      i++;
    }
    else if (c == ' ') {  // 공백처리 
      i++;
      continue;
	}
	else if (c == '(' ) { // 삼각함수처리
      i++;
      continue;
    }
    else {

      int func_index = 0;
      while (isalpha(postfix[i])) {
        func[func_index++] = postfix[i++];
      }
      func[func_index] = '\0';

      if (isFunction(func))
        bFunction = true;
    }
  }
  
  return pop(&stack);
}

int main() {
  char infix[MAX_SIZE];
  char postfix[MAX_SIZE];

  printf("Enter an infix expression (e.g., sin(30) + cos(45)): ");
  fgets(infix, sizeof(infix), stdin);
  infix[ strlen(infix)-1 ] = '\0';

  // 중위 표기법을 후위 표기법으로 변환
  infixToPostfix(infix, postfix);
  printf("Postfix Expression: %s\n", postfix);

  // 후위 표기법 계산
  double result = evaluatePostfix(postfix);  
  printf("Result: %.4f\n", result);

  return 0;
}
