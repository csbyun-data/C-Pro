### Extensible C & C++ determine which archiver was used on a packed file
* Function to determine archive types
  * Archive
  ```
  |=============================================================================
  | Extensible C & C++ determine which archiver was used on a packed file
  |=============================================================================
  | File         O/S  Description
  | ------------ ---  ----------------------------------------------------------
    Whicharc.Doc n/a  Information about archive detection
    Whicharc.H   any  Prototype declarations for WHICHARC.CPP
    Whicharc.Cpp any  Function to determine archive types
    Archive.Hpp  any  Declaration of extensible archive classes
  * Archive.Cpp  any  Archive class member functions
  ```
  * [code], [whicharc.cpp](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Arch/whicharc.cpp), [whicharc.h](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Arch/whicharc.h), [archive.cpp](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Arch/archive.cpp), [archive.hpp](https://github.com/csbyun-data/C-Pro/blob/main/chap03/Arch/whicharc.hpp)
  ```
  [Warning] deprecated conversion from string constant to 'char*' [-Wwrite-strings]
  char * -> const char * 로 변경

  > chcp 437
  > rename file.zip file.abc
  > whicharc file.abc
  ```
  ![image](https://github.com/user-attachments/assets/7422b5a1-ed70-4011-87fb-eeb050663d21)

  
  
