// unicode programming

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

void menu() {
  _putws(L"");
  _putws(L"1. 문자열 입력");
  _putws(L"2. 문자열 삭제");
  _putws(L"3. 문자열 출력");
  _putws(L"4. 문자열 정렬");
  _putws(L"5. 종료");
  _putws(L"==============");
}

wchar_t * Input() {
  wchar_t temp[100];
  wchar_t *str;
  wprintf(L"100자 이하의 문자를 입력: ");
  _getws(temp);
  str = (wchar_t *)malloc( sizeof(wchar_t)*wcslen( temp)+sizeof(wchar_t));
  wcscpy(str, temp);

  return str;
}

void Remove( wchar_t *strArray[], int *sCnt) {
  wchar_t temp[100];
  int i;

  if( *sCnt == 0)
    return ;

  wprintf(L"삭제할 문자열을 입력하세요:");
  _getws(temp);
  for( i=0; i<*sCnt; i++) {
    if( wcscmp(strArray[i], temp) == 0) {
      free(strArray[i]);
      --*sCnt;
      for(; i < *sCnt; i++)
        strArray[i] = strArray[i+1];
      break;
    }
  }
}

void Output(wchar_t *strArray[], int sCnt) { 
  int i;
  for( i=0; i<sCnt; i++)
    wprintf(L"%d : %s\n", i, strArray[i]);
}

void swap( wchar_t **a, wchar_t **b) {
  wchar_t *temp = *a;
  *a = *b;
  *b = temp;
}

void Sort( wchar_t *strArray[], int sCnt) {
  int i, j, min;

  for( i=0; i< sCnt-1; i++) {
    for( min=i, j=i+1; j < sCnt; j++) {
      if( wcscmp(strArray[j], strArray[min]) < 0)
        min = j;
    }
    swap(&strArray[i], &strArray[min]);
  }
  wprintf(L"Sorting End\n");
}

int main()
{
  wchar_t *strArray[100];
  int sCnt=0, bContinue=1;
  
  _wsetlocale(LC_ALL, L"Korean");

  while( bContinue) {
    menu();
    switch(_getwch()) {
    case L'1':
      if(sCnt < 100)
        strArray[sCnt++] = Input();
      break;
    case L'2':
      Remove(strArray, &sCnt);
      break;
    case L'3':
      Output(strArray, sCnt);
      break;
    case L'4':
      Sort( strArray, sCnt);
      break;
    case L'5':
      bContinue = !bContinue;
      break;
    default:
      _putws(L"1~5까지 입력 가능.");
    }
  }
}
