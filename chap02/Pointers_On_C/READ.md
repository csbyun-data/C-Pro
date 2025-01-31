## Pointers On C
### INDEX

* 1.Pointer On C
  * Contents 
  ```txt
  1. A Quick Start.
  2. Basic Concepts.
  3. Data.
  4. Statements.
  5. Operators and Expressions.
  6. Pointers.
  7. Functions.
  8. Arrays.
  9. Strings, Characters, and Bytes.
  10. Structures and Union.
  11. Dynamic Memory Allocation.
  12. Using Structures and Pointers.
  13. Advancd Pointer Topics.
  14. The Preprocessor.
  15. Input/Output Functions.
  16. Standard Library.
  17. Classic Abstract Data Types.
  18. Runtime Environment.
  Appendix:Seleted Problem Solutions.
  ```

  * Book [Code](https://github.com/DragScorpio/Pointers-On-C-Solutions)
* Chap01
  * rearrange [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/rearrange.c)
  ```
  주어진 문자열을 0~3, 10~12 문자를 합쳐 출력하는 예제
  ```
  ![image](https://github.com/user-attachments/assets/4446011d-fbec-4652-a3c1-86407086b15c)
  
* Chap03 Data
  * return string, int [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/return.c)
  ```c
  #include <stdio.h>

  char *returnstring( char *);
  int *returnint( int c);
  
  int main( void ) {
    char string[10] = "a string";
    
    printf( "%s\n", returnstring( string ) );
    printf( "%i\n", *returnint(20) );
    
    return 0;
  }
  
  char *returnstring( char *string ) {
    char *str = "the string";
    return str;
  }
  
  int *returnint( int c ) {
    int *value = &c;
    return value;
  }
  ```  
  ![image](https://github.com/user-attachments/assets/143fdf90-e459-459f-9409-40c2840f4ddf)


* Chap07
  * implementation printf() [main.c](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/printf/main.c), [printf.h](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/printf/printf.h), [printf.c](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/printf/printf.c) 
  ```c
  void print_format( char*, ... );
  void print_integer( int );
  void print_float( float );
  void print_string( char* );
  ```
  ![image](https://github.com/user-attachments/assets/2931a998-4a46-432f-88e4-b294590f1546)



