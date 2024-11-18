/*
#include <string.h>

int memcpy(void* dst, const void* src, unsigned int cnt)
{
    uint8_t *pszDest = (uint8_t *)dst;
    const uint8_t *pszSource =( const uint8_t*)src;
    while(cnt)
    {
        *(pszDest++)= *(pszSource++);
        cnt--;
    }
    return 0;
}
*/

#include <stdio.h>
#include <string.h>
int main()
{
  char *pszMessage  = "Welcome to csbyun!";//Source String
  char aszDisplayMessage[32]= {0}; //Destination string
  short siLenString=0;  
    
  siLenString = strlen(pszMessage)+1; // length of source string
  memcpy(aszDisplayMessage, pszMessage,siLenString );//copy source to destination
    
	printf("Message = %s\n", aszDisplayMessage);
    
	return 0;
}
