
### File Command
* File Commands
   * get file size [[fopen code](https://github.com/csbyun-data/C-Pro/blob/main/chap03/FileCmd/file_size_fopen.c)]
   * file copy [[high level code](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/file_copy1.c), [low level code](https://github.com/csbyun-data/C-Pro/blob/main/chap03/FileCmd/file_copy_open.c)]
   ```c
   // ligh level file code
   FILE *srcfp, *objfp;
   //..
   while ((ch = fgetc(srcfp)) != EOF)
      fputc(ch,objfp);
   ```
   ```c
   // low level file code
   int fd1, fd2;
   //..
   while ((n = read(fd1, buf, BUFSIZ)) > 0) 
     write(fd2, buf, n)
   ```
   
   * tail [[snip9707 code](https://github.com/csbyun-data/C-Pro/blob/main/chap03/FileCmd/tail.c)]
   ```c
   1) text파일의 하단부분 20line을 출력하는 프로그램

   void getlinenum(int n, char *str[]);
   void gettail(void);
   ```
   ![image](https://github.com/user-attachments/assets/4f5a3877-4451-4407-9fb1-49517254e0a1)

   

