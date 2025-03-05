#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define COL GetStdHandle(STD_OUTPUT_HANDLE)
#define RED SetConsoleTextAttribute(COL, 0x000c)
#define YELLOW SetConsoleTextAttribute(COL, 0x000e)
#define GREEN SetConsoleTextAttribute(COL, 0x000a)
#define SKY_BLUE SetConsoleTextAttribute(COL, 0x000b)
#define PURPLE SetConsoleTextAttribute(COL, 0x0005)
#define DEFAULT SetConsoleTextAttribute(COL, 0x0007)

#define MAX_COUNT 100
#define NO_FILE -1
#define LOADED_FILE 0
#define FILE_NAME "student.db"

typedef struct student{
  struct student* next; 
  char name[10];
  int kor;
  int math;
  int eng;
}NODE;

int loadfile(NODE*);
void savefile(NODE*);
void createfile();
void add_data(NODE*);
void delete_data(NODE*);
void modif_data(NODE*);
void print_data(NODE*);
void close_node(NODE*);
void clear_buf();

int count = 0;

int main(void){
  int status, menu;
  NODE* head = (NODE*)malloc(sizeof(NODE));
  head->next = NULL;
  
  status = loadfile(head);
  if(status == -1){
    createfile();
    printf("New File Created!\n");
    Sleep(1000);
    system("cls");
  }
  
  while(1){
    printf("1. View\n2. Add\n3. Update\n4. Delete\n0. Exit\n");
    GREEN;
    scanf("%d", &menu);
    DEFAULT;
    
    system("cls");
    switch(menu)
    {
      case 1:
        print_data(head);
        system("pause"); 
        system("cls");
        break;
      
      case 2:
        add_data(head);
        system("cls");
        break;
        
      case 3:
        modif_data(head);
        system("cls");
        break;
      
      case 4:
        delete_data(head);
        system("cls");
        break;
         
      default:
        menu=0; 
        break;
    }
    
    if(menu == 0) break;
  }
  
  close_node(head);
  return 0;
}

int loadfile(NODE* head){
  int i;
  NODE* add;
  FILE* open = fopen(FILE_NAME, "r");
  
  if(open == NULL){
    RED;
    printf("FILE ERROR!\n");
    DEFAULT;
    return NO_FILE; 
  }
  
  fscanf(open,"%d\n", &count);
  
  for(i=0; i<count; i++){
    add  = (NODE*)malloc(sizeof(NODE));
    fscanf(open ,"%d %d %d %s\n", &add->kor, &add->math, &add->eng, &add->name);
    add->next = head->next;
    head->next = add;
  }
  fclose(open);
  return LOADED_FILE;
}

void savefile(NODE* head){
  int i;
  NODE* curr;
  FILE* save = fopen(FILE_NAME, "w");
  
  if(save == NULL){
    RED;
    printf("FILE ERROR!\n");
    DEFAULT;
    return;
  }
  
  fprintf(save, "%d\n", count);
  
  curr = head->next;
  while(curr != NULL){
    fprintf(save ,"%d %d %d %s \n", curr->kor, curr->math, curr->eng, curr->name);
    curr= curr->next;
  }
  fclose(save);
}

void createfile(){
  FILE* newfile = fopen(FILE_NAME, "a");
  fprintf(newfile, "%d", 0);
  fclose(newfile);
}

void add_data(NODE* head){
  int over = 0;
  int n = 1;
  int i = 0;
  NODE* add = (NODE*)malloc(sizeof(NODE));
  add->next = head->next;
  head->next = add;
  
  
  while(1){
    clear_buf();
    if(over){
      RED;
      if(over == 1) printf("There are scores that are out of range among the data you entered.\n");
      else if(over == 2) printf("Empty data cannot be saved.\n");
      else printf("Unknown error!\n");
      DEFAULT;
    }
    
    printf("Student name: ");
    fgets(add->name, 10, stdin); 
    if(add->name[0] == '\n'){
      over = 2;
      continue;
    }
    printf("Kor: ");
    scanf("%d", &add->kor); 
    printf("Math: ");
    scanf("%d", &add->math); 
    printf("Eng: ");
    scanf("%d", &add->eng);
    if(add->kor>100 || add->math>100 || add->eng>100 || add->kor<0 || add->math<0 || add->eng<0) {
      over = 1;
      continue;
    }
    over = 0;
    printf("\n Do you want to save the above data? (Yes: 1/ No: 0): ");
    GREEN;
    scanf("%d", &n);
    DEFAULT; 
    if(n==1) break;
  }
  
  while(add->name[i] != '\n'){
    i++;
  }
  add->name[i]= NULL;
  count++;
  
  savefile(head);
}

void delete_data(NODE* head){
  int n,i=0;
  NODE* curr;
  NODE* temp;
  
  print_data(head);
  
  if(count == 0){
    printf("No data was saved.\n\n");
    system("pause");
    system("cls");
    return;
  }
  
  printf("Enter the data number to delete. (1~%d) [0 : Exit]: ", count);
  RED;
  scanf("%d", &n);
  DEFAULT;
  if(n==0) return;
  
  temp = head;
  curr = head->next;
  while(curr != NULL && i<n-1){
    temp = curr;
    curr = curr->next; 
    i++;
  }
  temp->next = curr->next;
  free(curr);
  count--;
  savefile(head);
}

