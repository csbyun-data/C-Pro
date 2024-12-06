// 최종 파일
#include <stdio.h>
#include <stdlib.h>

#include "lxml.h"

int main(int argc, char *argv[]) 
{

	XMLDocument doc;
	if (XMLDocument_load(&doc, "test.xml")) {
		XMLNode* str = XMLNode_child(doc.root, 0);
		printf("Struct: %s\n", XMLNode_attr_val(str, (char *)"name"));

		XMLNodeList* fields = XMLNode_children(str, "field");
		for (int i = 0; i < fields->size; i++) {
			XMLNode* field = XMLNodeList_at(fields, i);
			XMLAttribute* type = XMLNode_attr(field, "type");
			type->value = "";
		}
		
		XMLDocument_write(&doc, "out.xml", 4 );
		XMLDocument_free(&doc);
	}
	return 0;
}

