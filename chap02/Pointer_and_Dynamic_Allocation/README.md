## 01. Pointer and Dynamic memory allocation in C
### Index
[참조: aticleworld.com](https://aticleworld.com/C-Pro/#),
[참조: geeksforgeeks.org](https://www.geeksforgeeks.org/)
* 1.Dynamic memory allocation
  * 1.1 메모리할당, 해제(malloc, free)
  ```c
  ptr - (cast type *) malloc(byte size);

  int n=3;
  int *p = (int *)malloc( n*sizeof(int));
  free(p);
  
  ```
  ```c
  char *pcBuffer = malloc( 5*sizeof(char));

  free(pcBuffer);  // now pointer dangling pointer
  pcBuffer = NULL; // now pointer is not more dangling
  ```
  * 1.2 메모리 할당의 단점 [exam1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Dynamic_Allocation/Dynamic_memory_error1.c)
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
  * 1.3 malloc(), calloc(), realloc(), free() 함수 [malloc](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Dynamic_Allocation/Malloc_func1.c), [calloc](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Dynamic_Allocation/Calloc_func1.c), [realloc1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Dynamic_Allocation/Realloc_func1.c), [realloc2](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Dynamic_Allocation/Realloc_func2.c)
  ```c
  ptr = (cast-type *) malloc( byte-size);
  int *ptr = (int *)malloc( 5*sizeof(int));  // 5*4=20 bytes of memory
  
  ptr = (cast-type *) calloc( n, element-size); 
  ptr = (float *) calloc(25, sizeof(float));  // 5 blocks of 4 4byte each

  ptr = realloc( ptr, newSize));             // ptr 메모리 확장
  int *ptr = realloc( ptr, 10*sizeof(int));  // 20bytes + 20bytes ->
                                             // 10*4=40 bytes of memory
  ```
  * 1.4 C++ new와 malloc(), delete와 free()비교 [new와 malloc](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Dynamic_Allocation/New_Malloc_diff.cpp) [delete와 free()](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Dynamic_Allocation/Delete_Free_diff.cpp)
  
* 2.Dynamically allocation a 1D, 2D array
  * 2.1 dynamic memory allocation 1D [exam1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Dynamic_Allocation/Malloc_Integer_1D.c)
  <img src = "https://github.com/user-attachments/assets/a785f845-0f68-49dc-9ac5-4454ad577be1" width="70%" height="70%">
 
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
  * 2.2 C++ new, delete operator
  ```cpp
  #include <iostream>
  using namespace std;

  int main()
  {
    int *p = new int;
    if(!p) return 1;

    *p = 5;
    int n = *p;
    cout << n << endl;

     delete p;
  }
  ```
  ```cpp
  // Initialization
  int *p = new int(1);
  char *c = new char('a');
  ```
  ```cpp
  // Using dynamic memory in an array
  int *p = new int[5];
  if(!p) {
    cout << "Memory allocation error!" << endl;
    return 0;
  }

  for( int i=0; i<5; i++)
    p[i] = i;
  delete[] p;
  ```
  
  
  
  * 2.3 dynamic memory allocation 2D int형 [exam1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Dynamic_Allocation/Dynamic_Array_2D1.c) [exam2](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Dynamic_Allocation/Dynamic_Array_2D2.c) [2D int](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Dynamic_Allocation/Malloc_Integer_2D.c), [참조](https://www.geeksforgeeks.org/how-to-declare-a-two-dimensional-array-of-pointers-in-c/)
  <img src = "https://github.com/user-attachments/assets/7551961f-4820-4b6b-8896-37488076aff8" width="70%" height="70%">
  
  ```c
  int **piBuff = NULL;
  piBuff = malloc( nrows * sizeof(int *));
  ...
  for( icol=0; icol<nrows; icol++) 
    piBuff[icol] = (int *)malloc(ncolumns * sizeof(int));
  ```
  <img src = "https://github.com/user-attachments/assets/9f92a830-ef83-4d21-864a-6da634a955ea" width="70%" height="70%">  

  ```c
  int **piBuff = NULL;
  piBuff = malloc( nrows * sizeof(int *));
  ...
  for( icol=0; icol<nrows; icol++) 
    piBuff[icol] = (int *)malloc( (icol+1)*sizeof(int));
  ```
  * 2.4 C++ int형 2D 배열 동적 할당 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Dynamic_Allocation/New_Int_2D.cpp), [참조](https://www.geeksforgeeks.org/how-to-declare-a-2d-array-dynamically-in-c-using-new-operator/)
  ```cpp
  int **a = new int*[m];
  ...
  for( int i=0; i<m; i++) 
    a[i] = new int[n];
  ...
  for( int i=0; i<m; i++)
    delete[] a[i];
  delete[] a;
  ```
  
  * 2.5 dynamic memory allocation 2D char형 ([exam1 C++](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Dynamic_Allocation/Calloc_Char_2D.cpp))
  ```c
  char **name;
  names = (char **)calloc( n, sizeof( char *));
  ...
  for( i=0; i<n; i++)
    names[i] = (char *)calloc(30, sizeof(char));
  ```
   * 2.6 C++ int형 3D 배열 동적 할당 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Dynamic_Allocation/New_Int_3D.cpp). [참조](https://www.geeksforgeeks.org/how-to-dynamically-allocate-a-3d-array-in-c/)
   ```cpp
   int **a = new int**[x];
   ...
   for( int i=0; i<m; i++) {
     a[i] = new int*[y];
     for( int j=0; j<y; j++)
       a[i][j] = new int[z];
   }
   ...
   // Deallocate memory
   for (int i = 0; i < x; i++) {
     for (int j = 0; j < y; j++)
       delete[] a[i][j];
     delete[] a[i];
   }
   delete[] a;
   ```
   * 2.7 C++ class 배열 동적 할당 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Dynamic_Allocation/New_Class_1D.cpp)

* 3.Dynamically 2D array in C using the single pointer [here](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Dynamic_Allocation/Dynamic_Array_2D3.c)
  ```c
  int **piBuff = NULL;
  piBuff = malloc( nrows * ncolumns * sizeof(int *));
  ```
* 4.Pointer to string array in C
  * 4.1 2차원 배열 사용한 문자열
  ```c
   char arr[5][10] = {"abcdef1", "abcdef2","abcdef3","abcedf3","abcdef4","abcdef5" };
  ```
  ![image](https://github.com/user-attachments/assets/39b45f87-9633-4f74-9856-03e44c91ad48)

  * 4.2 string pointer 배열을 사용한 문자열
  ```c
   char *arr[5] = {"abcdef1", "abcdef2","abcdef3","abcedf3","abcdef4","abcdef5" };
  ```
  ![image](https://github.com/user-attachments/assets/93daf016-231f-4c92-b473-8ffc7905a6fc)
  
  * 4.3 Access 2d array of characters using the pointer to the array
  ```c
  // method1: pointer to the 1d array
  #include<stdio.h>

  int main()
  {
    int row =0;
    //create 2d array of the characters
    char arr[5][10] = {"abcdef1", "abcdef2","abcdef3","abcedf3","abcdef4","abcdef5" };
    //create pointer to the array
    char (*ptrArr)[10] = NULL;

    //initialize the pointer with array
    ptrArr = arr;
    for (row = 0; row < 5; ++row) // Loop for coloumn 
       printf("%s \n", ptrArr[row]);

    return 0;
  }
  ```
  ```c
  // method2: pointer to the 2d array
  #include <stdio.h>
  int main()
  {
    int row =0;
    //create 2d array of the characters
    char arr[5][10] = {"abcdef1", "abcdef2","abcdef3","abcedf3","abcdef4","abcdef5" };
    //create pointer to the 2d array
    char (*ptrArr)[5][10] = NULL;

    //initialize the pointer
    ptrArr = &arr;
    for (row = 0; row < 5; ++row) // Loop for coloumb
        printf("%s \n", (*ptrArr)[row]);

    return 0;
  }
  ```
  * 4.4 Access array of string using the pointer to the array and pointer to pointer
  ```c
  // method1: pointer to the 1d array
  #include<stdio.h>

  int main()
  {
    int row =0;
    //create 2d array of the characters
    char * arr[5] = {"abcdef1", "abcdef2","abcdef3","abcedf3","abcdef4","abcdef5" };

    //create pointer to the array
    char * (*ptrArr)[5] = NULL;

    //initialize the pointer
    ptrArr = &arr;
    for (row = 0; row < 5; ++row) // Loop for coloumb
       printf("%s \n", (*ptrArr)[row]);

    return 0;
  }
  ```    
  ```c
  // method2: pointer to pointer
  #include<stdio.h>

  int main()
  {
    int row =0;
    //create 2d array of the characters
    char * arr[5] = {"abcdef1", "abcdef2","abcdef3","abcedf3","abcdef4","abcdef5" };

    //create pointer to the array
    char **ptr = NULL;

    //initialize the pointer
    ptrArr = &arr;
  
    for (row = 0; row < 5; ++row) // Loop for coloumb
      printf("%s \n", ptr[row]);

    return 0;
  }
  ```
* 5.some invalid operations on an array of pointers to string
  ```c
  strcpy( arr[0], "abcdef"); // invalid
  strcat( arr[0], "abcdef"); // invalid
  gets(arr[0]);              // invalid
  fgets(arr[0], 10, stdin);  // invalid
  scanf("%s", arr[0]);       // invalid
  ```
* 6.메모리 할당 coding 실수
  * 6.1 null pointer 점검
  ```c
  int *piBuff = NULL;
  piBuff = malloc( n*sizeof(int));
  if ( piBuff == NULL) {  // null pointer 점검 필수!
    return FAIL;
  }
  ```
  * 6.2 메모리 할당 실수 
  ```txt
  1. 할당된 메모리 값을 초기화하지 않고 사용
  2. 할당 해제된 메모리의 주소를 사용, 포인터는 해제후에도 같은 주소를 가르키고 있음
    int *piData = NULL;
    piData = malloc( n*sizeof(int));
    free(piBuff);
    *piData = 10; // 해제후 이전 주소를 가지고 있음
  3. 해제된 메모리를 또 해제를 함
    int *piData = NULL;
    piData = malloc( n*sizeof(int));
    free(piBuff);
    free(piBuff);
  4. 메모리 할당되지 않은 포인터를 해제
    int data = 0;
    int *piData = &data;
    free(piData);
  5. 할당된 메모리 해제를 하지 않음
  6. 메모리 할당 보다 정규 배열 사용을 권장, 배열은 컴파일러에서 자동해제함, 배열이 빠름
  7. 동적 배열에는 sizeof() 사용하지 말것, 동적 배열주소 크기가 반환됨
  8. 메모리 할당 갯수, 해제 갯수 counter
  9. 메모리 할당 범위를 벗어난 접근
  10. 포인터를 재할당하여 참조를 손실함
    int *piData1 = NULL;
    int *piData2 = NULL;
    piData1 = malloc(sizeof(int));
    if ( piData1 == NULL) { return -1; }
    ...
    piData2 = piData1;
    free(piData1);
    *piData2 = 50;  // 해제된 메모리에 값을 전달
  11. 메모리를 할당하지 않고 값을 입력. dangling pointer
    int *piData;
    *piData = 10;
  ```
  * 6.3 메모리 할당 갯수, 해제 갯수 counter code [here](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_and_Dynamic_Allocation/Allocation_Deallocation_cnt.c)

  
  
  
