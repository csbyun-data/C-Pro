/* xlio - xlisp i/o routines */

#include <stdio.h>
#include "xlisp.h"

/* global variables */
int (*xlgetc)();
int xlpvals;

/* local variables */
static int prompt;

/* tgetc - get a character from the terminal */
static int tgetc()
{
    int ch;

    /* prompt if necessary */
    if (prompt) {
		printf("> ");
		prompt = FALSE;
    }

    /* get the character */
    if ((ch = getchar()) == '\n')
		prompt = TRUE;

    /* return the character */
    return (ch);
}

/* xltin - setup terminal input */
int xltin()
{
    /* initialize */
    prompt = TRUE;
    xlgetc = tgetc;
    xlpvals = TRUE;
}
