#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NO_OF_CONSECUTIVE_AVERAGE 5

#define NOOFDATA 50

typedef enum
{
	E_NOT_OK,
	E_OK,
    E_TEST_OK
}Status_t;

float Temp[NOOFDATA] = {};
float SOC[NOOFDATA] = {};
float   sensorsID[NOOFDATA] = {};