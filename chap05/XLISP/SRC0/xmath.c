/* xlmath - xlisp builtin arithmetic functions */

#include "xlisp.h"
#include "xldmem.h"
#include "xleval.h"
#include "xlread.h"

/* external variables */
extern struct node *xlstack;

/* external procedures */
extern struct node *xlevarg();

/* local variables */
static struct node *true;

/* forward declarations (the extern hack is for decusc) */
extern struct node *arith();

/* add - builtin function for addition */
int xadd(val, arg)
  int val,arg;
{
	printf("    xadd(%d, %d) \n",val, arg);
    return (val + arg);
}
struct node *add(args)
  struct node *args;
{
    return (arith(args,xadd));
}

/* arith - common arithmetic function */
struct node *arith(args,funct)
  struct node *args; int (*funct)();
{
    struct node *oldstk,arg,*val;
    int first,ival,iarg;

    /* create a new stack frame */
    oldstk = xlsave(&arg,NULL);

    /* initialize */
    arg.n_ptr = args;
    first = TRUE;
    ival = 0;

    /* evaluate and sum each argument */
    while (arg.n_ptr != NULL) {
		/* get the next argument */
		iarg = cnvnum(xlevarg(&arg.n_ptr));
	
		/* accumulate the result value */
		if (first) {
		    ival = iarg;
		    first = FALSE;
		}
		else
		    ival = (*funct)(ival,iarg);
    }

    /* initialize value */
    val = newnode(INT);
    val->n_int = ival;

    /* restore the previous stack frame */
    xlstack = oldstk;

    /* return the result value */
    return (val);
}


/* gettype - return the type of an argument */
int gettype(arg)
  struct node *arg;
{
    if (arg == NULL)
		return (LIST);
    else
		return (arg->n_type);
}

/* cnvnum - convert a numeric value */
int cnvnum(arg)
  struct node *arg;
{
    int ival;
    
    /* return false if node is null */
    if (arg == NULL)
		return (FALSE);

    /* convert the value if necessary */
    switch (arg->n_type) {
	    case INT:
		    ival = arg->n_int;
		    break;
	    default:
		    ival = TRUE;
		    break;
    }

    /* return the integer value */
    return (ival);
}

/* xlminit - xlisp math initialization routine */
xlminit()
{
    xlsubr("+",add);
    true = xlenter("t");
    true->n_symvalue = true;
}
