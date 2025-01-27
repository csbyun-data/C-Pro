#ifndef XLDMEM_H
#define XLDMEM_H

extern struct node *newnode(int type);
extern char *stralloc(int size);
extern char *strsave(char *str);
extern strfree(char *str);
extern gc();
extern unmark();
extern mark(struct node *ptr);
extern sweep();
extern int addseg();
extern int left(struct node *n);
extern int right(struct node *n);
extern  struct node *fgc(struct node *args);
extern xldmeminit();
  
#endif  
