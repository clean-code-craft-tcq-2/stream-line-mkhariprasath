#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define NO_OF_CONSECUTIVE_AVERAGE 5

void GetFromConsole();
void collectIdData(char consoleData[50][20], int ampData[50], int size);
void collectTempData(char input[50][20], int tempData[50], int size);
int findMaxValue(int * input,int noOfElements);
int findMinValue(int * input,int noOfElements);
int aveOfLastConsecutiveValues(int * input,int noOfElements);
void printOnConsole(int* Max ,int* Min, int* Ave);
void receiverMainFunction(void (*fpPrintOnConsole)(int* ,int*, int*));
