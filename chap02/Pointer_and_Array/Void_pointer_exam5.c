#include <stdio.h>

#define ELEMENT_SIZE(x) sizeof(x[0]);
#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

// compare function for integer array
int compareInt(const void *a, const void *b)
{
  int x = *(const int *)a;
  int y = *(const int *)b;

  if ( x<y )
    return -1; // -1 for ascending, 1 for descending order.
  else if ( x>y )
    return 1;  // 1 for ascending, -1 for descending order.

  return 0;
}

//compare function for float array
int compareFloat(const void *a, const void *b) {
  float x = *(const float *)a;
  float y = *(const float *)b;

  if (x < y)
    return -1; //-1 for ascending, 1 for descending order.
  else if (x > y)
    return 1; //1 for ascending, -1 for descending order.
  return 0;
}

int main(int argc, char *argv[])
{
  //Integer array
  int iData[] = { 40, 10, 100, 90, 20, 25 };

  //float array
  float fData[] = {1.2,5.7,78,98.5,45.67,81.76};

  //array index
  int index = 0;

  //sorting integer array
  qsort(iData,ARRAY_SIZE(iData),ELEMENT_SIZE(iData),compareInt);
  for (index=0; index<ARRAY_SIZE(iData); index++)
  {  printf ("%d ",iData[index]); }
  printf("\n\n");

  //sortig float array
  qsort(fData,ARRAY_SIZE(fData),ELEMENT_SIZE(fData),compareFloat);
  for (index=0; index<ARRAY_SIZE(fData); index++)
  { printf ("%f     ",fData[index]); }
  return 0;
}
