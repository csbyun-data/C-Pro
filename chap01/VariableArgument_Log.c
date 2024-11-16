#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void logfile(const char *str, ...);

int main() {
   int i;
	
   for(i=0; i<10; i++) {
        logfile("log %d", i);
   }
}

void logfile(const char *str, ...) {
    FILE* stream;
    va_list arg_ptr;
    char buf[50];
    struct tm* curtime;
    time_t ltime;
	
    va_start(arg_ptr, str);
	
    stream = fopen("logfilex.txt","a");
    time(&ltime);
    curtime = localtime(&ltime);
    sprintf(buf, "%d:%d", curtime->tm_hour, curtime->tm_min);
    fwrite(buf, strlen(buf), 1, stream);
	
    vfprintf(stream, str, arg_ptr);
    va_end(arg_ptr);
	
    fputc('\n', stream);
    fflush(stream);
    fclose(stream);
}
