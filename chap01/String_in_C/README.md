
## 01. String in C
### 참조 자료
* [참조: geeksforgeeks.org/string-c-cpp-programs](https://www.geeksforgeeks.org/string-c-cpp-programs/)
### Index
* 1.문자열 (String)
  ```c
  char c[] = "abcd";
  char c[50] = "abcd";
  char c[] = {'a','b','c','d','\0'}; // the last character is '\0'
  char c[5] = {'a','b','c','d','\0'};
  
  char c[100];
  c = "C programming"; // Error! array type is not assignable.
  ```
  ```c
  char *s1 = "Hello, world!";    // char pointer에 문자열의 메모리 주소를 저장
  char s2[20] = "Hello, world!"; // char 배열에 문자열 저장
  char s3[] = "Hello, world!";   // char 배열에 문자열 저장

  // 문자열과 NULL(\0)
  char s1[6] = "Hello"; // 5글자 + NULL로 배열에 입력 됨
  ```
  
  *  1.1 문자열 변수 출력 [code1](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/String_output1.c), [code2](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/String_output2.c)
  ```c
  // 문자열을 인덱스로 접근하여 문자 출력
  printf("%c\n", s1[0]);  //H
  printf("%c\n", s2[4]);  //o
  ```
  ```c
  // 문자열 초기화
  char s1[20];
  s1 = "Hello, world"; // 컴파일 error!, 선언된 배열에는 문자열을 할당할 수 없음
  
  // 문자열 포인터와 문자 배열의 요소 변경
  문자열 포인터에 문자열 리터럴을 할당한 뒤에는 인덱스로 접근하여 문자(요소)를 변경할 수 없음
  (문자열 리터럴이 있는 메모리 주소는 읽기 전용).
  문자 배열은 인덱스로 접근하여 문자를 변경할 수 있습니다(배열에 문자열이 복사됨).
  char *s1 = "Hello";  // 문자열 포인터에 문자열 리터럴 할당
  s1[0] = 'A';         // Error

  char s2[10] = "Hello"; // 문자 배열에 문자열 리터럴 할당
  s1[0] = 'A';           // Ok!
  ```
  
  *  1.2 scanf() 문자열 입력 받기 [scanf](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/String_input1.c)
  ```c
  문자열 "Dennis Ritchie"입력하면 "Dennis"만 받아 들임, 공백뒤 문자열 잘림
  ```
  ```c
  char s1[10];
  scanf("%s", s1);  // 표준 입력을 받아서 배열 행태의 문자열에 저장

  char *s1 = malloc(sizeof(char)*10); // char 10크기 동적 메모리 할당
  scanf("%s", s1); // 표준 입력을 받아서 배열 형태의 문자열에 저장
  free(s1);        // 동적 메모리 해제

  // "%s" <- 문자열 서식 지정자
  char s1[30];
  scanf("%[^\n]s", s1);  // 공백을 포함해서 문자열 입력 받음
  ```
  *  1.3 fgets(), puts() 함수를 이용한 문자열 입력 받기 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/String_gets1.c), [문자열 함수전달](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/Passing_String1.c)
  ```c
  char *fgets(char *str, int size, FILE *file);

  char input(256];
  int i;
  fgets( input, 256, stdin);
  for( i=0; i<256; i++) {
    if(input[i] == '\n') {
      input[i] = '\0';
      break;
    }
  }
  ```
  *  1.4 scanset을 이용한 문자열 입력 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/String_scanset1.c)
  *  1.5 strcat()함수, 문자열 합치기 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/String_strcat1.c), [strcat 구현](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/my_strcat.c)
  ```c
  char *strcat( char *dest, const char *src);
  ```
  *  1.6 문자열 복사(strcpy), 비교(strcmp), 검색(strstr) [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/String_func1.c), [strcmp](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/String_strcmp1.c)
  ```c
  char *strcpy( char *dest, const char *src);
  int  strcmp( const char *s1, const char *s2);
  ```
  *  1.7 문자열 배열 [code1](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/String_array1.c), [code2](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/String_array2.c), [문자열포인터1](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/String_array3.c), [문자열포인터2](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/String_array4.c)
  *  1.8 문자열 포인터 배열 사용 [code1](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/String_parray1.c), [code2](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/String_parray2.c)
  *  1.9 strdup()함수, 문자열 복사 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/String_strdup1.c)
  *  1.10 Reverse String [Using two-pointer](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/Reverse_String.c), [참조](https://www.geeksforgeeks.org/reverse-string-in-c/), [Using Recursion](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/Reverse_String2.c), [Using Temporary Array](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/Reverse_String3.c), [Using Library Function](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/Reverse_String4.c)
  *  1.10 유용한 문자열 함수 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/Useful_string_function.c)
  ```c
  void remchars(char *str, char c);
  void remcnks(char *str, char *cnk);
  void replchars(char *str, char c1, char c2);
  void replcnks(char *str, char *cnk1, char *cnk2);
  void reverse(char *str);
  ```
  * 1.11 문자열 필수 기능
  ```txt
  문자열 필수 기능
  문자열(string)
  ├── 문자열의 설정
  ├── 두 문자열 비교하기
  ├── 다른 형(type)의 자료형을 문자열로 변환하기
  ├── 문자열을 다른 자료형으로 변환하기
  ├── 문자열 중에서 임의의 문자(또는 문자열)을 찾기
  │ ├──문자열 처음부터 찾기
  │ ├──문자열 맨 뒤부터 찾기
  │ ├──문자열 중 임의의 위치에서 찾기
  ├── 문자열의 길이 얻기
  ├── 임의의 문자로 검사
  │ ├──임의의 문자로 시작하는지의 검사 여부
  │ ├──임의의 문자로 종료하는지의 검사 여부
  ├── 문자열 중 임의의 문자열을 위치(offset), 길이(length)에 따라 추출하기
  ├── 문자열 중 임의의 문자(또는 문자열)을 다른 문자(또는 문자열)로 변경하기
  ├── 전체 모두 변경하기
  ├── 임의의 지정한 영역에서만 변경하기
  ├── 영어(English)일 경우, 대문자화, 소문자화
  ```

* 2.문자열 프로그램
  * 2.1 문자열 단순 프로그램 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/String_in_C/Small_Program1.c)
  


