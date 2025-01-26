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

/* fexit - get out of xlisp */
void fexit()
{
    exit(0);
}

/* xlinit - xlisp initialization routine */
xlinit()
{
    xlsubr("exit",fexit);

}
