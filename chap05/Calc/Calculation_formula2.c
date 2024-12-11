// Command Line에서 계산식 받음, 숫자의 소수점 처리
// 이항연산자 배열과 Function pointer 매칭
// 단항연산자 배열과 Function pointer 매칭, SIN, COS, TAN, EXP 함수

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// 이항 연산 함수들 선언
double add(double a, double b) {
  return a + b;
}

double subtract(double a, double b) {
  return a - b;
}

double multiply(double a, double b) {
  return a * b;
}

double divide(double a, double b) {
  if (b != 0)
    return a / b;
  else {
    printf("Error: Division by zero\n");
    return 0; // 0으로 나누기 오류 처리
  }
}

// 삼각 함수들 선언
double sin_func(double a) {
  return sin(a);
}

double cos_func(double a) {
  return cos(a);
}

double tan_func(double a) {
  return tan(a);
}

// 지수 함수 처리
double exp_func(double a) {
  return exp(a);
}

// 연산자 우선순위 확인 함수
int precedence(char op) {
  if (op == '+' || op == '-') {
      return 1;
  } else if (op == '*' || op == '/') {
      return 2;
  }
  return 0;
}

// 이항 연산자와 연산을 처리하는 구조체 정의
typedef struct {
  char operator;
  double (*operation)(double, double); // 이항 연산을 위한 함수 포인터
} BinaryOperator;

typedef struct {
  char operator;
  double (*operation)(double); // 단항 연산을 위한 함수 포인터
} UnaryOperator;

// 중위 표현식을 계산하는 함수
double evaluate_infix(const char* expression) {
  double values[100];  // 숫자를 저장할 스택
  char ops[100];       // 연산자를 저장할 스택
  int value_top = -1, op_top = -1;
  int i = 0;

  // 이항 연산자와 연산 함수를 매칭하는 배열
  BinaryOperator binary_operators[] = {
    {'+', add},
    {'-', subtract},
    {'*', multiply},
    {'/', divide}
  };

  // 단항 연산자와 연산 함수를 매칭하는 배열
  UnaryOperator unary_operators[] = {
    {'s', sin_func},  // sin
    {'c', cos_func},  // cos
    {'t', tan_func},  // tan
    {'e', exp_func}   // exp (지수 함수)
  };

  int num_binary_ops = sizeof(binary_operators) / sizeof(binary_operators[0]);
  int num_unary_ops = sizeof(unary_operators) / sizeof(unary_operators[0]);

  while (expression[i]) {
    if (isspace(expression[i])) {
      i++;  // 공백은 무시
      continue;
    }

    if (isdigit(expression[i]) || expression[i] == '.') {
      // 숫자 또는 소수점 처리
      char num[50];
      int j = 0;
      while ((isdigit(expression[i]) || expression[i] == '.') && expression[i] != '\0') {
          num[j++] = expression[i++];
      }
      num[j] = '\0';
      values[++value_top] = atof(num);  // 숫자 스택에 저장
    } 
    else if (expression[i] == '(') {
      ops[++op_top] = expression[i++];  // 여는 괄호 처리
    }
    else if (expression[i] == ')') {
      // 닫는 괄호 처리
      while (op_top != -1 && ops[op_top] != '(') {
        double b = values[value_top--];
        double a = values[value_top--];
        char op = ops[op_top--];

        // 이항 연산자에 맞는 함수 찾기
        for (int j = 0; j < num_binary_ops; j++) {
            if (binary_operators[j].operator == op) {
                values[++value_top] = binary_operators[j].operation(a, b);
                break;
            }
          }
      }
      op_top--;  // 여는 괄호 제거
      i++;
    }
    else if (expression[i] == 's' || expression[i] == 'c' || expression[i] == 't' || expression[i] == 'e') {
      // 단항 연산자 (삼각 함수 또는 지수 함수 처리)
      char op = expression[i];
      i++;  // 's', 'c', 't', 'e' 처리 후 다음 문자로 이동
      while (op_top != -1 && precedence(ops[op_top]) >= precedence(op)) {
        double value = values[value_top--];
        for (int j = 0; j < num_unary_ops; j++) {
            if (unary_operators[j].operator == op) {
                values[++value_top] = unary_operators[j].operation(value);
                break;
            }
        }
      }
    }
    else {
      // 이항 연산자 처리
      while (op_top != -1 && precedence(ops[op_top]) >= precedence(expression[i])) {
        double b = values[value_top--];
        double a = values[value_top--];
        char op = ops[op_top--];

        // 이항 연산자에 맞는 함수 찾기
        for (int j = 0; j < num_binary_ops; j++) {
          if (binary_operators[j].operator == op) {
              values[++value_top] = binary_operators[j].operation(a, b);
              break;
          }
        }
      }
      ops[++op_top] = expression[i++];  // 이항 연산자를 스택에 저장
    }
  }

  // 남은 연산자 처리
  while (op_top != -1) {
    double b = values[value_top--];
    double a = values[value_top--];
    char op = ops[op_top--];

    // 이항 연산자에 맞는 함수 찾기
    for (int j = 0; j < num_binary_ops; j++) {
      if (binary_operators[j].operator == op) {
          values[++value_top] = binary_operators[j].operation(a, b);
          break;
      }
    }
  }

  return values[value_top];  // 계산된 최종 결과 반환
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s <expression>\n", argv[0]);
    return 1;  // 인자가 하나일 때만 처리
  }

  char* expression = argv[1];  // 커맨드 라인에서 입력된 계산식

  // 결과 출력
  double result = evaluate_infix(expression);
  printf("Result: %lf\n", result);

  return 0;
}
