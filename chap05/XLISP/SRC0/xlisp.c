/* xlisp - a small subset of lisp */

#include <setjmp.h>
#include "xlisp.h"

/* global variables */
jmp_buf xljmpbuf;

extern struct node *xlread();
extern struct node *xleval();

/* external variables */
extern struct node *xlstack;
extern int xlpvals;

/* main - the main routine */
main(argc,argv)
  int argc; char *argv[];
{
    struct node expr;
    
    /* initialize the dynamic memory module (must be first) */
    xldmeminit();
        
    /* initialize xlisp */
    xlinit();   // (routine)
	xlminit();  // (math)

    /* initialize terminal input */
    xltin();

    /* main command processing loop */
    while (TRUE) {

		/* setup the error return */
		setjmp(xljmpbuf);
		
		/* free any previous expression and leftover context */
		xlstack = NULL;
	
		/* create a new stack frame */
		xlsave(&expr, NULL);
		
		/* read an expression */
		expr.n_ptr = xlread();
	
		/* evaluate the expression */
		expr.n_ptr = xleval(expr.n_ptr);
	
		/* print it if necessary */
		if (xlpvals) {
		    xlprint(expr.n_ptr);
		    putchar('\n');
		}
    }
}
