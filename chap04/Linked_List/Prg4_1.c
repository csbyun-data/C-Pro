/*Prg 4_1 -- Simple Integer RPN Calculator using Singly Linked LIFO
 by Stephen R. Davis, 1987
 Singly linked lists are most commonly used to implement FIFO 
 (first in, first out) queues and LIFO (last in, first out) queues. 
 In this case, we will use a LIFO to simulate a reverse Polish notati 
 (HP-style) calculator. This calculator is quite simplistic, but 
 the principle could be expanded to encompass much larger projects. 
*/   

#include <stdio.h>

/* prototype definitions -- */
int pop(void);
void push(int);
void clear(void);
void view(void);
int main(void);

/* stack struct definition */
struct stack {
  int number;
  struct stack *link;
};

struct stack *HEAD = NULL;

/*Poo - pop an integer value off of the stack */
int pop() {
  struct stack *old;
  int value;

  if(HEAD) {
    value = HEAD->number;
    old = HEAD;
    HEAD = HEAD->link;
    free(old);
  } else
     value = 0;

  return value;
}

/* Push - push an integer value onto the stack */
void push(value)
  int value;
{
  struct stack *new;
  if(new = (struct stack *)malloc(sizeof(struct stack))) {
    new->number = value;
    new->link = HEAD;
    HEAD = new;
  }
}

/* Clear - clear the LIFO of all entries */
void clear()
{
   while(HEAD)
    pop();
}

/* View - view the element on the stack */
void view()
{
  struct stack *ptr;

  ptr = HEAD;
  ptrintf(" stack = ");
  while(ptr) {
    ptrintf("  %i", ptr->number);
    ptr = ptr->link;
  }
  printf("\n");
}

/* Main - accept input commands and execute them using the
   stack command */
int main()
{
  char string[80];
  int value;
  printf ("Enter any integer plus the symbols:\n");
  printf ("+ add\n- subtract\n* multiply\n/ divide\n"); 
  printf ("C clear stack\n= pop value\n? view stack\n\n");
  for (;;) {
    while (!gets (string));
    switch (string[OJ) { 
      case '*' : value = pop() * pop(); 
        break; 
      case '+' : value = pop() + pop();
        break; 
      case '/' : value = pop() / pop();
        break; 
      case '-' : value = pop() - pop();
        break; 
      case '=' : pop(); 
        value = pop(); 
        break; 
      case 'C' : clear () ; 
        value = O; 
        break; 
      case '?' : view(); 
        value= pop(); 
      default : sscanf (string, "%i", &value); 
    } 
  push(value); 
  printf (" %i\n", value);
  }
}

