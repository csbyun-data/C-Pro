#include <stdio.h>
#include <string.h>

int main(void)
{
  int iLoop = 0;
  int aiSrc [5]  = {100,200,300,400,500};//integer array
  int aiDst[5]= {0}; //Destination array
    
  memcpy(aiDst, aiSrc,sizeof(aiSrc));//copy integer array
  for(iLoop =0; iLoop <5 ; iLoop++) {
    printf("%d ",aiDst[iLoop]);
  }
    
  return 0;
}
