### [geeksforgeeks.org] Sorting
* Sorting 정리
   * 1.1 Bubble Sort in C [code](https://github.com/csbyun-data/C-Pro/blob/main/chap04/Sorting/BubbleSort1.c)
   * 1.2 Bubble Sort 최적화 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap04/Sorting/BubbleSort2.c)
   ```c
   내부 loop문에서 교환하는 data가 없는 경우 외부loop를 중단해 최적화
   ```
   * 1.3 Iterative Quick Sort [code C++](https://github.com/csbyun-data/C-Pro/blob/main/chap04/Sorting/Iterative_Quick_Sort1.cpp), [code Java](https://github.com/csbyun-data/C-Pro/blob/main/chap04/Sorting/Iterative_Quick_Sort1.java), [code1 C](https://github.com/csbyun-data/C-Pro/blob/main/chap04/Sorting/Iterative_recursive_Quick_Sort1.c), [code1 C++](https://github.com/csbyun-data/C-Pro/blob/main/chap04/Sorting/Iterative_recursive_Quick_Sort1.cpp), [code1 Java](https://github.com/csbyun-data/C-Pro/blob/main/chap04/Sorting/Iterative_recursive_Quick_sort1.java)
   * Reference [iterative-quick-sort](https://www.geeksforgeeks.org/iterative-quick-sort/)
   * Reference [quick-sort-algorithm](https://www.geeksforgeeks.org/quick-sort-algorithm/)
   
   ```txt
   1) 위의 구현은 마지막 인덱스를 피벗으로 사용합니다.이는 일반적으로 발생하는 경우인 이미 정렬된 배열에서 최악의 동작을
   일으킵니다.피벗에 대한 임의 인덱스를 선택하거나 파티션의 중간 인덱스를 선택하거나 피벗에 대한 파티션의 첫 번째, 중간
   및 마지막 요소의 중간값을 선택하면 문제를 해결할 수 있습니다.
   
   2) 재귀 깊이를 줄이려면 먼저 배열의 작은 절반에 대해 재귀하고 tail 호출을 사용하여 다른 절반으로 재귀합니다.
   3) 삽입 정렬은 작은 부분 배열에 더 잘 작동합니다.삽입 정렬은 이러한 작은 배열(즉, 길이가 실험적으로 결정된 임계값
   t보다 작은 경우)에 대한 호출에 사용할 수 있습니다. 예를 들어, Quicksort의  이 라이브러리 구현은 크기 7 미만의
   삽입 정렬을 사용합니다.
     위의 최적화에도 불구하고 함수는 재귀적으로 유지되고 함수 호출 스택을 사용하여 l 및 h의 중간 값을 저장합니다.
     함수 호출 스택은 매개변수와 함께 다른 회계 정보를 저장합니다. 또한 함수 호출에는 호출자 함수의 활성화 레코드를
   저장한 다음 실행을 재개하는 것과 같은 오버헤드가 포함됩니다.
   위의 함수는 보조 스택의 도움으로 반복 버전으로 쉽게 변환할 수 있습니다. 다음은 위의 재귀 코드의 반복 구현입니다. 
   ```
   * 1.4 Quick Sort [code1_1](https://github.com/csbyun-data/C-Pro/blob/main/chap04/Sorting/Quick_Sort1.cpp),[code1-2](https://github.com/csbyun-data/C-Pro/blob/main/chap04/Sorting/Quick_Sort1_1.cpp),[code1-3](https://github.com/csbyun-data/C-Pro/blob/main/chap04/Sorting/Quick_Sort1_2.cpp), [code2](https://github.com/csbyun-data/C-Pro/blob/main/chap04/Sorting/Quick_Sort2.cpp) [code3]()
   * 1.5 Advanced Quick Sort (Hybrid Algorithm) [code C++](https://github.com/csbyun-data/C-Pro/blob/main/chap04/Sorting/Hybrid_Quick_Sort.cpp)
   * Reference [advanced-quick-sort-hybrid-algorithm](https://www.geeksforgeeks.org/advanced-quick-sort-hybrid-algorithm/)
   * 1.6 Quick Sort using vector and iterator in STL [code C++](https://github.com/csbyun-data/C-Pro/blob/main/chap04/Sorting/STL_Quick_Sort1.cpp)

### [Snippets.org]
* sorting 정리
   * Sorting library
   ```c
   // https://github.com/vonj/snippets.org/blob/master/snipsort.h
   
   void hugesort(void HUGE *basep, unsigned  nel, unsigned width,
        int (*comp)(void HUGE *, void HUGE *));         /* Hugesort.C     */
   void    *sortl(void *list, void *(*getnext)(void *), void (*setnext)(void *, void *),
        int (*compare)(void *, void *));                /* Ll_Qsort.C     */
   void isort(void *base, size_t nmemb, size_t size,
        int (*comp)(const void *, const void *));       /* Rg_Isort.C     */
   void qsort(void *, size_t, size_t,
        int (*)(const void *, const void *));           /* Rg_Qsort.C     */
   void swap_chars(char *, char *, size_t);             /* Rg_Qsort.C     */
   void quicksort(int v[], unsigned n);                 /* Rgiqsort.C     */
   void ssort (void *base, size_t nel, size_t width,
        int (*comp)(const void *, const void *));       /* Rg_Ssort.C     */
   void strsort(char **v, unsigned n);                  /* Strsort.C      */
  
   /* File: LL_MSORT.C */
   typedef struct list_struct {
           struct list_struct *next;
           char *key;
           /* other stuff */
           } list;
  
   list *lsort (list *p);
  
  /*  File: BINSRCH.C */
  int BinSearch(double key, double *r, size_t n);
  ```
  * [dossort.c](https://github.com/vonj/snippets.org/blob/master/dossort.c)
  * 
  * void ssort (void *base, size_t nel, size_t width, int (*comp)(const void *, const void *)); [rg_ssort.c]()
  * void strsort(char **v, unsigned n) [strsort.c](https://github.com/vonj/snippets.org/blob/master/strsort.c)
  ```c
  // Shell sort an array of string pointers via strcmp()
  char *str[] = {"WELCOME", "TO", "LIBRARY", "MANAGEMENT", "SYSTEM" };
  int i, n=5;
  STRSORT(str, 5);
  
  for(i=0; i<n; i++) {
    printf("%s\n",str[i] );
  }
  ```
  ![image](https://github.com/user-attachments/assets/f4cd976c-ee9b-46dd-a9aa-33227746a584)

