// ChatGPT code, 중위표기법 계산, 배열 Stack사용, 우선순위, 소숫점 처리
// 이항연산자 배열과 Function pointer 매칭
// 단항연산자 배열과 Function pointer 매칭, SIN, COS, TAN, EXP 함수

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // strcmp()
#include <ctype.h>
#include <math.h>
#include <setjmp.h>	 // setjmp(), longjmp()
#include <stdbool.h> 

#define PI 3.141592

jmp_buf env;

void fail(char *err) {
  printf("error: %s\n", err);
  longjmp(env, 1);
}

// binary operation functions
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) {
  if (b != 0)
    return a / b;
  else {
    printf("Error: Division by zero\n");
    return 0;
  }
}

// trigonometric functions
double sin_func(double a) { return sin(a); }
double cos_func(double a) { return cos(a); }
double tan_func(double a) { return tan(a); }

// exponential function
double exp_func(double a) { return exp(a); }

// Operator priority check function
int precedence(char op) {
  if (op == '+' || op == '-') 
    return 1;
  else if (op == '*' || op == '/')
    return 2;
  return 0;
}

// 이항 연산자와 연산을 처리하는 구조체 정의
typedef struct {
  char operator;
  double (*operation)(double, double);
} BinaryOperator;

typedef struct {
  char operator;
  double (*operation)(double);
} UnaryOperator;

// 이항 연산자와 연산 함수를 매칭하는 배열
BinaryOperator binary_operators[] = { {'+', add}, {'-', subtract}, {'*', multiply}, {'/', divide}};

// 단항 연산자와 연산 함수를 매칭하는 배열
UnaryOperator unary_operators[] = {
  {'s', sin_func},  // sin
  {'c', cos_func},  // cos
  {'t', tan_func},  // tan
  {'e', exp_func}   // exp (지수 함수)
};

int num_binary_ops = sizeof(binary_operators) / sizeof(binary_operators[0]);
int num_unary_ops = sizeof(unary_operators) / sizeof(unary_operators[0]);

// 중위 표현식을 계산하는 함수
double evaluate_infix(const char *expr) {
  double values[100];  // 숫자를 저장할 스택
  char ops[100];       // 연산자를 저장할 스택, (, +, -, *, /, s, c, t, e
  int value_top = -1, op_top = -1, i = 0;
  double value;
  char op;
  
  while (expr[i]) {
    if (isspace(expr[i])) {
      i++;  // 공백은 무시
      continue;
    }

    if (isdigit(expr[i]) || expr[i] == '.') {  // 숫자 또는 소수점 처리
      char num[50];
      int j = 0;
      while ((isdigit(expr[i]) || expr[i] == '.') && expr[i] != '\0') {
        num[j++] = expr[i++];
      }
      num[j] = '\0';
      values[++value_top] = atof(num);  // 숫자 스택에 저장
    } 
    else if (expr[i] == '(') { // 여는 괄호 처리
      // printf("( num \n");
      ops[++op_top] = expr[i++];  
    }
    else if (expr[i] == ')') { // 닫는 괄호 처리
      // printf(" num ) op_top=%d, ops=%c\n", op_top, ops[op_top]);    
      while (op_top != -1 && ops[op_top] != '(') {
        double b = values[value_top--];
        double a = values[value_top--];
        op = ops[op_top--];
        
        // printf("bin): %g %c %g \n", a, op, b);
        for (int j = 0; j < num_binary_ops; j++) {
          if (binary_operators[j].operator == op) {
            values[++value_top] = binary_operators[j].operation(a, b);
            break;
          }
        }
      }
      op_top--;  // 여는 괄호 제거
      // printf(" Func ? : op_top=%d, ops=%c\n", op_top, ops[op_top]);    
      if(op_top != -1 && ops[op_top] != '(') { // function 점검 
      	op = ops[op_top--];
        if (op == 's' || op == 'c' || op == 't' || op == 'e') {
          value = values[value_top--];        
          value = value * PI / 180.0;
        } else if (op == 'e')
          value = values[value_top--];        
        else {
          printf("not funtion!: %c\n", op);
          exit(1);
      	}
        // printf("Unary): %c %g \n", op, value);
        
        for (int j = 0; j < num_unary_ops; j++) {
          if (unary_operators[j].operator == op) {
            values[++value_top] = unary_operators[j].operation(value);
            break;
          }
        }
      }
      i++;
    } else if (expr[i] == 's' || expr[i] == 'c' || expr[i] == 't' || expr[i] == 'e') {
      ops[++op_top] = expr[i];
      i++;
    }
    else {
      while (op_top != -1 && precedence(ops[op_top]) >= precedence(expr[i])) {
        double b = values[value_top--];
        double a = values[value_top--];
        char op = ops[op_top--];
        
        // printf("bin1: %g %c %g \n", a, op, b);

        for (int j = 0; j < num_binary_ops; j++) {
          if (binary_operators[j].operator == op) {
            values[++value_top] = binary_operators[j].operation(a, b);
            break;
          }
        }
      }
      ops[++op_top] = expr[i++];  // 이항 연산자를 스택에 저장
    }
  }
  
  // processing remaining operators
  while (op_top != -1) {
    double b = values[value_top--];
    double a = values[value_top--];
    char op = ops[op_top--];

    // printf("bin2: %g %c %g \n", a, op, b);
    for (int j = 0; j < num_binary_ops; j++) {
      if (binary_operators[j].operator == op) {
        values[++value_top] = binary_operators[j].operation(a, b);
        break;
      }
    }
  }
  return values[value_top];  // return calculated final results
}

void fexit() {
  printf("Program Exit.\n");
  exit(1);
}

int main(int argc, char* argv[]) 
{
  char expr[100];

  while(true) {
    setjmp(env);
    
    printf("계산식 입력 (종료: exit): ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';
    
    if(strcmp(expr, "exit") == 0)
      fexit();
    else {
      double result = evaluate_infix(expr);
      printf("Result: %lf\n", result);  	
    }
  }
  return 0;
}
