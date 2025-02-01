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

  * Pointers and Structures [code]()
  




