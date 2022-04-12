#include "sender.h"

float Temperature  [NOOFDATA] = {};
float StateOfCharge[NOOFDATA] = {};
int   sensorID     [NOOFDATA] = {};

Status_t readDataFromFile()
{
    float temp, soc;
    int senID;
    Status_t Status= E_NOT_OK;
    FILE * fp = fopen("./InputData.txt","r");
    if (fp) 
    {
        for(int i=0; fscanf(fp,"%d,%f,%f\n", &senID, &temp, &soc)!=EOF; i++)
        {
            sensorID[i]      = senID;
            Temperature[i]   = temp;
            StateOfCharge[i] = soc;
        }
        Status= E_OK;
    }
    fclose(fp);
    return Status;
}


Status_t fillRandomData()
{
    Status_t Status= E_NOT_OK;
    for (int i = 0; i < NOOFDATA; i++)
    {
        sensorID[i]      = optimumValuesRandom(MINIMUM_SENSORID   , MAXIMUM_SENSORID);
        Temperature[i]   = optimumValuesRandom(MINIMUM_TEMPERATURE, MAXIMUM_TEMPERATURE);
        StateOfCharge[i] = optimumValuesRandom(MINIMUM_CHARGESTATE, MAXIMUM_CHARGESTATE);
    }
    Status= E_OK;
    return Status;
}

Status_t passToConsole()
{
    for(int i = 0; i<NOOFDATA; i++)
    {
        printf("%d,%f,%f\n", sensorID[i], Temperature[i], StateOfCharge[i]);
    }
    return E_OK;
}


float optimumValuesRandom(float min, float max)
{
    float data = (rand() % (int)(max+1)) ;
    if(data < min)
    {
        data = data + min;
    }
    return data;
}

Status_t fetchData(Status_t (*fp_InputFunction)())
{
    Status_t Status = E_NOT_OK;
    Status = fp_InputFunction();
    return Status;
}

Status_t passDataToOutput(Status_t (*fp_OutputFunction)())
{
    Status_t Status = E_NOT_OK;
    Status = fp_OutputFunction();
    return Status;
}


//Main function - Input to the receiver

Status_t senderMain(Status_t (*fp_InputFunction)(), Status_t (*fp_OutputFunction)())
{
    Status_t status = E_NOT_OK;
    status = fp_InputFunction();
    if (status == E_OK)
    {
        status = fp_OutputFunction();
    }
    return status;
}
