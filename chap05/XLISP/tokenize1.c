// 문자열 수식 Lisp형태를 token으로 분리 (+ 1 2 3)
// ChatGPT code, token 분리후 계산하는 프로그램

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char **tokenize(const char *input, int *num_tokens) {
  int capacity = 100; // 초기 용량
  int size = 0; // 현재 토큰의 개수
  char **tokens = (char **)malloc(sizeof(char *) * capacity);
  const char *start = input;

  while (*start) {
    // 공백 문자 스킵
    if (isspace(*start)) {
      start++;
      continue;
    }

    // 괄호 처리
    if (*start == '(' || *start == ')') {
      char *token = (char *)malloc(2 * sizeof(char));
      token[0] = *start;
      token[1] = '\0';
      tokens[size++] = token;
      start++;
    } else {     // 숫자나 알파벳 처리
      const char *end = start;
      while (*end && !isspace(*end) && *end != '(' && *end != ')') {
        end++;
      }

      int length = end - start;
      char *token = (char *)malloc((length + 1) * sizeof(char));
      strncpy(token, start, length);
      token[length] = '\0';
      tokens[size++] = token;
      start = end;
    }

    // 배열이 가득 찬 경우 크기 증가
    if (size >= capacity) {
      capacity *= 2;
      tokens = (char **)realloc(tokens, sizeof(char *) * capacity);
    }
  }
  *num_tokens = size;
  return tokens;
}

// 토큰화된 배열을 출력하는 함수
void print_tokens(char **tokens, int num_tokens) {
  for (int i = 0; i < num_tokens; i++) {
    printf("Token %d: %s\n", i + 1, tokens[i]);
  }
}

// 메모리 해제 함수
void free_tokens(char **tokens, int num_tokens) {
  for (int i = 0; i < num_tokens; i++) {
    free(tokens[i]);
  }
  free(tokens);
}

int main() {
  const char *input = "(+ 2 35 4)";
  int num_tokens = 0;

  // 수식을 토큰화
  char **tokens = tokenize(input, &num_tokens);

  // 토큰 출력
  print_tokens(tokens, num_tokens);

  // token을 사용하여 Calc1.c 파일에 함수들을 사용하여 list로 만들어
  // 분석 함수에 입력
  // 숫자는 make_number(3)
  // 문자는 make_symbol("+")
  // 
  
  // Value args = make_cons(three, make_cons(four, make_number(0)));

  // 메모리 해제
  free_tokens(tokens, num_tokens);

  return 0;
}

/*
Token 1: (
Token 2: +
Token 3: 2
Token 4: 35
Token 5: 4
Token 6: )
*/
