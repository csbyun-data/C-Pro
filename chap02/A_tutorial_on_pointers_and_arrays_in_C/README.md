### A tutorial on pointers and arrays in C
* INDEX
  * Contents
  ```txt
  TABLE OF CONTENTS
  PREFACE 2
  INTRODUCTION 4
  CHAPTER 1: What is a pointer? 5
  CHAPTER 2: Pointer types and Arrays 9
  CHAPTER 3: Pointers and Strings 14
  CHAPTER 4: More on Strings 19
  CHAPTER 5: Pointers and Structures 22
  CHAPTER 6: Some more on Strings, and Arrays of Strings 26
  CHAPTER 7: More on Multi-Dimensional Arrays 30
  CHAPTER 8: Pointers to Arrays 32
  CHAPTER 9: Pointers and Dynamic Allocation of Memory 34
  CHAPTER 10: Pointers to Functions 42
  EPILOG 53
  ```
  * Pdf file [[here](https://github.com/csbyun-data/C-Pro/blob/main/chap02/A%20tutorial%20on%20pointers%20and%20arrays%20in%20c.pdf)]
  * Code [[github.com/jflaherty/ptrtut13](https://github.com/jflaherty/ptrtut13)]

* Chap01. What is a pointer?
  * sizeof [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/A_tutorial_on_pointers_and_arrays_in_C/sizeof.c)
  
  ![image](https://github.com/user-attachments/assets/6d5520f3-de4a-46b6-93c1-ebf4b14b0007)

* Chap02. Pointer types and Arrays
  * Arrays and Pointer [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/A_tutorial_on_pointers_and_arrays_in_C/pointer_arrays.c)
  ```c
  int my_array[] = {1, 23, 17, 4,- 5, 100};
  int *ptr;
  //...
  ptr = &my_array[0];     /* point our pointer to the first
                             element of the array */
  my_array[i] // 동일 표현 *(ptr + i)
  ```
  ![image](https://github.com/user-attachments/assets/abadf6f7-a62d-4a52-95ee-2a3667a99094)

* Chap3. Pointers and Strings
  * Pointers and Strings [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/A_tutorial_on_pointers_and_arrays_in_C/pointers_strings.c)
  ```c
  char strA[80] = "A string to be used for demonstration purposes";
  char strB[80];
  //..
  char *pA;     /* a pointer to type character */
  char *pB;     /* another pointer to type character */
  
  pA = strA;    /* point pA at string A */
  pB = strB;    /* point pB at string B */
  
  while(*pA != '\0') {
    *pB++ = *pA++;
  }
  *pB = '\0';
  ```
  ![image](https://github.com/user-attachments/assets/a6fe3402-d925-4703-9a50-80df50342c14)
  ```
  // String Copy
  char strA[80] = "A string to be used for demonstration purposes";
  char strB[80];
    
  char *my_strcpy(char *destination, char *source) {
    char *p = destination;
    while (*source != '\0') {
      *p++ = *source++;
    }
    *p = '\0';
  
    return destination;
  }
  
  int main(void) {
    my_strcpy(strB, strA);
    puts(strB);
  }
  ```
  
* Chap4. More on Strings
  * my_strcpy() function
  ```
  // 동일 표현 char *my_strcpy(char *destination, char *source)
  char *my_strcpy(char dest[], char source[]) {
    int i = 0;
  
    while (source[i] != '\0') {
      dest[i] = source[i];
      i++;
    }
    dest[i] = '\0';
  
    return dest;
  }
  ```
  
* Chap5. Pointers and Structures
  * Structures [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/A_tutorial_on_pointers_and_arrays_in_C/structure.c)
  ```c
  struct tag {
    char lname[20];      /* last name */
    char fname[20];      /* first name */
    int age;             /* age */
    float rate;          /* e.g. 12.75 per hour */
  };
  
  struct tag my_struct;       /* declare the structure my_struct */
  //..
  strcpy(my_struct.lname,"Jensen");
  strcpy(my_struct.fname,"Ted");
  printf("\n%s ",my_struct.fname);
  printf("%s\n",my_struct.lname);
  ```  
  ![image](https://github.com/user-attachments/assets/a9a66821-66f7-47c3-8388-30e081bf6ef8)

  * Pointers and Structures [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/A_tutorial_on_pointers_and_arrays_in_C/pointers_structures.c)
  ```c
  struct tag{                     /* the structure type */
    char lname[20];             /* last name */
    char fname[20];             /* first name */
    int age;                    /* age */
    float rate;                 /* e.g. 12.75 per hour */
  };
  
  struct tag my_struct;           /* define the structure */
  void show_name(struct tag *p);  /* function prototype */
  //..
   struct tag *st_ptr;         /* a pointer to a structure */
   st_ptr = &my_struct;        /* point the pointer to my_struct */
 
   strcpy(my_struct.lname,"Jensen");
   strcpy(my_struct.fname,"Ted");
   my_struct.age = 63;
  
   show_name(st_ptr);          /* pass the pointer */
  //..
  
  void show_name(struct tag *p) {
    printf("\n%s ", p->fname);  /* p points to a structure */
    printf("%s ", p->lname);
    printf("%d\n", p->age);
  }
  ```

* Chap6. Some more on Strings, and Arrays of Strings
  * integer arrays [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/A_tutorial_on_pointers_and_arrays_in_C/integer_arrays.c)
  ```c
  #define ROWS 5
  #define COLS 10
  int multi[ROWS][COLS];
  
  multi[row][col] = row*col;
  printf("\n%d ",multi[row][col]); // 동일표현 *(*(multi + row) + col)
  ```

* Chap7. More on Multi-Dimensional Arrays
  ```c
  #define ROWS 5
  #define COLS 10
  int multi[ROWS][COLS];

  void set_value(int m_array[][COLS]) {
    int row, col;
    for (row = 0; row < ROWS; row++) {
      for (col = 0; col < COLS; col++) {
        m_array[row][col] = 1;
      }
    }
  }
  set_value(multi);
  ```

* Chap8. Pointers to Arrays 
  ```c
  int *ptr;
  ptr = &my_array[0]; /* point our pointer at the first
                         integer in our array */
  int array[3] = {'1', '5', '7'};
  void a_func(int *p); // 동일 표현 void a_func(int p[]);
  
  typedef unsigned char byte;
  byte b[10]; would be an array of unsigned characters

  int (*p1d)[10]; // 10개의 정수 배열을 가르키는 포인터
  int *p1d[10];   // 10개의 포인터 배열
  ```

* Chap9 Pointers and Dynamic Allocation of Memory
  * malloc() function
  ```c
  int *iptr;
  iptr = (int *)malloc(10 * sizeof(int));

  if (iptr == NULL) { .. ERROR ROUTINE GOES HERE .. }
  int k;
  for (k = 0; k < 10; k++)
    iptr[k] = 2;
  ```
  * Method 1 1D [[malloc one demension code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/A_tutorial_on_pointers_and_arrays_in_C/mallc_one_demension.c)]
  ```c
  multi[row][col] = 1; *(*(multi + row) + col) = 1;

  multi[row] *(multi + row)
  ```
  * Method 2
  ```c
  int (*xptr)[COLS]; // int Arr[COLS]를 가르키는 포인터
  int *xptr[COLS];   // int *xptr 배열 COLS개
  ```
  * Method 3 2D [[malloc two dememsion code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/A_tutorial_on_pointers_and_arrays_in_C/malloc_two_demension.c)]  
  ![image](https://github.com/user-attachments/assets/cbd38104-ffb5-4709-886b-76a30ced892c)

  * Method 4 2D [[malloc two demension2 code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/A_tutorial_on_pointers_and_arrays_in_C/malloc_two_demension2.c)]  
  ![image](https://github.com/user-attachments/assets/d1d0b8f3-8789-4f47-88e0-b4d38f58b535)

  * Method 5 3D [[malloc three demenstion code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/A_tutorial_on_pointers_and_arrays_in_C/malloc_three_demension.c)]  
  ![image](https://github.com/user-attachments/assets/e414a4aa-c406-4b53-bb04-95f8f4e3bbc1)

* Chap10. Pointers to Functions
  * bubble sort 1 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/A_tutorial_on_pointers_and_arrays_in_C/bubble_sort1.c)
  ```c
  int arr[10] = { 3,6,1,2,3,8,4,1,7,2};
  void bubble(int a[], int N);
  //..
  bubble(arr,10);
  ```
  ![image](https://github.com/user-attachments/assets/1edd559a-6e2d-456d-bcfe-b34f143a8718)

  * bubble sort 2 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/A_tutorial_on_pointers_and_arrays_in_C/bubble_sort2.c)
  ```c 
  void bubble(int a[], int N);
  int compare(int m, int n);

  bubble(arr,10);

  void bubble(int a[], int N) {
    //..
    if (compare(a[j-1], a[j])) {}
    //..
  }
  int compare(int m, int n) {
    return (m > n);
  }
  ```
  * bubble sort 3 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/A_tutorial_on_pointers_and_arrays_in_C/bubble_sort3.c)
  ```c
  void bubble(int *p, int N);
  int compare(int *m, int *n);
  
  bubble(arr,10);
  void bubble(int *p, int N) {
    //..
    if (compare(&p[j-1], &p[j])) {}
    //..
  }
  int compare(int *m, int *n) {
    return (*m > *n);
  }
  ```

  * bubble sort 4 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/A_tutorial_on_pointers_and_arrays_in_C/bubble_sort4.c)
  ```c
  void bubble(int *p, int N);
  int compare(void *m, void *n);

  bubble(arr,10);
  void bubble(int *p, int N) {
    //..
    if (compare((void *)&p[j-1], (void *)&p[j])) {}
    //..
  }
  int compare(void *m, void *n) {
    int *m1, *n1;
    m1 = (int *)m;
    n1 = (int *)n;
  
    return (*m1 > *n1);
  }
  ```
  * bubble sort 5 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/A_tutorial_on_pointers_and_arrays_in_C/bubble_sort5.c)
  ```c
  void bubble(void *p, size_t width, int N);
  int compare(void *m, void *n);
  
  bubble(arr, sizeof(long), 10);
  void bubble(void *p, size_t width, int N) {
    //..
    if (compare((void *)(bp + width*(j-1)), (void *)(bp + j*width))){}
    //..
  }
  int compare(void *m, void *n) {
    long *m1, *n1;
    m1 = (long *)m;
    n1 = (long *)n;
  
    return (*m1 > *n1);
  }
  ```
  * bubble sort 6 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/A_tutorial_on_pointers_and_arrays_in_C/bubble_sort6.c)
  ```c
  char arr2[5][20] = { "Mickey Mouse",
                       "Donald Duck",
                       "Minnie Mouse",
                       "Goofy",
                       "Ted Jensen" };
  void bubble(void *p, int width, int N);
  int compare(void *m, void *n);

  bubble(arr2, 20, 5);
  void bubble(void *p, int width, int N) {
    //..
    k = compare((void *)(bp + width*(j-1)), (void *)(bp + j*width));
    //..
  }
  int compare(void *m, void *n) {
    char *m1 = m;
    char *n1 = n;
    return (strcmp(m1,n1));
  }
  ```
  * bubble sort 7 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/A_tutorial_on_pointers_and_arrays_in_C/bubble_sort7.c)
  ```c
  long arr[10] = { 3,6,1,2,3,8,4,1,7,2};
  char arr2[5][20] = { "Mickey Mouse",
                       "Donald Duck",
                       "Minnie Mouse",
                       "Goofy",
                       "Ted Jensen" };
  void bubble(void *p, int width, int N, int(*fptr)(const void *, const void *));
  int compare_string(const void *m, const void *n);
  int compare_long(const void *m, const void *n);

  bubble(arr, 4, 10, compare_long); /* sort the longs */
  bubble(arr2, 20, 5, compare_string); /* sort the strings */
  void bubble(void *p, int width, int N, int(*fptr)(const void *, const void *)) {
    //..
    k = fptr((void *)(bp + width*(j-1)), (void *)(bp + j*width));
    //..
  }
  int compare_string(const void *m, const void *n) {
    char *m1 = (char *)m;
    char *n1 = (char *)n;
  
    return (strcmp(m1,n1));
  }
  int compare_long(const void *m, const void *n) {
    long *m1, *n1;
    m1 = (long *)m;
    n1 = (long *)n;
  
    return (*m1 > *n1);
  }  
  ```
  ![image](https://github.com/user-attachments/assets/0a183fe9-10df-49c9-9ff5-7b7134cbe9c1)

  
