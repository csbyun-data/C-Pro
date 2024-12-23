// LISP 계산식을 Builtin functions사용 코딩
// 내장 함수, 변수 평가기능
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 데이터 타입 정의
typedef enum { NUMBER, SYMBOL, CONS } Type;

typedef struct ConsCell {
  void *car;
  void *cdr;
} ConsCell;

typedef struct Value {
  Type type;
  union {
    double num;      // 숫자
    char *symbol;    // 심볼 (변수명 등)
    ConsCell *cons;  // 리스트 (커널에서 다루는 리스트)
  } data;
} Value;

// 내장 함수 구조체
typedef Value (*BuiltinFunc)(Value args);

// 전역 변수 (심볼을 저장)
#define MAX_SYMBOLS 100
char *symbols[MAX_SYMBOLS];
int symbol_count = 0;

// 함수 선언
Value eval(Value v);
Value apply(Value func, Value args);
Value add(Value args);
Value subtract(Value args);
Value multiply(Value args);
Value divide(Value args);

// 값 생성 함수
Value make_number(double num) {
  Value v;
  v.type = NUMBER;
  v.data.num = num;
  
  return v;
}

Value make_symbol(char *symbol) {
  Value v;
  v.type = SYMBOL;
  v.data.symbol = symbol;

  return v;
}

Value make_cons(Value car, Value cdr) {
  Value v;
  v.type = CONS;
  ConsCell *cell = (ConsCell *)malloc(sizeof(ConsCell));

  cell->car = malloc(sizeof(Value));
  *(Value *)(cell->car) = car;

  cell->cdr = malloc(sizeof(Value));
  *(Value *)(cell->cdr) = cdr;

  v.data.cons = cell;

  return v;
}

// 내장 함수들
Value add(Value args) {
  double sum = 0;
  ConsCell *cell = (ConsCell *)args.data.cons;

  while (cell != NULL) {
    Value arg = *(Value *)(cell->car);
    if (arg.type == NUMBER) {
      sum += arg.data.num;
      printf("%f \n", arg.data.num);
    }
    arg = *(Value *)(cell->cdr);
    if (arg.type == NUMBER) {
      sum += arg.data.num;
      return make_number(sum);
	  } else if (arg.type == CONS) {
      cell = (ConsCell *)arg.data.cons;
    }
  }
  
  return make_number(sum);
}

Value subtract(Value args) {
  if (args.type != CONS) {
      return make_number(0);
  }
  
  double result = 0;
  ConsCell *cell = (ConsCell *)args.data.cons;
  if (cell != NULL) {
    Value first = *(Value *)(cell->car);
    if (first.type == NUMBER) {
      result = first.data.num;
    }
    Value arg = *(Value *)(cell->cdr);
    if (arg.type == NUMBER) {
      result -= arg.data.num;
      return make_number(result);
	  } else if (arg.type == CONS) {
      cell = (ConsCell *)arg.data.cons;
    }
  }
  while (cell != NULL) {
    Value arg = *(Value *)(cell->car);
    if (arg.type == NUMBER) {
      result -= arg.data.num;
    }
    arg = *(Value *)(cell->cdr);
    if (arg.type == NUMBER) {
      result -= arg.data.num;
      return make_number(result);
    } else if (arg.type == CONS) {
      cell = (ConsCell *)arg.data.cons;
    }
  }
  return make_number(result);
}

Value multiply(Value args) {
  double product = 1;
  ConsCell *cell = (ConsCell *)args.data.cons;
  
  while (cell != NULL) {
    Value arg = *(Value *)(cell->car);
    if (arg.type == NUMBER) {
      product *= arg.data.num;
      printf("num %f, product %f \n", arg.data.num, product);
    }
    arg = *(Value *)(cell->cdr);
    if (arg.type == NUMBER) {
    	product *= arg.data.num;
    	return make_number(product);
    } else if (arg.type == CONS) {
    	cell = (ConsCell *)arg.data.cons;
    }
  }
  return make_number(product);
}

Value divide(Value args) {
  double quotient = 1;
  int first = 1;
  ConsCell *cell = (ConsCell *)args.data.cons;
  while (cell != NULL) {
    Value arg = *(Value *)(cell->car);
    if (arg.type == NUMBER) {
      if (first) {
        quotient = arg.data.num;
        first = 0;
      } else {
        quotient /= arg.data.num;
      }
    }
    arg = *(Value *)(cell->cdr);
    if (arg.type == NUMBER) {
    	quotient /= arg.data.num;
    	return make_number(quotient);
    } else if (arg.type == CONS) {
    	cell = (ConsCell *)arg.data.cons;
    }
  }
  return make_number(quotient);
}

// 연산 함수 적용
Value apply(Value func, Value args) {
  if (func.type != SYMBOL) {
    return make_number(0);
  }
  char *symbol = func.data.symbol;

  if (strcmp(symbol, "+") == 0) {
    return add(args);
  } else if (strcmp(symbol, "-") == 0) {
    return subtract(args);
  } else if (strcmp(symbol, "*") == 0) {
    return multiply(args);
  } else if (strcmp(symbol, "/") == 0) {
    return divide(args);
  } else {
    return make_number(0); // 알 수 없는 함수
  }
}

// 값 평가 함수
Value eval(Value v) {
  if (v.type == NUMBER || v.type == SYMBOL) {
    return v;  // 숫자나 심볼은 그대로 반환
  } else if (v.type == CONS) {
    ConsCell *cell = (ConsCell *)v.data.cons;
    if (cell == NULL) {
      return v;
    }

    Value func = *(Value *)(cell->car);
    Value args = *(Value *)(cell->cdr);
    return apply(func, args);
  }

  return v;
}

int main() {
  // (+ 3 4)
  Value three = make_number(3);
  Value four = make_number(4);
  
  // Value args = make_cons(three, make_cons(four, make_number(0)));
  // Value add_fn = make_symbol("+");
  // Value expr = make_cons(add_fn, args);

  // (- 3 4)
  //Value args = make_cons(three, make_cons(four, make_number(0)));
  //Value subtract_fn = make_symbol("-");
  //Value expr = make_cons(subtract_fn, args);
  
  // (* 3 4)
  //Value args = make_cons(three, make_cons(four, make_number(1)));
  //Value multiply_fn = make_symbol("*");
  //Value expr = make_cons(multiply_fn, args);

  // (/ 3 4)
  Value args = make_cons(three, make_cons(four, make_number(1)));
  Value divide_fn = make_symbol("/");
  Value expr = make_cons(divide_fn, args);  

  Value result = eval(expr);
  printf("Result: %f\n", result.data.num);
  
  return 0;
}
