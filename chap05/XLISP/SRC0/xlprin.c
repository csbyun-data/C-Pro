/* xlprint - xlisp print routine */

#include "xlisp.h"

/* xlprint - print an xlisp value */
xlprint(vptr)
  struct node *vptr;
{
    struct node *nptr,*next;

    /* print null as the empty list */
    if (vptr == NULL) {
	printf("()");
	return;
    }

    /* check value type */
    switch (vptr->n_type) {
    case SUBR:
	    printf("#%o",vptr->n_subr);
	    break;
    case FUN:
    case LIST:
	    putchar('(');
	    for (nptr = vptr; nptr != NULL; nptr = next) {
	        xlprint(nptr->n_listvalue);
		if ((next = nptr->n_listnext) != NULL)
		    if (next->n_type == LIST)
			putchar(' ');
		    else {
			putchar('.');
			xlprint(next);
			break;
		    }
	    }
	    putchar(')');
	    break;
    case SYM:
	    printf("%s",vptr->n_symname);
	    break;
    case INT:
	    printf("%d",vptr->n_int);
	    break;
    }
}
