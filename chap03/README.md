
## FILE I/O
### Index
* 1.File I/O ([참조: aticleworld.com/file-handling-in-c](https://aticleworld.com/file-handling-in-c/))
  *   1.1 변수, 상수, 자료형, 비트 연산
  *   1.2 조건문, 반복문
  *   1.3 배열, 문자열
  *   1.4 Type Casting
  
* 2.XML response in C without using library
([참조: aticleworld.com/parse-xml-response-in-c/](https://aticleworld.com/parse-xml-response-in-c/))
  *   2.1 Create XML [here](https://github.com/csbyun-data/C-Programming/blob/main/chap03/XML/Create_XML_ex1.c)
  *   2.2 Parse XML [here](https://github.com/csbyun-data/C-Programming/blob/main/chap03/XML/Parse_XML_ex1.c)
  ```c
  //Create Opening Tag
  memset(openTag, 0, sizeof(openTag));
  strcpy(openTag, "<");
  strcat(openTag, pTag);
  strcat(openTag, ">");

  //Create Closing tag
  memset(closeTag, 0, sizeof(closeTag));
  strcpy(closeTag, "</");
  strcat(closeTag, pTag);
  strcat(closeTag, ">");
  ```
  ```c
  //Get Opening tag position
  for (pos=0; pos<len; pos++) {
    if ( !memcmp(openTag,pResBuf+pos,lenOpenTag)) {
        posOpenTag = pos;
        break;
    }
  }

  //Get closing tag position
  for (pos=0; pos<len; pos++) {
    if ( !memcmp(closeTag,pResBuf+pos,lenCloseTag) ) {
        posClosingTag = pos;
        break;
    }
  }
  ```
  ```c
  if ( (posOpenTag !=0) && (posClosingTag !=0) ) {
    const int lenTagVal = posClosingTag-posOpenTag-lenOpenTag;
    char *pStartPosTagVal = pResBuf+posOpenTag+lenOpenTag;
    if (lenTagVal) {
        //Get tag value
        memcpy(pTagValue,pStartPosTagVal, lenTagVal);
        if (strlen(pTagValue)) {
            return 1;
        }
    }
  }
  ```
