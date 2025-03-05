#include "game.h" 
#include "util.h"

char tempMap[14][56]; // 맵 임시저장할 배열  

char map1[14][56] = { // 쉬운맵  
	// 가로 숫자는 위 배열크기에 맞추어 56개  
	{"1111111111111111111111111111111111111111111111111111111"}, // 세로 길이에 맞추어 14줄   
	{"1000000010000000000000000000000000000000000000000000001"},
	{"1000000010000000000000000000000000000000000000000000001"}, // 0 : 빈 공간 
	{"1000100010000000000000000000000000000000000000000000001"}, // 1 : 벽 
	{"1000100010000000000000000000000000000000000000000000001"}, // k : 열쇠 
	{"1000100010000000000000000000000000000000000000000000001"}, // l : 잠긴 문 
	{"1000100011111100000000000000000000000000000000000000001"}, // q : 탈출구  
	{"1000100000000100000000000000000000000000000000000000001"},
	{"1000100010000100000000000000000000000000000000000000001"},
	{"10001000100k0100000000000000000000000000000000001111111"},
	{"1000100010000100000000000000000000000000000000001000001"},
	{"10s010001111111111111111111111111111111111111111100q001"},
	{"10001000l0000000000000000000000000000000000000000000001"},
	{"1111111111111111111111111111111111111111111111111111111"}
};

char map2[14][56] = { // 어려운맵  
	// 가로 숫자는 위 배열크기에 맞추어 56개  
	{"1111111111111111111111111111111111111111111111111111111"}, // 세로 길이에 맞추어 14줄   
	{"100000100010001k000100000000001000100000100010100010001"},
	{"1000001010101011110101111101101010101110101010101000101"},
	{"1000101010001000k10101000101k01010101k10101000111111101"},
	{"1000100010111111110101010101111000100010101111100000001"},
	{"100011111l100000000101010100000001110110101000101011111"},
	{"1000100000101111111101010111011100000010001010001010001"},
	{"1000101111101000000001010000000111011010100010100010001"},
	{"10001010000010000001010110111100000000101010101010001l1"},
	{"10001010111010000001000000000101011110101010101011111l1"},
	{"100010101k001000000111101111000100001010101010001000001"},
	{"10s010101111111110110010100001011110100010111110100q001"},
	{"1000100000l000l0001000100011110000001010100000001000001"},
	{"1111111111111111111111111111111111111111111111111111111"}
};

  
void drawMap(int* x, int* y){
	system("cls");
	int h, w; // 세로, 가로  
	
	for(h=0; h<14; h++){ // 세로길이까지  
		for(w=0; w<56; w++){ // 가로길이까지  
			char temp = tempMap[h][w]; // 임시저장한 맵 데이터  
			if(temp == '0'){ // 빈 공간(공백)
				setColor(black, black);  
				printf(" "); 
			} else if(temp == '1') { // 벽(#)
				setColor(white, white);  
				printf("#"); 
			} else if(temp == 's') { // 플레이어(@) 
				*x = w; // 플레이어 좌표값 저장  
				*y = h;
				setColor(cyan, black);  
				printf("@");
			} else if(temp == 'q') { // 목적지(O)
				setColor(lightgreen, black);    
				printf("O"); 
			} else if(temp == 'k') { // 열쇠(*) 
				setColor(yellow, black);
				printf("*"); 
			} else if(temp == 'l') { // 잠긴 문(+) 
				setColor(brown, black);
				printf("+");
			}
		}
		printf("\n"); // 한줄 다 출력했으면 한칸 줄바꿈  
	}
	setColor(white, black); // 다시 기본 색상으로 돌아오기 
} 

