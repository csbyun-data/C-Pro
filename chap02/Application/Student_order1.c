//C언어 프로그래밍
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
  char name[20];
  int score;
} Student;

// 구조체 배열을 함수의 매개변수로 활용
int compare(const void *a, const void * b){
  Student first = *(Student *)a;
  Student second = *(Student *)b;
  if(first.score > second.score)
    return -1;
  else if(first.score < second.score)
    return 1;
  else
    return 0;
}

//문자열 포인터, 숫자 배열 포인터를 함수 매개변수로 활용 예
char *solution(char* names[], int names_len, int scores[], int scores_len, int K) {
  int len = names_len;
  Student* students = (Student*)malloc(sizeof(Student)*len);
  for(int i = 0; i < len; ++i){
    strcpy(students[i].name, names[i]);
    students[i].score = scores[i];
  }
  qsort(students, len, sizeof(Student), compare);
  
  return students[K - 1].name;
}

int main() {
  char *names[5] = {"lukas", "james", "levi", "eli", "max"};
  int names_len = 5;
  int scores[5] = {30, 20, 50, 40, 10};
  int scores_len = 5;
  int K = 2;
  char* ret = solution(names, names_len, scores, scores_len, K);
  
  // Press Run button to receive output. 
  printf("ret value is %s .\n", ret);
}
