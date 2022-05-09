#include"receiver.h"


/*Status_t GetFromConsole()
{
    for(int i = 0; i <NOOFDATA; i++)
    {
        //  Temp[i] = Temperature[i];
        //  SOC[i] = StateOfCharge[i];
      //    sensorsID[i] =  (float)sensorID[i];
         
    }
    return E_OK;
}
*/

void GetFromConsole(char consoleData[50][20])
{
    char line[50];
    char *result;
	result = fgets(line,50,stdin);
    for(int i = 0;result != NULL;i++)
        {
	result = fgets(line,50,stdin);
        strcpy(consoleData[i], line);       
        
    }
}

void collectIdData(char consoleData[50][20], int ampData[50], int size)
{
    for (int i = 0; i < size; i++)
    {
        char *ampDataString = strtok(consoleData[i], ",");
        int ampDataValueString = atoi(strtok(ampDataString, " "));     	  
        ampData[i] = ampDataValueString;
    }
}

void collectTempData(char input[50][20], int tempData[50], int size)
{
    for (int i = 0; i < size; i++)
    {
        char *tempDataString = strtok(input[i], ",");
        char *tempDataValueString = strtok(NULL, " ");
        int tempDataValue = atoi(strtok(NULL, " "));
        tempData[i] = tempDataValue;
    }
}

int findMaxValue(int * input,int noOfElements)
{   float maxValue = input[0];

	for (int i =1; i < noOfElements;i++)
	{
		if( maxValue < input[i] )
		  maxValue = input[i];
	}
	return maxValue;
}

int findMinValue(int * input,int noOfElements)
{   float minValue = input[0];

	for (int i =1; i < noOfElements;i++)
	{
		if( minValue > input[i] )
		  minValue = input[i];
	}
return minValue;
}

int aveOfLastConsecutiveValues(int * input,int noOfElements)
{
int	startIndex = noOfElements - NO_OF_CONSECUTIVE_AVERAGE ;
	float total = 0;

	for (int i= startIndex ;i < noOfElements;i++)
	{
	   
		total += input[i];
	}

	return (total/NO_OF_CONSECUTIVE_AVERAGE);
}

void printOnConsole(int* Max ,int* Min, int* Ave)
{
	for(int i = 0; i<2; i++)
    {
		 printf("Max: %d,Min: %d,Average: %d\n", Max[i], Min[i], Ave[i]);
	}
}
void receiverMainFunction(void (*fpPrintOnConsole)(int* ,int*, int*))
{
    char consoleData[50][20];
	int tempData[50],idData[50],socData[50];
    	int Max[3], Min[3] ,Ave[3];

	GetFromConsole(consoleData);
collectIdData(consoleData,idData,50);
collectTempData(consoleData,tempData,50);
//collectSocData(consoleData,socData,50);
	 Max[0] = findMaxValue( tempData,9);
     Min[0] = findMinValue( tempData,9);
     Ave[0] = aveOfLastConsecutiveValues(tempData,9);
	// Max[1] = findMaxValue( SOC,9);
    // Min[1] = findMinValue( SOC,9);
    // Ave[1] = aveOfLastConsecutiveValues(SOC,9);	
	 Max[2] = findMaxValue( idData,9);
     Min[2] = findMinValue( idData,9);
     Ave[2] = aveOfLastConsecutiveValues(idData,9);
      
	 fpPrintOnConsole(Max,Min,Ave);
}
