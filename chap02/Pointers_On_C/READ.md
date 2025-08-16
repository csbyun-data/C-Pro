### Pointers On C
* INDEX
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
* Chap01 A Quick Start.
  * rearrange [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/rearrange.c)
  ```
  주어진 문자열을 0~3, 10~12 문자를 합쳐 출력하는 예제
  ```
  ![image](https://github.com/user-attachments/assets/4446011d-fbec-4652-a3c1-86407086b15c)

* Chap02 Basic Concepts [main.c](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/Ch02/main.c), [increment.h](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/Ch02/increment.h), [increment.c](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/Ch02/increment.c), [negate.h](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/Ch02/negate.h), [negate.c](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/Ch02/negate.c)  
  ![image](https://github.com/user-attachments/assets/fc01cb0d-25ff-41b2-b656-43b15cda4994)

* Chap03 Data.
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

* Chap06 Pointers.
  * [testPtr.c]()
  * 
 
 
* Chap07 Functions.
  * implementation printf() [main.c](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/printf/main.c), [printf.h](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/printf/printf.h), [printf.c](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/printf/printf.c) 
  ```c
  void print_format( char*, ... );
  void print_integer( int );
  void print_float( float );
  void print_string( char* );
  ```
  ![image](https://github.com/user-attachments/assets/2931a998-4a46-432f-88e4-b294590f1546)

* Chap11 Dynamic Memory Allocation.
  * Keyin한 문자열이 20개 단위로 잘라서 크기가 더 크면 메모리를 추가 할당하여 문자열 저장
  * [read_from_stdin code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/Ch11/read_from_stdin.c)
  ```txt
  - 문자열을 입력 중 종료하고 싶을때는 ^Z를 typing하여 준다
  ```
  ![image](https://github.com/user-attachments/assets/df18d5f5-3ffb-40ef-9736-515fc6fb51c6)
  
  * 문자열 크기의 확장으로 할당된 메모리를 다른곳에 크게 재생성하는 방법
  * [my_alloc.c code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/Ch11/my_alloc.c)
  ```c
  /* allocate num memory blocks each occupying size bytes */
  void *my_calloc( size_t num, size_t size );
  
  /* reallocate the memory block that is pointed to from ptr, to size bytes instead */
  void *my_realloc( void *ptr, size_t old_size, size_t new_size );
  ```
  ![image](https://github.com/user-attachments/assets/ee58aa4b-8b66-4b25-bc24-a7103b79528f)

  * Linked List 방식의 메모리를 할당하고, 해제하는 방법 점검 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/Ch11/linked_list.c)

  ![image](https://github.com/user-attachments/assets/2105a77e-10ca-4ace-9b67-20336a91905c)

* Chap16 Standard Library.
  * Generic Insertion Sort 구현 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/Ch16/insertion_sort.c)

  ![image](https://github.com/user-attachments/assets/78902849-f69c-4084-a9ef-c8ca9ab1effa)

* Chap17 Classic Abstract Data Types.
  * Linked List Tree Implementation [main_t.c](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/Ch17/main_t.c), [llist_tree.h](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/Ch17/llist_tree.h), [llist_tree.c](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/Ch17/llist_tree.c)
 
  ![image](https://github.com/user-attachments/assets/147ada53-c57b-404a-ae86-980e7608cfa7)

  ![image](https://github.com/user-attachments/assets/00c7c41b-5520-42b6-bbe8-26d97ab6118c)

  * Linked List Queue Implementation [main_q.c](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/Ch17/main_q.c), [llist_queue.h](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/Ch17/llist_queue.h), [llist_queue.c](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/Ch17/linst_queue.c)

  * Dynamic Memory Array Queue Implementation [main_d.c](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/Ch17/main_d.c), [arr_bst.h](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/Ch17/arr_bst.h), [arr_bst.c](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/Ch17/arr_bst.c), [dma_queue.h](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/Ch17/dma_queue.h), [dma_queue.c](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/Ch17/dma_queue.c)
 
  * Dynamic Memory Array Stack [main_s.c](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/Ch17/main_s.c), [dma_stack.h](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/Ch17/dma_stack.h), [dma_stack.c](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/Ch17/dma_stack.c)
  
