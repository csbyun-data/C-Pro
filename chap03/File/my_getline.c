// getline()은 표준 입력을 받아들여 한 줄을 읽고, 그 줄을 버퍼에 저장하는 함수
// ChatGPT code

#include <stdio.h>
#include <stdlib.h>

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream) {
  int ch;
  size_t len = 0;

  // 입력 버퍼가 NULL이라면 할당
  if (*lineptr == NULL) {
    *n = 128;  // 초기 버퍼 크기
    *lineptr = (char *)malloc(*n);
    if (*lineptr == NULL) {
        return -1;  // 메모리 할당 실패
    }
  }

  // 한 줄을 읽기
  while ((ch = fgetc(stream)) != EOF) {
    if (len + 1 >= *n) {  // 버퍼 크기가 부족하면 확장
      *n *= 2;  // 버퍼 크기 두 배로 확장
      *lineptr = (char *)realloc(*lineptr, *n);
      if (*lineptr == NULL) {
        return -1;  // 메모리 할당 실패
      }
    }
    
    (*lineptr)[len++] = ch;
  
    // 줄 바꿈 문자 처리
    if (ch == '\n') {
      break;
    }
  }

  // 끝에 널 종료 문자 추가
  (*lineptr)[len] = '\0';

  // EOF이면 더 이상 읽을 줄이 없다는 의미
  if (ch == EOF && len == 0) {
    return -1;
  }

  return len;  // 읽은 문자 수 반환
}

int main() {
  char *line = NULL;
  size_t len = 0;
  ssize_t nread;

  printf("Enter a line: ");
  nread = my_getline(&line, &len, stdin);

  if (nread != -1) {
    printf("You entered: %s", line);
  } else {
    printf("Error or EOF reached.\n");
  }

  // 할당된 메모리 해제
  free(line);
  return 0;
}
