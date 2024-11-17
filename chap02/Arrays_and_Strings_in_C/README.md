## 01. 배열과 문자열
### Index
* 1.배열을 함수 parameter로 전달 
  * 1.1 1차원 배열
  * 1.1.1 포인터 인자로 전달  [here1](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_one_dimension_pointer1.c) 
[here2](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_one_dimension_pointer2.c)
   * 1.1.2 크기가 정의된 배열을 인자로 전달 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_one_dimension1.c)
   * 1.1.3 크기가 정의되지 않은 배열을 인자로 전달 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_one_dimension2.c)

  * 1.2 2차원 배열
   * 1.2.1 포인터 인자, 매크로, 전역상수로 전달 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_two_dimension_pointer1.c) [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_two_dimension_pointer2.c)
   * 1.2.3 행을 생략, 열만 전달, C99 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_two_dimension1.c)
   * 1.2.4 2차 배열로 전달 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_two_dimension2.c)
   * 1.2.5 단일 포인터로 전달 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/Transfer_two_dimension3.c)

* 2.포인터를 사용한 2차원 배열 접근
   * 2.1 포인터와 배열의 관계
  ```c
  acData[i] = *(acData +i);       //1D array in form of pointer
  a[i] = *(a+i);                  //ith element of an 1D array
  acData[i][j] = *(acData[i]+j);  //2D array form of 1D array and pointer
  acData[i][j] = *(*(acData+i)+j); //2D array in form of pointer
  ``` 
   * 2.2 단일 포인터를 사용한 2차원 배열 접근 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap02/Arrays_and_Strings_in_C/two_dimension_using_pointers.c)
   * ![image](https://github.com/user-attachments/assets/0490cef6-23bc-49a6-94e2-6c16aa93a23b)
  ```c
  offset = (column_number*1)+2);   // calculate offset
  (int *)aiData + offset;           // Add offset in array base address
  //typecast with int pointer because aiData is an array of integer
  *((int *)aiData + offset);        // Get the element
  ``` 
   * 2.3 배열 포인터를 사용한 2차원 배열 접근
   
* 3.정렬되지 않은 배열보다 정렬된 배열 처리가 빠른 이유?