// 게임 루프  
void gLoop(int mapCode){
	int x, y; // 플레이어 좌표 저장 변수 선언(x, y) 
	int key = 0; // 열쇠 갯수 저장변수  
	
	int playing = 1; // 1이면 게임중, 0이면 게임 종료  
	
	// mapNumber가 0이면 쉬운맵, 1이면 어려운맵, 2이면..
	//(추가하실분은 아래와 같은 방식으로 추가하시면 됩니다)
	if(mapCode == 0){
		memcpy(tempMap, map1, sizeof(tempMap));
	} else if(mapCode == 1){
		memcpy(tempMap, map2, sizeof(tempMap));
	} // else if(...)
	
	drawMap(&x, &y); // 맵 설정 후 출력 
	// 맵에 좌표 포인터를 전달  
	
	// 게임 루프  
	while(playing){
		drawUI(&x, &y, &key);
		
		switch(keyControl()){
			case UP:
				move(&x, &y, 0, -1, &key, &playing); // 실제x, 실제y, x방향으로 이동할 칸, y방향으로 이동할 칸  
				break;
				
			case DOWN:
				move(&x, &y, 0, 1, &key, &playing); // x위치는 그대로, y위치는 +1 (아래로) 
				break;
				
			case RIGHT:
				move(&x, &y, 1, 0, &key, &playing); // x위치는 +1, y는 그대로(오른쪽) 
				break;
				
			case LEFT:
				move(&x, &y, -1, 0, &key, &playing); // x위치는 -1, y는 그대로(왼쪽) 
				break;
				
			case SUBMIT:
				playing = 0; // 0이 되면 반복 종료  
		} 
	}
	gotoxy(22, 8);
	printf("Game Clear!");
	Sleep(1500);
}

// 플레이어 좌표를 조작할 함수  
// 원래 좌표 (x, y), 증감할 좌표(_x, _y) 
void move(int* x, int* y, int _x, int _y, int* key, int* playing){
	// 이동할 위치에 있는 맵 배열의 문자 임시저장  
	char mapObject = tempMap[*y + _y][*x + _x];
	setColor(white, black); // 색 기본값  
	
	if(mapObject == '0') {
		gotoxy(*x, *y);
		printf(" "); // 지우기 
		
		setColor(cyan, black); // 색 설정  
		gotoxy(*x + _x, *y + _y); // 증감한 위치로 이동 후 플레이어 출력  
		printf("@");
		
		*x += _x; // 실제 좌표값으로 반영  
		*y += _y;
	} else if(mapObject == 'k') { // 이동할 위치에 열쇠가 있으면 획득  
		*key += 1; // 열쇠갯수 1증가 
		tempMap[*y + _y][*x + _x] = '0'; // 획득하였으면 기존에 있던 k를 0으로 설정 
		gotoxy(*x + _x, *y + _y); // 열쇠가 있는 위치를 지움  
		printf(" ");
	} else if(mapObject == 'l') {
		if(*key > 0){
			*key -= 1; // 열쇠 1개 소모  
			tempMap[*y + _y][*x + _x] = '0'; // 문이 열렸으니 l 데이터를 0으로 설정  
			setColor(white, black); // 색 기본값  
			gotoxy(*x + _x, *y + _y);
			printf(" ");
		}
	} else if(mapObject == 'q') {
		*playing = 0; // 1: 게임 진행 중, 0: 게임 종료  
	}
} 

// 게임 하단에 좌표 및 아이템 정보 출력  
void drawUI(int* x, int* y, int* key){
	setColor(white, black); // 색 기본값 
	gotoxy(3, 16);
	printf("위치: %02d, %02d", *x, *y); // x, y 값 출력 
	
	setColor(yellow, black);
	gotoxy(34, 16); 
	printf("열쇠: %d개", *key);
}


int keyControl(){
	char temp = getch();
	
	if(temp == 'w' || temp == 'W'){
		return UP;
	} else if(temp == 'a' || temp == 'A'){
		return LEFT;
	} else if(temp == 's' || temp == 'S'){
		return DOWN;
	} else if(temp == 'd' || temp == 'D'){
		return RIGHT;
	} else if(temp == ' '){ // 스페이스바(공백)이 선택 버튼  
		return SUBMIT;
	}
}

