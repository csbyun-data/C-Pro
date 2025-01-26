#ifndef XLEVAL_H
#define XLEVAL_H

extern struct node *xlsave(struct node *n, ...);
extern struct node *xleval(struct node *expr);
  
#endif
