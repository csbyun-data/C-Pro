// Text menu 기능

#include <stdio.h>
#include <math.h>
#include <string.h>

long bin2dec(char binStr[]);
char* bin2hex(char binStr[]);
long bin2oct(char binStr[]);

char* dec2bin(long decNum);
char* dec2hex(long decNum);
long dec2oct(long decNum);

char* hex2bin(char hexStr[]);
long hex2dec(char hexStr[]);
long hex2oct(char hexStr[]);

char* oct2bin(long octNum);
long oct2dec(long octNum);
char* oct2hex(long octNum);

void main()
{
  int ch;
  char binStr[20], hexStr[20];
  char* pBinStr, *pHexStr;
  long decNum;
  
  do 	{
    printf("\nMainMenu");
    printf("\n1: Binary to Decimal");
    printf("\n2: Binary to Hexadecimal");
    printf("\n3: Decimal to Binary");
    printf("\n4: Decimal to Hexadecimal");
    printf("\n5: Hexadecimal to Binary");
    printf("\n6: Hexadecimal to Decimal");
    printf("\n7: Hexadecimal to Octal");
    printf("\n0: Exit");
    
    printf("\nSelection Number:");
    scanf("%d",&ch);
    
    switch(ch) {
    case 1:
      printf("\nEnterBinary[0,1]:");
      scanf("%s",binStr);
      decNum= bin2dec(binStr);
      if(decNum== -1)
        printf("Invalidstring.");
      else
        printf("Decimal number: %ld",decNum);
      break;
    case 2:
      printf("\nEnterBinary[0,1]:");
      scanf("%s",binStr);
      pHexStr= bin2hex(binStr);
      printf("Hexadecimalnumber: %s",pHexStr);
      break;
    case 3:
      printf("\nEnterdecmal number[0-9]:");
      scanf("%d",&decNum);
      pBinStr= dec2bin(decNum);
      printf("Binarynumber: %s",pBinStr);
      break;
    case 4:
      printf("\nEnterdecmal number[0-9]:");
      scanf("%d",&decNum);
      pBinStr= dec2hex(decNum);
      printf("Hexadecimalnumber: %s",pBinStr);
      break;
    case 5:
      printf("\nEnterHexaDecimal[0-9,A-F]:");
      scanf("%s",hexStr);
      pBinStr= hex2bin(hexStr);
      printf("Binarynumber: %s",pBinStr);
      break;
    case 6:
      printf("\nEnterHexaDecimal[0-9,A-F]:");
      scanf("%s",hexStr);
      decNum= hex2dec(hexStr);
      if(decNum== -1)
        printf("Invalidstring.");
      else
        printf("Decimal number: %ld",decNum);
      break;
    case 7:
      printf("\nEnterHexaDecimal[0-9,A-F]:");
      scanf("%s",hexStr);
      decNum= hex2oct(hexStr);
      
      if(decNum== -1)
        printf("Invalidstring.");
      else
        printf("Octal number: %ld",decNum);
      break;
    case 0:
      printf("Endof Program...\n");
    }
  } while (ch!=0);
}

long bin2dec(char binStr[]) {
  long dnum = 0;
  int i = 0;
  int n;
  
  while(binStr[i] != '\0') {
    n = binStr[i]-48;
  
    if(n != 0 && n != 1)
      return -1;
  
    dnum = (dnum*2) + n;
    i++;
  }	
  return dnum;
}
	
char* bin2hex(char binStr[]) {
  long decNum = 0;
  int i = 0;
  static char* pHexStr;
  
  decNum = bin2dec(binStr);
  
  pHexStr = dec2hex(decNum);
  
  return pHexStr;
}
	
long bin2oct(char binStr[]) {
  long decNum;
  static long octal;
  
  decNum = bin2dec(binStr);
  octal = dec2oct(decNum);
  
  return octal;
}
	
char* dec2hex(long decNum) {
  int remNum;
  int i = 0;
  static char hexStr[20];
  
  while(decNum != 0) {
    remNum = decNum%16;
    if(remNum > 9)
      hexStr[i] = decNum%16+55;
    else
      hexStr[i] = decNum%16+48;
  
    decNum = decNum/16;
    i++;
  }
  hexStr[i] = '\0';
  strrev(hexStr);
  
  return hexStr;
}
	
char* dec2bin(long decNum) {
  static char binStr[20];
  int i = 0;
  
  while(decNum>0) {
    binStr[i] = decNum%2+48;
    decNum = decNum/2;
    i++;
  }
  binStr[i] = '\0';
  strrev(binStr);
  
  return binStr;
}
	
long dec2oct(long decNum) {
  long rem, i = 1;
  static long octal = 0;
  
  while(decNum != 0) {
    rem = decNum%8;
    octal = octal + (rem * i);
    decNum = decNum/8;
    i = i*10;
  }
  
  return octal;
}
	
