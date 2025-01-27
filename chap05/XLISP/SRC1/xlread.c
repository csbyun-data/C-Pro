/* xlread - xlisp expression input routine */

#include <stdio.h>
#include <ctype.h>
#include "xlisp.h"
#include "xldmem.h"
#include "xleval.h"

/* global variables */
struct node *oblist;

/* external variables */
extern struct node *xlstack;
extern int (*xlgetc)();

/* local variables */
static int savech;

/* forward declarations (the extern hack is for decusc) */
extern struct node *parse();
extern struct node *plist();
extern struct node *pnumber();
extern struct node *pname();

/* xlread - read an xlisp expression */
struct node *xlread()
{
    struct node *val;
    int ch;

    /* initialize */
    savech = -1;

    /* parse an expression */
    val = parse();

    /* skip to end of line */
    while ((ch = thisch()) > 0 && ch != '\n') {
	if (!isspace(ch))
	    xlfail("extra characters after expression");
	savech = -1;
    }

    /* return the result value */
    return (val);
}

/* parse - parse an xlisp expression */
struct node *parse()
{
    int ch;

    /* keep looking for a node skipping comments */
    while (TRUE)
		/* check next character for type of node */
		switch (ch = nextch()) {
			case '(':			/* a sublist */
				return (plist());
			case ')':			/* closing paren - shouldn't happen */
				xlfail("extra right paren");
			default:
				if (isdigit(ch))	/* a number */
				    return (pnumber());
				else			/* a name */
				    return (pname());
		}
}

/* plist - parse a list */
struct node *plist()
{
    struct node *oldstk,val,*lastnptr,*nptr;
    int ch;

    /* create a new stack frame */
    oldstk = xlsave(&val,NULL);

    /* skip the opening paren */
    savech = -1;

    /* keep appending nodes until a closing paren is found */
    for (lastnptr = NULL; (ch = nextch()) > 0 && ch != ')'; lastnptr = nptr) {

		/* allocate a new node and link it into the list */
		nptr = newnode(LIST);
		if (lastnptr == NULL)
		    val.n_ptr = nptr;
		else
		    lastnptr->n_listnext = nptr;
	
		/* initialize the new node */
		nptr->n_listvalue = parse();
    }

    /* skip the closing paren */
    savech = -1;

    /* restore the previous stack frame */
    xlstack = oldstk;

    /* return successfully */
    return (val.n_ptr);
}


/* pnumber - parse a number */
struct node *pnumber()
{
    struct node *val;
    int ch,ival;

    /* loop looking for a closing quote */
    for (ival = 0; (ch = thisch()) > 0 && isdigit(ch); savech = -1)
		ival = ival * 10 + ch - '0';

    /* initialize the node */
    val = newnode(INT);
    val->n_int = ival;

    /* return the new number */
    return (val);
}

/* xlenter - enter a symbol into the symbol table */
struct node *xlenter(sname)
  char *sname;
{
    struct node *sptr;
	
    /* check for nil */
    if (strcmp(sname,"nil") == 0)
		return (NULL);

    /* check for symbol already in table */
    for (sptr = oblist; sptr != NULL; sptr = sptr->n_listnext) 
		if (sptr->n_listvalue == NULL)
		    printf("bad oblist\n");
		else if (sptr->n_listvalue->n_symname == NULL)
		    printf("bad oblist symbol\n");
		else
		if (strcmp(sptr->n_listvalue->n_symname,sname) == 0)
		    return (sptr->n_listvalue);
    
    /* enter a new symbol and link it into the symbol list */
    sptr = newnode(LIST);
    sptr->n_listnext = oblist;
    oblist = sptr;
    sptr->n_listvalue = newnode(SYM);
    sptr->n_listvalue->n_symname = strsave(sname);

    /* return the new symbol */
    return (sptr->n_listvalue);
}


/* pname - parse a symbol name */
struct node *pname()
{
    char sname[STRMAX+1];
    int ch,i;
    
    /* get symbol name */
    for (i = 0; i < STRMAX && (ch = thisch()) > 0 && issym(ch); i++) 
		sname[i] = getch();
	
	sname[i] = 0;

    /* initialize value */
    return (xlenter(sname));
}

/* nextch - look at the next non-blank character */
int nextch()
{
    int ch;

    /* look for a non-blank character */
    while ((ch = thisch()) > 0)
		if (isspace(ch))
		    savech = -1;
		else
		    break;

    /* return the character */
    return (ch);
}

/* thisch - look at the current character */
int thisch()
{
    /* return and save the current character */
    return (savech = getch());
}

/* getch - get the next character */
int getch()
{
    int ch;

    /* check for a saved character */
    if ((ch = savech) >= 0)
		savech = -1;
    else
		ch = (*xlgetc)();

    /* return the character */
    return (ch);
}

/* issym - check whether a character if valid in a symbol name */
int issym(ch)
  int ch;
{
    if (isspace(ch) || ch == '(' || ch == ')' || ch == ';' || ch == '\'')
		return (FALSE);
    else
		return (TRUE);
}
