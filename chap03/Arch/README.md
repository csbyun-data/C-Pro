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
  char *Arctypes[] -> const char *Arctypes[]
  char *fingerprint; ->   const char *fingerprint;
  Archive (long offs, char *fp, int t = UNKNOWN, int t2 = UNKNOWN) :
           offset (offs), fingerprint (fp), type(t), sfxtype (t2) { };
  -> Archive (long offs, const char *fp, int t = UNKNOWN, int t2 = UNKNOWN) :
           offset (offs), fingerprint (fp), type(t), sfxtype (t2) { };
  LhaArchive (long offs, char *fp) : Archive (offs, fp) { };
  -> LhaArchive (long offs, const char *fp) : Archive (offs, fp) { };
  char *p; ->   const char *p;
  ```
  
  
