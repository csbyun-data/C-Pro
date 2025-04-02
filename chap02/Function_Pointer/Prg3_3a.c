/* Prg 3_4 - the classic Bubble Sort using user-supplied routines 
 by Stephen R. Davis, 1987 
 
 The bubble sort routine first appeared in Kernighan and Ritchie as 
 an example of the passing of one routine to another. This is a 
 further generalization of that routine. This version is as 
 completely g~neral as is possible. 
 
 SORT () can sort ANY data type, including any user defined 
 structure, if provided with three routines: one to compare two 
 entries, another to swap two entries and a third to sequence from 
 one entry to the next. The details of these routines are given 
 below. Sort returns a 0 if the sort is successful and a -1 
 otherwise. 
 
 COMPARE(ptrl, ptr2) 
 receives two pointers to the structures to be compared. 
 Returns a -1 if *ptrl < *ptr2, a 0 if *ptrl == *ptr2, and 1 if 
 *ptrl > *ptr2 for ascending order and the opposite for 
 descending. 
 
 SWAP (ptrl, ptr2) 
 receives two pointers to structures. Upon returning *ptr2 is 
 in the location of *ptrl and visca versa. If ptrl == ptr2 then 
 swap() has no effect. Swap() returns a 0 if the exchange is 
 successful and a non-zero otherwise. 

 SEQUENCE (ptrl) 
 receives a pointer to an entry. Returns a pointer to the 
 next entry. Notice that the definition of "next" is left to 
 the user. If ptrl == 0, sequence() returns the first entry. 
 If sequence () == 0 then the end of sequence has been reached. 
*/ 
 
#include <stdio.h> 
 
/*prototype definitions --*/ 
int sort (int (*)(void*, void*), int(*) (void*, void*), 
void * (*) (void *)); 
 
/*Sort - implement bubble sort*/ 
int sort (compare, swap, sequence) 
 int (*compare) (void*, void*), (*swap) (void*, void*); 
 void *(*sequence) (void *); 
{
	int flag; 
	void *pl, *p2; 
	do { 
		flag = 0; 
		p2 = (*sequence) (0); /*starting w/ first entry ... */ 
		while (pl= p2, p2 = (*sequence) (p2)) { /* ... sequence thru*/ 
			if ((*compare) (pl, p2) > 0) { /*if pl> p2 ... */ 
				if ((*swap)(pl, p2)) return -1;/* ... swappl & p2*/ 
				flag = 1; 
			}
		}
	} while (flag); 	/* stop when all are in order */
	return 0; 
}

/*simple example of using SORT() --
  let's simply sort an array of integers called "data" declared 
  globally with N entries. Convince yourself that the 3 routines 
  below actually operate according to the description above. Then 
  prove that it works at all by executing the p~ogram. 
*/
 
#define N 10 
int data [N]; 

int compare (i1, i2) 
  int *i1, *i2; 
{
	if (*i1 != *i2) return (*i1 > *i2)  ? 1: -1;
	return 0; 
}

int swap (il, i2) 
  int *il, *i2; 
{
	int temp; 
	
	temp = *il; 
	*il = *i2; 
	*i2 = temp; 
	
	return 0; 
}

void *sequence (i) 
  int *i; 
{
	if (i) 
		if (i == &data[N - 1])  /*if last entry ... */ 
			return 0;			/* ... return a 0; else ... */ 
		else
			return ++i;			/* ... return the next entry*/ 
	else
		return data;			/*return first entry*/ 
}


int main () 
{
	int i; 

	printf ("Enter a sequence of %d integers\n", N); 
	for (i = 0; i < N; i++) 
		scanf ("%d", &data[i]); 
	if (sort (compare, swap, sequence)) 
		printf ("Error during sort!\n"); 
	printf ("\n\nHere is the sorted sequence\n"); 
	for (i = 0; i < N; i++) 
		printf ("%d ", data[i]); 
}
