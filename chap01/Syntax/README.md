### Syntax
* Syntax
    * Command line argument in C [exam1](https://github.com/csbyun-data/C-Pro/blob/main/chap01/CommandLineArgument1.c), [exam2](https://github.com/csbyun-data/C-Pro/blob/main/chap01/CommandLineArgument.c)
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
    * 증감 연산자
    ```c
    // 후위 증감 연산자
    num2 = num1++;  // 동일 표현 num2 = num1; num1++;
    num2 = num1--;  // num2 = num1; num1--;
  
    // 전위 증감 연산자
    num2 = ++num1;  // num1++; num2 = num1;
    num2 = --num1;  // num1--; num2 = num1;
    ```
