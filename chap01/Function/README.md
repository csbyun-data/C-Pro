## 01. 문법1
### Index
* 1.함수
  *  1.1 함수 parameter 전달 ([Call by value](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Call_by_value1.c), [Call by address](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Call_by_address1.c), [Call by reference](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Call_by_reference1.c) [Call by pointer](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Call_by_pointer1.c) )
  *  1.2 1D 배열을 전달 
  ```c
  return_type foo ( array_type array_name[크기], ...);
  return_type foo ( array_type array_name[] , ...);
  return_type foo ( array_type* array_name, ...);

  //배열의 크기를 함수에 전달하지 않으면 크기를 알수 없다

  //Passing Array to Function in C
  //매개변수의 크기를 전달
  void func(int a[], int size) {}
  // void func(int* a, int size) {} 동일 표현

  int main() {
    int n = 5;
    int arr[5] = {1, 2, 3, 4, 5};
    func(arr, n);

    return 0;
  }
  ```
  [2-1 잘못된 예](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Incorrect_function_2-1.c), [2-1 옳은 예](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Correct_function_2-1.c), [2-2 잘못된 예](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Incorrect_function_2-2.c), [2-2 옳은 예](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Correct_function_2-2.c), [2-3](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Correct_function_2-2.c),[2-4](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Correct_function_2-2.c), [2-5 잘못된 예](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Incorrect_function_2-2.c), [2-5 옳은 예](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Correct_function_2-2.c)  

  ```txt
  2-1) 배열 매개변수에 sizeof()를 사용하지 말것( 배열의 갯수를 찾지 못함)
  2-2) 배열 pointer 붕괴 예제 (방법: 배열의 크기를 매개변수로 전달)
  2-3) 배열의 크기를 찾기위한 #define 매크로 사용
  2-4) pointer 연산사용: (&arr)[1]-arr을 이용 배열 크기 찾기
  2-5) 함수를 이용하여 숫자 배열 출력
  ```
  [2-6예1](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/String_function_2-6-1.c), [2-6예2](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/String_function_2-6-2.c)
  ```txt
  2-6) 함수를 이용하여 문자열 출력, 명령줄 인수 활용
  ```
  *  7.3 2D 배열을 전달 [3-1](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Two_dimension_parameter_3-1.c), [3-2](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Two_dimension_parameter_3-2.c), [3-2p](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Two_dimension_parameter_3-2p.c), [3-3](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Two_dimension_parameter_3-3.c)
  ```txt
  3-1) 고정된 행과 열을 2D 배열의 매개변수로 전달
  3-2) 행 제외, 열만 2D 배열의 매개변수로 전달
      - 행, 열을 parameter로 전달
  3-3) 행, 열 고정되지 않은 2D배열을 매개변수로 전달
  ```
  *  7.4 Struct를 전달 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Struct_parameter.c)
  *  7.5 Reference Variable과 Pointer Variable의 차이 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap01/Function/Reference_Pointer_diff.cpp)
