#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 
| This routine converts the macro  __TIME__ to standard format
| Example:   "11:50:21" -> "115021"
|----------------------------------------------------------------------------|
| CALL:
|    strcpy(string, time_mac_conv(string) );
| HEADER:
|    string.h    : strcpy
|    stdio.h     : sscanf, sprintf
| GLOBALE VARIABLES:
|    %
| ARGUMENTS:
|    pszTime      : String with time in  __TIME__ format (HH:MM:SS)
| PROTOTYPE:
|    char far *time_mac_conv(char *pszTime);
| RETURN VALUE:
|    char szStr   : Time in format HHMMSS
| MODULE:
|    time__.c
\---------------------------------------------------------------------------|*/

char *time_mac_conv(char *pszTime) {
  static char  szStr[12];            /* Convertion string */
  char  hh[3],                /* Hour     */
        mm[3],                /* Minutes  */
        ss[3];                /* Seconds  */
  
  strcpy(szStr, pszTime);     /* Copy string */
  sscanf(szStr, "%2s %*c %2s %*c %2s", hh, mm, ss);
  
  /* Split the string into basics */
  sprintf(szStr, "%s%s%s", hh,mm,ss);
  
  /* Assemble new string */
  return((char *) szStr);    /* Return new string */
}

int main()
{
  char pszTime[]= "11:50:21";
  printf("%s\n", time_mac_conv(pszTime));
  
  return 0;
}
