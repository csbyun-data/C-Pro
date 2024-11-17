## 01. 배열과 문자열
### Index
* 1.배열
  * 1.1 배열 정의, 초기화 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/Array_Initialize1.c)
  ```c
  int aiData[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  // 나머지 초기화 0, 1, 2, 3, 4, 5, 6, 7, 0, 0 
  int aiData[] = { 0, 1, 2, 3, 4, 5, 6, 7 };

  char str1[] = "abc";
  char str2[4] = "abc";
  char str3[] = { 'a','b','c','\0'};

  // C99 초기화
  int a1[6] = { [4]=4, [2]=2 };
  int a2[6] = { [4]4, [2]2 };    // 0, 0, 2, 0, 4, 0
  ```

* 1.배열을 함수 parameter로 전달 
  * 1.1 1차원 배열
  * 1.1.1 포인터 인자로 전달  [here1](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_one_dimension_pointer1.c) 
[here2](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_one_dimension_pointer2.c)
  ```c
  void func(int *paData, int size) {}
  ...
  int size=10;
  int aiData[size];
  func(aiData, size);
  ```
   * 1.1.2 크기가 정의된 배열을 인자로 전달 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_one_dimension1.c)
  ```c
  void func(int paData[10]) {}
  ...
  int aiData[10];
  func(aiData);
  ```
   * 1.1.3 크기가 정의되지 않은 배열을 인자로 전달 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_one_dimension2.c)
  ```c
  void func(int paData[], int size) {}
  ...
  int size=10;
  int aiData[size];
  func(aiData, size);
  ```
  * 1.2 2차원 배열
   * 1.2.1 포인터 인자, 매크로, 전역상수로 전달 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_two_dimension_pointer1.c) [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_two_dimension_pointer2.c)
   ```c
  void func(int (*piData)[10], int size) {}
  ...
  int size=10;
  int aiData[row][size];
  func(aiData, size);
  ```    
   * 1.2.3 행을 생략, 열만 전달, C99 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_two_dimension1.c)
   ```c
  void func(int aiData[][10], int size) {}
  ...
  int size=10;
  int aiData[row][size];
  func(aiData, size);
  ```         
   * 1.2.4 2차 포인터 배열로 전달 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_two_dimension2.c)
   ```c
  void func(int (*piData)[10][10], int irow, int size) {}
  ...
  int irow=10, size=10;
   
  int aiData[irow][size];
  func(&aiData, irow, size);
  ```
   * 1.2.5 단일 포인터로 전달 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_two_dimension3.c)
   ```c
  void func(int *piData, int irow, int size) {}
  ...
  int irow=10, size=10;
   
  int aiData[][size];
   
  // func(&aiData[0][0], irow, size); 동일 표현식
  // func( (int *)aiData[0], irow, size); 동일 표현식
  func( (int *)aiData, irow, size);
  ```

* 2.포인터를 사용한 2차원 배열 접근
   * 2.1 포인터와 배열의 관계
  ```c
  acData[i] = *(acData +i);       //1D array in form of pointer
  a[i] = *(a+i);                  //ith element of an 1D array
  acData[i][j] = *(acData[i]+j);  //2D array form of 1D array and pointer
  acData[i][j] = *(*(acData+i)+j); //2D array in form of pointer
  ``` 
   * 2.2 단일 포인터를 사용한 2차원 배열 접근 [here1](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/two_dimension_using_pointers.c) [here2](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/two_dimension_using_pointers2.c)
   * ![image](https://github.com/user-attachments/assets/0490cef6-23bc-49a6-94e2-6c16aa93a23b)
  ```c
  offset = (column_number*1)+2);   // calculate offset
  (int *)aiData + offset;           // Add offset in array base address
  //typecast with int pointer because aiData is an array of integer
  *((int *)aiData + offset);        // Get the element
  ```
  ```c
  #define ROW 3
  #define COL 3
  int iRow = 0, iCol = 0;
 
  int aiData[ROW][COL];
  int *piData = NULL;
  piData = &aiData[0][0];  
  ...
  data = *(piData + (iRow * COL) + iCol)
  ```
   * 2.3 배열 포인터를 사용한 2차원 배열 접근 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/two_dimension_using_pointers3.c)
  ```c
  #define ROW   3
  #define COL   3
  typedef int Array2D[ROW][COL]; //New type

  Array2D aiData = { { 9, 6, 1 }, { 144, 70, 50 }, {10, 12, 78} };
  Array2D *p2DArray = NULL; //Pointer to the 2d Array
  int iRow =0, iCol =0; //Row and col

  p2DArray = &aiData; //Assign address of array to the pointer
  ...
  //Read element of 2D array
  printf("aiData[%d][%d] = %d\n",iRow,iCol, (*p2DArray)[iRow][iCol]);
  ```   
* 3.정렬되지 않은 배열보다 정렬된 배열 처리가 빠른 이유?
   * 3.1 정렬되지 않은 int형 합 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/Unsorted_Array.c)
   * 3.2 정렬된 int형 합 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/Sorted_Array.c)
   * 분기 예측은 알고리즘이 따르고 있는 패턴 또는 기본적으로 이전 단계에서 어떻게 실행되었는지에 대해 작동하고. 추측이 맞다면 CPU는 실행을 계속하고 잘못되면 CPU는 파이프라인을 플러시하고 분기로 롤백하고 처음부터 다시 시작해야 합니다.
   * 3.3 정렬되지 않은 int형을 빠르게 계산하기 위한 변형 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/Unsorted_Array2.c)
  ```c
  if(data[c] >= 128)
    sum += data[c];
          --->
  int t = (data[c] - 128) >> 31;
  sum += ~t&data[c];
  ``` 
