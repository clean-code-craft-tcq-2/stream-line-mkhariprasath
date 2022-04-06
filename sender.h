#ifndef SENDER_H
#define SENDER_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define BUFFER_SIZE 50

#define MINIMUM_TEMPERATURE 0
#define OPTIMUM_TEMPERATURE 25
#define MAXIMUM_TEMPERATURE 45

#define MINIMUM_CHARGESTATE 20
#define OPTIMUM_CHARGESTATE 70
#define MAXIMUM_CHARGESTATE 80

typedef enum
{
	E_NOT_OK,
	E_OK,
    	E_TEST_OK
}Status_t;

Status_t readDataFromFile();
Status_t testWithNoInputFile();
Status_t fillRandomData();
Status_t passToConsole();
Status_t testOutput();
float    optimumValuesRandom(float min, float max);

Status_t fetchData(float (*)(float,float));
Status_t passDataToOutput(float (*)(float,float));

// Main function to do send operation
Status_t senderMain(float (*)(float,float), float (*)(float,float)); // input function pointer , output function pointer


#endif // multiple include protection for SENDER_H
