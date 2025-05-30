### Array and String
* 1.배열과 포인터
  * 1.1 배열 정의, 초기화 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Arrays_and_Strings_in_C/Array_Initialize1.c)
  ```c
  int aiData[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  
  // 나머지 초기화 0, 1, 2, 3, 4, 5, 6, 7, 0, 0 
  int aiData[] = { 0, 1, 2, 3, 4, 5, 6, 7 };

  char str1[] = "abc";  //char[3] 배열생성, 'a','b','c','\0'
  char str2[4] = "abc";
  char str3[] = { 'a','b','c','\0'};

  // C99 초기화
  int a1[6] = { [4]=4, [2]=2 };
  int a2[6] = { [4]4, [2]2 };    // 0, 0, 2, 0, 4, 0
  ```
  ```c
  #include <stdio.h>

  int main()
  {
    char acBuff[] = {'a','b','c','d','e','f'};
    int i=0;
    char *pcBuff = NULL;   // character pointer

    pcBuff = acBuff;
    for( i=0; i<6; i++)
      printf("pcBuff[%d] = %c or *(pcBuff+%d)=%c \n\n", i, pcBuff[i], i, *(pcBuff+i));

    return 0;
   }
  ```

* 2.배열을 함수 parameter로 전달 
  * 2.1 1차원 배열
  * 2.1.1 포인터 인자로 전달  [code1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_one_dimension_pointer1.c) 
[code2](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_one_dimension_pointer2.c)
  ```c
  void func(int *paData, int size) {}
  ...
  int size=10;
  int aiData[size];
  func(aiData, size);
  ```
   * 2.1.2 크기가 정의된 배열을 인자로 전달 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_one_dimension1.c)
  ```c
  void func(int paData[10]) {}
  ...
  int aiData[10];
  func(aiData);
  ```
   * 2.1.3 크기가 정의되지 않은 배열을 인자로 전달 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_one_dimension2.c)
  ```c
  void func(int paData[], int size) {}
  ...
  int size=10;
  int aiData[size];
  func(aiData, size);
  ```
  * 2.2 2차원 배열
   * 2.2.1 포인터 인자, 매크로, 전역상수로 전달 [code1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_two_dimension_pointer1.c) [code2](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_two_dimension_pointer2.c)
   ```c
  void func(int (*piData)[10], int size) {}
  ...
  int size=10;
  int aiData[row][size];
  func(aiData, size);
  ```    
   * 2.2.3 행을 생략, 열만 전달, C99 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_two_dimension1.c)
   ```c
  void func(int aiData[][10], int size) {}
  ...
  int size=10;
  int aiData[row][size];
  func(aiData, size);
  ```         
   * 2.2.4 2차 포인터 배열로 전달 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_two_dimension2.c)
   ```c
  void func(int (*piData)[10][10], int irow, int size) {}
  ...
  int irow=10, size=10;
   
  int aiData[irow][size];
  func(&aiData, irow, size);
  ```
   * 2.2.5 단일 포인터로 전달 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_two_dimension3.c)
   ```c
  void func(int *piData, int irow, int size) {}
  ...
  int irow=10, size=10;
   
  int aiData[][size];
   
  // func(&aiData[0][0], irow, size); 동일 표현식
  // func( (int *)aiData[0], irow, size); 동일 표현식
  func( (int *)aiData, irow, size);
  ```

* 3.포인터를 사용한 2차원 배열 접근
   * 3.1 포인터와 배열의 관계
  ```c
  acData[i] = *(acData +i);       //1D array in form of pointer
  a[i] = *(a+i);                  //ith element of an 1D array
  acData[i][j] = *(acData[i]+j);  //2D array form of 1D array and pointer
  acData[i][j] = *(*(acData+i)+j); //2D array in form of pointer
  ``` 
   * 3.2 단일 포인터를 사용한 2차원 배열 접근 [code1](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Arrays_and_Strings_in_C/two_dimension_using_pointers.c) [code2](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Arrays_and_Strings_in_C/two_dimension_using_pointers2.c)
  <img src = "https://github.com/user-attachments/assets/0490cef6-23bc-49a6-94e2-6c16aa93a23b" width="70%" height="70%">  

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
   * 3.3 배열 포인터를 사용한 2차원 배열 접근 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Arrays_and_Strings_in_C/two_dimension_using_pointers3.c)
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
* 4.정렬되지 않은 배열보다 정렬된 배열 처리가 빠른 이유?
   * 4.1 정렬되지 않은 int형 합 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Arrays_and_Strings_in_C/Unsorted_Array.c)
   * 4.2 정렬된 int형 합 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Arrays_and_Strings_in_C/Sorted_Array.c)
   * 분기 예측은 알고리즘이 따르고 있는 패턴 또는 기본적으로 이전 단계에서 어떻게 실행되었는지에 대해 작동하고. 추측이 맞다면 CPU는 실행을 계속하고 잘못되면 CPU는 파이프라인을 플러시하고 분기로 롤백하고 처음부터 다시 시작해야 합니다.
   * 4.3 정렬되지 않은 int형을 빠르게 계산하기 위한 변형 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Arrays_and_Strings_in_C/Unsorted_Array2.c)
  ```c
  if(data[c] >= 128)
    sum += data[c];
          --->
  int t = (data[c] - 128) >> 31;
  sum += ~t&data[c];
  ``` 
* Reference [aticleworld.com](https://aticleworld.com/C-Pro/#)

### String
* Turbo C The Art of Advanced Program Design Optimization and Debugging
  * [Complex Pointer](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Arrays_and_Strings_in_C/Prg3_2b.c)
  ```
  /*Prg 3_2b - Print the names of the month
    by Stephen R. Davis, 1987 
  
    The following program demonstrates in a simplistic fashion 
    the concept of arrays of pointers. Almost unknown in other 
    languages, this concept can save much code both in terms of size
    and speed. Compare this program to the "Pascal-like" Program 3_2a
    which does the same thing. */ 
  
  #include <stdio.h>
  #include <stdlib.h>
  
  unsigned putmonths(unsigned);
  
  /* an array of pointers to the names of the months */
  char *months[] = {"Bye bye\n\n", 
   "January\n\n", 
   "February\n\n", 
   "March\n\n", 
   "April\n\n", 
   "May\n\n", 
   "June\n\n", 
   "July\n\n", 
   "August\n\n", 
   "September\n\n", 
   "October\n\n", 
   "November\n\n", 
   "December\n\n"}; 
  
  /* Main - input a number and output the corresponding name of the month */
  int main(int argc, char *argv[]) {
    unsigned putmonths();
    unsigned innum;
    
    do {
    	printf("Enter another month: ");
    	scanf("%d", &innum);
    } while(putmonths(innum));
  	
    return 0;
  }
  
  /* Putmonths - given a number, print the corresponding month, Return
     the number, unless it is out of range, in which case,
     return a 0 */
  unsigned putmonths( unsigned month ) {
  	if(month > 12)
  	  month = 0;
  	printf(months[month]);
  	
  	return(month);
  }
  ```
