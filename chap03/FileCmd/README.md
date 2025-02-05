
### File Command
* File Commands
   * get file size [[fopen code](https://github.com/csbyun-data/C-Pro/blob/main/chap03/FileCmd/file_size_fopen.c)]
   * file copy [[high level code](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/file_copy1.c), [low level code](https://github.com/csbyun-data/C-Pro/blob/main/chap03/FileCmd/file_copy_open.c)]
   ```c
   
     while ((ch = fgetc(srcfp)) != EOF)
        fputc(ch,objfp);
   ```
   
   * tail [[code](https://github.com/csbyun-data/C-Pro/blob/main/chap03/FileCmd/tail.c)]
   ```c
   void getlinenum(int n, char * str[]);
   void gettail(void);
   ```
   ![image](https://github.com/user-attachments/assets/4f5a3877-4451-4407-9fb1-49517254e0a1)

   

