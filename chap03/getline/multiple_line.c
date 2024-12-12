#include <stdio.h>
#include <stdlib.h>

// 위에서 구현한 my_getline 함수가 여기에 포함되어 있다고 가정합니다.

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    printf("Enter multiple lines (press Ctrl+D or Ctrl+Z to end):\n");

    // 여러 줄을 읽기 위한 루프
    while ((nread = my_getline(&line, &len, stdin)) != -1) {
        printf("You entered: %s", line);  // 입력된 줄을 출력
    }

    printf("End of input.\n");

    free(line);  // 할당된 메모리 해제
    return 0;
}
