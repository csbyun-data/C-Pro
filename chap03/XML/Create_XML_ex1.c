#include <stdio.h>
#include <string.h>

/**Structure, contains a field which will be sent to the server**/
typedef struct {
  char aszMessage[64];
  char aszUserId[20];
  char aszPassword[12];
} sRequestData;

// Function to create a XML Tag
void SetValueInXmlTag(char *pszXmlRequest,const char *pszSource,const char *pszXmlTag) {
  short iLen=0;
  char acXmlTag[120]= {0};
  iLen =strlen(pszSource);
  if(0 == iLen) {
    sprintf(acXmlTag,"<%s>%s</%s>",pszXmlTag,"0",pszXmlTag);
  } else {
    sprintf(acXmlTag,"<%s>%s</%s>",pszXmlTag,pszSource,pszXmlTag);
  }
  strcat(pszXmlRequest,acXmlTag);
}

//XML Request which will be send to the server.
short XmlRequest(sRequestData *psRequestData,char *pszXmlRequest) {
  short lRequest=0;
  
  /*Create XML Request*/
  strcpy(pszXmlRequest,"<BODY>");
  SetValueInXmlTag(pszXmlRequest,psRequestData->aszUserId,"USER_ID");
  SetValueInXmlTag(pszXmlRequest,psRequestData->aszPassword,"PASSWORD");
  SetValueInXmlTag(pszXmlRequest,psRequestData->aszMessage,"MESSAGE");
  strcat(pszXmlRequest,"</BODY>");
  lRequest=strlen(pszXmlRequest);
  
  return lRequest; // Length of request data
}

// Driver program
int main()
{
  sRequestData RequestData = {0}; //structure to contain data
  char aszXmlRequest[200]= {0}; //Buffer to store XML request data
  printf("Enter User Id = ");
  scanf("%s",&RequestData.aszUserId);
  printf("\n\nEnter Password = ");
  scanf("%s",&RequestData.aszPassword);
  printf("\n\nEnter Message = ");
  scanf("%s",&RequestData.aszMessage);
  XmlRequest(&RequestData,aszXmlRequest);
  printf("\n\nRequest = %s\n\n\n\n\n\n",aszXmlRequest);
  
  return 0;
}
