// data.dat파일을 정렬하여 다른 파일에 저장
// 한 line을 읽어 들여 처리

// data.dat 파일의 한 Line을 읽어들여 순서를 정렬하고 출력
// >line_sort name_data.dat sdata.dat
//data.dat 파일의 한 line을 읽어들여 역순으로 정렬하고 출력
// >line_sort -r name_data.dat sdata.dat

#include <stdio.h>
#include <string.h>

#define REVERSE     -1
#define NORMAL       1
#define MAXLINENO  100
#define MAXCNO      80
#define TRUE    EOF*-1 

int main(int argc, char *argv[]) 
{
  static char text[MAXLINENO][MAXCNO];
  char t[MAXCNO];
  FILE *fp1, *fp2;
  int direction = NORMAL;
  int no = 0;
  int i, j;
  
  if ((argc != 3 && argc != 4) || (argc == 4 && strcmp(*(argv+1), "-r"))) {
    fprintf(stderr,"USAGE: %s [-r] filename(1) filename(2)\n",*argv);
    return (1);
  }
  
  if (argc == 4) {              /*  -r을 주면 역으로 정렬  */
    direction = REVERSE;
    ++argv;
  }
  
  if ((fp1 = fopen(*++argv, "r")) == NULL) {
    fprintf(stderr,"Error: Cannot open %s\n",*argv);
    return (2);
  }
  
  if ((fp2 = fopen(*++argv, "w")) == NULL) {
    fprintf(stderr,"Error: Cannot create %s\n",*argv);
    return (3);
  }
    
  while (fget_line(fp1, text[no++]) != EOF);
  for (i = 0; i < no - 2; i++)
    for (j = i + 1; j < no - 1; j++)
      if (strcmp(text[i], text[j]) * direction > 0) {
        strcpy(t, text[i]);
        strcpy(text[i], text[j]);
        strcpy(text[j], t);
      }
  
  for (i = 0; i < no - 1; i++)
    fprintf(fp2,"%s\n",text[i]);
    
  fclose(fp1);
  fclose(fp2);
}

int fget_line(FILE *fp, char *s) { /*  화일로부터 한 라인을 읽어들임  */
  char *cp = s;                       
  while ((*s = getc(fp)) != EOF)  /*    ( data.dat )    */
    if (*s == '\n') {             /*    Lee Seung Wook  */
      *s = '\0';                  /*    Kwon Oh Jin     */
      return (TRUE);              /*    Oh Jung Pyo     */
      }                           /*    Kim Joon Sik    */
    else                          /*    Yun Young Il    */
      ++s;                        /*    Kwon Oh Chang   */
  if (cp == s)                    /*    Kim Chang Ju    */
    return (EOF);                 /*    Hong Gil Dong   */
  *s = '\0';                      /*    Kim Young Hoon  */
  return (TRUE);                  /*    Kim Jong Min    */
}  
