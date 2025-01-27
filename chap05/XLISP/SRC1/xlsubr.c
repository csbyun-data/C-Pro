/* xlsubr - xlisp builtin functions */

#include "xlisp.h"
#include "xldmem.h"
#include "xlread.h"
#include "xleval.h"

/* external variables */
extern int (*xlgetc)();
extern struct node *xlstack;

/* local variables */
static char *sgetptr;

/* xlsubr - define a builtin function */
xlsubr(sname,subr)
  char *sname; int (*subr)();
{
    struct node *sym;

    /* enter the symbol */
    sym = xlenter(sname);

    /* initialize the value */
    sym->n_symvalue = newnode(SUBR);
    sym->n_symvalue->n_subr = subr;
}


/* xlarg - get the next argument */
struct node *xlarg(pargs)
  struct node **pargs;
{
    struct node *arg;

    /* make sure the argument exists */
    if (*pargs == NULL)
		xlfail("too few arguments");

    /* get the argument value */
    arg = (*pargs)->n_listvalue;

    /* move the argument pointer ahead */
    *pargs = (*pargs)->n_listnext;

    /* return the argument */
    return (arg);
}

/* xlevarg - get the next argument and evaluate it */
struct node *xlevarg(pargs)
  struct node **pargs;
{
    struct node *oldstk,val;

    /* create a new stack frame */
    oldstk = xlsave(&val,NULL);

    /* get the argument */
    val.n_ptr = xlarg(pargs);

    /* evaluate the argument */
    val.n_ptr = xleval(val.n_ptr);

    /* restore the previous stack frame */
    xlstack = oldstk;

    /* return the argument */
    return (val.n_ptr);
}

/* assign - assign a value to a symbol */
static assign(sym,val)
  struct node *sym,*val;
{
    struct node *lptr,*bptr,*optr;

    /* not an instance variable of the current object */
    sym->n_symvalue = val;
}

/* xlmatch - get an argument and match its type */
struct node *xlmatch(type,pargs)
  int type; struct node **pargs;
{
    struct node *arg;

    /* get the argument */
    arg = xlarg(pargs);

    /* check its type */
    if (type == LIST) {
	if (arg != NULL && arg->n_type != LIST)
	    xlfail("bad argument type");
    }
    else {
	if (arg == NULL || arg->n_type != type)
	    xlfail("bad argument type");
    }

    /* return the argument */
    return (arg);
}

/* setq - builtin function setq */
static struct node *setq(args)
  struct node *args;
{
    struct node *oldstk,arg,sym,val;

    /* create a new stack frame */
    oldstk = xlsave(&arg,&sym,&val,NULL);

    /* initialize */
    arg.n_ptr = args;

    /* get the symbol */
    sym.n_ptr = xlmatch(SYM,&arg.n_ptr);

    /* get the new value */
    val.n_ptr = xlevarg(&arg.n_ptr);

    /* make sure there aren't any more arguments */
    if (arg.n_ptr != NULL)
	xlfail("too many arguments");

    /* assign the symbol the value of argument 2 and the return value */
    assign(sym.n_ptr,val.n_ptr);

    /* restore the previous stack frame */
    xlstack = oldstk;

    /* return the result value */
    return (val.n_ptr);
}

/* fexit - get out of xlisp */
void fexit()
{
    exit(0);
}

/* xlinit - xlisp initialization routine */
xlinit()
{
	xlsubr("setq",setq);
    xlsubr("exit",fexit);

}
