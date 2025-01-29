#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE *logfilep;  // 로그 파일 포인터
char prompt = '>';

// 로그와 표준 출력에 동시에 출력하는 함수
void ourprint(char *s) {
    printf("%s", s);  
    fflush(stdout);  
    fprintf(logfilep, "%s", s);  
    fflush(logfilep);  // 로그 파일에 바로 기록
}

// 로그 파일을 초기화하고 열기
void initlisp(void) {
    logfilep = fopen("lisp.log", "w");
    if (logfilep == NULL) {
        perror("Cannot open logfile");
        exit(1);
    }

    ourprint("ENTERING THE LISP INTERPRETER\n");
}

// 로그 파일 닫기
void closeLogfile(void) {
    if (logfilep != NULL) {
        fclose(logfilep);
    }
}

// 숫자 처리 함수
int process_number(char *str) {
    printf("숫자 처리: %s\n", str);  // 숫자 전체를 출력
    return 0;  // 예시로 0 반환
}

// 문법을 처리하는 함수
int e(void) {
    char c;
    char buffer[1024];  // 입력을 임시로 저장할 버퍼
    int idx = 0;

    while ((c = getgchar()) != EOF) {
        if (isspace(c)) {
            continue;  // 공백은 무시
        }

        if (c == '(') {
            printf("왼쪽 괄호 '(' 발견\n");
            return 1;  // 괄호는 여기서만 처리
        }
        else if (c == ')') {
            printf("오른쪽 괄호 ')' 발견\n");
            return 2;  // 괄호는 여기서만 처리
        }
        else if (isalpha(c)) {
            // 알파벳 처리 (변수명 등)
            idx = 0;
            buffer[idx++] = c;
            while (isalpha(lookgchar()) || lookgchar() == '_') {
                c = getgchar();
                buffer[idx++] = c;
            }
            buffer[idx] = '\0';
            printf("알파벳 처리: %s\n", buffer);  // 알파벳 전체 단어를 출력
            return 3;  // 알파벳 처리 완료
        } else if (isdigit(c) || (c == '-' && isdigit(lookgchar()))) {
            // 숫자 처리
            idx = 0;
            buffer[idx++] = c;
            while (isdigit(lookgchar())) {
                c = getgchar();
                buffer[idx++] = c;
            }
            buffer[idx] = '\0';
            process_number(buffer);  // 숫자 처리
            return 4;
        } else {
            // 기타 문자 처리
            printf("기타 문자: %c\n", c);
            return 5;
        }
    }
    return 0;  // EOF에 도달
}

// 한 문자씩 읽어오기
char getgchar(void) {
    char c = getchar();
    return c;
}

// 현재 문자를 미리 보기
char lookgchar(void) {
    char c = getchar();
    ungetc(c, stdin);  // 다시 입력 스트림에 넣어줌
    return c;
}

// (exit) 명령 처리 함수
int check_exit_condition(char *input) {
    if (strcmp(input, "(exit)\n") == 0) {
        return 1;  // (exit)을 입력받았을 때 종료
    }
    return 0;  // 그 외에는 계속 입력 받기
}

int main(void) {
    // Lisp 인터프리터 초기화
    initlisp();

    char input[1024];

    // 반복문 시작
    while (1) {
        // 사용자로부터 입력을 받음
        ourprint("Enter a Lisp expression: ");
        fgets(input, sizeof(input), stdin);  // 한 줄 입력 받기

        // (exit)을 입력하면 프로그램 종료
        if (check_exit_condition(input)) {
            ourprint("프로그램을 종료합니다.\n");
            break;  // 반복문 종료 -> 프로그램 종료
        }

        // 입력이 비어 있으면 다시 시작
        if (input[0] == '\n') {
            continue;
        }

        // 입력 받은 내용 처리
        printf("입력한 표현식: %s", input);

        // 문법 분석 함수 호출 (예시로 e() 사용)
        e();  // 문법 분석 후 결과 처리

        // 결과 출력 후 다시 입력을 받음
        ourprint("입력받은 후 처리 완료.\n\n");
    }

    // 로그 파일 닫기
    closeLogfile();

    return 0;
}
