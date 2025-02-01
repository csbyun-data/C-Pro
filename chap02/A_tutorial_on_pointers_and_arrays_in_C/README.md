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

* Chap01 What is a pointer?
  * sizeof [code](https://github.com/csbyun-data/C-Pro/blob/main/chap02/A_tutorial_on_pointers_and_arrays_in_C/sizeof.c)  
  ![image](https://github.com/user-attachments/assets/6d5520f3-de4a-46b6-93c1-ebf4b14b0007)

* Chap02 Pointer types and Arrays
  * Arrays and Pointer
  ```c
  int my_array[] = {1, 23, 17, 4,- 5, 100};
  int *ptr;
  //...
  ptr = &my_array[0];     /* point our pointer to the first
                             element of the array */
  my_array[i] // 동일 표현 *(ptr + i)
  ```
