### [SDB] Simple Data Base
* simple data base code
    * [cmd.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/SDB/cmd.c)
    * [com.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/SDB/com.c)
    * [cre.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/SDBcre.c)
    * [err.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/SDB/err.c)
    * [iex.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/SDB/iex.c)
    * [int.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/SDB/int.c)
    * [io.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/SDB/io.c)
    * [mth.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/SDB/mth.c)
    * [pcjunk.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/SDB/pcjunk.c)
    * [scn.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/SDB/scn.c)
    * [sdb.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/SDB/sdb.c)
    * [sdbio.h](https://github.com/csbyun-data/C-Pro/blob/main/chap05/SDB/sdbio.h)
    * [sel.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/SDB/sel.c)
    * [srt.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/SDB/srt.c)
    * [tbl.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/SDB/tbl.c)
    * [_proto.h](https://github.com/csbyun-data/C-Pro/blob/main/chap05/SDB/_proto.h)
    ```
    // SQL 문장 분석하여 파일 생성, 자료 조회, 저장, 수정, 삭제, 정렬 기능
    // 매크로 작업 저장 기능
    create checks (
    number      num     4
    date        char    8
    payee       char    20
    amount      num     8
    category    char    5
    ) 200

    1. ./checks.sdb 파일이 생성 됨, 속성이 읽기 모드로 생성 됨으로 속성 수정해야됨
    2. 속성 수정관련 프로그램 점검 필요함
    ```
    ```
    // scn.c
    int dbv_token;                          /* current token */
    int dbv_tvalue;                         /* integer token value */
    char dbv_tstring[STRINGMAX+1];          /* string token value */
    
    const static char *keywords[] = {             /* keyword table */
      "ascending",
      "by",
      "char",
      "compress",
      "create",
      //..
    };
    const static int keytokens[] = {              /* token values for each keyword */
      ASCENDING, //-32
      BY,        //-31
      CHAR,      //-14
      COMPRESS,  //-25
      CREATE,    //-10
      //..
    };
    ```
    ```
    // cmd.c
    /* db_parse - parse a command */
    int db_parse(char *fmt, ... ) {
      int sts;

      /* check for a command line */
      if (fmt != NULL)
        db_scan(fmt);

      /* determine the statement type */
      switch (db_ntoken()) {
      case CREATE:
                sts = create();
                break;
      default:
         return (db_ferror(SYNTAX));
      }
      return (sts);
    }
    ```
    ```
    /* db_token - return the current input token */
    int db_token() {
      struct macro *mptr;
      struct ifile *new_ifp;
   
      /* find a token that's not a macro call */
      // db_xtoken()에서 dbv_token 값 대입 
      while (db_xtoken() == ID) {
        /* check for a macro call */
        //...
      }
      return (dbv_token);
    }

    /* db_xtoken - return the current input token */
    int db_xtoken() {
       int ch;
   
       /* check for a saved token */
       if ((dbv_token = savetkn) != NULL)
         return (dbv_token);
   
       /* get the next non-blank character */
       ch = nextch();
   
       /* check type of character */
       if (isalpha(ch))                    /* identifier or keyword */
         get_id();
       else if (isdigit(ch))               /* number */
         get_number();
       else if (ch == '"')                 /* string */
         get_string();
       else if (get_rel())                 /* relational operator */
         ;
       else                                /* single character token */
         dbv_token = getch();
   
       /* save the lookahead token */
       savetkn = dbv_token;
   
       /* return the token */
       return (dbv_token);
    }
           
    /* db_ntoken - get next token (after skipping the current one) */
    int db_ntoken() {
      /* get the current token */
      db_token();
   
      /* make sure another is read on next call */
      savetkn = NULL;
   
      /* return the current token */
      return (dbv_token);
    }

    /* db_xntoken - get next token (after skipping the current one) */
    int db_xntoken() {
      /* get the current token */
      db_xtoken();

      /* make sure another is read on next call */
      savetkn = NULL;

      /* return the current token */
      return (dbv_token);
    }    
    ```
    ![image](https://github.com/user-attachments/assets/c4c26f22-f863-4b8c-ad0c-ff739bd0912f)
    ```
    insert checks
    ```
    ![image](https://github.com/user-attachments/assets/e583607d-f0a8-4268-bd85-57ddb5409870)
    ```
    delete checks where category = "junk";
    ```
    ![image](https://github.com/user-attachments/assets/165be257-c102-4f7e-8470-b825f2042788)
    ```
    update amount, category from checks where number = 2;
    print payee,amount from checks where category;
    select * from checks;
    ```
    ![image](https://github.com/user-attachments/assets/91e22ab9-f1fc-4bac-a776-f1e4ecd8ef1d)
    ![image](https://github.com/user-attachments/assets/0e99360b-9ec8-4c71-9619-6bf8e957ff6f)

    ```
    import in.dat into checks
    export checks into a.dat
    extract checks into c; <- c.def 파일이 생성됨
    compress checks - 지워진 row를 줄이고, 마지막 row 입력칸을 당김
    ```
    ![image](https://github.com/user-attachments/assets/b25f6712-38e5-44fd-9ec5-90a77dd1949a)
    ![image](https://github.com/user-attachments/assets/e0412b88-8418-4337-8a4b-f9316c4c8d6f)
    ```
    sort checks by amount descending;
    sort checks by amount asending;
    ```
    ![image](https://github.com/user-attachments/assets/ee946edd-cf7e-42c2-a58d-d02efe232998)
    ![image](https://github.com/user-attachments/assets/b86e1720-52fc-47c0-8873-d380968a9062)
    ```
    // macro 파일생성
    define macro
    show macro
    ```
    ![image](https://github.com/user-attachments/assets/6e7900a2-cfde-4535-a234-e508c209885e)
    ```
    //fuction
    help <- sdb.hlp 파일 내용을 화면에 출력
    exit <- 프로그램 종료
    ```
    ![image](https://github.com/user-attachments/assets/125068ed-becc-41a1-b35d-22cd79b9dfa5)





    
