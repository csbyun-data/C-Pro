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
* Chapter 1: Memory, Runtime Memory Organization, and Virtual Memory
    * Memory Segmments
    ```
    // test.c
    #include<stdio.h>
    #include<malloc.h>

    int glb_uninit;  /* Part of BSS Segment -- global uninitialized variable, at runtime it is
                        initialized to zero */
    int glb_init = 10;      /* Part of DATA Segment -- global initialized variable */
    
    void  foo(void) {
      static int num = 0;       /* stack frame count */
      int autovar;        /* automatic variable/Local variable */
      int *ptr_foo = (int*)malloc(sizeof(int));
      if (++num == 4)           /* Creating four stack frames */
        return;
      printf("Stack frame number %d: address of autovar: %p\n", num, & autovar);
      printf("Address of heap allocated inside foo() %p\n",ptr_foo);
      foo();                    /* function call */
    }

    int main() {
      char *p, *b, *nb;
      int *ptr_main = (int*)malloc(sizeof(int));
      printf("Text Segment:\n");
      printf("Address of main: %p\n", main);
      printf("Address of afunc: %p\n",foo);

      printf("Stack Locations:\n");
      foo();

      printf("Data Segment:\n");
      printf("Address of glb_init: %p\n", & glb_init);

      printf("BSS Segment:\n");
      printf("Address of glb_uninit: %p\n", & glb_uninit);
    
      printf("Heap Segment:\n");
      printf("Address of heap allocated inside main() %p\n",ptr_main);
    
      return 0;
   }
   ```
