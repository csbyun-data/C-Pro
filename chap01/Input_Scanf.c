// 입력 문자열에 공백이 있는 경우 공백뒷글자 잘림 
#include <stdio.h>

int main()
{
    int age;
    
    char name[10];
    char address[10];
	
    printf("input name, age : ");
    scanf("%s %d", name, &age);
	
    printf("input address. :");
    scanf("%s", address);  //문자열에 공백이 있는경우 잘림
	
    printf("name: %s, age: %d, address:%s \n", name, age, address);
	
    return 0;
}
