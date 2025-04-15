#include <stdlib.h>
#include <stdio.h>

struct Man {
	int age;
	char sex;
	int id;
	char name[12];
};

char name[100];
int count;
struct Man nclass[100];
struct Man man = {19, 'M',201112020, "hongkildong"};
int szman = sizeof(man);

int main(int argc, char *argv[])
{
	int cnt;
	struct Man *pMemb;
	
	pMemb = (struct Man *)malloc( sizeof(struct Man));
	memcpy(pMemb, &man, sizeof(struct Man));
	
	printf("pMemb: 0x%08X\n", pMemb);
	printf("age = %d\n", pMemb->age);
	printf("sex = %c\n", pMemb->sex);
	printf("id  = %d\n", pMemb->id);
	printf("name= %s\n", pMemb->name);
	
	free(pMemb);
	
	return 0;
}
