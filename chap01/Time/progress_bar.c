#include <stdio.h>
#include <stdlib.h>  
#include <windows.h> // Sleep 함수 

int main() 
{
const char bar = '='; // 프로그레스바 문자  
const char blank = ' '; // 비어있는 프로그레스바 문자  
const int LEN = 20; // 프로그레스바 길이  
const int MAX = 1000;
const int SPEED = 50;
int count = 0;
int i;

float tick = (float)100/LEN; // 몇 %마다 프로그레스바 추가할지 계산 
printf("%0.2f%% 마다 bar 1개 출력\n\n", tick); 
int bar_count;
float percent;

while(count <= MAX) {
	printf("\r%d/%d [", count, MAX);
	percent = (float)count/MAX*100;
	bar_count = percent/tick; // 프로그레스바 갯수 계산  
	
	for(i=0; i<LEN; i++) {
		if(bar_count > i) {
			printf("%c", bar);
		} else { // i가 더 커지면  
			printf("%c", blank);
		}
	}
	printf("] %0.2f%%", percent);
	count++;
	Sleep(SPEED); // SPEEDms 대기  
}
printf(" done!\n\n");
system("pause"); // 프로그램 종료 전 일시정지  

return 0; 
}
