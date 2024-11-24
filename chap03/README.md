
## FILE I/O
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
  
  *   1.1 File Open, Create [code](https://github.com/csbyun-data/C-Programming/blob/main/chap03/File/Create_File.c)
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
  *   1.2 fscanf(), fgetc(), fgets(), fread(), fseek() 사용법 ([fscanf 1](https://github.com/csbyun-data/C-Programming/blob/main/chap03/File/fscanf_func1.c), [fscanf 2](https://github.com/csbyun-data/C-Programming/blob/main/chap03/File/fscanf_func2.c))
  ```c
  FILE *fp = fopen("abc.txt", "r");
  ...
  while( (ch=fgetc(fp)) != EOF) {
    printf("%c", ch);
  }
  
  fclose(fp);
  ```
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
  
  
* 2.XML response in C without using library
([참조: aticleworld.com/parse-xml-response-in-c/](https://aticleworld.com/parse-xml-response-in-c/))
  *   2.1 Create XML [here](https://github.com/csbyun-data/C-Programming/blob/main/chap03/XML/Create_XML_ex1.c)
  *   2.2 Parse XML [here](https://github.com/csbyun-data/C-Programming/blob/main/chap03/XML/Parse_XML_ex1.c)
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
