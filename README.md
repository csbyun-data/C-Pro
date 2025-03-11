# C Programming
Grammar of programming, a collection of basic materials for application.

## Index
## Syntax
* [Syntax (command line, 증감 연산자)](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Syntax/README.md) 
* [가변인자, 가변함수](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Variadic/README.md) [ErrExit(), printf()]
* [Input함수](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Input/README.md) [scanf(), gets(), fgets()]
* [sleep(), time(), qsort() 사용법](https://github.com/csbyun-data/C-Pro/blob/main/chap01/QSort/README.md)
* [조건문, 반복문, setjmp()](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Flow/README.md)
* [Array, String](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/README.md)
* [function(), parameter, return value](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Function/README.md)
* [typedef 사용법](https://github.com/csbyun-data/C-Pro/blob/main/chap01/TypeDef/README.md)
* [Binary Octal Decimal Hexa변환](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Bin/README.md)
* [static, extern 사용](https://github.com/csbyun-data/C-Pro/blob/main/chap01/extern/README.md)
* [bit unit operator](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Bit/README.md)
  
## Pointer, Array, String, Function Pointer  
* [pointer and array, function pointer, pointer structure](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Array/READ.md)
* [Pointer and Dynamic memory allocation](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Dynamic_Allocation/README.md)
* [Arrays and String in C](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Arrays_and_Strings_in_C/README.md)
* [snippets.org],[BASIC-like string functions](https://github.com/csbyun-data/C-Pro/blob/main/chap02/bastring/README.md)
* [Function Pointer](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer/README.md)
* [Book], [Function Pointer Tutorials](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Function_Pointer_Tutorials/README.md)
* [Book], [Pointers on C](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointers_On_C/READ.md)
* [Book], [A tutorial on pointers and arrays in C](https://github.com/csbyun-data/C-Pro/blob/main/chap02/A_tutorial_on_pointers_and_arrays_in_C/README.md)
  ```c
  // pointer function implementation
  void bubble(void *p, int width, int N, int(*fptr)(const void *, const void *));
  int compare_string(const void *m, const void *n);
  int compare_long(const void *m, const void *n);
  ```

## Structure, Union
* Structures and Unions in C
    * [Structures](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/README.md)
    * [Unions and Bit field](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Structures_and_Union/UNION.md)
* [Structures, String Pointer 활용](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Application/README.md)
* [Memory layout of C program](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Memory-layout/README.md)
  
## File I/O
* [File I/O](https://github.com/csbyun-data/C-Pro/blob/main/chap03/File/README.md)
  ```txt
  고수준 파일함수 fopen(), fprintf(), fputc(), fputs(), fwrite(),fscanf(),
    fgetc(), fgets(), fread(), fseek()
  저수준 파일함수 open(), write()
    ```
* [File Command](https://github.com/csbyun-data/C-Pro/blob/main/chap03/FileCmd/README.md), [file copy, file size, tail]
* [snippets.org], [The indexing function for creating a binary file from an ASCII](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Index/README.md)
* [snippets.org], [A utility to split large text files into smaller files
](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Split/README.md)
* [snippets.org], [Functions to read configuration files](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Cfg/README.md)
* [snippets.org], [Read a directory into a linked list](https://github.com/csbyun-data/C-Pro/blob/main/chap03/FileList/README.md)
* [snippets.org], [Extensible C & C++ determine which archiver was used on a packed file](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Arch/README.md)
* [snippets.org], [Fork output to multiple files, including console.](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Fork/README.md)
* [aticleworld.com], [Parse XML response in C without using library](https://github.com/csbyun-data/C-Pro/blob/main/chap03/XML/README.md)

## Data Structure, Algorithm
* [Stack](https://github.com/csbyun-data/C-Pro/blob/main/chap04/Stack/README.md)
* Queue, Priority Queue, Heap
* [Linked List](https://github.com/csbyun-data/C-Pro/blob/main/chap04/Linked_List/README.md)
* Recursion method
* [Binary Tree](https://github.com/csbyun-data/C-Pro/blob/main/chap04/Binary_Tree/README.md)
* Graph
* [Sorting](https://github.com/csbyun-data/C-Pro/blob/main/chap04/Sorting/README.md)
* Searching
* Hashing
* [Reference](https://github.com/csbyun-data/C-Pro/blob/main/chap04/README.md)

## Project  
* [File handling function](https://github.com/csbyun-data/C-Pro/blob/main/chap05/File/README.md)
    ```
    1.도서 관리, 2.학생 기록-성적, 3.직원 기록, 4.주소록
    ```
* [Calculation formula analysis](https://github.com/csbyun-data/C-Pro/blob/main/chap05/Calc/README.md)
* [XML Parser](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XML_Parser/README.md)
* [Lightweight JSON library written in C](https://github.com/csbyun-data/C-Pro/blob/main/chap05/JSON/README.md)
* [David Betz. XLISP], [XLISP Calculation formula analysis](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XLISP/README.md)
* [Book], [Interpreting LISP: Programming and Data Structures](https://github.com/csbyun-data/C-Pro/blob/main/chap05/Interpreting-lisp/READ.md)
* [Console Game], [Escape](https://github.com/csbyun-data/C-Pro/blob/main/chap05/Escape/README.md)
* [Console Game], [Packman](https://github.com/YoctoForBeaglebone/pacman4console)
* [Console Game], [Snake](https://github.com/Contagious06/console-snake-game), [Snake1](https://github.com/peperunii/Games-Snake)
* [Console Game], [Console-Games](https://github.com/arasgungore/console-games), [Pong, Snake, Tetris]
* [Console Game], [Rhythm](https://github.com/Waterticket/C-Rhythm-Game)
* [Console Game], [tictactoe](https://github.com/emacdona/tictactoe)
* [Console Gaem], [Sokoban](https://github.com/maksimKorzh/sokoban)
* [Console Gaem], [Chess](https://github.com/omeredel/Chess-In-C)

## Reference
* [참조: [www.cprogramming.com](https://www.cprogramming.com/tutorial/c-tutorial.html)]
* [참조: [aticleworld.com/c-tutorial](https://aticleworld.com/c-tutorial/)]
* [참조: [aticleworld.com/c-programming](https://aticleworld.com/c-programming/)]
* [참조: [www.geeksforgeeks.org/c-programming-language](https://www.geeksforgeeks.org/c-programming-language/)]
* [참조: [www.c-program-example.com](https://www.c-program-example.com)]
* [참조: [www.w3schools.com/c](https://www.w3schools.com/c/index.php)]
* [참조: [www.tutorialspoint.com/cprogramming](https://www.tutorialspoint.com/cprogramming/index.htm)]
* [참조: [www.ibm.com/~functions-cc-library](https://www.ibm.com/docs/ko/i/7.5?topic=functions-cc-library)]
* [참조: [modoocode.com](https://modoocode.com/)]
* [참조: [snippets.org](https://github.com/vonj/snippets.org)]
    * [SNIPPETS Table of Contents](https://github.com/vonj/snippets.org/blob/master/snippets.ndx)
* [참조: [kocw.net](http://www.kocw.net/home/search/kemView.do?kemId=1267012])]
* [참조: [cppreference.com/w/c](https://en.cppreference.com/w/c)]
* [참조: [bito.ai/resources_categories/c-c/](https://bito.ai/resources_categories/c-c/)]
