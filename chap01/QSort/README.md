### Function
* time(), qsort() 사용법
    * 실행시간체크 time() [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Running_time.c)
    * qsort() 숫자배열 정렬 [code1](https://github.com/csbyun-data/C-Pro/blob/main/chap01/QSort/qsort_num1.c), [code2](https://github.com/csbyun-data/C-Pro/blob/main/chap01/QSort/qsort_num2.c), [code3](https://github.com/csbyun-data/C-Pro/blob/main/chap01/QSort/qsort_num3.c) 문자배열 정렬 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/QSort/qsort_word1.c), 구조체배열 정렬 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/QSort/qsort_struct1.c)
    ```c
    // https://en.cppreference.com/w/c/algorithm/qsort
    #include <stdlib.h>
    void qsort( void* ptr, size_t count, size_t size, int (*comp)(const void*, const void*) );
    ```
