// gets 함수, puts 함수 사용법
#include <stdio.h>
#include <stdlib.h>

int main()
{
  char buffer[100];
	
  // 문자열을 받아 buffer에 저장, 공백을 받아들임
  printf("input String : ");
  gets(buffer);  
	
  // buffer에 저장된 문자열을 출력
  printf("String : ");
  puts(buffer); 
	
  return 0;
}
