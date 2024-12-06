##  05. File Handling in C

### Index

* 1.File handling function
  * 1.1 Library management system project (File handling) ([here](https://github.com/csbyun-data/C-Pro/blob/main/chap05/File/Library_Management_system.md))
  * 1.2 Student Record System (File handling) ([here](https://github.com/csbyun-data/C-Pro/blob/main/chap05/File/Student_Record_System.md))
  * 1.3 Employee Record System (File handling) ([here](https://github.com/csbyun-data/C-Pro/blob/main/chap05/File/Employee_Record_System.md))
  * 1.4 Linked List를 이용한 주소록 관리 [code]()
  ```c
  //#define ADDRFILE		"c:\\addrlist.txt"  c:폴더에 파일 생성 Error!
  #define ADDRFILE		".\\addrlist.txt"

  //void main( void )  리턴값 void -> int로 변경
  int main( void )
  //Remove_addr(); return; 리턴값 void -> int로 변경
  Remove_addr(); return 0;

  //main함수 마지막 부분 추가
  return 0;

  //plocal = malloc( sizeof(ADDR) );	// ADDR 구조체 할당
  plocal = (ADDR *)malloc( sizeof(ADDR) );	// ADDR 구조체 할당
  ```
* 2.aa
