#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* variables used in file operations */
FILE *logfilep;
char prompt = '>';
/* general output buffer pointer */
char *sout;

void ourprint(char *s) {
  printf("%s", s);  
  fflush(stdout);  
  fprintf(logfilep, "%s", s);  
  fflush(logfilep);
}

void initlisp(void) {
  /* allocate a global character array for messages */
  sout= (char *)calloc(80,sizeof(char));

  logfilep = fopen("lisp.log", "w");
  if (logfilep == NULL) {
    perror("Cannot open logfile");
    exit(1);
  }
}

void closelisp(void) {
  if (sout != NULL) {
    free(sout);
  }
  
  if (logfilep != NULL) {
    fclose(logfilep);
  }
}

int process_number(char *str) {
  sprintf(sout,"%s\n", str);
  ourprint(sout);

  return 0;
}

int e(const char *str) {
  char c;
  char buffer[100];  // 입력을 임시로 저장할 버퍼
  int idx = 0;
  int i = 0;    

  while ((c = str[i++]) != '\n') {
    if (isspace(c)) {
      continue;  // 공백은 무시
    }
  
    if (c == '(') {
      ourprint("(\n");
      continue;
    }
    else if (c == ')') {
      ourprint(")\n");
      continue;            
    }
    else if (isalpha(c)) {
      idx = 0;
      buffer[idx++] = c;
      while (isalpha(str[i]) || str[i] == '_') {
          c = str[i++];
          buffer[idx++] = c;
      }
      buffer[idx] = '\0';
      sprintf(sout, "%s\n", buffer);
      ourprint(sout);
      continue;            
    } else if (isdigit(c) || (c == '-' && isdigit(str[i]))) {
      idx = 0;
      buffer[idx++] = c;
      while (isdigit(str[i]) || str[i] == '.') {
        c = str[i++];
        buffer[idx++] = c;
      }
      buffer[idx] = '\0';
      sprintf(sout,"%s\n", buffer);
      ourprint(sout);
      continue;
    } else {
      sprintf(sout, "%c\n", c);
      ourprint(sout);            
      continue;
    }
  }
  return 0;  // EOF에 도달
}

int check_exit_condition(char *input) {
  if (strcmp(input, "(exit)\n") == 0) {
      return 1;
  }
  return 0;
}

int main(void) {
  char input[1024];
  initlisp();

  while (1) {
    ourprint("> ");
    fgets(input, sizeof(input), stdin);

    fprintf(logfilep, "%s", input);
    fflush(logfilep);

    if (check_exit_condition(input)) {
      ourprint("Exit the program.\n");
      break;
    }

    if (input[0] == '\n') {
      continue;
    }
    printf("Expression entered: %s", input);

    e(input);
  }
  closelisp();

  return 0;
}
