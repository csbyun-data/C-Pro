##  05. File Handling in C
### Index

* 1.File handling function
  * 1.1 Library management system project (File handling) ([here](https://github.com/csbyun-data/C-Pro/blob/main/chap05/File/Library_Management_system.md))
  * 1.2 Student Record System (File handling) ([here](https://github.com/csbyun-data/C-Pro/blob/main/chap05/File/Student_Record_System.md))
  * 1.3 Employee Record System (File handling) ([here](https://github.com/csbyun-data/C-Pro/blob/main/chap05/File/Employee_Record_System.md))
  * 1.4 Linked List를 이용한 주소록 관리 ([code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/File/Address_Mgr.c))
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
* 2.XML Parser [here](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XML_Parser/README.md)
  * 2.1 XML File 화면 출력
  * 2.2 XML 내용 조회 구현
  * 2.3 XML 파일 속성 조회
  * 2.4 XML 파일 형식 변경 조회
  * 2.5 XML 파일 형식 변경 분석
  * 2.6 XML 주석문 분석시 제외
  * 2.7 속성을 읽어들여 출력
  * 2.8 XML version, encoding 얻기
  * 2.9 tag의 끝이 />로 마무리 되는 inline node
  * 2.10 dummy tag분석 제외
  * 2.11 XMLDocument_write(), XML문서 생성

* 3.수식 계산 프로그램 [here](https://github.com/csbyun-data/C-Pro/blob/main/chap05/Calc/README.md)
  * 3.1 계산기 프로그램
  * 3.2 함수 포인터를 배열에 넣어 가감 계산
  * 3.3 함수 포인터를 구조체에 넣어 가감 계산
  * 3.4 사칙연산 함수를 STL을 이용하여 표현
  * 3.5 재귀호출 계산기
  * 3.6 Infix to Postfix, Infix to Prefix

* 4. XLISP 계산식 분석
  * 4.1  사칙연산 계산 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XLISP/Calc1.c)
     