void modif_data(NODE* head){
  int over = 0, n, i=1;
  NODE* curr;
  NODE* temp;
  
  print_data(head);
  
  if(count == 0){
    printf("No data was saved.\n\n");
    system("pause");
    system("cls");
    return;
  }
  
  printf("Enter the data number you want to modify (1~%d) [0 : Exit]: ", count);
  YELLOW;
  scanf("%d", &n);
  DEFAULT;
  if(n==0) return;
  i=0;
  
  curr = head->next;
  while(curr != NULL && i<n-1){
    curr = curr->next; 
    i++;
  }
  
  while(1){
    clear_buf();
    if(over){
      RED;
      printf("There are scores that are out of range among the data you entered.\n");
    }
    DEFAULT;
    printf("[ Student Name: %s ] >> ", curr->name);
    GREEN;
    scanf("%s", curr->name);
    DEFAULT;
    printf("Korean language score: %d >> ", curr->kor);
    GREEN;
    scanf("%d", &curr->kor);
    DEFAULT;
    printf("Math score: %d >> ", curr->math);
    GREEN;
    scanf("%d", &curr->math);
    DEFAULT;
    printf("English score: %d >> ", curr->eng);
    GREEN;
    scanf("%d", &curr->eng);
    DEFAULT;
    
    if(curr->kor>100 || curr->math>100 || curr->eng>100 || curr->kor<0 || curr->math<0 || curr->eng<0) {
      over = 1;
      continue;
    }
    else break;
  }
  
  over = 0;
  savefile(head);
}

void print_data(NODE* head){
  int c_len=0, c_space=0, obb=0, i=1;
  int kor_total = 0;
  int math_total = 0;
  int eng_total = 0;
  float avg = 0.0f;
  float avg_total = 0.0f;
  float kor_avg = 0.0f;
  float math_avg = 0.0f;
  float eng_avg = 0.0f;
  NODE* curr;
  
  printf("Total Student: ");
  SKY_BLUE;
  printf("%d\n\n", count);
  DEFAULT;
  printf("+----+----------------+------+------+------+------+\n");
  printf("|NO. | Student Name   | Kor  | Math | Eng  | Avg. |\n"); 
  printf("+----+----------------+------+------+------+------+\n"); 
  curr = head->next;
  while(curr != NULL){
    printf("|%04d|", i++);
    for(c_len=0; curr->name[c_len]!=NULL; c_len++){
      c_space = 16-c_len;
    }
    
    if(c_len%2==0){
      obb = 0;
    } else {
      obb = 1;
    }
    
    for(c_len=0+obb; c_len<c_space/2; c_len++){
      printf(" ");
    }
    
    YELLOW;
    printf("%s", curr->name);
    
    for(c_len=0; c_len<c_space/2; c_len++){
      printf(" ");
    }
    DEFAULT;
    printf("|");
    GREEN;
    if(curr->kor!=100){
      printf(" ");
      if(curr->kor<10){
        printf(" ");
      }
    }
    printf("  %d", curr->kor);
    kor_total += curr->kor;
    
    DEFAULT;
    printf(" |");
    GREEN;
    if(curr->math!=100){
      printf(" ");
      if(curr->math<10){
        printf(" ");
      }
    }
    printf("  %d", curr->math);
    math_total += curr->math;
    
    DEFAULT;
    printf(" |");
    GREEN;
    if(curr->eng!=100){
      printf(" ");
      if(curr->eng<10){
        printf(" ");
      }
    }
    printf("  %d", curr->eng);
    eng_total += curr->eng;
    
    DEFAULT;
    printf(" |");
    RED;
    avg = (curr->kor+curr->math+curr->eng)/(float)3;
    if(100!=(int)avg) {
      printf(" "); 
      if(10>(int)avg) printf(" ");
    }
    avg_total += avg;
    printf("%0.2f", avg);
    
    DEFAULT;
    printf("|\n+----+----------------+------+------+------+------+\n");
    curr = curr->next;
  }
  kor_avg = (float)kor_total/(float)count;
  math_avg = (float)math_total/(float)count;
  eng_avg = (float)eng_total/(float)count;
  
  printf("|    | the average of all students |"); 
  if(count == 0){
    printf("0.00  |0.00  |0.00  |0.00  ");
  } else {
    SKY_BLUE;
    printf("%0.2f", kor_avg); DEFAULT;
    if(100!=(int)kor_avg) {
      printf(" ");
      if(10>(int)kor_avg) printf(" ");
    }	
    printf("|");
    SKY_BLUE;
    printf("%0.2f", math_avg); DEFAULT;
    if(100!=(int)math_avg) {
      printf(" ");
      if(10>(int)math_avg) printf(" ");	
    }
    printf("|");
    SKY_BLUE;
    printf("%0.2f", eng_avg); DEFAULT;
    if(100!=(int)eng_avg) {
      printf(" ");
      if(10>(int)eng_avg) printf(" ");	
    }
    printf("|");
    SKY_BLUE;
    printf("%0.2f", avg_total/(float)count); DEFAULT;
    if(100!=(int)(avg_total/(float)count)){
      printf(" ");
      if(10>(int)(avg_total/(float)count)) printf(" ");	
    }	
    DEFAULT;
  }
  printf("|\n+----+----------------+------+------+------+------+\n");
}

void close_node(NODE* head){
  NODE* target = head->next;
  
  while(target != NULL){
    head->next = target->next;
    free(target);
    target = head->next;
  }
  free(head);
}

void clear_buf(){
  RED;
  printf("Error Freeing Buffer! Press Enter to proceed manually.");
  while(getchar() != '\n');
  DEFAULT;
  system("cls");
}
