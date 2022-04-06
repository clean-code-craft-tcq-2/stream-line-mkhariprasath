#ifndef SENDER_H
#define SENDER_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define BUFFER_SIZE 100
typedef enum{
    viaFile,
    //viaRandomNumberGenerator, // for testing and extensibility purpose
    // ...
    // ...
    noOfFetchChannelMethod
}dataFetchChannel;

typedef enum{
    viaConsole,
    // ...
    // ...
    noOfOutputChannelMethods
}dataOutputChannel;

typedef enum
{
	E_NOT_OK,
	E_OK
}Status_t;

Status_t readDataFromFile(float Temperature[],float StateOfCharge[]);
Status_t readData(float Temperature[],float StateOfCharge[]);
Status_t passToConsole(float Temperature[],float StateOfCharge[]);
Status_t fetchData(dataFetchChannel inputvaluefetch);
Status_t passDataToOutput(dataOutputChannel outputvaluefetch);


#endif // multiple include protection for SENDER_H
