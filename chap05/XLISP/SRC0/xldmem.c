/* xldmem - xlisp dynamic memory management routines */

#include "xlisp.h"

/* useful definitions */
#define ALLOCSIZE (sizeof(struct segment) + anodes * sizeof(struct node))

/* memory segment structure definition */
struct segment {
    int sg_size;
    struct segment *sg_next;
    struct node sg_nodes[];
};

/* external variables */
extern struct node *oblist;
extern struct node *xlstack;

/* local variables */
int anodes,nnodes,nsegs,nfree,gccalls;
static struct segment *segs;
static struct node *fnodes;

/* newnode - allocate a new node */
struct node *newnode(type)
  int type;
{
    struct node *nnode;

    /* get a free node */
    if ((nnode = fnodes) == NULL) {
		gc();
		if ((nnode = fnodes) == NULL)
		    xlfail("insufficient node space");
    }

    /* unlink the node from the free list */
    fnodes = nnode->n_right;
    nfree -= 1;

    /* initialize the new node */
    nnode->n_type = type;
    nnode->n_left = NULL;
    nnode->n_right = NULL;

    /* return the new node */
    return (nnode);
}

/* stralloc - allocate memory for a string adding a byte for the terminator */
char *stralloc(size)
  int size;
{
    char *sptr;

    /* allocate memory for the string copy */
    if ((sptr = malloc(size+1)) == NULL) {
		gc();
		if ((sptr = malloc(size+1)) == NULL)
		    xlfail("insufficient string space");
    }

    /* return the new string memory */
    return (sptr);
}

/* strsave - generate a dynamic copy of a string */
char *strsave(str)
  char *str;
{
    char *sptr;

    /* create a new string */
    sptr = stralloc(strlen(str));
    strcpy(sptr,str);

    /* return the new string */
    return (sptr);
}

/* strfree - free string memory */
strfree(str)
  char *str;
{
    free(str);
}

/* gc - garbage collect */
gc()
{
    /* unmark all nodes */
    unmark();

    /* mark all accessible nodes */
    mark(oblist);
    mark(xlstack);

    /* sweep memory collecting all unmarked nodes */
    sweep();

    /* if there's still nothing available, allocate more memory */
    if (fnodes == NULL)
		addseg();

    /* count the gc call */
    gccalls += 1;
}

/* unmark - unmark each node */
unmark()
{
    struct segment *seg;
    struct node *n;
    int i=0;
     
    /* unmark the stack */
    for (n = xlstack; n != NULL ; n = n->n_listnext)	
		n->n_flags &= ~(MARK | LEFT);

}

/* mark - mark all accessible nodes */
mark(ptr)
  struct node *ptr;
{
    struct node *this,*prev,*tmp;

    /* just return on null */
    if (ptr == NULL)
		return;
		
    /* initialize */
    prev = NULL;
    this = ptr;

    /* mark this list */
    while (TRUE) {

	/* descend as far as we can */
	while (TRUE) {

	    /* check for this node being marked */
	    if (this->n_flags & MARK)
		break;

	    /* mark it and its descendants */
	    else {

		/* mark the node */
		this->n_flags |= MARK;

		/* follow the left sublist if there is one */
		if (left(this)) {
		    this->n_flags |= LEFT;
		    tmp = prev;
		    prev = this;
		    this = prev->n_left;
		    prev->n_left = tmp;
		}
		else if (right(this)) {
		    this->n_flags &= ~LEFT;
		    tmp = prev;
		    prev = this;
		    this = prev->n_right;
		    prev->n_right = tmp;
		}
		else
		    break;
	    }
	}

	/* backup to a point where we can continue descending */
	while (TRUE) {

	    /* check for termination condition */
	    if (prev == NULL)
		return;

	    /* check for coming from the left side */
	    if (prev->n_flags & LEFT)
		if (right(prev)) {
		    prev->n_flags &= ~LEFT;
		    tmp = prev->n_left;
		    prev->n_left = this;
		    this = prev->n_right;
		    prev->n_right = tmp;
		    break;
		}
		else {
		    tmp = prev;
		    prev = tmp->n_left;
		    tmp->n_left = this;
		    this = tmp;
		}

	    /* came from the right side */
	    else {
		tmp = prev;
		prev = tmp->n_right;
		tmp->n_right = this;
		this = tmp;
	    }
	}
    }
}

/* sweep - sweep all unmarked nodes and add them to the free list */
sweep()
{
    struct segment *seg;
    struct node *n;
    int i;

    /* empty the free list */
    fnodes = NULL;
    nfree = 0;

    /* add all unmarked nodes */
    for (seg = segs; seg != NULL; seg = seg->sg_next)
	for (i = 0; i < seg->sg_size; i++)
	    if (!((n = &seg->sg_nodes[i])->n_flags & MARK)) {
			switch (n->n_type) {
			case SYM:
				if (n->n_symname != NULL)
				    strfree(n->n_symname);
				break;
			}
			n->n_type = FREE;
			n->n_left = NULL;
			n->n_right = fnodes;
			fnodes = n;
			nfree += 1;
	    }
	    else
			n->n_flags &= ~MARK;
}

/* addseg - add a segment to the available memory */
int addseg()
{
    struct segment *newseg;
    int i;
    
    /* allocate a new segment */
    if ((newseg = calloc(1,ALLOCSIZE)) != NULL) {

		/* initialize the new segment */
		newseg->sg_size = anodes;
		newseg->sg_next = segs;
		segs = newseg;
	
		/* add each new node to the free list */
		for (i = 0; i < newseg->sg_size; i++) {
		    newseg->sg_nodes[i].n_right = fnodes;
		    fnodes = &newseg->sg_nodes[i];
		}

		/* update the statistics */
		nnodes += anodes;
		nfree += anodes;
		nsegs += 1;
	
		/* return successfully */
		return (TRUE);
    }
    else
		return (FALSE);
}
 
/* left - check for a left sublist */
int left(n)
  struct node *n;
{
    switch (n->n_type) {
    case SYM:
    case SUBR:
    case INT:
    case STR:
    case LIST:
    case FUN:
    case OBJ:
	    return (n->n_left != NULL);
    default:
	    printf("bad node type found during garbage collection\n");
	    exit(0);
    }
}

/* right - check for a right sublist */
int right(n)
  struct node *n;
{
    switch (n->n_type) {
    case SUBR:
    case INT:
    case STR:
	    return (FALSE);
    case SYM:
    case LIST:
    case FUN:
    case OBJ:
	    return (n->n_right != NULL);
    default:
	    printf("bad node type found during garbage collection\n");
	    exit(0);
    }
}

/* fgc - xlisp function to force garbage collection */
struct node *fgc(args)
  struct node *args;
{
    /* make sure there aren't any arguments */
    if (args != NULL)
	xlfail("too many arguments");

    /* garbage collect */
    gc();

    /* return null */
    return (NULL);
}

/* xldmeminit - initialize the dynamic memory module */
xldmeminit()
{
    /* setup the default number of nodes to allocate */
    anodes = NNODES;
    nnodes = nsegs = nfree = gccalls = 0;

    /* define some xlisp functions */
    xlsubr("gc",fgc);
}
