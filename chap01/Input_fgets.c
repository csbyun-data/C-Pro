#include <stdio.h>

int main()
{
	int age;
	char name[10];
	char address[10];
	
	printf("input name, age : ");
	scanf("%s %d", name, &age);
	
	printf("input address. :");

  // 문자열이 공백이 있어도 줄 전체를 읽어들임
	fflush(stdin); // Keyboard Buffer를 비움
	fgets(address, 50, stdin); //scanf("%s", address);
	
	printf("name: %s, age: %d, address:%s \n", name, age, address);
	
	return 0;
}
