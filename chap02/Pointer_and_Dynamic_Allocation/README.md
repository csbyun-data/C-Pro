## 01. Pointer and Dynamic memory allocation in C
### Index
* 1. Dynamic memory allocation
  * 1.1 메모리할당, 해제
  ```c
  char *pcBuffer = malloc( 5*sizeof(char));

  free(pcBuffer);  // now pointer dangling pointer
  pcBuffer = NULL; // now pointer is not more dangling
  ```
  * 1.2 메모리 할당의 단점
  ```c
  // memory leck 발생
  #include <stdio.h>

  int foo() {
    int *piData = (int *) malloc(sizeof(int));
    // not freeing the allocated memory
    return 0;
  }
  ```
  ```c
  // memory 조각화
  char *pcData1 = malloc(512);
  char *pcData2 = malloc(1024);
  char *pcData3 = malloc(512);

  free(pcData2);
  ```
  
* 2.Dynamically allocation a 1D, 2D array
  * 2.1 dynamic memory allocation 1D
  * 2.2 dynamic memory allocation 2D

* 3.Dynamically 2D array in C using the single pointer