char* hex2bin(char hexStr[]){
  int i = 0;
  static char binStr[20];
  
  while(hexStr[i]) {
    switch(hexStr[i]) {
      case '0':
        strcat(binStr,"0000");break;
      case '1':
        strcat(binStr,"0001");break;
      case '2':
        strcat(binStr,"0010");break;
      case '3':
        strcat(binStr,"0011");break;
      case '4':
        strcat(binStr,"0100");break;
      case '5':
        strcat(binStr,"0101");break;
      case '6':
        strcat(binStr,"0110");break;
      case '7':
        strcat(binStr,"0111");break;
      case '8':
        strcat(binStr,"1000");break;
      case '9':
        strcat(binStr,"1001");break;
      case 'A':
        strcat(binStr,"1010");break;
      case 'B':
        strcat(binStr,"1011");break;
      case 'C':
        strcat(binStr,"1100");break;
      case 'D':
        strcat(binStr,"1101");break;
      case 'E':
        strcat(binStr,"1110");break;
      case 'F':
        strcat(binStr,"1111");break;
      default:
        printf("\nInvalidhexdecimal digit %c ", hexStr[i]);
      return"";
    }		
    i++;
  }	
  return binStr;
}
	
long hex2dec(char hexStr[]) {
  long decNum = 0;
  int len, val;
  int i = 0;
  
  len = strlen(hexStr)-1;
  
  while(hexStr[i]) {
    if(hexStr[i] >= '0' && hexStr[i] <= '9')
      val = hexStr[i]-48;
    elseif(hexStr[i] >= 'A' && hexStr[i] <= 'F')
      val = hexStr[i]-55;
  
    decNum += val*(long)pow(16,len);
    len--;
    i++;
  }
  return decNum;
}
	
long hex2oct(char hexStr[]) {
  long decNum;
  long octal;
  
  decNum = hex2dec(hexStr);
  octal = dec2oct(decNum);
  
  return octal;
}
	
char* oct2bin(long octNum) {
  int i = 0;
  static char binStr[20];
  long rem;
  
  while(octNum != 0) {
    rem = octNum%10;
  
    switch(rem) {
      case 0:
        strcat(binStr,"000");break;
      case 1:
        strcat(binStr,"001");break;
      case 2:
        strcat(binStr,"010");break;
      case 3:
        strcat(binStr,"011");break;
      case 4:
        strcat(binStr,"100");break;
      case 5:
        strcat(binStr,"101");break;
      case 6:
        strcat(binStr,"110");break;
      case 7:
        strcat(binStr,"111");break;
      default:
        printf("\nInvalidoctal digit %d ", rem);
        return"";
    }		
    octNum = octNum/10;
  }	
  return binStr;
}
	
long oct2dec(long octNum) {
  long rem;
  long i = 1;
  static long decNum;
  
  while(octNum != 0) {
    rem = octNum%10;
    decNum += rem*i;
    octNum /= 10;
    i = i*8;
  }
  
  return decNum;
}
	
char* oct2hex(long octNum) {
  long decNum;
  static char *pBinStr;
  
  decNum = oct2dec(octNum);
  pBinStr = dec2bin(decNum);
  
  return pBinStr;
}

/* 
Main Menu

 1:Binary to Decimal

 2:Binary to Hexadecimal

 3:Decimal to Binary

 4:Decimal to Hexadecimal

 5:Hexadecimal to Binary

 6:Hexadecimal to Decimal

 7:Hexadecimal to Octal

 0:Exit

 Selection Number:1

 

Enter Binary[0,1]:1111

 Decimal number: 15

Main Menu

 1:Binary to Decimal

 2:Binary to Hexadecimal

     ..

 0: Exit

 Selection Number:2

 

Enter Binary[0,1]:1111

Hexadecimal number: F

Main Menu

 1:Binary to Decimal

 2:Binary to Hexadecimal

 3:Decimal to Binary

     ..

 0:Exit

 Selection Number:3

 

Enter decmal number[0-9]:15

Binary number: 1111

Main Menu

 1:Binary to Decimal

 2:Binary to Hexadecimal

 3:Decimal to Binary

 4:Decimal to Hexadecimal

     ..

 0:Exit

 Selection Number:4

 

Enter decmal number[0-9]:15

Hexadecimal number: F

Main Menu

      ..

 5:Hexadecimal to Binary

 6:Hexadecimal to Decimal

 7:Hexadecimal to Octal

 0:Exit

 Selection Number:5

 

Enter HexaDecimal[0-9,A-F]:F

Binary number: 1111

Main Menu

     ..

 6:Hexadecimal to Decimal

 7:Hexadecimal to Octal

 0:Exit

 Selection Number:6

 

Enter HexaDecimal[0-9,A-F]:F

 Decimal number: 15

Main Menu

     ..

 7:Hexadecimal to Octal

 0:Exit

 Selection Number:7

 

Enter HexaDecimal[0-9,A-F]:F

 Octalnumber: 17

Main Menu

      ..

 7:Hexadecimal to Octal

 0:Exit

 Selection Number:0

End of Program...

Press any key to continue
*/
