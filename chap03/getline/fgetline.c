// 파일에서 한줄씩 읽어들여 출력

#include <stdio.h>
#include <stdlib.h>

// 위에서 구현한 my_getline 함수가 여기에 포함

int main() {
  char *line = NULL;
  size_t len = 0;
  ssize_t nread;
  FILE *file = fopen("example.txt", "r");  // "example.txt" 파일 열기

  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  printf("Reading lines from file:\n");

  // 파일에서 한 줄씩 읽기
  while ((nread = my_getline(&line, &len, file)) != -1) {
    printf("Line: %s", line);  // 읽은 줄을 출력
  }

  fclose(file);  // 파일 닫기
  free(line);  // 할당된 메모리 해제
  
  return 0;
}
