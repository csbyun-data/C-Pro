### [SDB] Simple Data Base
* simple data base code
    * [cmd.c]()
    * [com.c]()
    * [cre.c]()
    * [err.c]()
    * [iex.c]()
    * [int.c]()
    * [io.c]()
    * [mth.c]()
    * [pcjunk.c]()
    * [scn.c]()
    * [sdb.c]()
    * [sdbio.h]()
    * [sel.c]()
    * [srt.c]()
    * [tbl.c]()
    * [_proto.h]()
    ```
    // 활용 문장
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
    extract checks into c; - c.def 파일이 생성됨
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



    
