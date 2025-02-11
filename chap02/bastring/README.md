### bastring
* bastring function
    * string function [bastring.c](https://github.com/csbyun-data/C-Pro/blob/main/chap02/bastring/bastring.c), [bastring.h](https://github.com/csbyun-data/C-Pro/blob/main/chap02/bastring/bastring.h)
    ```
    char *stralloc(size_t length);
    void  str_free(char *string);
    char *left(char *string, size_t N);
    char *right(char *string, size_t N);
    char *mid(char *string, size_t M, size_t N);
    char *string_add(char *string, ...);
    char *string(int ch, size_t N);
   
    unsigned int instr(const unsigned int start_pos,
                       const char        *string,
                       const char        *findstr);
    ```
    ![image](https://github.com/user-attachments/assets/1ef5f6fd-d9bd-4fae-9fba-568a86e69209)
