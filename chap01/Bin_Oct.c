/* 02. COS Pro 1급 5회 6번 문제
   p 진법으로 표현한 수란, 각 자리를 0부터 p-1의 숫자로만 나타낸 수를 의미합니다.
   p 진법으로 표현한 자연수 두개를 더한 결과를 q 진법으로 표현하려 합니다.
   예를 들어, 3진법 수 112001과 12010을 더한 결과를 8진법으로 나타내면 1005입니다.

   solution 함수의 매개변수로 p 진법 자연수를 담은 문자열 s1, s2와 두 수를 
   나타내는 진법의 기수 p, 두 수의 덧셈 결과를 표현할 진법의 기수 q가 매개변수로
   주어집니다.
   p진법으로 표현된 두 수를 더한 결과를 q 진법으로 나타낸 값을 return 하도록
   solution 함수를 완성해주세요.

   #####매개변수 설명

   p 진법으로 자연수를 담은 문자열 s1, s2와 두 수를 표현한 진법의 기수 p,
   두 수의 덧셈 결과를 표현할 진법의 기수 q가 solution 함수의 매개변수로 주어집니다.

   * p와 q는 2 이상 10 이하인 자연수입니다.
   * s1과 s2의 길이는 1 이상 9 이하입니다.
   * s1과 s2의 원소는 '0', '1', '2', …, ‘p-1’로만 구성됩니다.
   * s1이나 s2가 ‘0’인 경우는 주어지지 않습니다.

   #####return 값 설명
   두 수를 더한 결과를 q 진법으로 나타낸 값을 문자열로 return 하도록
   solution 함수를 완성해주세요.

    #예시
    | s1 | s2 | p | q | return |
    |-----|-----|---|---|---------|
    | "112001" | "12010" | 3 | 8 | "1005" |
*/
​
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numbers_int[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
char *numbers_char = "0123456789";

const int char_to_int(char ch) {
  for (int i = 0; i < 10; i++)
    if (ch == numbers_char[i])
      return numbers_int[i];
}

const char int_to_char(int val) {
  for (int i = 0; i < 10; i++)
    if (val == numbers_int[i])
      return numbers_char[i];
}

char* convert_scale(int num, int q) {
  if (num == 0) return "";
  char *s2 = convert_scale(num / q, q);
  char *s = (char*) malloc(sizeof(char) * (strlen(s2) + 2));
  strcpy(s, s2);
  s[strlen(s2)] = int_to_char(num % q);
  s[strlen(s2) + 1] = 0;
  
  return s;
}

int parse_decimal(char* s, int p) {
  int num = 0;
  for (int i = strlen(s) - 1, mul = 1; i >= 0; i--, mul *= p)
    num += char_to_int(s[i]) * mul;
    return num;
}

char* solution(char* s1, char* s2, int p, int q) {
   int num1 = parse_decimal(s1, p);
   int num2 = parse_decimal(s2, p);
   char* answer = convert_scale(num1 + num2, q);
  
    return answer;
}

int main() {
  char* s1 = "112001";
  char* s2 = "12010";
  int p = 3;
  int q = 8;
    
  // 3진수 (s1 + s2) => ret 8진수로 출력
  char* ret = solution(s1, s2, p, q);

  printf("solution 함수의 반환 값은 %s 입니다.\n", ret);
}

// solution 함수의 반환 값은 1005 입니다.