void titleDraw(){
	printf("\n\n\n\n"); // 맨위에 4칸 개행  
	printf("        #####    ###    ###    #    ####   ##### \n");
	printf("        #       #      #      # #   #   #  #     \n");
	printf("        ####    ####   #     #####  ####   ####  \n");
	printf("        #           #  #     #   #  #      #     \n");
	printf("        #####   ####    ###  #   #  #      ##### \n");
} 

int menuDraw(){
	int x = 24; 
	int y = 12;
	gotoxy(x-2, y); // -2 한 이유는 > 를 출력해야하기 때문에  
	printf("> 게임시작");
	gotoxy(x, y+1);
	printf("게임정보");
	gotoxy(x, y+2);
	printf("  종료  ");
	while(1){ // 무한반복  
		int n = keyControl(); // 키보드 이벤트를 키값으로 받아오기  
		switch(n){
			case UP: { // 입력된 키의 값이 UP인경우 (w) 
				if(y > 12){ // y는 12~14까지만 이동  
					gotoxy(x-2, y); // x-2 하는 이유는 ">"를 두칸 이전에 출력하기위해  
					printf(" "); // 원래 위치를 지우고  
					gotoxy(x-2, --y); // 새로 이동한 위치로 이동하여  
					printf(">"); // 다시 그리기  
				}
				break;
			}
				
			case DOWN: { // 입력된 키의 값이 DOWN인경우 (s) 
				if(y < 14) { // 최대 14  
					gotoxy(x-2, y);
					printf(" ");
					gotoxy(x-2, ++y);
					printf(">");
				}
				break;
			}
			
			case SUBMIT: {
				return y-12; // 스페이스바(선택)되었을 경우 y-12
				// y 시작 위치가 12였으므로 y-12 를 하면 0, 1, 2 세 숫자를 받을 수 있다. 
			}
		}
	}
} 

int maplistDraw(){
	int x = 24;
	int y = 6;
	system("cls"); // 화면 모두 지우기  
	printf("\n\n");
	printf("                      [ 맵 선택 ]\n\n");
	
	gotoxy(x-2, y);
	printf("> 쉬움");
	gotoxy(x, y+1);
	printf("어려움"); 
	gotoxy(x, y+2);
	printf("뒤로"); 
	
	while(1){  
		int n = keyControl(); // 키보드 이벤트를 키값으로 받아오기  
		switch(n){
			case UP: { // 입력된 키의 값이 UP인경우 (w) 
				if(y > 6){ // y는 6~9까지만 이동  
					gotoxy(x-2, y); // x-2 하는 이유는 ">"를 두칸 이전에 출력하기위해  
					printf(" "); // 원래 위치를 지우고  
					gotoxy(x-2, --y); // 새로 이동한 위치로 이동하여  
					printf(">"); // 다시 그리기  
				}
				break;
			}
				
			case DOWN: { // 입력된 키의 값이 DOWN인경우 (s) 
				if(y < 9) { // 최대 9  
					gotoxy(x-2, y);
					printf(" ");
					gotoxy(x-2, ++y);
					printf(">");
				}
				break;
			}
			
			case SUBMIT: {
				return y-6; // 스페이스바(선택)되었을 경우 y-6
			}
		}
	}
}

void infoDraw(){
	system("cls"); // 화면 모두 지우기  
	printf("\n\n");
	printf("                        [ 조작법 ]\n\n");
	printf("                    이동: W, A, S, D\n");
	printf("                    선택: 스페이스바\n\n\n\n\n\n\n");
	printf("               개발자: codevkr.tistory.com\n\n");
	printf("      스페이스바를 누르면 메인화면으로 이동합니다.");
	
	while(1){
		if(keyControl() == SUBMIT){
			break;
		}
	}
}


