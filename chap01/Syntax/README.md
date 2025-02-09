### Syntax
* Command line argument in C
    * Command line argument in C [[file open](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Syntax/arg_file_open.c)]
    ```c
    > cmdline file.txt
    FILE *file = fopen(argv[1], "r");

    // fopen return 0, the NULL pointer, on failure
    if( file == 0) {
      printf("Could not open file\n");
    } else {
      int x;
      while (( x = fgetc(file))!= EOF ) {
        printf("%c", x);
      }
    }
    fclose(file);
    ```
    ![image](https://github.com/user-attachments/assets/c2b81abd-95a5-4f10-ad37-e91ad2fc899c)

    
    * main argc [[argc argv](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Syntax/main_argc.c)]
    ```c
    int main(int argc, char* argv[]) {
      // printing the coundt of arguments
      printf("The value of argc is %d\n", argc);

      // prining each argument
      for (int i = 0; i < argc; i++)
        printf("%s \n", argv[i]);
      return 0;
    }
    ```
    ![image](https://github.com/user-attachments/assets/e5b98ca0-675c-40d3-a996-0efb67329a7e)


    
    * Command line argument '/20' [[code]()]
    ```c
    unsigned int linenum = 20;

    void getlinenum(int n, char * str[]) {
      for (--n; n; --n) {
        ++str;
        if ((**str == '/') || (**str == '-')) {
          linenum = atoi(*(str) + 1);
          if (linenum <= 0)
            linenum = 20;
        }
      }
    }
   
   int main(int argc, char **argv) {
     getlinenum(argc, argv);
   }
   ```
    ![image](https://github.com/user-attachments/assets/b63f8fb0-85b5-40b5-bb70-0963a1cc3cf8)  

   * [snippets.org] cmdline [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Syntax/cmdline.c)
   ```txt
   > cmdline 1 2 abc
   ```
   ![image](https://github.com/user-attachments/assets/87784b32-e090-4ad0-9319-45c84e13df33)

  * [snippets.org] do [code](https://github.com/csbyun-data/C-Pro/blob/main/chap01/Syntax/do.c)
   ```txt
   a simple facility for specifying multiple commands
   > do dir/w
   ```

   
* 증감 연산자
    ```c
    // 후위 증감 연산자
    num2 = num1++;  // 동일 표현 num2 = num1; num1++;
    num2 = num1--;  // num2 = num1; num1--;
  
    // 전위 증감 연산자
    num2 = ++num1;  // num1++; num2 = num1;
    num2 = --num1;  // num1--; num2 = num1;
    ```
