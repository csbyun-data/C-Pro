/* xleval - xlisp evaluator */

#include <setjmp.h>
#include <stdarg.h>

#include "xlisp.h"
#include "xlsubr.h"
#include "xlread.h"

/* global variables */
struct node *xlstack;

/* external variables */
extern jmp_buf xljmpbuf;

/* forward declarations (the extern hack is for decusc) */
extern struct node *evlist();
extern struct node *evsym();

/* xleval - evaluate an xlisp expression */
struct node *xleval(expr)
  struct node *expr;
{
    /* evaluate null to itself */
    if (expr == NULL)
	  return (NULL);
	
	printf("  xleval() run \n");
	
    /* check type of value */
    switch (expr->n_type) {
    case LIST:
    	printf("    LIST\n");
	    return (evlist(expr));
    case SYM:
    	printf("    SYM\n");
	    return (evsym(expr));
    case INT:
    case STR:
    case SUBR:
	    return (expr);
    default:
	    xlfail("can't evaluate expression");
    }
}

/* xlsave - save nodes on the stack */
struct node *xlsave(struct node *n,...)
{
    struct node **nptr,*oldstk, *arg;

    // Declaring pointer to the argument list
    va_list ptr;

    /* save the old stack pointer */
    oldstk = xlstack;

    // Initializing argument to the list pointer
    va_start(ptr, n);

    /* save each node */
    for (nptr = &n; *nptr != NULL; ) {
		(*nptr)->n_type = LIST;
		(*nptr)->n_listvalue = NULL;
		(*nptr)->n_listnext = xlstack;
		xlstack = *nptr;

		// Accessing current variable and pointing to next one
		arg = va_arg(ptr, struct node *);
		nptr = &arg;
    }
    
    // Ending argument list traversal
    va_end(ptr);

    /* return the old stack pointer */
    return (oldstk);
}

/* evlist - evaluate a list */
struct node *evlist(nptr)
  struct node *nptr;
{
    struct node *oldstk,fun,args,*val;

    /* create a stack frame */
    oldstk = xlsave(&fun,&args,NULL);

    /* get the function and the argument list */
    fun.n_ptr = nptr->n_listvalue;
    args.n_ptr = nptr->n_listnext;

    /* evaluate the first expression */
    if ((fun.n_ptr = xleval(fun.n_ptr)) == NULL)
		xlfail("null function");

    /* evaluate the function */
    switch (fun.n_ptr->n_type) {
	    case SUBR:
		    val = (*fun.n_ptr->n_subr)(args.n_ptr);
			break;
	    case FUN:
	    case LIST:
		    //val = evfun(fun.n_ptr,args.n_ptr);
		    break;
	    case OBJ:
		    //val = xlsend(fun.n_ptr,args.n_ptr);
		    break;
	    default:
		    xlfail("bad function");
    }

    /* restore the previous stack frame */
    xlstack = oldstk;

    /* return the result value */
    return (val);
}

/* evsym - evaluate a symbol */
struct node *evsym(sym)
  struct node *sym;
{
    /* return the current symbol value */
    return (sym->n_symvalue);
}


/* xlfail - error handling routine */
xlfail(err)
  char *err;
{
    /* print the error message */
    printf("error: %s\n",err);

    /* restore input to the terminal */
    xltin();

    /* restart */
    longjmp(xljmpbuf,1);
}
