#include <string.h>


#define NO_OF_CONSECUTIVE_AVERAGE 5

extern float Temp[NOOFDATA]; 
extern float SOC[NOOFDATA] ;
extern float sensorsID[NOOFDATA]; 


 extern float Temperature  [NOOFDATA] ;
 extern float StateOfCharge[NOOFDATA]; 
 extern int   sensorID     [NOOFDATA] ;

void GetFromConsole();
void collectIdData(char consoleData[50][20], int ampData[50], int size);
void collectTempData(char input[50][20], int tempData[50], int size);
float findMaxValue(float * input,int noOfElements);
float findMinValue(float * input,int noOfElements);
float aveOfLastConsecutiveValues(float * input,int noOfElements);
void printOnConsole(float* Max ,float* Min, float* Ave);
void receiverMainFunction(void (*fpPrintOnConsole)(float* ,float*, float*));
