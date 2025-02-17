
### File Index
* File Index
    * Create Index [index.c](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Index/index.c), [records.txt](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Index/records.txt)
    ```
    1) records.txt file (name, address, phone-number)
    **  This is the indexing function for creating a binary file from an ASCII
    **  file formatted as follows:
    **
    **  Mark Corgan
    **  550 Foothill Rd.
    **  Gardnerville, NV 89410
    **  (702) 265-2388
    **  .
    **  Hello World
    **  123 Anywhere St.
    **  Anytown, CA 12345
    **  (123) 456-7890
    **  .
    **  etc...
    2) create index binary file index.ndx
    - name, line position
    3) index.exe records.txt index.ndx
       index.ndx binary file content : person name, 이름의 위치(문자의 갯수 카운터) 
    ```
    ![image](https://github.com/user-attachments/assets/8f683ed0-093d-424d-9ce1-d762135331fa)
    ```txt
    // binary-file viewer
    > powershell
    > format-hex index.ndx
    ```
    ![image](https://github.com/user-attachments/assets/4d5d3a71-bcc4-424f-b50f-922e2672325d)

    * lookup [lookup.c](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Index/lookup.c), [errors.h](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Index/errors.h), [ferrorf.c](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Index/ferrorf.c), [indxlook.h](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Index/indxlook.h), [sniptype.h](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Index/sniptype.h)
    ```
    1) 찾는 name을 받아들여 index.ndx 파일에 name을 찾아 recodes.txt의 line을 찾음
    2) lookup.exe records.txt index.ndx
    ```
    ![image](https://github.com/user-attachments/assets/dcf06104-7003-47ab-8b12-e74b7c6ddc40)

   
