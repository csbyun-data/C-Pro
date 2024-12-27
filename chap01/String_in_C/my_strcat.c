// strcat() 구현

#include <stdio.h>
#include <string.h>

char *my_strcat( char *src, const char *tail ) {
	char *s = src;
	
	for( ; *src ; src++ );
	
	for( ; *tail ; src++, tail++ )
	  *src = *tail;
	*src = '\0';
	
	return s;
}

int main(void)
{
	char buffer[20] = "1234567890";
	my_strcat( buffer, "abcd" );
	printf("buffer = %s\n", buffer );
	
	return 0;
}
