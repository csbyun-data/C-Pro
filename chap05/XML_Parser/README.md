### XML Parser
* 1.XML file load 화면 출력 기능 구현
    * main.c file 생성
    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include "lxml.h"

    int main(int argc, char *argv[])
    {
      XMLDocument doc;
    
      if (XMLDocument_load(&doc, "test.xml")) {
        printf("%s\n", doc.source);
        XMLDocument_free(&doc);
      }
      return 0;
    }
    ```
    * lxml.h file 생성
    ```c
    # include <stdbool.h>
    bool XMLDocument_load(XMLDocument *doc, const char *path);

    bool XMLDocument_load(XMLDocument *doc, const char *path) {
      FILE* file = fopen(path, "r");
      if (!file) {
        fprintf(stderr, "Could not load file from '%s'\n", path);
        return false;
      }
        //.......................................
      return true;
    }
    ```
    * test.xml file 생성
    ```txt
    <root>I am a root </root>
    ```
  
    * lxml.h XMLDocument_load() 기능 작업  
    ![image](https://github.com/user-attachments/assets/b0682e0a-6f0d-4c43-b8b4-22fec94674db)

    ```
    #pragma once
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>

    // Definitions

    struct _XMLDocument {
      char *source;
    };
    typedef struct _XMLDocument XMLDocument;

    bool XMLDocument_load(XMLDocument *doc, const char *path);
    void XMLDocument_free(XMLDocument *doc);

    // Implementation
    bool XMLDocument_load(XMLDocument *doc, const char *path) {
      FILE *file = fopen(path, "r");
      if (!file) {
        fprintf(stderr, "Could not load file from '%s'\n", path);
        return false;
      }
      fseek(file, 0, SEEK_END);
      int size = ftell(file);
      fseek(file, 0, SEEK_SET);
  
      doc->source = (char *)malloc(sizeof(char) * size * 1);
      fread(doc->source, 1, size, file);
      fclose(file);
      doc->source[size] = '\0';
  
      return true;
    }

    void XMLDocument_free(XMLDocument *doc) { }
    ```
    ![image](https://github.com/user-attachments/assets/c4ca3118-abc6-4c5a-a446-8e6be19e80c9)

* 2.XML 내용 조회 구현
    * main.c 프로그램 수정
    ```c
    #include <stdio.h>
    #include <stdlib.h>

    #include "lxml.h"

    int main(int argc, char *argv[])
    {
      XMLDocument doc;
      if (XMLDocument_load(&doc, "test.xml")) {
        printf("%s: %s\n", doc.root->tag, doc.root->inner_text); //수정된 부분
        XMLDocument_free(&doc);
      }
      return 0;
    }
    ```
    * lxml.h 프로그램 수정  
    ![image](https://github.com/user-attachments/assets/8bd0e95e-7af5-45ad-a629-4eb0d8c50666)

    ```c
    #pragma once
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #include <stdbool.h>

    // Definitions
    struct _XMLNode {
      char *tag;
      char *inner_text;
      struct _XMLNode *parent;
    };
    typedef struct _XMLNode XMLNode;

    XMLNode *XMLNode_new(XMLNode *parent);
    void XMLNode_free(XMLNode *node);

    struct _XMLDocument {
      XMLNode *root;
    };
    typedef struct _XMLDocument XMLDocument;

    bool XMLDocument_load(XMLDocument *doc, const char *path);
    void XMLDocument_free(XMLDocument *doc);

    // Implementation
    XMLNode *XMLNode_new(XMLNode *parent) {
      XMLNode *node = (XMLNode *)malloc(sizeof(XMLNode));
      node->parent = parent;
      node->tag = NULL;
      node->inner_text = NULL;
      return node;
    }

    void XMLNode_free(XMLNode *node) {
      if (node->tag)
        free(node->tag);
      if (node->inner_text)
        free(node->inner_text);
    }

    bool XMLDocument_load(XMLDocument *doc, const char *path) {
      FILE *file = fopen(path, "r");
      if (!file) {
        fprintf(stderr, "Could not load file from '%s'\n", path);
        return false;
      }
      fseek(file, 0, SEEK_END);
      int size = ftell(file);
      fseek(file, 0, SEEK_SET);

      char *buf = (char *)malloc(sizeof(char) * size * 1);
      fread(buf, 1, size, file);
      fclose(file);
      buf[size] = '\0';

      doc->root = XMLNode_new(NULL);

      char lex[256];
      int lexi = 0;
      int i = 0;

      XMLNode *curr_node = NULL;

      while (buf[i] != '\0')	{
        if (buf[i] == '<') {
          lex[lexi] = '\0';

          // Inner text
          if (lexi > 0) {
            if (!curr_node) {
              fprintf(stderr, "Text outside of document\n");
              return false;
            }

            curr_node->inner_text = strdup(lex);
            lexi = 0;
          }

          // End of node
          if (buf[i + 1] == '/') {
            i += 2;
            while (buf[i] != '>')
              lex[lexi++] = buf[i++];
            lex[lexi] = '\0';
            if (!curr_node) {
              fprintf(stderr, "Already at the root\n");
              return false;
            }
            if (strcmp(curr_node->tag, lex)) {
              fprintf(stderr, "Mismatched tags (%s !=%s)", curr_node->tag, lex);
              return false;
            }

            curr_node = curr_node->parent;
            i++;
            continue;
           }

          // Set current node
          if (!curr_node)
            curr_node = doc->root;
          else
            curr_node = XMLNode_new(curr_node);

          // Get tag name
          i++;
          while (buf[i] != '>')
            lex[lexi++] = buf[i++];
          lex[lexi] = '\0';
          curr_node->tag = strdup(lex);

          // Reset lexer
          lexi = 0;
          i++;
          continue;
        }	else {
          lex[lexi++] = buf[i++];
        }
      }
      return true;
    }

    void XMLDocument_free(XMLDocument *doc) {
      XMLNode_free(doc->root);  //수정 Source
    }
    ```
    ![image](https://github.com/user-attachments/assets/452b65a7-6832-4606-bc43-0a71d5262814)

* 3.XML 파일 속성 조회
    * test.xml 파일 속성 조회 예제 형식으로 수정
    ```xml
    <root key="value" another="one more">I am a root</root>
    ```
    * main.c 파일 수정
    ```c
    #include <stdio.h>
    #include <stdlib.h>

    #include "lxml.h"

    int main(int argc, char *argv[])
    {
      XMLDocument doc;
      if (XMLDocument_load(&doc, "test.xml")) {
        XMLNode node = *doc.root;
  
        printf("Attributes:\n");
        for (int i = 0; i < node.attributes.size; i++) {
          XMLAttribute attr = node.attributes.data[i];
          printf(" %s => \"%s\"\n", attr.key, attr.value);
        }
        XMLDocument_free(&doc);
      }
      return 0;
    }
    ```
    ![image](https://github.com/user-attachments/assets/2d9e4a62-8c13-4aef-9231-18cea310b0bd)

    * lxml.h 파일 수정 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XML_Parser/lxml3_3.h)  
    ![image](https://github.com/user-attachments/assets/a4247c78-0ade-4588-a8d6-f9ee51149ec6)

* 4.XML 파일 형식 변경 조회
    * test.xml 파일 내용
    ```xml
    <root>
      <inner>
        <more> This is nested node</more>
      </inner>
      <another>This is another node</another>
    </root>
    ```
    * main.c 파일 변경
    ```c
    #include <stdio.h>
    #include <stdlib.h>

    #include "lxml.h"

    int main(int argc, char *argv[])
    {
      XMLDocument doc;
      if (XMLDocument_load(&doc, "test.xml")) {
        XMLNode* more_node = XMLNode_child(XMLNode_child(doc.root, 0), 0);
        printf("%s: %s\n", more_node->tag, more_node->inner_text);
  
        XMLNode* another_node = XMLNode_child(doc.root, 1);
        printf("%s: %s\n", another_node->tag, another_node->inner_text);
  
        XMLDocument_free(&doc);
      }
      return 0;
    }
    ```
    ![image](https://github.com/user-attachments/assets/dc835f20-5157-4bfc-b592-7547bb999f92)

    * lxml.h 파일 수정 작업 [code](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XML_Parser/lxml4_3.h)  
    ![image](https://github.com/user-attachments/assets/e67b3e0f-711b-40ca-a4b4-6f80facfb0b9)

* 5.XML 파일 형식 변경 분석
    * test.xml
    ```xml
    <main>
      <inner>
        <more> This is nested node</more>
      </inner>
      <another>This is another node</another>
    </main>
    <another> This should work too</another>
    ```
    * main.c 파일 수정
    ```c
    #include <stdio.h>
    #include <stdlib.h>

    #include "lxml.h"

    int main(int argc, char *argv[])
    {
      XMLDocument doc;
      if (XMLDocument_load(&doc, "test.xml")) {
        XMLNode* main_node = XMLNode_child(doc.root, 0);
        printf("%d children\n", main_node->children.size);
  
        XMLNode* another_node = XMLNode_child(doc.root, 1);
        printf("%s\n", another_node->inner_text);
  
        XMLDocument_free(&doc);
      }
      return 0;
    }
    ```
    * lxml.h 파일 수정
    ```c
		bool XMLDocument_load(XMLDocument* doc, const char* path) {
			XMLNode* curr_node = doc->root; //<-- NULL을 doc->root로 수정함
		}
    ```  
    ![image](https://github.com/user-attachments/assets/3c2cebc9-075a-4ec9-97f4-8df571936108)
    
* 6.주석문 XML분석시 제외
    * test.xml 문서 수정
    ```xml
    <!-- This is a comment-->
    <car type="couple">
    	<!-- This is a comment-->
    	<description> This is a really cool description</description>
    </car>
    ```
    * main.c 파일 수정
    ```c
		#include <stdio.h>
		#include <stdlib.h>
	
		#include "lxml.h"
	
		int main(int argc, char *argv[])
		{
	
			XMLDocument doc;
			if (XMLDocument_load(&doc, "test.xml")) {
				XMLNode* main_node = XMLNode_child(doc.root, 0);
				printf("%d children\n", main_node->children.size);
			
				XMLNode* desc = XMLNode_child(main_node, 0);
				printf("%s\n", desc->inner_text);
			
				XMLDocument_free(&doc);
			}
			return 0;
		}
    ```
    * lxml.h 파일 수정
    ```
    // ends_with 함수 추가
    int ends_with(const char *haystack, const char *needle) {
    	int h_len = strlen(haystack);
    	int n_len = strlen(needle);

    	if (h_len < n_len)
    		return FALSE;

    	for (int i = 0; i < n_len; i++)
    		if (haystack[h_len - n_len + i] != needle[i])
    			return FALSE;

    	return TRUE;
    }

    bool XMLDocument_load(XMLDocument *doc, const char *path) {
			XMLNode *curr_node = doc->root;
	
			while (buf[i] != '\0') 	{
				// End of node
				//Special nodes  주석 제외 Source 추가
				if (buf[i + 1] == '!') {
					while ( buf[i] != ' ' && buf[i] != '>')
						lex[lexi++] = buf[i++];
				lex[lexi] = '\0';
						
				// Comments
				if (!strcmp(lex, "<!--")) {
					lex[lexi] = '\0';
					while(!ends_with(lex, "-->")) {
						lex[lexi++] = buf[i++];
						lex[lexi] = '\0';
					}
					//i++
					continue;
				}
			}
			// Set current node
    }
    ```
    ![image](https://github.com/user-attachments/assets/4d5d746e-b8c2-47ff-a251-b24864895444)

* 7.속성 읽어들여 출력
   * test.xml 파일 수정
   ```xml
   <car type="KIA">  This is a really cool description </car>
   ```
   * main.c 파일 수정
   ```c
   #include <stdio.h>
   #include <stdlib.h>

   #include "lxml.h"

   int main(int argc, char *argv[])
   {
		XMLDocument doc;
		if (XMLDocument_load(&doc, "test.xml")) {
			XMLNode *main_node = XMLNode_child(doc.root, 0);
			printf("Car (%s)\n", main_node->attributes.data[0].value);
	
			XMLDocument_free(&doc);
		}
		return 0;
   }
   ```
   ![image](https://github.com/user-attachments/assets/9005f0dd-e902-49cb-b11b-760432379c09)

* 8.XML version, encoding 얻기
    * test.xml 파일 수정
    ```xml
    <?xml version="1.0" encoding="utf-8" ?>
    <car type="KIA">  This is a really cool description </car>
    ```
    * main.c 파일 수정
    ```c
    #include <stdio.h>
    #include <stdlib.h>

    #include "lxml.h"

    int main(int argc, char *argv[])
    {
			XMLDocument doc;
			if (XMLDocument_load(&doc, "test.xml")) {
				printf("XML Document (version=%s, encoding=%s)\n", doc.version, doc.encoding);
	
				XMLNode* main_node = XMLNode_child(doc.root, 0);
				printf("Car (%s)\n", main_node->attributes.data[0].value);
	
				XMLDocument_free(&doc);
			}
			return 0;
    }
    ```
    * lxml.h 파일 수정
    ```c
    static void parse_attrs(char *buf, int *i, char *lex, int *lexi, XMLNode *curr_node) {
      XMLAttribute curr_attr = { 0,0 };
      while (buf[*i] != '>') {
        lex[(*lexi)++] = buf[(*i)++];
  
        // Tag name
        if (buf[*i] == ' ' && !curr_node->tag) {
          lex[*lexi] = '\0';
          curr_node->tag = _strdup(lex);
          *lexi = 0;
          (*i)++;
          continue;
        }
  
        // Usually ignore spaces
        if (lex[*lexi - 1] == ' ') {
          (*lexi)--;
          continue;
        }
  
        // Attribute key
        if (buf[*i] == '=') {
          lex[*lexi] = '\0';
          curr_attr.key = _strdup(lex);
          *lexi = 0;
          continue;
        }
  
        // Attribute value
        if (buf[*i] == '"') {
          if (!curr_attr.key) {
            fprintf(stderr, "Value has no key\n");
            return;
          }
  
          *lexi = 0;
          (*i)++;
  
          while (buf[*i] != '"')
            lex[(*lexi)++] = buf[(*i)++];
          lex[*lexi] = '\0';
          curr_attr.value = _strdup(lex);
          XMLAttributeList_add(&curr_node->attributes, &curr_attr);
          curr_attr.key = NULL;
          curr_attr.value = NULL;
          *lexi = 0;
          (*i)++;
          continue;
        }
      }
    }

    bool XMLDocument_load(XMLDocument *doc, const char *path) {
			// Declaration tags
      if (buf[i + 1] == '?') {
        while ( buf[i] != ' ' && buf[i] != '>')
           lex[lexi++] = buf[i++];
        lex[lexi] = '\0';
      
        // This is the XML declaration
        if (!strcmp(lex, "<?xml")) {
           lexi = 0;
           XMLNode* desc = XMLNode_new(NULL);
           parse_attrs(buf, &i, lex, &lexi, desc);
      
           doc->version = XMLNode_attr_val(desc, "version");
           doc->encoding = XMLNode_attr_val(desc, "encoding");
           continue;
        }
      }
      // Start tag
      i++;
      parse_attrs(buf, &i, lex, &lexi, curr_node);
    }
    ```
    ![image](https://github.com/user-attachments/assets/7e7e19c7-d9bb-4852-b014-278f21a6afdc)
    * XML Document Structure  
    <img src = "https://github.com/user-attachments/assets/1cfca3f7-c9d8-4bf0-a40e-75bb80f07316" width="70%" height="70%">

* 9.tag의 끝이 /> 로 마무리 되는 inline node인 경우
    * test.xml 파일 수정
    ```xml
    <?xml version="1.0" encoding="utf-8" ?>
    <struct name="Person">
      <field name="name" type="string" />
      <field name="age" type="int" />
    </struct>
    ```
    * main.c 파일 수정
    * lxml.h 파일 수정

* 10.dummy tag분석 제외
    * test.xml파일 수정
    ```xml
    <?xml version="1.0" encoding="utf-8" ?>
    <struct name="Person">
    	<field name="name" type="string" />
    	<dummy/>
     	<field name="age" type="int" />
    </struct>
    ```
    * main.c 파일 수정
    ```c
    #include <stdio.h>
    #include <stdlib.h>

    #include "lxml.h"

    int main(int argc, char *argv[])
    {
      XMLDocument doc;
      if (XMLDocument_load(&doc, "test.xml")) {
        XMLNode *str = XMLNode_child(doc.root, 0);
        printf("Struct: %s\n", XMLNode_attr_val(str, (char *)"name"));

        XMLNodeList *fields = XMLNode_children(str, "field");
        for (int i = 0; i < fields->size; i++) {
          XMLNode* field = XMLNodeList_at(fields, i);
          printf(" %s (%s)\n", XMLNode_attr_val(field, (char *)"name"), XMLNode_attr_val(field, (char *)"type"));
        }
        XMLDocument_free(&doc);
      }
      return 0;
    }
    ```
    * lxml.h 파일 수정
    ```c
    struct _XMLNode *XMLNodeList_at(XMLNodeList *list, int index);
    void XMLNodeList_free(XMLNodeList *list);

    XMLNodeList *XMLNode_children(XMLNode *parent, const char *tag);

    XMLNode *XMLNodeList_at(XMLNodeList *list, int index) {
      return list->data[index];
    }

    void XMLNodeList_free(XMLNodeList* list) {
      free(list);
    }

    XMLNodeList *XMLNode_children(XMLNode *parent, const char *tag) {
      XMLNodeList *list = (XMLNodeList *) malloc(sizeof(XMLNodeList));
      XMLNodeList_init(list);

      for (int i = 0; i < parent->children.size; i++) {
        XMLNode *child = parent->children.data[i];
        if (!strcmp(child->tag, tag))
          XMLNodeList_add(list, child);
      }
      return list;
    }
    ```
    ![image](https://github.com/user-attachments/assets/832e767b-7b46-4c94-9d89-7d2534df0106)
     
* 11.XMLDocument_write(), XML문서 생성
    * main.c 파일 수정
    ```c
    #include <stdio.h>
    #include <stdlib.h>

    #include "lxml.h"

    int main(int argc, char *argv[])
    {
      XMLDocument doc;
      if (XMLDocument_load(&doc, "test.xml")) {
        XMLNode *str = XMLNode_child(doc.root, 0);
        printf("Struct: %s\n", XMLNode_attr_val(str, (char *)"name"));
  
        XMLNodeList *fields = XMLNode_children(str, "field");
        for (int i = 0; i < fields->size; i++) {
          XMLNode *field = XMLNodeList_at(fields, i);
          XMLAttribute* type = XMLNode_attr(field, "type");
          type->value = "";
        }
  
        XMLDocument_write(&doc, "out.xml", 4 );
        XMLDocument_free(&doc);
      }
      return 0;
    }
    ```
    * lxml.h 파일 수정
    ```c
    bool XMLDocument_write(XMLDocument *doc, const char *path, int indent);

    static void node_out(FILE *file, XMLNode *node, int indent, int times) {
      for (int i = 0; i < node->children.size; i++) {
        XMLNode* child = node->children.data[i];
  
      if(times > 0)
          fprintf(file, "%0*s", indent*times, " ");
  
        fprintf(file, "<%s", child->tag);
        for(int i = 0; i < child->attributes.size; i++){
          XMLAttribute attr = child->attributes.data[i];
          if (!strcmp(attr.value, ""))
            continue;
          fprintf(file, " %s=\"%s\"", attr.key, attr.value);
        }
  
        if(child->children.size == 0 && !child->inner_text)
          fprintf(file, " /> \n");
        else {
          fprintf(file, ">\n");
          if(child->children.size == 0)
            fprintf (file, "%s</%s>\n", child->inner_text, child->tag);
          else {
            node_out(file, child, indent, times + 1);
            if(times > 0)
              fprintf(file, "%0*s", indent * times, " ");
            fprintf(file, "</%s>\n", child->tag);
          }
        }
      }
    }

    bool XMLDocument_write(XMLDocument *doc, const char *path, int indent) {
      FILE *file = fopen(path, "w");
      if (!file) {
        fprintf(stderr, "Could not open file '%s'\n", path);
        return TRUE;
      }
  
      fprintf(file, "<?xml version=\"%s\" encoding=\"%s\" ?>\n",
        (doc->version) ? doc->version : "1.0",
        (doc->encoding) ? doc->encoding : "UTF-8"
      );
      node_out(file, doc->root, indent, 0);
      fclose(file);
    }
    ```
    ![image](https://github.com/user-attachments/assets/beb46743-f512-48f5-ac3f-1ba6c16ef36a)
  
    ![image](https://github.com/user-attachments/assets/9c13db1a-153e-427f-b772-cdfdfebc89a7)

    * 최종 파일 [[lxml.h](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XML_Parser/lxml.h), [main.c](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XML_Parser/main.c), [test.xml](https://github.com/csbyun-data/C-Pro/blob/main/chap05/XML_Parser/test.xml)]
