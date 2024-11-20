#include <stdio.h>
#include<string.h>

//define enum
typedef enum  { ROLLNUMB, AGEYEAR, AGEMONTH } eInfoTypes;

//struc contains union
typedef struct {
  eInfoTypes e_Infotype;
  union //Anonyms union {
    int RollNumber;
    int AgeYear;
    int AgeMonth;
  };
} InfoData;

//function to read stored data
void readInformation (const InfoData *MyInfoData, InfoData *ReadData) {
  switch(MyInfoData->e_Infotype) {
  case ROLLNUMB:
    ReadData->RollNumber = MyInfoData->RollNumber; // Read MyInfoData->RollNumber
    break;
  case AGEYEAR:
    ReadData->AgeYear = MyInfoData->AgeYear; // Read MyInfoData->AgeYear
    break;
  case AGEMONTH:
    ReadData->AgeMonth = MyInfoData->AgeMonth; // Read MyInfoData->AgeMonth
    break;
  }
}

//function to write data
void writeInformation (InfoData *MyInfoData) {
  switch(MyInfoData->e_Infotype) {
  case ROLLNUMB:
    MyInfoData->RollNumber = 100; // write MyInfoData->RollNumber
    break;
  case AGEYEAR:
    MyInfoData->AgeYear = 20; // write MyInfoData->AgeYear
    break;
  case AGEMONTH:
    MyInfoData->AgeMonth = 240;  // write MyInfoData->AgeMonth
    break;
   }
}

//Driving main function
int main()
{
  InfoData sInfoData = {(eInfoTypes)0};
  InfoData sReadInfoData = {(eInfoTypes)0};
  sInfoData.e_Infotype = ROLLNUMB;
  writeInformation(&sInfoData);

  readInformation(&sInfoData,&sReadInfoData);
  printf("Roll Number %d\n", sReadInfoData.RollNumber);
  sInfoData.e_Infotype = AGEYEAR;
  writeInformation(&sInfoData);

  readInformation(&sInfoData,&sReadInfoData);
  printf("Age in year %d\n", sReadInfoData.AgeYear);
  sInfoData.e_Infotype = AGEMONTH;
  writeInformation(&sInfoData);

  readInformation(&sInfoData,&sReadInfoData);
  printf("Age in month %d\n", sReadInfoData.AgeMonth);

  return 0;
}

// output: 
// Roll Number 100
// Age in year 20
// Age in month 240
