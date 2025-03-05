#include <stdio.h>
#include <stdlib.h>  
#include <windows.h> // Sleep 함수 

int main() {
	const char bar = '='; // 프로그레스바 문자  
	const char blank = ' '; // 비어있는 프로그레스바 문자  
	const int LEN = 20; // 프로그레스바 길이  
	const int MAX = 1000; // 진행작업 최대값 
	const int SPEED = 50; // 카운트 증가 대기시간  
	int count = 0; // 현재 진행된 작업  
	int i; // 반복문 전용 변수  
	
	float tick = (float)100/LEN; // 몇 %마다 프로그레스바 추가할지 계산 
	printf("%0.2f%% 마다 bar 1개 출력\n\n", tick); 
	int bar_count; // 프로그레스바 갯수 저장 변수  
	float percent; // 퍼센트 저장 변수  
	
	while(count <= MAX) {
		printf("\r%d/%d [", count, MAX); // 진행 상태 출력  
		percent = (float)count/MAX*100; // 퍼센트 계산  
		bar_count = percent/tick; // 프로그레스바 갯수 계산  
		for(i=0; i<LEN; i++) { // LEN길이의 프로그레스바 출력  
			if(bar_count > i) { // 프로그레스바 길이보다 i가 작으면 
				printf("%c", bar);
			} else { // i가 더 커지면  
				printf("%c", blank);
			}
		}
		printf("] %0.2f%%", percent); // 퍼센트 출력  
		count++; // 카운트 1증가  
		Sleep(SPEED); // SPEEDms 대기  
	}
	printf(" done!\n\n");
	system("pause"); // 프로그램 종료 전 일시정지  
	
	return 0; 
}
