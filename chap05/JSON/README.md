## JSON 파일 parser
### INDEX
* 1.JSON (JavaScript Object Notation)
    * 1.1 참조 Lightweight JSON library written in C [[kgabis/parson](https://github.com/kgabis/parson)] [[parson.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/JSON/parson.c), [parson.h](https://github.com/csbyun-data/C-Pro/blob/main/chap05/JSON/parson.h)]
    * 1.2 pason library를 활용한 json 문서 읽기 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/JSON/JSON_read.c)  
    ![image](https://github.com/user-attachments/assets/942b7429-e06a-4a10-aa59-51e3fcda9db6)
  
    * 1.3 pason library를 활용한 json 문서 쓰기 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/JSON/JSON_write.c)
    ![image](https://github.com/user-attachments/assets/a124ddd5-adb0-46c7-80a8-1ba0a6f76290)
    * 1.4 pason library, Serialization [code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/JSON/JSON_Serialization.c)
    ```txt
    - Create a simple JSON value containing basic information about a person.
    ```
    ![image](https://github.com/user-attachments/assets/347a56e2-c953-46f3-8f8b-c3a65a6630b6)

    * 1.5 pason library, Persistence [code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/JSON/JSON_Persistence.c)
    ```txt
    using parson to save user information to a file then load it and validate later.
    - 파일을 user_data.json에 저장 후 파일 자료를 읽어 화면에 출력
    ```
    ![image](https://github.com/user-attachments/assets/99ed35b1-6389-469c-903d-465b4b03625a)
    ![image](https://github.com/user-attachments/assets/76f649a8-32cb-4d68-8e83-c44d993ec6cb)

    * 1.6 pason library, Parsing JSON [code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/JSON/Commit_Info.c)
    ```txt
    Here is a function, which prints basic commit info( data, sha and author)
    from a github repository
    ```  
    ![image](https://github.com/user-attachments/assets/1e785172-bafd-46c9-ba01-d2479c2022cb)

    
