### Input (scanf, gets, fgets)
* Input
    * scanf() 사용법 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Input/Input_Scanf.c), (입력 문자열에 공백이 있는 경우 공백뒷글자 잘림 )
    * fgets() 문자열 한줄 읽어 들임 [code1](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Input/Input_fgets.c), [code2](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Input/Input_fgets4.c)
    ```c
    // stream : 순서를 가진 연속된 문자열
    #include <stdio.h>
    #include <stdlib.h>
  
    int main() {
      char* ptr;
  
      ptr = (char *)malloc( sizeof(char) * 50);
      fputs("input String : ", stdout); // stdout 표준촐력 stream 

      if(fgets(ptr, 50, stdin) != NULL) // stdin 표준입력 stream 
        fputs(ptr, stdout);            	// stderr 표준에러 stream
  	  free(ptr);
      return 0;
    }
    // 주의!, fgets()함수는 문자열 끝의 Enter Key('\n')값을 buffer에 읽어 들여 전달함
    ```
    * fgets(), fputs() 사용법 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Input/Input_fgets1.c)
    * fgets() 문자열 끝 newline '\n' 제거, null terminator '\0'로 변경 [code1](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Input/Input_fgets2.c), [code2](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Input/Input_fgets3.c)
    ```c
    //  아래code를 한줄로 표현 string[ strlen(buffer)-1 ] = '₩0';
    
    void strip_newline( char *str, int size ) {
      int i;
   
      /* remove the null terminator */
      for ( i = 0; i < size; ++i ) {
        if( str[i] == '\n' ) {
          str[i] = '\0';
          /* we're done, so just exit the function by returning */
          return;   
        }
      }
      /* if we get all the way to here, there must not have been a newline! */
    }
    ```
    * gets(), puts() 사용법 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Input/Input_gets1.c)
    * sscanf() [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Input/time_mac_conv.c)
