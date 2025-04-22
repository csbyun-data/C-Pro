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
    ```
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
    
    

    
    
    
    

