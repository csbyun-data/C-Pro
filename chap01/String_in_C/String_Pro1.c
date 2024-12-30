#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void menu() {
  puts("");
  puts("1. 문자열 입력");
  puts("2. 문자열 삭제");
  puts("3. 문자열 출력");
  puts("4. 문자열 정렬");
  puts("5. 종료");
  puts("==============");
}

char * Input() {
  char temp[100];
  char *str;
  printf("100자 이하의 문자를 입력: ");
  gets(temp);
  str = (char *)malloc( sizeof(char)*strlen( temp)+1);
  strcpy(str, temp);

  return str;
}

void Remove( char *strArray[], int *sCnt) {
  char temp[100];
  int i;

  if( *sCnt == 0)
    return ;

  printf("삭제할 문자열을 입력하세요:");
  gets(temp);
  for( i=0; i<*sCnt; i++) {
    if( strcmp(strArray[i], temp) == 0) {
      free(strArray[i]);
      --*sCnt;
      for(; i < *sCnt; i++)
        strArray[i] = strArray[i+1];
      break;
    }
  }
}

void Output(char *strArray[], int sCnt) { 
  int i;
  for( i=0; i<sCnt; i++)
    printf("%d : %s\n", i, strArray[i]);
}

void swap( char **a, char **b) {
  char *temp = *a;
  *a = *b;
  *b = temp;
}

void Sort( char *strArray[], int sCnt) {
  int i, j, min;

  for( i=0; i< sCnt-1; i++) {
    for( min=i, j=i+1; j < sCnt; j++) {
      if(strcmp(strArray[j], strArray[min]) < 0)
        min = j;
    }
    swap(&strArray[i], &strArray[min]);
  }
  printf("Sorting End\n");
}

int main()
{
  char *strArray[100];
  int sCnt=0, bContinue=1;

  while( bContinue) {
    menu();
    switch(getch()) {
    case '1':
      if(sCnt < 100)
        strArray[sCnt++] = Input();
      break;
    case '2':
      Remove(strArray, &sCnt);
      break;
    case '3':
      Output(strArray, sCnt);
      break;
    case '4':
      Sort( strArray, sCnt);
      break;
    case '5':
      bContinue = !bContinue;
      break;
    default:
      puts("1~5까지 입력 가능.");
    }
  }
}
