#include <stdio.h>

typedef union {
    unsigned char a;
    unsigned short b;
    unsigned int c;
} SHAREDATA;

int main(void)
{
    SHAREDATA var;
    var.c = 0x12345678;  

    printf("%x\n", var.a);
    printf("%x\n", var.b);
    printf("%x\n", var.c);

    return 0;
}

/*
78
5678
12345678
*/
