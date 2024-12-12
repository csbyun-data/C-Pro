// https://dev-ori.tistory.com/entry/CC-Data-Structure-Stack을-사용한-계산기-infix-to-postfix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//
// Calculator
//

// 프로그램 5.3 
// 스택 동작 관련 함수들

typedef char element;

#define MAX_STACK_SIZE 100
#define MAX_STR_SIZE   4096

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s) {
	s->top = -1;
	//s->capacity = 1;
	//s->data = (element *) malloc(s->capacity * sizeof(element));
}

// 공백 상태 검출 함수
int is_empty(StackType* s) {
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s) {
	//return (s->top == (s->capacity - 1));
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	} else
		s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];

}

// 피크함수
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[s->top];

}

// 스택 코드 끝

// 프로그램 5.5
// 괄호 검사 함수
int check_matching(const char* in) {
  StackType s;
  char ch, open_ch;
  int i, n = strlen(in);  	// n= 문자열의 길이
  init_stack(&s);			// 스택의 초기화

  for (i = 0; i < n; i++) {
    ch = in[i];		// ch = 다음 문자
    switch (ch) {
    case '(':   case '[':    case '{':
      push(&s, ch);
      break;
    case ')':   case ']':    case '}':
      if (is_empty(&s)) return 0; // 스택에 오른쪽 괄호는 있는데 왼쪽 괄호가 없는 Error

      else {
        open_ch = pop(&s);
        if ((open_ch == '(' && ch != ')') ||
          (open_ch == '[' && ch != ']') ||
          (open_ch == '{' && ch != '}')
          ) {
          return 0; // 괄호 매칭 안되는 Error
        }
        break;
      }
    }
  }
  if (!is_empty(&s)) return 0; // 스택에 남아있으면 오류
  return 1; // 성공
}

// 후위 표시 수식 계산 함수
int eval(char exp[ ] ) {
  int op1, op2, value, i = 0;
  int len = strlen(exp);
  char ch;
  StackType s;
  
  init_stack(&s);
  for (i = 0; i<len; i++){
    ch = exp[i];
    
    if(ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '%' && ch != '^'){
    // 입력이 피연산자이면 스택에 push
      value = ch - '0'; //문자를 숫자로 정수화 ex) '2'-'0' = 2
      push(&s, value);
    }
    else {
    //연산자이면 피연산자를 스택에서 제거
      op2 = pop(&s);
      op1 = pop(&s);
      switch (ch) { //연산자이면 피연산자를 스택에서 제거
          case '+' : push(&s, op1+op2); break;
          case '-' : push(&s, op1-op2); break;
          case '*' : push(&s, op1*op2); break;
          case '/' : push(&s, op1/op2); break;
          // %, ^ 추가'
          case '%' : push(&s, op1%op2); break;
          case '^' : push(&s, pow(op1, op2)); break;
        }
    }
  }
  return pop(&s);
}
// 연산의 우선순위 반환함수
int prec(char op) {
  switch (op){
    case '(':
    case ')':
      return 0;
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
    // %, ^ 추가
    case '%':
      return 2;
    case '^':
      return 3;
  }
  return -1;
}
 // 입력(infix): exp[],  결과(postfix): post[]
char* infix_to_postfix(char exp[ ], char post[ ]) {
  // %, ^ 추가
  // printf 대신 sprintf 사용하여 post로 출력
  int i=0;
  char ch, top_op;
  int len = strlen(exp)-1;
  StackType s;
  
  init_stack(&s); //스택 초기화
  for (i=0; i<len; i++){
    ch = exp[i];
    switch (ch){
      case '+':
      case '-':
      case '*':
      case '/':
      case '%':
      case '^':
        // 연산자일 경우
        while (!is_empty(&s) && ( prec(ch) <= prec(peek(&s)) ) ){ //스택 연산자의 우선순위가 크거나 같다면 post배열 저장
            // printf("%c",pop(&s));
            sprintf(post, "%s%c", post, pop(&s));
        }
        push(&s, ch);
        break;
      case '(':
        //왼쪽 괄호일 경우
        push(&s, ch);
        break;
      case ')':
        //오른쪽 괄호일 경우
        top_op = pop(&s);
        //왼쪽 괄호를 만날때 까지 post배열에 저장
        while(top_op != '('){
            // printf("%c", top_op);
            sprintf(post, "%s%c", post,top_op);
            top_op = pop(&s);
        }
        break;
      default:
        //피연산자일 경우
        // printf("%c", ch);
        sprintf(post, "%s%c", post,ch);
        break;
    }
  }
  while(!is_empty(&s)){ //스택에 저장된 연산자 출력
      // printf("%c", pop(&s));
      sprintf(post, "%s%c", post,pop(&s));

  }
  return post;
}


void main()
{
  char* line = NULL;
  // char* post = NULL;
	size_t     size;
	getline(&line, &size, stdin);
	if (check_matching(line) == 1){
	  //괄호 검사 성공 시
	    
		//Postfix expression 출력
		char post[MAX_STACK_SIZE] = {NULL};
		char* test = NULL;
 		printf("POSTFIX: ");
		test = infix_to_postfix(line, post);
		printf("%s\n", test);

		//결과값 출력
		printf("RESULT=%d",eval(test));
	}
	else
	  //괄호 검사 실패 시
		printf("Error: 괄호가 올바르지 않음.");
}
