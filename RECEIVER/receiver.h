#include"../sender.h"

#define NO_OF_CONSECUTIVE_AVERAGE 5

Status_t GetFromConsole();
float findMaxValue(float * input,int noOfElements);
float findMinValue(float * input,int noOfElements);
float aveOfLastConsecutiveValues(float * input,int noOfElements);
void printOnConsole(float* Max ,float* Min, float* Ave);
void receiverMainFunction(void (*fpPrintOnConsole)(float* ,float*, float*));



extern Status_t readDataFromFile();
extern Status_t fillRandomData();
extern Status_t passToConsole();
extern float    optimumValuesRandom(float min, float max);

extern Status_t fetchData(Status_t (*fp_InputFunction)());
extern Status_t passDataToOutput(Status_t (*fp_OutputFunction)());
