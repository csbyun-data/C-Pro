### FILE I/O
* 1.File I/O
    * Reference [file-handling-in-c](https://aticleworld.com/file-handling-in-c/)
    * 1.1 고수준 파일 입력 함수
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
  
    *   1.1 File Open fopen(), Create [[Text파일 code1](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/Create_File.c), [Text 파일 code2](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/Text_File1.c), [Binary 파일 code](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/Binary_File1.c)]  
    ![image](https://github.com/user-attachments/assets/93bb7595-bba8-4e44-84df-d2a2553b606d)
    *   1.1-1 Binary File, song 구조체 저장, 읽기 [저장 code](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/Bin_Struct_song1.c), [읽기 code](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/Bin_Struct_song2.c)

* Writing to a File
    *   1.2 fprintf(), fputc(), fputs(), fwrite() 사용 [fprintf.c](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/fprintf.c), [fputc.c](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/fputc.c), [fputs.c](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/fputs.c), [fwrite.c](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/fwrite.c)
    ```c
    // fprintf.c
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
    // fputc.c
    FILE *fp = fopen("abc.txt", "w");
    ...
    // write A to Z in file
    for( int ch=65; ch<=90; ++ch)
      fputc(ch, fp);
    fclose(fp);
    ```
    ```c
    // fputs.c
    FILE *fp = fopen("abc.txt", "w");
    ...
    fputs("Hello There, I hope this abc will help!", fp);
    fclose(fp);
    ```
    ```c
    // fwrite.c
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
    
* Reading from a file
    *   1.3 fscanf(), fgetc(), fgets(), fread(), fseek() 사용법 ([fscanf 1](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/fscanf_func1.c), [fscanf 2](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/fscanf_func2.c), [fgetc](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/fgetc_func1.c), [fgets](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/fgets_func1.c), [fget_line](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/fget_line_func1.c))
    ```c
    //fscanf_func1.c
    char readFileData[MAX_SIZE+MAX_SIZE] = {0};
    FILE *fp = fopen("abc.txt", "r");
    ...
    fscanf(fp, "%s", readFileData);
    puts(readFileData);
    fclose(fp);
    ```
    ```c
    //fgetc_func1.c
    FILE *fp = fopen("abc.txt", "r");
    ...
    while( (ch=fgetc(fp)) != EOF) {
      printf("%c", ch);
    }
    
    fclose(fp);
    ```
    ```c
    // fgets_func1.c
    char readFileData[MAX_SIZE] = {0};
    FILE *fp = fopen("abc.txt", "r");
    ...
    if( fges(readFileData, MAX_SIZE, fp) == NULL) {
      fclose(fp);
      exit(1);
    }
    puts(readFileData);
    fclose(fp);
    ```
    
    * getline() 구현 및 사용법 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap03/getline/README.md)
    * getc(), putc() 함수를 활용하여 파일 2개를 다른 한개의 파일로 결합 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/combine_file.c)
    
    * fgetc, fputc 함수를 활용한 file 복사 프로그램 ([file_copy1](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/file_copy1.c), [fread](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/fread_func1.c), [c++ code](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/file_copy3.cpp))
    ```c
    // file_copy1.c
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
    // fread_func1.c
    #define MAX_SIZE 32
    
    char readFileData[MAX_SIZE] = {0};
    FILE *fp = fopen("abc.txt", "r");
    ...
    // Read 5 character from stream
    fread( readFileData, sizeof(char), 6, fp);
  
    puts(readFileData);
    
    fclose(fp);
    ```
    * fseek()이용 파일크기 계산 [code]()
    ```c
    // int fseek(FILE *pointer. long int offset, int position);
    // SEEK_SET(파일 시작)
    // SEEK_CUR(파일 포인터의 현재 위치)
    // SEEK_END(파일 종료)
    
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
