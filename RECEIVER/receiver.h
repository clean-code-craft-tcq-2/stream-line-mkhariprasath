#include"../sender.h"

#define NO_OF_CONSECUTIVE_AVERAGE 5

extern float Temp[NOOFDATA]; 
extern float SOC[NOOFDATA] ;
extern float sensorsID[NOOFDATA]; 

Status_t GetFromConsole();
float findMaxValue(float * input,int noOfElements);
float findMinValue(float * input,int noOfElements);
float aveOfLastConsecutiveValues(float * input,int noOfElements);
void printOnConsole(float* Max ,float* Min, float* Ave);
void receiverMainFunction(void (*fpPrintOnConsole)(float* ,float*, float*));
