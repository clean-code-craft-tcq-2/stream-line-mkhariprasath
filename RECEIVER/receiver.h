#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define NO_OF_CONSECUTIVE_AVERAGE 5

void GetFromConsole();
void collectIdData(char consoleData[50][20], int ampData[50], int size);
void collectTempData(char input[50][20], int tempData[50], int size);
float findMaxValue(float * input,int noOfElements);
float findMinValue(float * input,int noOfElements);
float aveOfLastConsecutiveValues(float * input,int noOfElements);
void printOnConsole(float* Max ,float* Min, float* Ave);
void receiverMainFunction(void (*fpPrintOnConsole)(float* ,float*, float*));
