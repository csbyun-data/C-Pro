/* xlisp - a small subset of lisp */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* useful definitions */
#define TRUE	1
#define FALSE	0

/* program limits */
#define STRMAX	100	/* maximum length of a string constant */
#define NNODES	2000	/* number of nodes to allocate in each request */

/* node types */
#define FREE	0
#define SUBR	1
#define LIST	2
#define MSG	2
#define BND	2
#define SYM	3
#define INT	4
#define STR	5
#define FUN	8
#define OBJ	9

/* node flags */
#define MARK	1
#define LEFT	2

/* string types */
#define DYNAMIC	0
#define STATIC	1

/* symbol structure */
struct xsym {
    char *xsy_name;		/* symbol name */
    struct node *xsy_value;	/* the current value */
};

/* subr node structure */
struct xsubr {
    struct node *(*xsu_subr)();		/* pointer to an internal routine */
};

/* list node structure */
struct xlist {
    struct node *xl_value;	/* value at this node */
    struct node *xl_next;	/* next node */
};

/* integer node structure */
struct xint {
    int xi_int;			/* integer value */
};

/* string node structure */
struct xstr {
    int xst_type;		/* string type */
    char *xst_str;		/* string pointer */
};

/* shorthand macros for accessing node substructures */

/* symbol node */
#define n_symname	n_info.n_xsym.xsy_name
#define n_symvalue	n_info.n_xsym.xsy_value

/* subr node */
#define n_subr		n_info.n_xsubr.xsu_subr

/* list node (and message node and binding node) */
#define n_listvalue	n_info.n_xlist.xl_value
#define n_listnext	n_info.n_xlist.xl_next
#define n_msg		n_info.n_xlist.xl_value
#define n_msgcode	n_info.n_xlist.xl_next
#define n_bndsym	n_info.n_xlist.xl_value
#define n_bndvalue	n_info.n_xlist.xl_next
#define n_left		n_info.n_xlist.xl_value
#define n_right		n_info.n_xlist.xl_next
#define n_ptr		n_info.n_xlist.xl_value

/* integer node */
#define n_int		n_info.n_xint.xi_int

/* function node */
#define n_funargs	n_info.n_xfun.xf_funargs
#define n_funcode	n_info.n_xfun.xf_funcode

/* node structure */
struct node {
    char n_type;		/* type of node */
    char n_flags;		/* flag bits */
    union {			/* value */
	struct xsym n_xsym;	/*     symbol node */
	struct xsubr n_xsubr;	/*     subr node */
	struct xlist n_xlist;	/*     list node */
	struct xint n_xint;	/*     integer node */
    } n_info;
};
