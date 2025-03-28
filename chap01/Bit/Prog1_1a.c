/*Prgl_la - Simple bit manipulation functions by Stephen R. Davis, '87 

 Simple Clacks "bit picking" primitives. The following routines 
 provide some simple bit manipulation capabilities. 
*/ 

#include <stdio.h> 
//#include "mylib.h" 

/*define an array of bits which we use for the following routines*/ 

static char bitarray[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01}; 

/*SetBit - set the 'bitnum'th bit offset from 'ptr'*/ 
void setbit (ptr, bitnum) 
  char *ptr; 
  unsigned bitnum; 
{
  unsigned bitpos, bytepos; 
  
  bytepos = bitnum >> 3; 
  bitpos = bitnum & 0x07; 
  *(ptr+bytepos) |= bitarray[bitpos]; 
}

/*ClrBit - clear the 'bitnum'th bit offset from 'ptr'*/ 
void clrbit (ptr, bitnum) 
  char *ptr; 
  unsigned bitnum; 
{
  unsigned bitpos, bytepos; 
  
  bytepos = bitnum >> 3; 
  bitpos = bitnum & 0x07; 
  *(ptr+bytepos) &= -(bitarray[bitpos]); 
}

/*TestBit - test the 'bitnum'th bit offset from 'ptr'. 
            Return a 0 if the bit is cleared, and a 1 if set.*/ 
char testbit (ptr, bitnum) 
  char *ptr; 
  unsigned bitnum; 
{
  unsigned bitpos, bytepos; 
  
  bytepos = bitnum >> 3; 
  bitpos = bitnum & 0x07; 
  if (*(ptr+bytepos) & bitarray[bitpos]) 
    return (1); 
  return(0); 
}

/*HexDump - display in l's and O's starting from 'ptr'*/ 
void hexdump (ptr, nobytes) 
  char *ptr; 
  unsigned nobytes; 
{
  int nobits; 
  
  for (; nobytes; ) {
    for (nobits = 0; nobits < 8; nobits++)  {
      if (testbit (ptr,nobits)) 
        printf ("l"); 
      else 
        printf ("0"); 
    }
    printf (" "); 
    if (! (--nobytes % 8)) 
      printf ("\n"); 
    ptr++; 
  }
}

/*Main - test the above routines*/ 
int main () 
{ 
  char buffer[16]; 
  int i,bit; 
  
  for (i = 0; i < 16; i++) /* test SetBit */
    buffer[i] = 0; 
  for (; ;) { 
    hexdump (buffer,16); 
    printf ("\nenter the number of bit to set (>=128 quits):"); 
    scanf ("%d",&bit); 
    printf ("\n"); 
    if (bit >= 128) 
      break; 
    setbit (buffer,bit); 
  }
  printf ("\n\n"); 
  
  for (i = 0; i < 16; i++) /* now test ClrBit */
    buffer[i] = -1; 
  for (; ;) { 
    hexdump (buffer,16); 
    printf ("\nenter the number of bit to clear (>=128 quits):"); 
    scanf ("%d",&bit); 
    printf ("\n"); 
    if (bit >= 128) 
      break; 
    clrbit (buffer, bit); 
  }
  printf ("\n\nThat's all folks!"); 
}
