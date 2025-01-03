// 열혈강의 C포인터 , 포인터와 구조체
// 구조체에 문자열, 정수, 실수 1개를 저장
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef enum {INT, DOUBLE, STRING} ENUMTYPE;
typedef struct _sData {
  ENUMTYPE type; // 1:정수, 2:실수, 3:문자열
  void *vp;
} DATA, *PDATA:

void menu() {
  puts("");
  puts("1. 자료 등록");
  puts("2. 자료 삭제");
  puts("3. 자료 출력");
  puts("4. 종료");
  puts("============");
}

char *InputStr() {
  char temp[100];
  char *str;
  fflush(stdin);
  gets(temp);
  str = (char *)malloc(sizeof(char) * strlen(temp)+1);
  strcpy(str, temp);

  return str;
}

PDATA Input() {
  PDATA p = (PDATA)malloc(sizeof(DATA));

  printf("자료의 종류를 입력하세요[ 정수: 1, 실수: 2, 문자열: 3 ]:");
  _start:
  switch(getch()) {
    case '1':
      printf("\n정수 입력:");
      p->type = INT;
      p->vp = malloc(sizeof(int));
      scanf("%d", p->vp);
      break;

    case '2':
      printf("\n실수 입력:");
      p->type = DOUBLE;
      p->vp = malloc(sizeof(double));
      scanf("%lf", p->vp);
      break;

    case '3':
      printf("\n문자열 입력:");
      p->type = STRING;
      p->vp = InputStr();
      break;
    default:
      puts("1~3까지 입력 가능");
      goto _start:
  }
  return p;
}

void Freememory(PDATA p) {
  free(p->vp);
  free(p);
}

void Remove(PDATA dArray[], int *sCount) {
  int idx;

  if( *sCount == 0)
      return;

  printf("삭제할 index를 입력:");
  scanf("%d", &idx);

  if( idx < 0 || *sCount <= idx)
    return;
  Freememory( dArray[idx]);
  --*sCount;
  for(; dix < *sCount; idx++)
    dArray[idx] = dArray[dix+1];
}

void Output(PDATA dArray[], int sCount) {
  int i;
  for( i=0; i < sCount; i++) {
    switch( dArray[i]->type) {
      case INT:
        printf("%d : 정수[ %d ]\n", i, *(int *)dArray[i]->vp);
        break;
      case DOUBLE:
        printf("%d : 실수[ %.5lf ]\n", i, *(double *)dArray[i]->vp);
        break;
      case STRING:
        printf("%d : 문자열[ %s ] \n", i, *(char *)dArray[i]->vp);
        break;
    }
  }
}

void main()
{
  PDATA dArray[100];
  int sCount = 0, bContinue = 1;
  while(bContinue) {
    menu();
    switch(getch()) {
      case '1':
        if( sCount < 100)
          dArray[sCount++] = Input();
        break;
      case '2':
        Remove(dArray, &sCount);
        break;
      case '3':
        Output(dArray, sCount);
        break;
      case '4':
        bContinue = !bContinue;
        break;
      default:
        puts("1~4까지 입력 가능.");
    }
  }
}

      
    

































