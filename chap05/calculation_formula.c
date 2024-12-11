// calculation formula
// ChatGPT code

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

// 스택 구조체 정의
typedef struct {
  double items[MAX_SIZE];
  int top;
} Stack;

// 스택 함수들
void initStack(Stack* stack) {
  stack->top = -1;
}

int isEmpty(Stack* stack) {
  return stack->top == -1;
}

int isFull(Stack* stack) {
  return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, double value) {
  if (!isFull(stack)) {
    stack->items[++(stack->top)] = value;
  } else {
    printf("Stack overflow\n");
  }
}

double pop(Stack* stack) {
  if (!isEmpty(stack)) {
    return stack->items[(stack->top)--];
  } else {
    printf("Stack underflow\n");
    return -1;
  }
}

// 연산자 우선순위 반환 함수
int precedence(char op) {
  if (op == '+' || op == '-') {
    return 1;
  } else if (op == '*' || op == '/') {
    return 2;
  } else if (op == '^') {
    return 3;
  }
  return 0;
}

// 삼각 함수의 우선순위와 계산 함수들
int isFunction(char* func) {
  return (strcmp(func, "sin") == 0 || strcmp(func, "cos") == 0 || strcmp(func, "tan") == 0);
}

// 삼각 함수 계산
double evaluateFunction(char* func, double value) {
  if (strcmp(func, "sin") == 0) {
    return sin(value);
  } else if (strcmp(func, "cos") == 0) {
    return cos(value);
  } else if (strcmp(func, "tan") == 0) {
    return tan(value);
  }
  return 0;
}

// 중위 표기법을 후위 표기법으로 변환하는 함수
void infixToPostfix(char* infix, char* postfix) {
  Stack stack;
  initStack(&stack);
  int i = 0, k = 0;
  char token[10];
  int token_index = 0;

  while (infix[i] != '\0') {
    char c = infix[i];

    // 공백은 무시
    if (c == ' ') {
        i++;
        continue;
    }

    // 숫자나 소수점을 처리
    if (isdigit(c) || c == '.') {
      while (isdigit(infix[i]) || infix[i] == '.') {
          postfix[k++] = infix[i++];
      }
      postfix[k++] = ' ';
    }
    // 삼각 함수 처리
    else if (isalpha(c)) {
      token_index = 0;
      // 함수 이름을 토큰으로 인식
      while (isalpha(infix[i])) {
        token[token_index++] = infix[i++];
      }
      token[token_index] = '\0';
      if (isFunction(token)) {
        postfix[k++] = ' ';

        // 함수가 스택에 쌓이도록 처리
        push(&stack, 0);  // 임시로 자리만 차지
        postfix[k++] = '(';
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

// 후위 표기법 계산 함수
double evaluatePostfix(char* postfix) {
  Stack stack;
  initStack(&stack);
  int i = 0;
  double num;

  while (postfix[i] != '\0') {
    char c = postfix[i];

    // 숫자인 경우
    if (isdigit(c) || c == '.') {
      num = 0;
      double decimalPlace = 1;
      while (isdigit(postfix[i]) || postfix[i] == '.') {
          if (postfix[i] == '.') {
              i++;
              decimalPlace = 0.1;
              continue;
          }
          num = num * 10 + (postfix[i] - '0');
          decimalPlace *= 10;
          i++;
      }
      push(&stack, num / decimalPlace);
    }
    // 연산자인 경우
    else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
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
    // 삼각 함수 처리
    else if (c == '(') {
        i++;
    }
    else {
      char func[10];
      int func_index = 0;
      while (isalpha(postfix[i])) {
          func[func_index++] = postfix[i++];
      }
      func[func_index] = '\0';

      if (isFunction(func)) {
          double operand = pop(&stack);
          push(&stack, evaluateFunction(func, operand));
      }
    }
  }
  
  return pop(&stack);
}

int main() {
  char infix[MAX_SIZE];
  char postfix[MAX_SIZE];

  printf("Enter an infix expression (e.g., sin(30) + cos(45)): ");
  fgets(infix, sizeof(infix), stdin);

  // 중위 표기법을 후위 표기법으로 변환
  infixToPostfix(infix, postfix);
  printf("Postfix Expression: %s\n", postfix);

  // 후위 표기법 계산
  double result = evaluatePostfix(postfix);
  printf("Result: %.4f\n", result);

  return 0;
}
