#include"receiver.h"

void GetFromConsole(char consoleData[NOOFDATA][20])
{
    char line[NOOFDATA];
    char *result;
    result = fgets(line,NOOFDATA,stdin);
    for(int i = 0;result != NULL;i++)
    {
	result = fgets(line,NOOFDATA,stdin);
        strcpy(consoleData[i], line);       
        
    }
}

void collectIdData(char consoleData[NOOFDATA][20], int sensorIdData[NOOFDATA], int size)
{
    for (int i = 0; i < size; i++)
    {
        char *DataString = strtok(consoleData[i], ",");
        sensorIdData[i] = atoi(strtok(DataString, " "));     	  
     
    }
}

void collectTempData(char consoleData[NOOFDATA][20], int tempData[NOOFDATA], int size)
{
    for (int i = 0; i < size; i++)
    {
        char *tempDataString = strtok(consoleData[i], ",");
        tempData[i]  =  atoi(strtok(NULL, ","));
        
    }
}


void collectSocData(char consoleData[NOOFDATA][20], int socData[NOOFDATA], int size)
{
        for (int i = 0; i < size; i++)
    {
       char *token = strtok(consoleData[i], ",");
        while( token != NULL ) 
        {
        socData[i] = atoi(token);
        token = strtok(NULL, ",");
   
        }
        
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
        char consoleData[NOOFDATA][20];
	int tempData[NOOFDATA],idData[NOOFDATA],socData[NOOFDATA];
    	int Max[3], Min[3] ,Ave[3];

	GetFromConsole(consoleData);
        collectIdData(consoleData,idData,NOOFDATA);
        collectTempData(consoleData,tempData,NOOFDATA);
        collectSocData(consoleData,socData,NOOFDATA);
	
	     Max[0] = findMaxValue( tempData,NOOFDATA);
	     Min[0] = findMinValue( tempData,NOOFDATA);
	     Ave[0] = aveOfLastConsecutiveValues(tempData,NOOFDATA);
	     Max[1] = findMaxValue( socData,NOOFDATA);
	     Min[1] = findMinValue( socData,NOOFDATA);
	     Ave[1] = aveOfLastConsecutiveValues(socData,NOOFDATA);	
	     Max[2] = findMaxValue( idData,NOOFDATA);
	     Min[2] = findMinValue( idData,NOOFDATA);
	     Ave[2] = aveOfLastConsecutiveValues(idData,NOOFDATA);
      
	fpPrintOnConsole(Max,Min,Ave);
}