* Chapter 2: Pointer Basics
    * What is an address of a variable?
    ```
    int x = 40;

    address -> x = 40
    ```
    * Address of operator
    ```
    // ptr1.c
    int main() {
      int var_int;
      printf("Insert data\n");
      scanf("%d", &var_int);
      return 0;
    }
    ```
    * Retriveing the address of a variable
    ```
    // ptr2.c 
    int main() {
      int var_int = 40;
      printf("Address of variable \"var_int\": %p\n", &var_int);
    }
    ```
    ```
    // ptr3.c
    struct node {
      int a;
      int b;
    };
    int main() {
      struct node p;
      printf("Address of node =%p\n", &p);
      printf("Address of variable a = %p\n", &(p.a));
      printf("Address of variable b = %p\n", &(p.b));

      return 0;
    }
    ```
    * Pointer Declaration
    ```
    datatype *variable_name;
    int *intptr, char *charptr;

    struct inner_node {
      int in_a;
      int in_b;
    };
    struct node {
      int *a;
      int *b;
      struct inner_node *in_node;
    };
    ```
    * Pointer assignment  
    ![image](https://github.com/user-attachments/assets/d18e0d76-f066-47c7-a459-36ed491cea6b)
    ```
    int x = 40;
    int *ptr;
    ptr = &x;  // address of operator used to collect the address of varibale x

    int *ptr;
    ptr = (int *)malloc(sizeof(int)*count);
    ```
    ```
    // ptr4.c
    #include <stdio.h>
    #include <conio.h>
    int main() {
      char c_var;
      int i_var;
      double d_var;
      char *char_ptr;
      int *int_ptr;
      double *double_ptr;

      char_ptr = &c_var;
      int_ptr = &i_var;
      double_ptr = &d_var;

      printf("Size of char pointer = %d value = %u\n", sizeof(char_ptr), char_ptr);
      printf("Size of integer pointer = %d value = %u\n", sizeof(int_ptr), int_ptr);
      printf("Size of double pointer = %d value = %u\n", sizeof(double_ptr), double_ptr);

      getch();
    }
    ```
    ```
    // ptr5.c
    #include <stdio.h>
    #include <conio.h>
    struct inner_node {
      int in_a;
      int in_b;
    };
    struct node {
      int *a;
      int *b;
      struct inner_node *in_node;
    };

    int main() {
      struct node *p;
      int *arrptr;
      int arr[10];
      arrptr = arr;

      printf("Size of pointer variable (struct node *) = %d\n", sizeof(struct node *));
      printf("Size of pointer variable pointing to int array = %d\n", sizeof(arrptr));

      return 0;
    }
    ```
    * Pointer Dereferencing  
    ![image](https://github.com/user-attachments/assets/96970da7-0ef7-4aea-a6e4-402cd74e53c5)
    ```
    int x = 10;  // value 10 sotred at some memory location
    int *ptr - &x; // now pointer variable "ptr" is pointing to the memory location x = 10
    printf("Address of variable \"x\" = %p\n", &x);
    printf("Address of variable \"x\" = %p\n", ptr);
    printf("Value of variable \"x\" = %p\n", x);
    printf("Value stored at address ptr = %p is %d\n", ptr, *ptr);
    ```  
    ![image](https://github.com/user-attachments/assets/3daa7e0d-2640-4c9b-8e90-23abdeb34cea)
    ```
    int count = 1;
    int *ptr = (int *)malloc( sizeof(int) * count);
    *ptr = 10;
    free(ptr);
    *ptr = 20; // Again at this point the porgram wull throw a segmentation error,
                 because we are trying to access a memory which has already been freed.
    ```
    * Basic usage of pointer
    ```
    // pass by value
    void calling_function(void) {
      int t1, t2, t3;
      t1 = 10;
      t2 = 20;
      t3 = called_function(t1, t2);
    }

    int called_function( int x, int y) {
      int t1, t2, t3;
      t1 = x;
      t2 = y;
      t3 = t1 + t2;

      return t3;
    }
    // case 1 : pass by value
    struct data {
      int x;
      int y;
    };
    void func(struct data v1) {
      struct data v2 = v1;
    }
    int main() {
      struct data var;
      var.x = 10;
      var.y = 20;
      func( var);

      return 0;
    }
    ```
    ```
    // pass by reference
    void calling_function(void) {
      int t1;
      int *t2;
      t1 = 10;
      t2 = called_function(&t1);
      free(t2); // addtional code
    }

    int *called_function( int *x) {
      int t2;
      int *t1, *t3;
      t1 = x;
      t2 = 10;
      t3 = (int *)malloc(sizeof(int));
      t3 = *t1 + t2;

      return &t3;
    }
    // case 2: pass by reference
    struct data {
      int x;
      int y;
    };
    void func( struct data *v1) {
      struct data *v2 = v1;
    }
    int main() {
      struct data var;
      var.x = 10;
      var.y = 20;
      func( &var);

      return 0;
    }
    ```
    * Pointers and Constants
    ```
    // Constant pointer variable
    // ptr6.c
    int main() {
      int num = 10;
      int * const ptr1 = &num;  // Initialization of const ptr
      printf("Value stored at pointer = %d\n", *ptr1);
    }
    
    // ptr7.c
    int main() {
      int num1 = 10;
      int num2 = 20;
      int * const ptr1 = &num1;  // Initialization of const ptr

      ptr1 = &num2; // can't do this
      printf("Value stored at pointer = %d\n", *ptr1);
    }
    ```
    ![image](https://github.com/user-attachments/assets/b90bd7a1-2b56-4927-9b60-8d9d43f57b77)

    ```
    // Pointers to constant variable
    // ptr8.c
    int main() {
      int num1 = 10;
      const int *ptr1;
      int *ptr2;
      ptr1 = &num1;

      *ptr1 = 20; // can't do this
      num1 = 20; // can be done
      printf("Value stored at pointer = %d\n"m *ptr1);
    }
    ```
    ![image](https://github.com/user-attachments/assets/b53430ec-73fd-4c31-8177-ca4814dd9da1)

    ```
    // Constant pointer to a constant variable
    // ptr9.c
    int main() {
      int num1 = 10;
      int num2 = 20;
      const int *ptr1 = *num1;
      int *ptr2;
      *ptr1 = 20; // can't change the value that the const pointer is pointing to
      num1 = 20; // can be done
      ptr1 = &num2; // can't change the constant pointer's value
      (i.e. - constant pointer should not point to any other memory address once initialized
      printf("Value stored at pointer = %d\n", *ptr1);
    }
    ```
    * Multievel pointers
    ```
    // Pointers to a pointer variable

    int a = 10;
    int *ptr = &a;
    int **ptr1 = &ptr;
    ```  
    ![image](https://github.com/user-attachments/assets/219452f6-8b6f-4214-be11-39bac5c55b8e)  
    ```
    // ptr10.c
    int main() {
      int num = 10;
      int *ptr = &num;
      int **mptr = &ptr;

      printf("Value of var num = %d\n", num);
      printf("Value of var num = %d\n", *ptr);
      printf("Value of var num = %d\n", **mptr);

      printf("Address of var num = %p\n", &num);
      printf("Address of var num = %p\n", ptr);
      printf("Address of var num = %p\n", *mptr);

      printf("Address of pointer var ptr = %p\n", &ptr);
      printf("Address of pointer var ptr = %p\n", mptr);
      printf("Address of pointer var mptr = %p\n", &mptr);

      return 0;
    }
    ```
* Chapter 3: Pointer Arithmetic and Single Dimension Arrays
   * Array Memory Layout
   ```
   // ptr1.c
   #include <stdio.h>
   int main() {
     int iArray[32];
     int i;

     for( i=0; i<32; i++)
       iArray[i] = i;
     for( i=0; i<32; i++) {
       printf("a[%d] %u %d ", i, &iArray[i], iArray[i]);
       if(i%4 ==0;) && (i != 0))
         printf("\n");
     }
     getch();
   }
   ```
   * Little endian, Big endian
   ```
   // ptr2.c
   #include <stdio.h>
   #define BIG_ENDIAN 0
   #define LITTLE_ENDIAN 1
   int endian() {
     short int word = 0x0001;
     char *byte = (char *) &word;
     return (byte[0]? LITTLE_ENDIAN : BIG_ENDIAN);
   }
   int main(int argc, char *argv[]) {
     int value;
     value = endian();
     if(value == 1)
       printf("The machine is Little Endian\n");
     eles
       printf("The machine is Big Endian\n");
     return 0;
   }
   ```
   * Pointer Arithmetic
   ```
   int arr[10]; // array of type integer which can hold 10 integers.
   int *ptr;  // an integer to pointer
   ptr = arr; // This will point to first index of the array element.
   ```
   * Pointer addition
   ```
   ptr = ptr  + 1;

   // ptr3.c
   #include <stdio.h>
   int main(int argc, char *argv[]) {
     int i = 0;
     int data = 9;
     int *iptr;
     char *cptr;
     iptr = &data;
     cptr = (char *)&data;

     printf("value of data = %d hex value = %x\n", data, data);
     printf("Address of data = %p\n", &data);
     printf("Integer pointer pointing at %p\n", iptr);
     printf("Character pointer pointing at %p\n", cptr);
     printf("Printing address of all the four bytes of variable int data\n");
     for( i=0; i<4; i++) {
       printf("address = %p value = %x\n", cptr, *cptr);
       cptr++;
     }

     return 0;
   }
   ```
   * Subtracting two pointer variables
   ```
   // ptr4.c
   #include <stdio.h>
   int main( int argc, char * argv[]) {
     int data[4] = {1, 2, 3, 4};
     int *iptr1;
     int *iptr2;
     int val;
     iptr1 = &data[0];
     iptr2 = &data[1];
     val = iptr2 - iptr1;
     printf("Distance between the two addresses = %d\n", val);

     return 0;
   }
   ```
   * Comparing two pointer variables
   ```
   #include <stdio.h>
   int main( int argc, char *argv[]) {
     int data[4] = {1, 2, 3, 4};
     int *iptr1;
     int *ptr2;
     iptr1 = &data[0];
     iptr2 = &data[1];
     if( iptr1 == iptr2)
       printf("Address of iptr1 is equal to address of iptr2\n");
     if( iptr1 > iptr2)
       printf("Address of iptr1 is greater than address of iptr2\n");
      else
       printf("Address of iptr1 is smaller than address of iptr2\n");

     return 0;
   }
   ```
   * Arrays Explored
   ```
   int arr_var[100];
   arr_var // 동일 표현 &arr_var[0]
   arr_var + 1 // address of 1st index
   arr_var + 2 // address of 2nd index location
   arr_var + offset    // 동일 표현 &arr_var[offset]
   *(arr_var + offset) // 동일 표현 arr_var[offset]

   // ptr7.c
   #include <stdio.h>
   int main(int argc, char *argv[]) {
     int arr[4] = {1, 2, 3, 4};
     int *iptr;
     iptr = &arr[0] + 2; // pointing to the 2nd element
     printf("Address of 2nd index = %p\n", iptr);
   
     iptr = &arr[2]; // pointing to the 2nd element
     printf("Address of 2nd index = %p\n", iptr);

     return 0;
   }
   ```
   ```
   // ptr8.c
   #include <stdio.h>
   ibt main(int argc, char *argv[]) {
     int arr[4] = {1, 2, 3, 4};
     printf("Address of 0th index = %p\n", arr);
     printf("Address of 0th index = %p\n", &arr[0]);

     return 0;
   }
   ```
   ```
   int arr_var[5];
   arr_var = arr_var + 1; // this is not allowed since this expression is trying to shift the pointer
   // location via array name to the next integer variable's address.
   arr_var ++; // illegal statement, as it is trying to change the starting address of an array variable
   ```
   * Dynamic array
   ```
   // ptr9.c
   #include <stdio.h>
   #include <malloc.h>
   int *ptr = NULL;
   static int count = 0;
   void insert(int data) {
     if(ptr == NULL) {
       ptr = (int *)malloc(sizeof(int)); // allocating space from heap for 1st data
       ptr[0] = data; // accessing memory address with array notation to store data
     } else  {
       ptr = (int *)realloc(ptr, sizeof(int)*(count+1)); // Increasing the size of memory
       // accomodate new integer
       ptr[count] = data; // accessing memory address with array notation to store data
     }
     count++;
   }
   void show() {
     int i=0;
     for( i=0; i<count; i++) {
       printf("%d\n", ptr[i]);
     }
   }
   int main(int argc, char *argv[]) {
     int c=0;
     int data;
     while( c != 3) {
       printf("Insert choice\n");
       printf("1 to insert data\n");
       printf("2 to Show data\n");
       printf("3 to quit data\n");
       scanf("%d", &c);
       if( c==3)
         break;
       switch(c) {
         case 1:
           printf("Data = \n");
           scanf("%d", &data);
           insert(data);
           break;
         case 2:
           printf("Data in array\n");
           show();
           break;
       }
     }
     return 0;
   }
   ```
   * Array of pointers
   ```
   // int *arr_ptr[10]  , pointer to 10 integer variable
   // ptr10.c
   #include <stdio.h>
   int main(int argc, char *argv[]) {
     int arr[4] = {1, 2, 3, 4};
     int *arr_ptr[4];
     int i;

     for( i=0; i<4; i++) 
       arr_ptr[i] = arr + i;

     printf("Address of (arr) array element\n");
     for( i=0; i<4; i++)
       printf("Address of %d index = %p\n", i, arr+i);

     printf("Value of (arr_ptr) array of pointer element\n");
     for(i=0; i<4; i++)
       printf("Value of %d index = %p\n", i, arr_ptr[i]);

     return 0;
   }
   ```
   ![image](https://github.com/user-attachments/assets/ad1313ac-473b-47d9-8829-e4536ba9eafc)

   * Pointer to array  
   ```
   // int (*ptr2arr)[4]; // it is a pointer to an array of 4 integers
   // ptr11.c
   #include <stdio.h>
   int main( int argc, char *argv[]) {
     int arr[4] = {1, 2, 3, 4};
     int (*ptr2arr)[4];
     int i;
     int *ptr = arr;
     ptr2arr = &arr;

     for(i=0; i<4; i++)
       printf("Address of array = %p\n", arr + i);

     printf("Value at = %d\n", *(ptr2arr[0] + 1));
     for( i=0; i<4; i++)
       printf("Value at %p = %d\n', (ptr2arr[0] + i), *(ptr2arr[0] + i));

     return 0;
   }
   ```
   
* Chapter 4: Pointers and Strings
   * String layout in memory  
   ![image](https://github.com/user-attachments/assets/04e5fbea-e6c4-4ca2-8653-0e1c78d39ba7)

   ```
   char *strptr = "Hello";
   char strarray1[] = "Hello";
   char strarray2[6] = "Hello";
   char strarray3[4] = {'a','b','c','d'};

   char arr1[7] = "STRING";
   char arr2[9] = "STRING";
   ```
   ![image](https://github.com/user-attachments/assets/08e0f85b-0166-4e4b-b640-e3c61420e819)

   * Accessing string elements
   ```
   // string1.c
   #include <string.h>
   int main(int argc, char *argv[]) {
     char *str = "Hello Pointer";
     int i = 0;

     for( i=0; i<strlen(str); i++)
       printf("%c", str[i]);

     return 0;
   }
   ```
   ```
   // string2.c
   #include <stdio.h>
   int main(int argc, char *argv[]) {
     char *str = "Hello Pointer";
     char *ptr = str;
     while( *ptr != '\0') {
       printf("%c", *ptr);
       ptr++;
     }
     return 0;
   }
   ```
   * Dynmic memory allocation
   ```
   // string3.c
   #include <string.h>
   #include <malloc.h>
   int main(int argc, char *argv[]) {
     char *src = "Hello pointer";
     char *dst = NULL;
     dst = (char *)malloc(sizeof(char) * (strlen(src) + 1));
     memcpy(dst, src, strlen(src));

     return 0;
   }
   ```
   * String literals and constants
   ```
   // string4.c 
   #include <stdio.h>
   int *foo(void);
   int main( int argc, char *argv[]) {
     int *m = foo();
     printf("Priniting local value of function foo = %d\n", *m);

     return 0;
   }

   int *foo(void) {
     int i = 10;
     return &i; // , not valid anymore
   }
   ```
   ```
   // literal or constant, and the memory is allocated from the RO section,
    which is persistent throughout the life cycle of program execution
   // string5.c
   #include <stdio.h>
   char *foo(void);
   int main(int argc, char *argv[]) {
     char *m = foo();
     printf("Printing local value of function foo = %s\n", m);

     return 0;
   }
   char * foo(void) {
     char *str = "STRING";
     return str;
   }
   ```
   ```
   // string6.c
   #include <stdio.h>
   int main() {
     char *strliteral = "ADD";
     strliteral[0] = 'B';   // Modifying value of 0th index, NOT ALLOWED,
                            // program will generate segmentation fault
     strliteral++; //Allowed
     return 0;
   }
   ```
   * String operations
   ```
   // handling string inputs
   // string7.c
   #include <stdio.h>
   #include <malloc.h>
   int main() {
     char arrstr[6];
     char *strptr;
     printf("Input hello\n");
     strptr = (char *)malloc(sizeof(char)*10);
     printf("Input hello\n");
     scanf("%s", strptr);
   }
   ```
   * String iteration
   ```
   // string8.c
   #include <stdio.h>
   #include <malloc.h>
   int main() {
     char arrstr[6];
     char *strptr;
     printf("Input hello\n");
     scanf("%s", arrstr);
     printf("String received = %s\n", arrstr);
   }
   // string9.c
   #include <stdio.h>
   #include <malloc.h>
   int main() {
     char arrstr[6];
     char *strptr;
     printf("Input hello\n");
     scanf("%s", arrstr);
     strptr = arrstr;
     while( *strptr != '\0') {
       printf("%c", *strptr);
       strptr++;
     }
   }
   ```
   * String length
   ```
   int str_length(char *str) {
     int string_length = 0;
     char *ptr = null;
     ptr = str;
     while( *ptr != '\0')
       string_length++;
     return string_length;
   }
   ```
   * String copy
   ```
   void str_copy(char *dest_str, const char *src_str) {
     char *stemp = src_str;
     char *dtemp = dest_str;
     while( *stemp != '\0') {
       *dtemp = *stemp;
       stemp++;
       dtemp++;
     }
     *dtemp = '\0';
   }
   ```
   * String Concatenation
   ```
   void str_cat(char *deststr, const char *srcstr) {
     char *dtemp = deststr;
     char *stemp = srcstr;
     // reach till end of the deststr
     while( *dtemp != '\0') {
       dtemp++;
     while( *srcstr != '\0') {
       *dtemp = *srcstr;
       dtemp++;
       srcstr++;
     }
     *dtemp = '\0';
   }
   ```
   * Array of Strings
   ```
   // string10.c
   #include <stdio.h>
   int main(int argc, char *argv[]) {
     char arr[6][10] = { "EGRET", "IBIS", "MYNA", "IORA", "MUNIA", "BULBUL" };
     int i;
     for( i=0; i<6; i++)
       printf(" %d - %s\n", i, arr[i]);
     return 0;
   }

   // string11.c
   #include <stdio.h>
   #include <string.h>
   #include <malloc.h>

   int main( int argc, char *argv[]) {
     char *arr[6];
     char tempstring[30];
     int i;

     for( i=0; i<6; i++) {
       printf("Insert data\n");
       scanf("%s", tempstring);
       arr[i] = (char *)malloc( sizeof(char)*(strlen(tempstring) + 1));
       strcpy(arr[i], tempstring);
     }

     printf("Data in array");
     for( i=0; i<6; i++) 
       printf(" %d - %s\n", i, arr[i]);
     freestring(arr, 5);

     return 0;
   }

   freestring( char arr[], int length) {
     int i;
     for( i=0; i<= length; i++)
       free(arr[i]);
   }

   // string12.c
   #include <stdio.h>
   #include <string.h>
   #include <malloc.h>

   int main( int argc, char *argv[]) {
     char **arr = NULL;
     char tempstring[30];
     int i;

     for( i=0; i<6; i++) {
       printf("Insert data\n");
       scanf("%s", tempstring);
       if( arr == NULL) 
         arr = (char **)malloc(sizeof(char *));
       else
         arr = (char **)realloc(arr, sizeof(char *)*(i+1));
       arr[i] = (char *)malloc(sizeof(char) * (strlen(tempstring) + 1));
       strcpy(arr[i], tempstring);
     }
     for( i=0; i<6; i++)
       prinf("%d - %s\n", i, arr[i]);
     freestrmemory(arr, 5);
     return 0;
   }

   void freestrmemory( char ** arr, int length)
   {
     int i;
     for( i=0; i <= length; i++)
       free(arr[i]);

     free(arr);
   }
   ```
   <img src = "https://github.com/user-attachments/assets/5de354db-c250-446f-8924-8779441115ef" width="70%" height="70%">

* Chapter 5: Pointers and Multidimensional Arrays
   *  access to two-dimemsional array
   ```
   // multidim1.c
   int main( int argc, char *argv[]) {
     int data[5][5];
     int i, j;
     for( i=0; i<5; i++) {
       data[i][j] = -1;
     }
     return 0;
   }
   ```
   * Pointer to 2D array
   ```
   // multidim2.c
   int main( int argc, char *argv[]) {
     int data[5][5];
     int i, j;
     int count = 0;
     for( i=0; i<5; i++) {
       for( j=0; j<5; j++)
         data[i][j] = count++;
     }
     printf("Starting address of the array %p\n", data);
     for( i=0; i<5; i++) {
       printf(" %dth row location = %p\n", i, data[i]);
       printf("Loc %d,1 = %p\n", &dadta[i][0]);
     }
     return 0;
   }
   ```
   * Arithmetic on an address of an array
   ```
   // multidim3.c
   #include <stdio.h>
   int main( int argc, char *argv[]) {
     int data[5][5];
     int i, j;
     int count = 0;
     for( i=0; i<5; i++) {
       for( j=0; j<5; j++)
         data[i][j] = count++;
     }
     for( i=0; i<5; i++) {
       printf(" %d row = %p\n", i, data[i]);
       printf("Columns\n");
       for( j=0; j<5; j++) {
         printf("%d = %p, ", j, data[i] + j);
       }
       printf("\n");
     }
     return 0;
   }
   ```
   * Value at the location
   ```
   arr[i][j]
   arr[i] == *(&arr[i]) == *(arr+i)
   *(arr[i]+j) == *(*(arr+i)+j)
   ```
   ```
   // multidim4.c
   #include <stdio.h>
   int main( int argc, char *argv[]) {
     int data[5][5];
     int i, j;
     int count = 0;
     int (*aptr)[5];
   
     for( i=0; i<5; i++) {
       for( j=0; j<5; j++)
         data[i][j] = count++;
     }
     aptr = data;
     for( i=0; i<5; i++)
       printf("%dth row = %p\n", i, *aptr++);

     return 0;
   }
   ```
   ```
   // multidim5.c
   #include <stdio.h>
   int main( int argc, char *argv[]) {
     int data[5][5];
     int i, j;
     int count = 0;
     int (*aptr)[5];
   
     for( i=0; i<5; i++) {
       for( j=0; j<5; j++)
         data[i][j] = count++;
     }
     aptr = data;
     for( i=0; i<5; i++) {
       for( j=0; j<5; j++) 
         printf("%d,%d = %p val = %d \n", i, j, (*aptr+j), *(*aptr+j));
       printf("\n");
       aptr++;
     }
     return 0;
   }
   ```
   * Accessing the indices with a pointer variable in the case of 2D array  
   ```
   // multidim6.c
   #include <stdio.h>
   int main( int argc, char *argv[]) {
     int data[5][5];
     int i, j;
     int count = 0;
     int (*aptr)[5];
     int *dataptr;
   
     for( i=0; i<5; i++) {
       for( j=0; j<5; j++)
         data[i][j] = count++;
     }
     aptr = data;
     for( i=0; i<5; i++) {
       printf("Address of %d row = %p\n", i, (*aptr + i));
       dataptr = (*aptr + i*5);
       for( j=0; j<5; j++) {
         printf("%d,%d = %p val = %d \n", i, j, dataptr, *(dataptr));
         dataptr++;
       }
       printf("\n");
     }
     return 0;
   }
   ```
   * 3D array basics
   ```
   // multidim7.c
   #include <stdio.h>
   int main( int argc, char *argv[]) {
     int data[3][3][3];
     int i, j, k;
     int count = 0;
   
     for( i=0; i<3; i++) {
       for( j=0; j<3; j++)
         for( k=0; k<3; k++)
           data[i][j][k] = count++;
     }
   
     for( i=0; i<3; i++) {
       for( j=0; j<3; j++) {
         for( k=0; k<3; k++)
           printf("%d%d%d = %d", i, j, k, data[i][j][k]);
         printf("\n");
       }
       printf("\n");
     }
     return 0;
   }
   ```
   * Understanding 3D array expressions and their meaning
   ```
   // multidim8.c
   #include <stdio.h>
   int main( int argc, char *argv[]) {
     int data[3][3][3];
     int i, j, k;
     int count = 0;
   
     for( i=0; i<3; i++) {
       for( j=0; j<3; j++)
         for( k=0; k<3; k++)
           data[i][j][k] = count++;
     }
     printf("0th row of 3d array = %p\n", data);
     printf("0th row of 2d array = %p\n", data[0][0]);
     printf("0th row of 1d array = %p\n", data[0][0][0]);

     return 0;
   }
   ```
   * Array arithmetic
   ```
   // multidim9.c
   #include <stdio.h>
   int main( int argc, char *argv[]) {
     int data[3][3][3];
     int i, j, k;
     int count = 0;
   
     for( i=0; i<3; i++) {
       for( j=0; j<3; j++)
         for( k=0; k<3; k++)
           data[i][j][k] = count++;
     }
   
     for( i=0; i<3; i++) {
       for( j=0; j<3; j++) {
         for( k=0; k<3; k++)
           printf("%d%d%d addr %p", i, j, k, &data[i][j][k]);
         printf("\n");
       }
       printf("\n");
     }
     printf("Index value address\n");
     for( i=0; i<3; i++)
       printf("row %d addr = %p\n", i, data+i);
   
     return 0;
   }
   ```
   ```
   // multidim10.c
   #include <stdio.h>
   int main( int argc, char *argv[]) {
     int data[3][3][3];
     int i, j, k;
     int count = 0;
   
     for( i=0; i<3; i++) {
       for( j=0; j<3; j++)
         for( k=0; k<3; k++)
           data[i][j][k] = count++;
     }
   
     for( i=0; i<3; i++) {
       for( j=0; j<3; j++) {
         for( k=0; k<3; k++)
           printf("%d%d%d=%d addr %p", i, j, k, data[i][j][k], &data[i][j][k]);
         printf("\n");
       }
       printf("\n");
     }
   
     for( i=0; i<3; i++)
       printf("row %d addr = %p\n", i, data[0][i]);
     printf("2D row address\n");
     for( i=0; i<3; i++)
       printf("2D row %d addr = %p %p \n", j, data[i][j], *(data[i]+j));
     return 0;
   }
   ```   
   ```
   // *(*(data[i]+j)+k) == *(data[i][j]+k) == d[i][j][k]
   // multidim11.c
   #include <stdio.h>
   int main( int argc, char *argv[]) {
     int data[3][3][3];
     int i, j, k;
     int count = 0;
   
     for( i=0; i<3; i++) {
       for( j=0; j<3; j++)
         for( k=0; k<3; k++)
           data[i][j][k] = count++;
     }
     printf("Index=val addr <>\n");
     for( i=0; i<3; i++) {
       for( j=0; j<3; j++) {
         for( k=0; k<3; k++)
           printf("%d%d%d=%d addr %p", i, j, k, data[i][j][k], &data[i][j][k]);
         printf("\n");
       }
       printf("\n");
     }
     for( i=0; i<3; i++)
       printf("row %d addr = %p\n", i, data[0][i]);
   
     printf("2D row address\n");
     for( i=0; i<3; i++) {
       printf("3D %d ROW\n", i);
       for( j=0; j<3; j++)
         printf("2D row %d addr = %p %p \n", j, datda[i][j], *(data[i]+j));
     }
   
     printf("1D row address\n");
     for( i=0; i<3; i++) {
       printf("3D %d ROW\n", i);
       for( j=0; j<3; j++) {
         printf("2D %d row\n", j);
         for( k=0; k<3; k++)
           printf("%d%d%d = %p val = %d ", i, j, k, *(data[i]+j)+k, *(*(data[i]+j)+k));
         printf("\n");
       }
     }
     return 0;
   }
   ```   
   ```
   // multidim12.c
   #include <stdio.h>
   int main( int argc, char *argv[]) {
     int data[3][3][3];
     int i, j, k;
     int count = 0;
     int *dataptr = NULL;
   
     for( i=0; i<3; i++) {
       for( j=0; j<3; j++)
         for( k=0; k<3; k++)
           data[i][j][k] = count++;
     }

     for( i=0; i<3; i++) {
       printf("3D %d ROW\n", i);
       for( j=0; j<3; j++) {
         printf("2D %d row\n", j);
         dataptr = *(data[i]+j);
         for( k=0; k<3; k++)
           printf("%d%d%d = %p val = %d ", i, j, k, dataptr, *dataptr++);
         printf("\n");
       }
     }
     return 0;
   }
   ```
* Chapter 6: Pointers to Structures
   * Defining structures
   ```
   struct header {
     int header_version;
     char tagid;
     char signature[4];
     int data_offset;
   }
   ```
   * Declaring structure variables
   ```
   struct date {
     int day;
     int month;
     int year;
   };
   struct date correntdate;
   ```
   * Accessing structure members
   ```
   // struct1.c
   int main( int argc, char *argv[]) {
     struct date {
       int day;
       int month;
       int year;
     }
     sturct date current;
     current.day = 1;
     current.month = 11;
     current.year = 2012;

     return 0;
   }
   ```
   * Initializing structure variables
   ```
   // sturct2.c
   int main( int argc, char *argv[]) {
     struct date {
       int day;
       int month;
       int year;
     };
     sturct date current = { 1, 11, 2012 };
     return 0;
   }
   ```
   * Structure nesting
   ```
   struct header {
     int version;
     int signature;
     struct tagname {
       int id;
       int offset;
     } tagid;
   };

   // struct3.c
   int main( int argc, char *argv[]) {
      struct header {
        int version;
        int signature;
        struct tagname {
          int id;
          int offset;
        } tagid;
     };
     struct header hdrinfo;
     hdrinfo.version = 0;
     hdrinfo.signature = 5;
     hdrinfo.tagid.id = 1;
     hdrinfo.tagid.offset = 10;

     return 0;
   }
   ```
   * Struct in Memory
   ```
   // struct4.c
   int main( int argc, char * argv[]) {
     struct data {
       int i;
       int j;
       int k;
     };
     struct data v1;
     printf("Size of sutructure data = %d\n", sizeof(sutruct data));
   }
   ```
   * Struct Padding
  ![image](https://github.com/user-attachments/assets/8cccf400-727d-479b-a71c-735db0388add)

   ```
   // struct5.c
   #include <stdio.h>
   int main( int argc, char * argv[]) {
     struct data {
       int i;
       char c;
       int j;
     };
     struct data v1;
     struct data *dsptr;
     printf("Size of structure data = %d\n", sizeof(struct data));
     dsptr = (struct data *)malloc(sizeof(struct data));
     printf("Address of member int i = %u\n", &(dsptr->i));
     printf("Address of member char c = %u\n", &(dsptr->c));
     printf("Address of member int j = %u\n", &(dsptr->j));

     return 0;
   }
   ```
   ![image](https://github.com/user-attachments/assets/26f83dcd-51d3-4b0c-913a-a63f39d72c46)

    ```
   // struct6.c
   #include <stdio.h>
   int main( int argc, char * argv[]) {
     struct data {
       int i;
       char c1;
       int j;
       char c2;
       int k;
     };
     struct data v1;
     struct data *dsptr;
     printf("Size of structure data = %d\n", sizeof(struct data));
     dsptr = (struct data *)malloc(sizeof(struct data));
     printf("Address of member int i = %u\n", &(dsptr->i));
     printf("Address of member char c1 = %u\n", &(dsptr->c1));
     printf("Address of member int j = %u\n", &(dsptr->j));
     printf("Address of member char c2 = %u\n", &(dsptr->c2));
     printf("Address of member int k = %u\n", &(dsptr->k));

     return 0;
   }
   ```
   * When structure padding is not helpful
   <img src = "https://github.com/user-attachments/assets/5b4007b6-0c7a-4e8a-85b6-88d41fe2faf7" width="70%" height="70%">
   ```
   // struct7.c
   int main( int argc, char *argv[]) {
     struct gif_hdr {
       char signature[3];
       char version[3];
       int width;
       int height;
       char colormap;
       char bgcolor;
       char ratio;
     };
     struct gif_hdr v1;
     struct gif_hdr *dsptr;
   
     printf("Size of structure data = %d\n", sizeof(struct gif_hdr));
     dsptr = (struct gif_hdr *)malloc(sizeof(struct gif_hdr));
     printf("Offset of signature = %d\n", &(dsptr->signature[0] - &(dsptr->signture[0]));
     printf("Offset of version = %d\n", &(dsptr->version[0] - &(dsptr->signature[0]));
     printf("Offset of width = %d\n", (char *)&(dsptr->width) - &(dsptr->signature[0]));
     printf("Offset of height = %d\n", (char *)&(dsptr->height) - &(dsptr->signature[0]));
     printf("Offset of colormap = %d\n", &(dsptr->colormap) - &(dsptr->signature[0]));
     printf("Offset of bgcolor = %d\n", &(dsptr->bgcolor) - &(dsptr->signature[0]));
     printf("Offset of ratio = %d\n", &(dsptr->ratio) - &(dsptr->signature[0]));

     return 0;
   }
   ```
   * Structure packing
   ```
   #pragma pack(1) // 1 - byte aligment
   struct data { 
     int i;
     char c;
     int j;
   };
   // Directly againist the members of structure
   struct data { 
     int i __attribute__((__packed__));
     char c __attribute__((__packed__));
     int j __attribute__((__packed__));
   };
   // Againist the complete structure
   struct data {
     int i;
     char c;
     int j;
   } __attribute__((__packed__));
   ```
   * Structure assignment and copying
   ```
   // struct9.c
   #include <malloc.h>
   int main(int argc, char* argv[]) {
     struct data {
       int i;
       char c;
       int j;
       int arr[2];
      };
      struct datawptr {
        int i;
        char *c;
      };
      struct datawptr dptr1;
      struct datawptr dptr2;
      struct data svar1;  // a normal variable of type struct data
      struct data svar2;  // a normal variable of type struct data
      svar1.c = 'a';
      svar1.i = 1;
      svar1.j = 2;
      svar1.arr[0] = 10;
      svar1.arr[1] = 20;
      svar2 = svar1;
      printf("Value of second variable \n");
      printf("Member c = %c\n", svar2.c);
      printf("Member i = %d\n", svar2.i);
      printf("Member j = %d\n", svar2.j);
      printf("Member arr0th = %d\n", svar2.arr[0]);
      printf("Member arr1st = %d\n", svar2.arr[1]);
      dptr1.i = 10;
      dptr1.c = (char*)malloc(sizeof(char));
      *(dptr1.c) = 'c';
      dptr2.c = (char*)malloc(sizeof(char));
      dptr2 = dptr1;
      printf("int member = %d\n", dptr2.i);
      printf("char ptr member = %c\n", *(dptr2.c));
   
      return 0;
   }
   ```
   // struct10.c
   int main(int argc, char* argv[]) {
     struct datawptr {
       int i;
       char *c;
     };
     struct datawptr dptr1;
     struct datawptr dptr2;
     dptr1.i = 10;
     dptr1.c = (char*)malloc(sizeof(char));
     *(dptr1.c) = 'c';
     dptr2.c = (char*)malloc(sizeof(char));
     memcpy(&dptr2, &dptr1, sizeof(struct datawptr));
     printf("Int member value of 2nd variable = %d\n", dptr2.i);
     printf("Char ptr member value of 2nd variable = %c\n", *(dptr2.c));
     printf("value of char ptr in 1st variable = %p\n", dptr1.c);
     printf("value of char ptr in 2nd variable = %p\n", dptr2.c);
     printf("Changing value of 2nd member in 2nd variable (dptr2)\n");
     *(dptr2.c) = 'a';
     printf("value of char ptr of 2nd variable = %c and 1st variable = %c\n", *(dptr2.c), *(dptr1.c));
     return 0;
   }
   ```
   * Structure pointers
   ```
   struct data {
     int i;
     char c;
     int j;
   };
   struct data *var; // declaring a pointer variable "var" of type struct data
   ```
   * Accessing member variables
   ```
   #include <stdio.h>
   int main(int argc, char* argv[]) {
     struct data {
       int i;
       char c;
       int j;
     };
     struct data *sptr; //pointer variable of type struct data
     struct data svar;  // a normal variable of type struct data
     sptr = (struct data*) malloc (sizeof(struct data)); //the code below is accessing the member 
     // fields with help of arrow operator ->
     sptr->c = 'c';
     sptr->i = 10;
     sptr->j = 20;    //or the same variable could be access in the following way
     (*sptr).c = 'd';
     (*sptr).i = 30;
     (*sptr).j = 40;  //below code is accessing the member fields with help of dot operator
     svar.c = 'a';
     var.i = 1;
     svar.j = 2;     //or the same variable could be access in the following way, using address
     // of operator and arrow operator
     (&svar)->c = 'c';
     (&svar)->i = 3;
     (&svar)->j = 4;
  
     return 0;
   }
   ```
   * Passing structure pointer variable
   ```
   // struct12.c
   struct node {
    int data;
    char c;
   };
   int main() {
    struct node v1;
    struct node *p1 = &v1;
    foo_passbyvalue(v1);
    foo_passbyaddr(p1);
  }
  void foo_passbyvalue(struct node v) {
    //do something
  }
  void foo_passbyaddr(struct node *p) {
    //do something
  }
  ```
  ```
  // struct13.c
  struct node {
    int data;
  };
  void addnode(struct node *n1) {
    n1 = (struct node *)malloc(sizeof(struct node));
    n1->data = 9;
  }
  int main( int argc, char *argv[]) {
    struct node *n1 = NULL;
    addnode(n1);

    return 0;
  }
  ```
  ```
  // struct14.c
  struct node {
    int data;
  };
  void addnode( structure node **n1) {
    *n1 = (struct node *)malloc(sizeof(struct node));
    (*n1)->data = 9;
  }
  int main( int argc, char *argv[]) {
    struct node *n1 = NULL;
    addnode(&n1);

    return 0;
  }
  ```
  * Type casting structure pointers
  ```
  // struct15.c
  int main() {
    struct signature {
      char sign;
      char version;
    };
    struct id {
      char id;
      char platform;
    };
    struct data {
      struct signature sig;
      struct id idv;
      char data[100];
    };
    struct data *img;
    receivedata(img);
    struct signature *sign = extractsignature(&img);
    struct id *idval = extractid(&img);
  }
  struct signature *extractsignature( struct data *d) {
    struct signature *sig = (struct signature *)d;
    return sig;
  }
  struct id *extracted( struct data *d) {
    struct id *idv = (struct id *)d;
    return idv;
  }
  ```
  * Self-referential structures
  ```
  struct node {
    int data;
    struct node * self;
  }
  ```
* Data structure and algorithms
   * linked lists  
   ![image](https://github.com/user-attachments/assets/e0f2b57b-f17f-4408-94e2-1dbf85dca21e)
   ```
   // struct16.c
   #include <malloc.h>
   #include <stdio.h>
   struct node {
     int data;
     struct node *next;
   };
   struct node *createnode(int data) {
     struct node *n1 = (struct node *)malloc(sizeof(struct node));
     n1->data = data;
     n1->next = NULL;
   
     return n1;
   }
   void addatend(struct node **root, struct node *n) {
     struct node *temp = *root;
     if( temp == NULL)
       *root = n;
     else {
       while(temp->next != NULL)
         temp = temp->next;
       temp->next = n;
     }
   }
   int main( int argc, char *argv[]) {
     struct node *root = NULL;
     for( int i=0; i<10; i++)
       addatend(&root, createnode(i));
     return 0;
   }
   ```
   * Binary search tree  
   ![image](https://github.com/user-attachments/assets/0d2ec1e9-b29a-402f-b55e-97c9e0183ef7)
   ```
   struct node {
     int data;
     struct node *left;
     struct node *right;
   };
   ```
   * Creation of a BST
   ```
   // struct17.c
   #include <string.h>
   #include <malloc.h>
   #include <stdio.h>
   struct node {
     int data;
     struct node *left;
     struct node *right;
   };
   struct node *createnode(int dadta) {
     struct node *n1 = (struct node *)malloc(sizeof(struct node));
     n1->data = data;
     n1->left = NULL;
     n1->right = NULL;

     return n1;
   }
   void insertnode( struct node **root, struct node *n) {
     struct node *temp = *root;
     if( temp == NULL) {
       *root = n;
     } else {
       if(n->data < temp->data) {
         insertnode( &(temp->left), n);
       } else if { n->data > temp->data) {
         insertnode( &(temp->right), n);
       }
     }
   }
   int main( int argc, char *argv[]) {
     struct node *root = NULL;
     for( int i=0; i<10; i++) {
       insertnode( &root, createnode(i));
     }
     return 0;
   }
   ```
* Chapter 7: Function Pointers
   * Initializing function pointers
   ```
   // fptr1.c
   #include <malloc.h>
   #include <stdio.h>
   void mesg( int num) {
     printf("Mesg no. %d\n", num);
   }
   int * add(int x, int y) {
     int *z = (int *)malloc(sizeof(int));
     *z = 10;
     return z;
   }
   int main( int argc, char *argv[]) {
     int *t;
     void (*fpmsg)(int);          //function pointer variable to point to the function "mesg"
     int *(*addfptr)(int, int);   //function pointer variable to point to the function "add"
     addfptr = &add;              //assignment using "address of" operator
     fpmsg = mesg;                //assignment using implicit method

     return 0;
   }
   ```
   * Using function pointers
   ```
   // fptr2.c
   #include <malloc.h>
   #include <stdio.h>
   void mesg( int num) {
     printf("Mesg no. %d\n", num);
   }
   int main(int argc, char *argv[]) {
     int *t;
     void (*fpmsg1)(int);  //function pointer variable to point to the function "mesg"
     void (*fpmsg2)(int);  //function pointer variable to point to the function "mesg"
     fpmsg1 = mesg;
     fpmsg2 = mesg;
     fpmsg1(10);           // implicit method of invoking a function
     (*)fpmsg2(20);        // explicit way of invoking a function

     return 0;
   }
   ```
   ```
   // fptr3.c
   bool arraysearch(int data) {
     //some code
     return true;
   }
   bool linkedlistsearch(int data) {
     //some code
     return true;
   }
   bool binarysearch(int data) {
     //some code
     return true;
   }
   bool search( bool (*funcptr)( int ), int data ) {
     return (*funcptr)(data);
   }
   int main(int argc, char* argv[]) {
     printf("Input Options\n");
     printf("1 arrsrch\n");
     printf("2 linkedlistsrch\n");
     printf("3 binarysrch\n");
     printf("4 exit\n");
   
     int choice = 0;
     int data;
     while(choice != 4) {
       printf("Input\n");
       scanf("%d", &choice);
       printf("Data to search\n");
       scanf("%d", &data);
       if(choice == 1) {
         search(arraysearch,data);       //invoking 1st function
       } else if(choice == 2) {
         search(linkedlistsearch, data); //invoking 2nd function
       } else if(choice == 3) {
         search(binarysearch, data);     //invoking  3rd function
       } else if(choice == 4)
          break;
      }
     return 0;
   }
   ```
   * Array of function pointers
   ```
   // fptr4.c
   int myadd( int a, int b) {
     int z = a + b;
     return z;
   }
   int mysub(int a, int b) {
     int z = a - b;
     return z;
   }
   int mymul(int a, int b) {
     int z = a*b;
     return z;
   }
   int mydiv(int a, int b) {
     int z = a/b;
     return z;
   }
   //array of function pointers,
   int (* opfunctptr [ ] ) ( int x, int y) = { myadd, mysub, mymul, mydiv };
   typedef int (*calc)(int x, int y );
   //function returning the function pointer of type int (*calc)(int x, int y )
   calc retmathfunc(int index) {
     return opfunctptr[index];
   }
   int main(int argc, char* argv[]) {
     int choice, p1, p2, res;
     int (*calculator)(int x, int y);
     printf("Type -1 to quit\n");
     printf("Type 0 - add, 1 - sub, 2 - mul, 3 - div\n");
     scanf("%d", &choice);
     while( choice != -1) {
       calculator = retmathfunc(choice); //returns function pointer
       printf("Param1\n");
       scanf("%d", &p1);
       printf("Param2\n");
       scanf("%d", &p2);
       res = calculator(p1, p2);         //calling function pointer
       printf("res = %d\n", res);
       printf("Type 0 - add, 1 - sub, 2 - mul, 3 - div\n");
       scanf("%d", &choice);
     }
     return 0;
   }
   ```
* Chapter 8: [Pointers to File I/O](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Pointer_in_C/README.md)
