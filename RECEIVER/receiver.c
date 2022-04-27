#include"receiver.h"


 float Temp[NOOFDATA] ={}; 
 float SOC[NOOFDATA] = {};
 float sensorsID[NOOFDATA] = {}; 

Status_t GetFromConsole()
{
    for(int i = 0; i <NOOFDATA; i++)
    {
          Temp[i] = Temperature[i];
          SOC[i] = StateOfCharge[i];
          sensorsID[i] =  (float)sensorID[i];
         
    }
    return E_OK;
}


float findMaxValue(float * input,int noOfElements)
{   float maxValue = input[0];

	for (int i =1; i < noOfElements;i++)
	{
		if( maxValue < input[i] )
		  maxValue = input[i];
	}
	return maxValue;
}

float findMinValue(float * input,int noOfElements)
{   float minValue = input[0];

	for (int i =1; i < noOfElements;i++)
	{
		if( minValue > input[i] )
		  minValue = input[i];
	}
return minValue;
}

float aveOfLastConsecutiveValues(float * input,int noOfElements)
{
int	startIndex = noOfElements - NO_OF_CONSECUTIVE_AVERAGE ;
	float total = 0;

	for (int i= startIndex ;i < noOfElements;i++)
	{
	   
		total += input[i];
	}

	return (total/NO_OF_CONSECUTIVE_AVERAGE);
}

void printOnConsole(float* Max ,float* Min, float* Ave)
{
	for(int i = 0; i<3; i++)
    {
		 printf("Max: %f,Min: %f,Average: %f\n", Max[i], Min[i], Ave[i]);
	}
}
void receiverMainFunction(void (*fpPrintOnConsole)(float* ,float*, float*))
{
    
    	float Max[3], Min[3] ,Ave[3];

	Status_t status = GetFromConsole();

	 Max[0] = findMaxValue( Temp,9);
     Min[0] = findMinValue( Temp,9);
     Ave[0] = aveOfLastConsecutiveValues(Temp,9);
	 Max[1] = findMaxValue( SOC,9);
     Min[1] = findMinValue( SOC,9);
     Ave[1] = aveOfLastConsecutiveValues(SOC,9);	
	 Max[2] = findMaxValue( sensorsID,9);
     Min[2] = findMinValue( sensorsID,9);
     Ave[2] = aveOfLastConsecutiveValues(sensorsID,9);
      
	 fpPrintOnConsole(Max,Min,Ave);
}
