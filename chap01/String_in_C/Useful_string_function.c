#include <string.h>
#include <stdlib.h>
 
void remchars(char *str, char c);
void remcnks(char *str, char *cnk);
void replchars(char *str, char c1, char c2);
void replcnks(char *str, char *cnk1, char *cnk2);
void reverse(char *str);
 
//remove specified characters from a string
void remchars(char *str, char c) {
  char *pos;
  while(pos = strchr(str,c))
    memmove(pos, pos + 1, strlen(pos));
}
 
//remove specified chunks from a string
void remcnks(char *str, char *cnk) {
  char *pos;
  int clen = strlen(cnk);
  while(pos = strstr(str, cnk))
    memmove(pos, pos + clen, strlen(pos) - clen + 1);
}
 
//replace specified characters in a string
void replchars(char *str, char c1, char c2) {
  char *pos;
  while(pos = strchr(str, c1))
     *pos = c2;
}
 
//replace specified chunks in a string (size-independent, just remember about memory)
void replcnks(char *str, char *cnk1, char *cnk2) {
  char *pos;
  int clen1 = strlen(cnk1), clen2 = strlen(cnk2);
  while(pos = strstr(str, cnk1)) {
    memmove(pos + clen2, pos + clen1, strlen(pos) - clen1 + 1);
    memcpy(pos, cnk2, clen2);
  }
}
 
//reverse a string
void reverse(char *str)
{
    int i;
    int len = strlen(str) - 1;
    int mid = (len % 2) ? (len / 2) : ((len + 1) / 2);
    for(i = 0; i <= mid; ++i)
    {
        char buf = str[i];
        str[i] = str[len - i];
        str[len - i] = buf;
    }
}
