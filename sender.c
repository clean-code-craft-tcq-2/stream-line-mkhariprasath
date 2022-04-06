#include "sender.h"

float Temperature  [BUFFER_SIZE] = {};
float StateOfCharge[BUFFER_SIZE] = {};

Status_t readDataFromFile()
{
    float temp, soc;
    Status_t Status= E_NOT_OK;
    FILE * fp= fopen("./InputData.txt","r");  
    if (fp) 
    {
        for(int i=0; fscanf(fp, "%f,%f\n", &temp, &soc)!=EOF; i++)
        {
            Temperature[i] = temp;
            StateOfCharge[i] = soc;
        }
        Status= E_OK;
    }
    fclose(fp);
    return Status;
}

Status_t testWithNoInputFile()
{
    return E_NOT_OK;
}

Status_t fillRandomData()
{
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        Temperature[i] = optimumValuesRandom(MINIMUM_TEMPERATURE, MAXIMUM_TEMPERATURE);
        StateOfCharge[i] = optimumValuesRandom(MINIMUM_CHARGESTATE, MAXIMUM_CHARGESTATE);
    }
}

Status_t passToConsole()
{
    for(int i = 0; i<BUFFER_SIZE; i++)
    {
        printf("%f \t\t %f\n",Temperature[i], StateOfCharge[i]);
    }
    return E_OK;
}

Status_t testOutput()
{
    return E_TEST_OK;
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
    Status = (*readBMSData[inputMethod])(Temperature,StateOfCharge);
    return Status;

}

Status_t passDataToOutput(Status_t (*fp_OutputFunction)())
{
    Status_t Status = E_NOT_OK;
    Status = (*passBMSData[outputMethod])(Temperature,StateOfCharge);
    return Status;
}

Status_t senderMain(Status_t (*fp_InputFunction)(), Status_t (*fp_OutputFunction)())
{
    Status_t status = E_OK;
    status = fp_InputFunction();
    if (status == E_OK)
    {
        status = fp_OutputFunction();
    }
    return status;
}
