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
