/* Turbo C The Art of Advanced Program Design Optimization and Debugging_1987
  Prg8_4 - The Maze Problem 
  by Stephen R. Davis, 1987 
  
  Notice how small this reiterative solution to the maze problem 
  is. The routine evaluate() checks the current location for 
  cheese (success) or wall (failure). If the answer is neither, 
  it then calls itself in each of the 3 directions open to it 
  (we forbid it from looking in the direction from which it came) 
  until success or failure is attained. The successful path is 
  marked with '.'s. 
  
  Create mazes with any ASCII file editor. Rules for mazes are: 
   - no loops 
   - halls marked with spaces 
   - cheese marked with '&' (need not be present) 
   - halls must be single space wide 
   - must have a single opening at the top; search starts here 
*/ 

#include <stdio.h> 
#include <dos.h> 
#include <conio.h>

char screenaddr[30*80];
#define screen(y,x) screenaddr [(y * 80) + x] 

#define space ' ' 
#define cheese '&' 
#define path '.' 
#define VISIBLE 1 

/*define prototypes for routines used*/ 

int main (int, char**); 
void readmaze (FILE*); 
int evaluate (unsigned, unsigned, unsigned); 
int value (unsigned, unsigned); 

/*Main - if one argument provided, read it up onto the screen and 
  evaluate it for a maze solution*/ 
int main (argc, argv) 
  int argc; 
  char *argv[]; 
{
  FILE *fp; 
  unsigned x; 

  /*clear the screen - first line of maze must be at top of screen*/ 
  //clrscr (); 

  if (argc == 2) { 
    if (fp = fopen(argv[1], "r")) { 
      readmaze (fp); 

      /*solve maze by finding a space in the top and 
        searching from there*/ 
      for (x = 0; (char) screen (0, x) != space; x++); 
      if (evaluate (0, x, 2)) {
        printf ("\nsolution!\n"); 
        printmaze();
      } else 
        printf ("\nno solution found\n"); 
    } else 
      printf ("File not found\n"); 
  } else 
    printf ("Enter 'Prg8 4 <filename>'\n" 
            "  where filename contains the maze to be solved\n"); 
  

}

/*Readmaze - read a maze from a file onto the screen. Transfer 
  only the character part to the screen.*/ 
void readmaze (fptr) 
  FILE *fptr; 
{
  char buffer [81]; 
  
  int x, y=0;
  while (fgets (buffer, 80, fptr)) {
  	for(x=0; x<80; x++) {
      if (buffer[x] != '\n' )		
  	  	screen(y,x) = buffer[x];
  	  else {
  	  	screen(y,x) = buffer[x];
  	  	break;
	  }
	}
	y++;
    
    printf (buffer);     
  } 
}

/*Evaluate - solve the maze*/ 
int deltax [] = {0, 1, 0, -1};   /*define the directions*/
int deltay [] = {-1, 0, 1, 0}; 
int noallow [] = {2, 3, 0, 1}; 

int evaluate(yloc, xloc, prevmove) 
  unsigned yloc, xloc, prevmove; 
{
  int i, val; 
  int value(); 
  
  if ((val= value(xloc, yloc)) == -1) /* wall */ 
    return 0; 
  if (val == 1)                       /*cheese!*/ 
    return 1; 
    
  for (i = 0; i < 4; i++) /*4 possible moves*/ 
    if (i != noallow[prevmove]) /*don't go backwards*/ 
      if (evaluate(yloc+deltay[i], xloc+deltax[i], i)) { 
        screen (yloc, xloc) = path; /*found it!*/ 
        return 1; 
      }
  return 0; /*nothing down this path*/ 
}

/*Value - evaluate the current location*/ 
int value (xloc, yloc) 
  unsigned xloc, yloc; 
{
  char curr; 
  int i; 
  
  curr = (char)screen (yloc, xloc); 
#if VISIBLE                 /*make the search visible*/  
  screen (yloc, xloc) = '#'; 
  for (i = 0; i < 10000; i++) ;
  screen (yloc, xloc) = curr; 
#endif 
  switch (curr) { 
    case cheese: return 1;  /*cheese -> success*/ 
    case space : return 0;  /*space -> keep looking*/ 
    default    : return -1; /*else -> can't go that way*/ 
  }
}

void printmaze()
{
  int i, j;
  for(j=0; j <= 10; j++) {
    for(i=0; i<80; i++) {
    	if (screenaddr[j*80+i] != '\n' )
			printf("%c", screenaddr[j*80+i]);
		else {
		   break;
		}
	}
    printf("\n");
  }	
}
