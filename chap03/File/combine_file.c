//getc, putc 함수를 활용하여 파일 2개를 다른 파일 한개로 합침

#include <stdio.h>

int main()
{
  char c;
  char fname1[20], fname2[20], fname3[20];
  FILE *fp1, *fp2, *fp3;

  printf("Input the first file name -> ");
  gets(fname1);

  printf("Input the second file name -> ");
  gets(fname2);

  printf("Input the file name to create -> ");
  gets(fname3);

  if ((fp1 = fopen(fname1, "r")) == NULL) {
    printf("Error : Cannot open %s\n",fname1);
    exit(-1);
  }

  if ((fp2 = fopen(fname2, "r")) == NULL) {
    printf("Error : Cannot open %s\n",fname2);
    fclose(fp1);
    exit(-1);
  }

  if ((fp3 = fopen(fname3, "w")) == NULL) {
    printf("Error : Cannot create %s\n",fname3);
    fclose(fp1);
    fclose(fp2);
    exit(-1);
  }

  while ((c = getc(fp1)) != EOF)  /*  화일로부터 한자씩 읽어들일 때에는 getc를,  */
    putc(c,fp3);                  /*  출력할 때에는 putc를 사용하면 된다  */

  fclose(fp1);

  while ((c = getc(fp2)) != EOF)
    putc(c,fp3);

  fclose(fp2);

  fclose(fp3);
}
