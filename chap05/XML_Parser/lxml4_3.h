#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef TRUE
  #define TRUE 1
#endif
#ifndef FALSE
  #define FALSE 0
#endif

// Definitions
struct _XMLAttribute {
  char* key;
  char* value;
};
typedef struct _XMLAttribute XMLAttribute;

void XMLAttribute_free(XMLAttribute* attr);

struct _XMLAttributeList {
  int heap_size;
  int size;
  XMLAttribute* data;
};
typedef struct _XMLAttributeList XMLAttributeList;

void XMLAttributeList_init(XMLAttributeList* list);
void XMLAttributeList_add(XMLAttributeList* list, XMLAttribute* attr);

struct _XMLNodeList {
  int heap_size;
  int size;
  struct _XMLNode** data;
};
typedef struct _XMLNodeList XMLNodeList;

void XMLNodeList_init(XMLNodeList* list);
void XMLNodeList_add(XMLNodeList* list, struct _XMLNode* node);

struct _XMLNode {
  char* tag;
  char* inner_text;
  struct _XMLNode* parent;
  XMLAttributeList attributes;
  XMLNodeList children;
};
typedef struct _XMLNode XMLNode;

XMLNode* XMLNode_new(XMLNode* parent);
void XMLNode_free(XMLNode* node);
XMLNode* XMLNode_child(XMLNode* parent, int index);

struct _XMLDocument {
  XMLNode* root;
};
typedef struct _XMLDocument XMLDocument;

bool XMLDocument_load(XMLDocument* doc, const char* path);
void XMLDocument_free(XMLDocument* doc);

// Implementation

void XMLAttribute_free(XMLAttribute* attr) {
  free(attr->key);
  free(attr->value);
}

void XMLAttributeList_init(XMLAttributeList* list) {
  list->heap_size = 1;
  list->size = 0;
  list->data = (XMLAttribute*)malloc(sizeof(XMLAttribute) * list->heap_size);
}

void XMLAttributeList_add(XMLAttributeList* list, XMLAttribute* attr) {
  while (list->size >= list->heap_size) {
    list->heap_size *= 2;
    list->data = (XMLAttribute*)realloc(list->data, sizeof(XMLAttribute) * list->heap_size);
   }
  
  list->data[list->size++] = *attr;
}

void XMLNodeList_init(XMLNodeList* list) {
  list->heap_size = 1;
  list->size = 0;
  list->data = (XMLNode**)malloc(sizeof(XMLNode*) * list->heap_size);
}

void XMLNodeList_add(XMLNodeList* list, XMLNode* node) {
  while (list->size >= list->heap_size) {
    list->heap_size *= 2;
    list->data = (XMLNode**)realloc(list->data, sizeof(XMLNode*) * list->heap_size);
  }

  list->data[list->size++] = node;
}

XMLNode* XMLNode_new(XMLNode* parent) {
  XMLNode* node = (XMLNode*)malloc(sizeof(XMLNode));
  node->parent = parent;
  node->tag = NULL;
  node->inner_text = NULL;
  XMLAttributeList_init(&node->attributes);
  XMLNodeList_init(&node->children);
  if (parent)
    XMLNodeList_add(&parent->children, node);
  
  return node;
}

void XMLNode_free(XMLNode* node) {
  if (node->tag)
    free(node->tag);
  if (node->inner_text)
    free(node->inner_text);
    
  for (int i = 0; i < node->attributes.size; i++)
    XMLAttribute_free(&node->attributes.data[i]);
  free(node);
}

XMLNode* XMLNode_child(XMLNode* parent, int index) {
  return parent->children.data[index];
}

bool XMLDocument_load(XMLDocument* doc, const char* path) {
   //위 lxml.h 파일 동일 Source 복사하면 됨
}

void XMLDocument_free(XMLDocument* doc) {
  XMLNode_free(doc->root);
}
