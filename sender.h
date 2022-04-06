#ifndef SENDER_H
#define SENDER_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

#define MINIMUM_TEMPERATURE 0
#define OPTIMUM_TEMPERATURE 25
#define MAXIMUM_TEMPERATURE 45

#define MINIMUM_CHARGESTATE 20
#define OPTIMUM_CHARGESTATE 70
#define MAXIMUM_CHARGESTATE 80

#define MINIMUM_CHARGERATE  0
#define OPTIMUM_CHARGERATE  0.7f
#define MAXIMUM_CHARGERATE  0.8f

typedef enum{
    viaFile,
    viaRandomNumberGenerator, // for testing and extensibility purpose
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
Status_t fillRandomData(float Temperature[],float StateOfCharge[]);
Status_t readData(float Temperature[],float StateOfCharge[]);
Status_t passToConsole(float Temperature[],float StateOfCharge[]);
Status_t fetchData(dataFetchChannel inputvaluefetch);
Status_t passDataToOutput(dataOutputChannel outputvaluefetch);
float optimumValuesRandom(float min, float max);


#endif // multiple include protection for SENDER_H
