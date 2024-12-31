### Array, String
* Array, String
    * 배열 초기화
    ```c
    int a[][2] = { {1, 2}, {3, 4}};
    int a[][2][2] = { {{1, 2}, {3, 4}}, {{5, 6}, {7, 8}} };
    int a[2][3] = { {1, 2, 3}, {4, 5, 6} };
    ```
    * 배열의 sizeof [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Array/sizeof_array1D.c)
    ```c
    /* arr, 배열의 이름은 sizeof를 사용하여 배열의 크기를 구할수 있음
       arr은 배열의 시작 주소 == &arr[0], 주소는 표시는 동일,
       sizeof이용 크기를 구하면 arr은 20, &arr[0]는 64 OS에서 8byte를 계산함
       sizeof(arr) == sizeif(int)*5, 
       arr[0], 동일 표현 *arr, sizeof(a[0]) == sizof(int)
    */
    int arr[] = { 12, 34, 10, 6, 40 };
    int n = sizeof(arr)/sizeof(arr[0]);
    // 동일 표현, int n = sizeof arr / sizeof *arr; 
    ```
  
    * 비정렬 배열 검색, 삽입, 삭제 [검색code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Array/Unsorted_Array_Search.c), [삽입 code1](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Array/Unsorted_Array_Insert.c),[삽입 code2](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Array/Unsorted_Array_Insert2.c) [삭제 code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Array/Unsorted_Array_Delete1.c)
    * 정렬 배열 검색, 삽입, 삭제 [검색 code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Array/Sorted_Array_Search1.c), [삽입 code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Array/Sorted_Array_Insert1.c), [삭제 code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Array/Sorted_Array_Delete1.c)
    * String in C [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/README.md)
    * 포인터 배열, 배열 포인터 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Array/pointer_array1.c)
    ```txt
    1) 포인터 배열
      char *arr[3]; == (char *) arr[3];
      // 포인터 3개가 존재 함
      char a, b, c;
      arr[0] = &a;
      arr[1] = &b;
      arr[2] = &c;
    
    2) 배열 포인터
      char (*arr)[3];
      // 포인터가 1개 존재, array[3]인 배열을 가르킴
      char tmp1[3] = {'a','b','c'};
      arr = &tmp1;
    ```
