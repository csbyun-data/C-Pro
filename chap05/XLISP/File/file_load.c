#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <setjmp.h>

/* global variables */
jmp_buf xljmpbuf;

/* local variables */
static int savech;

int (*xlgetc)();
int xlpvals;

static int prompt;
static FILE *ifp;

/* tgetc - get a character from the terminal */
static int tgetc() {
  int ch;
  
  /* prompt if necessary */
  if (prompt) {
  printf("> ");
  prompt = false;
  }
  
  /* get the character */
  if ((ch = getchar()) == '\n')
  prompt = true;
  
  /* return the character */
  return (ch);
}

/* xltin - setup terminal input */
int xltin() {
  /* initialize */
  prompt = true;
  xlgetc = tgetc;
  xlpvals = true;
}

/* xfgetc - get a character from a file */
static int xfgetc() {
  int ch;
  
  /* get a character */
  if ((ch = getc(ifp)) <= 0) {
    xlgetc = tgetc;
    xlpvals = true;
    return (tgetc());
  }
  
  /* return it */
  return (ch);
}

/* xlfin - setup file input */
void xlfin(char *str) {
  char fname[100];
  
  /* create the file name */
  strcpy(fname, str);
  
  /* open the input file */
  if ((ifp = fopen(fname,"r")) == NULL) {
    printf("can't open \"%s\" for input\n",fname);
    return;
  }
  
  /* setup input from the file */
  xlgetc = xfgetc;
  xlpvals = false;
}

/* xlread - read an xlisp expression */
void xlread() {
  int ch;
  
  /* initialize */
  savech = -1;    
  
  /* read an content */
  while (true) {
    ch = getch();  // (*xlgetc)(), 문자 1개 읽어들임 
    printf("%c", ch);
    if (ch == '\n')
      break;
  }
}


/* thisch - look at the current character */
int thisch() {
  /* return and save the current character */
  return (savech = getch());
}

/* getch - get the next character */
int getch() {
  int ch;
  
  /* check for a saved character */
  if ((ch = savech) >= 0)
    savech = -1;
  else
    ch = (*xlgetc)();
  
  /* return the character */
  return (ch);
}


int main( int argc, char *argv[])
{
  /* initialize terminal input */
  xltin();
  
  /* read the input file if specified */
  if (argc > 1)
    xlfin(argv[1]);
  
  
  /* main command processing loop */
  while (true) {
    /* setup the error return */
    setjmp(xljmpbuf);    
    
    /* read an expression */
    xlread();	
  }
}
