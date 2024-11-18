## 01. Pointer and Dynamic memory allocation in C
### Index
* 1. Dynamic memory allocation
  * 1.1 메모리할당, 해제
  ```c
  char *pcBuffer = malloc( 5*sizeof(char));

  free(pcBuffer);  // now pointer dangling pointer
  pcBuffer = NULL; // now pointer is not more dangling
  ```
  * 1.2 메모리 할당의 단점 [exam1](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Pointer_and_Dynamic_Allocation/Dynamic_memory_error1.c)
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
  ```c
  #include <stdio.h>
  #include <stdlib.h>

  #define FAIL 1
  #define TRUE 0

  int main() {
    int *piBuff = NULL;
    int nBlock = 0, i = 0;

    printf("\nEnter the number of block : ");
    scanf("%d", &nBlock);

    piBuff = (int *)malloc(nBlock*sizeof(int));
    if ( piBuff == NULL) {
      return FAIL;
    }

    for( i=0; i < nBlock; i++)
      printf("piBuffer[%d] = %d\n", i, piBuff[i]);

    free(piBuff);

    return TRUE;
  }
  ```  
  * 2.2 dynamic memory allocation 2D [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Pointer_and_Dynamic_Allocation/Two_dimension_dynamic_array.c) [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Pointer_and_Dynamic_Allocation/Two_dimension_dynamic_array2.c)
  ```c
  int **piBuff = NULL;
  piBuff = malloc( nrows * sizeof(int *));
  ...
  for( i=0; i<nrows; i++) 
    piBuff[i] = (int *)malloc(ncolumns * sizeof(int));
  ```
  ```c
  int **piBuff = NULL;
  piBuff = malloc( nrows * sizeof(int *));
  ...
  for( i=0; i<nrows; i++) 
    piBuff[i] = (int *)malloc( (i+1)*sizeof(int));
  ```

* 3.Dynamically 2D array in C using the single pointer

