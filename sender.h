#ifndef SENDER_H
#define SENDER_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define NOOFDATA 50

#define MINIMUM_TEMPERATURE 0
#define OPTIMUM_TEMPERATURE 25
#define MAXIMUM_TEMPERATURE 45

#define MINIMUM_CHARGESTATE 20
#define OPTIMUM_CHARGESTATE 70
#define MAXIMUM_CHARGESTATE 80

#define MINIMUM_SENSORID 1
#define MAXIMUM_SENSORID 2

typedef enum
{
	E_NOT_OK,
	E_OK,
    E_TEST_OK
}Status_t;

 extern float  Temperature  [NOOFDATA] ;
extern  float StateOfCharge[NOOFDATA];
 extern int   sensorID     [NOOFDATA] ;
extern int suriya;

Status_t readDataFromFile();
Status_t fillRandomData();
Status_t passToConsole();
float    optimumValuesRandom(float min, float max);

Status_t fetchData(Status_t (*fp_InputFunction)());
Status_t passDataToOutput(Status_t (*fp_OutputFunction)());

// Main function to do send operation
Status_t senderMain(Status_t (*fp_InputFunction)(), Status_t (*fp_OutputFunction)()); // input function pointer , output function pointer


#endif // multiple include protection for SENDER_H
