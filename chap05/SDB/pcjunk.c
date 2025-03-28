/*  PCJUNK.C     Misc. procedures */

#include <stdio.h>
#include <stdlib.h>

#include "sdbio.h"

/*    Replaces JUNK.C for the IBM/PC version            dns */


char *alloc(n)
int n;
{
   return (char*) malloc(n);
}


int getcx(fp)
  FILE *fp;
{
    static char buf[LINEMAX] = {0};
    static char *pbuf = buf;
    int ch, i;

    if (fp!=stdin)
       if ((ch = getc(fp)) == '\r')
          return getc(fp);
       else
          return ch;

    if (*pbuf > 0)
       return *pbuf++;

    pbuf = buf;
    for (i = 0; (ch = getc(fp)) != -1; )
        if (i < LINEMAX)  {
            if (ch == ESC)     { i=0;  putchar('\n'); fflush(stdout); }  else
            if (ch == BS)      { if (i>0)  i--;                       }  else
               buf[i++] = ch;
            if (ch == '\n')    break;
            }
        else {
            printf("*** line too long ***\nRetype> ");
            i = 0;
        }
    buf[i] = EOS;
     return getcx(fp);
}

#if 0

/*    string copy up to n characters    */
strncpy(to, from, n)
char *to, *from;
int n;
{
  char *cp;

  for( cp=to; n-- && (*cp++ = *from++);  ) ;
  if( n<0 )   *cp = 0;
  return to;
}

/*    string compare up to n characters     */
strncmp(s1, s2, n)
char *s1, *s2;
int n;
{

  for( ;n-- && (*s1==*s2); s2++ )
     if( !*s1++ )
        return 0;
  if( n < 0 )
     return 0;
  if( *s1 < *s2 )
     return -1;
  return 1;
}
#endif
