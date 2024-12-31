### XML response in C without using library
* XML response in C without using library
    * Reference [parse-xml-response-in-c](https://aticleworld.com/parse-xml-response-in-c/) 
    * Create XML [code](https://github.com/csbyun-data/C-Pro/blob/main/chap03/XML/Create_XML_ex1.c)
    * Parse XML [code](https://github.com/csbyun-data/C-Pro/blob/main/chap03/XML/Parse_XML_ex1.c)
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
