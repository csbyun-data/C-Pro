#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
  char name[20];
  int score;
} Student;

int compare(const void *a, const void * b){
  Student first = *(Student *)a;
  Student second = *(Student *)b;

  //내림차순 정렬 3, 2, 1, 0
  if(first.score > second.score)
    return -1;
  else if(first.score < second.score)
    return 1;
  else
    return 0;
}

// K번째 학생 , 메모리 free되지 않음 ?
char* solution(char* names[], int names_len, int scores[], int scores_len, int K) {
  int len = names_len;
  Student* students = (Student*)malloc(sizeof(Student)*len);
	
  for(int i = 0; i < len; ++i){
    strcpy(students[i].name, names[i]);
    students[i].score = scores[i];	
  }

  qsort(students, len, sizeof(Student), compare);

  return students[K - 1].name;
}

// The following is main function to output testcase.
int main() {
  char* names[5] = {"lukas", "james", "levi", "eli", "max"};
  int names_len = 5;
  int scores[5] = {30, 20, 50, 40, 10};//No scores tie
  int scores_len = 5;
  int K = 2;
	
  char* ret = solution(names, names_len, scores, scores_len, K);

  // Press Run button to receive output.
  printf("Solution: return value of the function is %s .\n", ret);
}
