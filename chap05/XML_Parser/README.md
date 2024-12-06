## 1.XML Parser
### INDEX
* 1.XML file load 화면 출력 기능 구현
    * 1.1 mainc. 생성
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
    * 1.2 lxml.h 생성
    ```c
    // # include <stdbool.h>  추가
    int XMLDocument_load(XMLDocument* doc, const char* path);  // bool형으로 변경

    int XMLDocument_load(XMLDocument* doc, const char* path) {  // bool형으로 변경
    	FILE* file = fopen(path, "r");
    	if (!file) {
    		fprintf(stderr, "Could not load file from '%s'\n", path);
    		return false;
    	}
        //.......................................
    	return true;
    }
    ```
    * 1.3 lxml.h 수정 작업
    ```
    #pragma once
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>

    // Definitions

    struct _XMLDocument {
    	char* source;
    };
    typedef struct _XMLDocument XMLDocument;

    bool XMLDocument_load(XMLDocument* doc, const char* path);
    void XMLDocument_free(XMLDocument* doc);

    // Implementation
    bool XMLDocument_load(XMLDocument* doc, const char* path) {
    	FILE* file = fopen(path, "r");
    	if (!file) {
    		fprintf(stderr, "Could not load file from '%s'\n", path);
    		return false;
    	}
    	fseek(file, 0, SEEK_END);
    	int size = ftell(file);
    	fseek(file, 0, SEEK_SET);

    	doc->source = (char*)malloc(sizeof(char) * size * 1);
    	fread(doc->source, 1, size, file);
    	fclose(file);
    	doc->source[size] = '\0';

    	return true;
    }

    void XMLDocument_free(XMLDocument* doc) { }
    ```
    ![image](https://github.com/user-attachments/assets/c4ca3118-abc6-4c5a-a446-8e6be19e80c9)

  * 2.XML 내용 조회 구현
      * 2.1 main.c 프로그램 수정
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
      * 2.2 lxml.h 프로그램 수정
      ```c
      #pragma once
      #include <stdio.h>
      #include <stdlib.h>
      #include <string.h>

      #include <stdbool.h>

      // Definitions
      struct _XMLNode {
      	char* tag;
      	char* inner_text;
      	struct _XMLNode* parent;
      };
      typedef struct _XMLNode XMLNode;

      XMLNode* XMLNode_new(XMLNode* parent);
      void XMLNode_free(XMLNode* node);

      struct _XMLDocument {
      	XMLNode* root;
      };
      typedef struct _XMLDocument XMLDocument;

      bool XMLDocument_load(XMLDocument* doc, const char* path);
      void XMLDocument_free(XMLDocument* doc);

      // Implementation
      XMLNode* XMLNode_new(XMLNode* parent) {
      	XMLNode* node = (XMLNode*)malloc(sizeof(XMLNode));
      	node->parent = parent;
      	node->tag = NULL;
      	node->inner_text = NULL;
      	return node;
      }

      void XMLNode_free(XMLNode* node) {
      	if (node->tag)
      		free(node->tag);
      	if (node->inner_text)
      		free(node->inner_text);
      }

      bool XMLDocument_load(XMLDocument* doc, const char* path) {
      	FILE* file = fopen(path, "r");
      	if (!file) {
      		fprintf(stderr, "Could not load file from '%s'\n", path);
      		return false;
      	}
      	fseek(file, 0, SEEK_END);
      	int size = ftell(file);
      	fseek(file, 0, SEEK_SET);

      	char* buf = (char*)malloc(sizeof(char) * size * 1);
      	fread(buf, 1, size, file);
      	fclose(file);
      	buf[size] = '\0';

      	doc->root = XMLNode_new(NULL);

      	char lex[256];
      	int lexi = 0;
      	int i = 0;

      	XMLNode* curr_node = NULL;

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

      void XMLDocument_free(XMLDocument* doc) {
      	XMLNode_free(doc->root);  //수정 Source
      }
      ```
      ![image](https://github.com/user-attachments/assets/452b65a7-6832-4606-bc43-0a71d5262814)

* 3.XML 파일 속성 조회
    * 3.1 test.xml 파일 속성 조회 예제 형식으로 수정
    ```xml
    <root key="value" another="one more">I am a root</root>
    ```
    * 3.2 main.c 파일 수정
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
    * 3.3 lxml.h 파일 수정 [code] ()
    * 
    
    
    



  
  
