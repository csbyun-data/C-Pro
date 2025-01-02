//포인터 배열 10개를 선언, 문자열 10개를 순서대로 메모리 할당으로 받아들임
#include <stdio.h>
#include <stdlib.h> /* malloc() */
#include <string.h> /* strcpy() */

#define MAX_LEN 256

int main(void)
{
  char *p[10];
  char buffer[MAX_LEN];
  int i;
  
  for( i = 0 ; i < 10 ; i++ ) {
    printf("Input %2d string: ", i );
    fgets( buffer, MAX_LEN, stdin );
    /* fgets() 함수로 입력을 받으면 마지막에 엔터키 까지 저장이 된다.
    * 이 엔터키를 없애기 위해서 문자열 크기 - 1 인 곳에 NULL을 넣는다
    */
    buffer[ strlen(buffer)-1 ] = '₩0';
    
    /* buffer 크기 + 1 만큼 메모리를 할당 받고, 할당 받은 메모리의 첫 번지 값을 p[i] 에 저장한다.
    * 메모리를 할당 받을때 문자열의 크기보다 1개가 더 큰 이유는 NULL 값을 저장하기 위함이다.
    */
    p[i] = (char *)malloc( strlen(buffer) + 1 );
    if( p[i] == NULL ) {
      printf("main(): memory allocation error!₩n");
      exit(-1);
    }
    
    /* buffer의 문자열을 p[i]가 가리키고 있는 방금 할당 받은 메모리로 복사 한다.
    * p[i]가 가리키고 있는 영역은 메모리의 Heap 영역이다
    */
    strcpy( p[i], buffer );
  }
  
  for( i = 0 ; i < 10 ; i++ )
    printf("%2d: %s₩n", i, p[i] );
  return 0;
}
