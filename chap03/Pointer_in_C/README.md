### [Book] Pointer in C-a Hands on Approach
* Index
    * Contents
    ```
    Chapter 1: Memory, Runtime Memory Organization, and Virtual Memory
    Chapter 2: Pointer Basics
    Chapter 3: Pointer Arithmetic and Single Dimension Arrays
    Chapter 4: Pointers and Strings
    Chapter 5: Pointers and Multidimensional Arrays
    Chapter 6: Pointers to Structures
    Chapter 7: Function Pointers
    Chapter 8: Pointers to File I/O
    ```
*[Chap1~7](https://github.com/csbyun-data/C-Pro/blob/main/chap02/Pointer_in_C/README.md)
* Chapter 8: Pointers to File I/O
   * fopen(), fclose()
   ```
   // fileprog2.c
   #include <stdio.h>
   int main(int argc, char *argv[]) {
     FILE *fp = NULL;
     int res;
     fp = fopen("c:\\test.txt","w");
     if(fp == NULL) {
       printf("File opening error\n");
     } else {
       printf("File opening success\n");
     }
     res = fclose(fp);
     if( res == 0) {
       printf("File closed\n");
     } else {
       printf("Unable to close file\n");
     }
     return 0;
   }
   ```
   * Reading from a File
   ```
   // fileprog3.c
   #include <stdio.h>
   int main(int argc, char *argv[]) {
     FILE *fp = NULL;
     int res;
     int data;
     fp = fopen("c:\\test.txt","w");
     if(fp == NULL) {
       printf("File opening error\n");
     } else {
       printf("File opening success\n");
     }
     // add code
     while(( data = fgetc(fp)) != EOF) {
       if ( data != 10) // checking for new line
         printf("%d %c,", data, (char)data);
       else
         printf("\n");
     }
   
     res = fclose(fp);
     if( res == 0) {
       printf("File closed\n");
     } else {
       printf("Unable to close file\n");
     }
     return 0;
   }
   ```   
   ```
   // fileprog4.c
   #include <malloc.h>
   #define BUFFER 4
   int main(int argc, char * argv[]) {
     FILE* fp;
     int res;
     char*str = NULL;
      
     unsigned char chr;
     int fpos;
     fp = fopen("c:\\test.txt","r");
     if(fp == NULL) {
        printf("File opening error\n");
     } else {
        printf("File opening success\n");
     }
     str = (char*)malloc(sizeof(char)*BUFFER);
     fpos = ftell(fp);
     printf("File pointer pos before reading = %d\n", fpos);
     if(fgets(str, BUFFER, fp)) {
       printf("%s \n",str);
     } else {
       printf("Line reading failure\n");
     }
     fpos = ftell(fp);
     printf("File pointer pos after reading = %d\n", fpos);
     res = fclose(fp);
     if(res == 0) {
       printf("File closed\n");
     } else {
       printf("Unable to close file\n");
     }
     return 0;
   }
   ```
   * Reading Block from file
   ```
   // fileprog5.c
   #include <stdio.h>
   #include <malloc.h>
   #define BUFFER 5
   int main(int argc, char* argv[]) {
     FILE* fp;
     int res;
     char*str = NULL;
     fp = fopen("c:\\test.txt","r");
     if(fp == NULL) {
       printf("File opening error\n");
     } else {
       printf("File opening success\n");
     }
     str = (char*)malloc(sizeof(char)*BUFFER);
     res = fread(str, sizeof(char), BUFFER-1, fp);
     str[4] = '\0';
     if(res) {
       printf("%s \n",str);
     } else {
       printf("Line reading failure\n");
     }
     res = fclose(fp);
     if(res == 0) {
       printf("File closed\n");
     } else {
       printf("Unable to close file\n");
     }
     return 0;
   }
   ```
   * Formatted reading from file
   ```
   // fileprog6.c
   #include<stdio.h>
   #include<malloc.h>
   int main(int argc, char* argv[]) {
     FILE* fp;
     int res;
     int index;
     char* name = NULL;
     char* country = NULL;
     fp = fopen("c:\\test.txt","r");
     if(fp == NULL) {
       printf("File opening error\n");
     } else {
       printf("File opening success\n");
     }
     name = (char*)malloc(sizeof(char)*BUFFER);
     country = (char*)malloc(sizeof(char)*BUFFER);
     while (!feof(fp)) {
       fscanf(fp, "%d %s %s", &index, name, country);
       printf("%d %s %s\n", index, name, country);
     }
     res = fclose(fp);
     if(res == 0) {
       printf("File closed\n");
     } else {
        printf("Unable to close file\n");
     }
     return 0;
   }
   ```
   * Writing to a file
   * Writing a single character to a file
   ```
   // fileprog7.c
   #include<stdio.h>
   #include<malloc.h>
   int main(int argc, char* argv[]) {
     FILE* fp;
     int res;
     int index;
     char* namefmt = "First Middle Last";
     fp = fopen("c:\\test.txt","w");
     if(fp == NULL) {
       printf("File opening error\n");
       return 0;
     } else {
       printf("File opening success\n");
     }
     for( index = 0; index <= strlen(namefmt); index++) {
       fputc(namefmt[index], fp);
     }
     res = fclose(fp);
     if(res == 0) {
       printf("File closed\n");
     } else {
       printf("Unable to close file\n");
     }
     return 0;
   }
   ```
   * Writing a string onto the file
   ```
   // fileprog8.c
   #include<stdio.h>
   #include<malloc.h>
   int main(int argc, char* argv[]) {
     FILE* fp;
     int res;
     int index;
     char* namefmt = "First Middle Last";
     fp = fopen("c:\\test.txt","w");
     if(fp == NULL) {
       printf("File opening error\n");
       return 0;
     } else {
       printf("File opening success\n");
     }
     fputs(namefmt, fp);
     res = fclose(fp);
     if(res == 0) {
       printf("File closed\n");
     } else {
       printf("Unable to close file\n");
     }
     return 0;
   }
   ```
   * Writing a block of data to a file
   ```
   // fileprog9.c
   #include<stdio.h>
   int main(int argc, char* argv[]) {
     FILE* fp;
     int res;
     int index;
     int numofdatatowrite;
     char* namefmt = "First Middle Last";
     fp = fopen("c:\\test.txt","w");
     if(fp == NULL) {
       printf("File opening error\n");
       return 0;
     } else {
       printf("File opening success\n");
     }
     numofdatatowrite = 5;
     if(numofdatatowrite == fwrite(namefmt, sizeof(char), numofdatatowrite, fp)) {
       printf("Success in writing data\n");
     } else
       printf("Unsuccess in writing data\n");
     res = fclose(fp);
     if(res == 0) {
       printf("File closed\n");
     } else {
       printf("Unable to close file\n");
     }  
     return 0;
   }
   ```
   * Accessing disk at random locations
   ```
   // fileprog10.c
   #include<stdio.h>
   #include<malloc.h>
   int main(int argc, char* argv[]) {
     FILE* fp;
     int res;
     int index;
     char* datafromfile = (char*)malloc(sizeof(char)*6);
     fp = fopen("c:\\test.txt","w");
     if(fp == NULL) {
       printf("File opening error\n");
       return 0;
     } else {
       printf("File opening success\n");
     }
     fputs("HELLO NAV", fp);
     fclose(fp);
   
     fp = fopen("c:\\test.txt","r");
     //Read the current content
     fgets(datafromfile, 10, fp);
     printf("Current content of file %s\n", datafromfile);
     rewind(fp);     //resetting the file pointer
     fseek(fp, 6, SEEK_SET);//seeks file pointer to offset value 6 from beginning of file
     memset(datafromfile, 0, sizeof(char));
     fgets(datafromfile, 6, fp);
     printf("Content of data %s\n", datafromfile);
     fseek(fp, 0L, SEEK_SET); //seeks file pointer to offset value 0 from beginning of file
     memset(datafromfile, 0, sizeof(char));
     fgets(datafromfile, 6, fp);
     printf("Content of data %s\n", datafromfile);
     fclose(fp);
   
     return 0;
   }
   ```
   * Miscellaneous Functions
   ```
   // fileprog11.c
   int main(int argc, char* argv[]) {
     FILE* fp;
     int fileoffset = 0;
     fp = fopen("c:\\test.txt","w");
     if(fp == NULL) {
       printf("File opening error\n");
       return 0;
     } else{
       printf("File opening success\n");
     }
     fputs("HELLO NAV", fp);
     fclose(fp);
   
     fp = fopen("c:\\test.txt","r");
     fileoffset = ftell(fp);
     printf("File offset at default position %d\n", fileoffset);
     fseek(fp, 6, SEEK_SET);
     fileoffset = ftell(fp);
     printf("File offset after seeking %d\n", fileoffset);
     fclose(fp);
   
     return 0;
   }
   ```
   ```
   // fileprog12.c
   int main(int argc, char* argv[]) {
     FILE* fp;
     int fileoffset=0;        fp = fopen("c:\\test.txt","w");
     if(fp == NULL) {
       printf("File opening error\n");
       return 0;
     } else {
       printf("File opening success\n");
     }
     fputs("HELLO NAV", fp);
     fclose(fp);
   
     fp = fopen("c:\\test.txt","r");
     fseek(fp, 0, SEEK_END);
     fileoffset = ftell(fp);
     printf("Size of file in bytes %d\n", fileoffset);
     fclose(fp);

     return 0;
   }
   ```
   * Another way of resetting the position of file
   ```
   // fileprog13.c
   int main(int argc, char* argv[]) {
     FILE* fp;
     int fileoffset = 0;
     char* data = (char*)malloc(sizeof(char)*11);
     int val;
     fp = fopen("c:\\test.txt","r");
     if(fp == NULL) {
       printf("File opening error\n");
       return 0;
     } else {
       printf("File opening success\n");   
     }

     if(fgets(data, 10, fp)) {
       printf("%s \n",data);
     } else {
       printf("Line reading failure\n");   
     }
     rewind(fp); //resetting the file offset to the beginning of file
     while((val = fgetc(fp)) != EOF) {
       if(val != 10) //checking for new line {
         printf("%c",(char)val);
       } else {
         printf("\n");
       }
     }
     fclose(fp);
     return 0;
   }
   ```
