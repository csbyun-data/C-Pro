### A fork command for DOS
* fork()
    * [code]  [fork.man](https://github.com/vonj/snippets.org/blob/master/fork.man), [fork.c](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Fork/fork.c), [fork.h](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Fork/fork.h)
    ```
    typedef struct filenode {
     FILE            *ptr;
     struct filenode *next;
    } FILENODE;                 /* Node in ll containing a file pointer */
   
    typedef struct {
     FILENODE     *head;
     FILENODE     *tail;
    } LL;                       /* ll of FILE pointers                  */
    ```
    ![image](https://github.com/user-attachments/assets/0259cf04-4a76-43e5-967b-4f2459411b1d)

    ```
    echo hello world > abc.txt
    type abc.txt|fork out1.txt *out2.txt /c
    ```
    ![image](https://github.com/user-attachments/assets/dc478c2f-e859-49a5-b088-ee2490920ff0)
  
