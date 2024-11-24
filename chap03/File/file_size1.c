//각 파일의 크기를 출력하는 프로그램

#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[]) 
{
  int fd;
  long int size;
  int n;
  char buf[BUFSIZ];
  
  if (argc == 1) {
    fprintf(stderr,"USAGE: %s file(1) file(2) ... file(n)\n",*argv);
    return (0);
  }
  
  while (--argc > 0) {
    if ((fd = open(*++argv, O_RDONLY | O_BINARY)) == -1) {
      fprintf(stderr,"Error: Cannot open %s\n",*argv);
      continue;
    }
    
    size = 0l;
    while ((n = read(fd, buf, BUFSIZ)) > 0)
      size += n;
    if (n == 0)
      fprintf(stdout,"%s: %ld bytes.\n",*argv,size);
    else
      fprintf(stderr,"Error in reading %s\n",*argv);
  }
  close(fd);          /*  핸들이 다루는 화일을 닫는다. 되돌림 값은 화일 닫기가  */ 
}                     /*  성공하면 0, 실패하면 -1의 값을 되돌린다  */
