
##  03. FILE I/O
### Index
* 1.File I/O ([참조: aticleworld.com/file-handling-in-c](https://aticleworld.com/file-handling-in-c/))
  *   1.1 고수준 파일 입력 함수
  ```c
  // FILE의 구조
  typedef struct   {
    short           level;         /* fill/empty level of buffer */
    unsigned        flags;         /* File status flags    */
    char            fd;            /* File descriptor      */
    unsigned char   hold           /* Ungetc char if no buffer */
    short           bsize;         /* Buffer size          */
    unsigned char   *buffer;       /* Data transfer buffer */
    unsigned char   *curp;         /* Current active pointer */
    unsigned        istemp;        /* Temporary file indicator */
    short           token;         /* Used for validity checking */
  } FILE;                          /* This is the FILE object */
  ```
  | mode | description |
  |--|--|
  | "r" | file을 읽기 전용 open, file이 없으면 error |
  | "w" | file을 쓰기 전용 open, file이 존재하면 내용 제거, file이 없으면 생성 |
  | "a" | file을 쓰기 전용 open, file이 존재하면 내용 맨 뒤쪽에 자동이동 덧붙여 작성, file이 없으면 생성 |
  | "r+" | file을 읽기, 쓰기 open, file이 없으면 error |
  | "w+" | file을 읽기, 쓰기 open, file이 존재하면 내용이 지워지며, file이 없으면 생성 |
  | "a+" | file을 읽기, 쓰기 open, file이 존재하면 내용 맨 뒤쪽에 자동이동 읽기, 쓰기, file이 없으면 생성 |
  
  *   1.1 File Open, Create [[Text파일 code1](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/Create_File.c), [Text 파일 code2](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/Text_File1.c), [Binary 파일 code](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/Binary_File1.c)]
  *   ![image](https://github.com/user-attachments/assets/93bb7595-bba8-4e44-84df-d2a2553b606d)
  *   1.2 fprintf(), fputc(), fputs(), fwrite() 사용
  ```c
  FILE *fp = fopen("abc.txt", "w");
  ...
  // tree times asking for student name
  for( i=1; i<4; i++ ) {
    puts("Enter the student name: ");
    gets(name);
    fprintf(fp, "%d. Name = [%s]\n", i, name);
  }
  fclose(fp);
  ```
  ```c
  FILE *fp = fopen("abc.txt", "w");
  ...
  // write A to Z in file
  for( int ch=65; ch<=90; ++ch)
    fputc(ch, fp);
  fclose(fp);
  ```
  ```c
  FILE *fp = fopen("abc.txt", "w");
  ...
  fputs("Hello There, I hope this abc will help!", fp);
  fclose(fp);
  ```
  ```c
  #define MAX_SIZE 32

  char buff[MAX_SIZE] = {0};

  // Get input from the user
  printf("Enter your name = ");
  fgets( buff, MAX_SIZE, stdin);
  
  FILE *fp = fopen("abc.txt", "w");
  ...
  fwrite( buff, sizeif(buff[0]), MAX_SIZE, fp);
  fclose(fp);
  ```  
  *   1.3 fscanf(), fgetc(), fgets(), fread(), fseek() 사용법 ([fscanf 1](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/fscanf_func1.c), [fscanf 2](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/fscanf_func2.c), [fgetc](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/fgetc_func1.c), [fget_line](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/fget_line_func1.c))
  ```c
  FILE *fp = fopen("abc.txt", "r");
  ...
  while( (ch=fgetc(fp)) != EOF) {
    printf("%c", ch);
  }
  
  fclose(fp);
  ```
  getc(), putc() 함수를 활용하여 파일 2개를 다른 한개의 파일로 결합 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/combine_file.c)
  
  fgetc, fputc 함수를 활용한 file 복사 프로그램 ([c code](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/file_copy1.c), [c++ code](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/file_copy3.cpp))
  ```c
  #define MAX_SIZE 32
  
  char readFileData[MAX_SIZE] = {0};
  FILE *fp = fopen("abc.txt", "r");
  ...
  // read file using fgets
  if( fgets(readFileData, MAX_SIZE, fp) == NULL) {
    printf("Error in reading the file\n");
    fclose(fp);
    exit(1);
  }

  puts(readFileData);
  
  fclose(fp);
  ```
  ```c
  #define MAX_SIZE 32
  
  char readFileData[MAX_SIZE] = {0};
  FILE *fp = fopen("abc.txt", "r");
  ...
  // Read 5 character from stream
  fread( readFileData, sizeof(char), 6, fp);

  puts(readFileData);
  
  fclose(fp);
  ```
  ```c
  // fseek에는 SEEK_SET(파일 시작), SEEK_CUR(파일 포인터의 현재 위치), SEEK_END(파일 종료)
  FILE *fp = fopen("abc.txt", "r");
  ...
  fseek( fp, 1, SEEK_SET);
  ch = fgetc(fp);

  fclose(fp);
  ```
  *   1.4 저수준 파일 입출력함수
  
  | mode | value | description |
  |--|--|--|
  | O_RDONLY | 0x0001 | 읽기 전용으로 화일을 연다. |
  | O_WRONLY | 0x0002 | 쓰기 전용으로 화일을 연다. |
  | O_RDWR | 0x0004 | 읽고 쓰기 위해 화일을 연다. |
  | O_CREAT | 0x0100 | 화일이 없을 경우 새로운 화일을 만든다. |
  | O_TRUNC | 0x0200 | 현재 있는 화일의 내용을 0으로(제거) 한다. |
  | O_EXCL | 0x0400 | O_CREAT과 함께 사용하며, 화일이 없을 경우에만 연다. |
  | O_APPEND | 0x0800 | 화일을 쓰기용으로 열고 화일 포인터를 화일의 끝에 위치시킨다. |
  | O_TEXT | 0x4000 | 화일을 텍스트 형식으로 연다. |
  | O_BINARY | 0x8000 | 화일을 이진 형식으로 연다. |
  ```c
  int fd;
  char buf[80];
  int n;
  fd = open("data.dat", O_RDONLY);
  n = (fd, buf, 80); // buf는 포인터 변수
  ```
  ```c
  int fd;
  cha *buf;
  int size;
  int n;
  n = write(fd, buf, size);
  ```
  file size 구하기 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/file_size1.c)
  
  file copy code [here](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/file_copy2.c)
  
* 2.XML response in C without using library
([참조: aticleworld.com/parse-xml-response-in-c/](https://aticleworld.com/parse-xml-response-in-c/))
  *   2.1 Create XML [here](https://github.com/csbyun-data/C-Pro/blob/main/chap03/XML/Create_XML_ex1.c)
  *   2.2 Parse XML [here](https://github.com/csbyun-data/C-Pro/blob/main/chap03/XML/Parse_XML_ex1.c)
  ```c
  //Create Opening Tag
  memset(openTag, 0, sizeof(openTag));
  strcpy(openTag, "<");
  strcat(openTag, pTag);
  strcat(openTag, ">");

  //Create Closing tag
  memset(closeTag, 0, sizeof(closeTag));
  strcpy(closeTag, "</");
  strcat(closeTag, pTag);
  strcat(closeTag, ">");
  ```
  ```c
  //Get Opening tag position
  for (pos=0; pos<len; pos++) {
    if ( !memcmp(openTag,pResBuf+pos,lenOpenTag)) {
        posOpenTag = pos;
        break;
    }
  }

  //Get closing tag position
  for (pos=0; pos<len; pos++) {
    if ( !memcmp(closeTag,pResBuf+pos,lenCloseTag) ) {
        posClosingTag = pos;
        break;
    }
  }
  ```
  ```c
  if ( (posOpenTag !=0) && (posClosingTag !=0) ) {
    const int lenTagVal = posClosingTag-posOpenTag-lenOpenTag;
    char *pStartPosTagVal = pResBuf+posOpenTag+lenOpenTag;
    if (lenTagVal) {
        //Get tag value
        memcpy(pTagValue,pStartPosTagVal, lenTagVal);
        if (strlen(pTagValue)) {
            return 1;
        }
    }
  }
  ```
