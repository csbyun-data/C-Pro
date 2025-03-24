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

    insert checks
    delete checks where category = "junk";
    update amount, category from checks where number > 4;
    print payee,amount from checks where category = "junk";
    import in.dat into checks
    export checks into a.dat
    extract checks into c; - c.def 파일이 생성됨
    compress checks - 지워진 row를 줄이고, 마지막 row 입력칸을 당김
    ```
