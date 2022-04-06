#include "sender.h"

float Temperature  [BUFFER_SIZE] = {};
float StateOfCharge[BUFFER_SIZE] = {};

Status_t (*readBMSData[]) (float Temperature[],float StateOfCharge[])={readDataFromFile, fillRandomData}; // dataFetchChannel
Status_t (*passBMSData[]) (float Temperature[],float StateOfCharge[])={passToConsole, testOutput};    // dataOutputChannel

Status_t readDataFromFile(float Temperature[],float StateOfCharge[])
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

Status_t fillRandomData(float Temperature[],float StateOfCharge[])
{
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        Temperature[i] = optimumValuesRandom(MINIMUM_TEMPERATURE, MAXIMUM_TEMPERATURE);
        StateOfCharge[i] = optimumValuesRandom(MINIMUM_CHARGESTATE, MAXIMUM_CHARGESTATE);
    }
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

Status_t passToConsole(float Temperature[],float StateOfCharge[])
{
    for(int i = 0; i<BUFFER_SIZE; i++)
    {
        printf("%f \t\t %f\n",Temperature[i], StateOfCharge[i]);
    }
    return E_OK;
}

Status_t testOutput(float Temperature[],float StateOfCharge[])
{
    return E_TEST_OK;
}

Status_t fetchData(dataFetchChannel inputMethod)
{
    Status_t Status = E_NOT_OK;
    Status = (*readBMSData[inputMethod])(Temperature,StateOfCharge);
    return Status;

}

Status_t passDataToOutput(dataOutputChannel outputMethod)
{
    Status_t Status = E_NOT_OK;
    Status = (*passBMSData[outputMethod])(Temperature,StateOfCharge);
    return Status;
}

Status_t senderMain(dataFetchChannel inputMethod, dataOutputChannel outputMethod)
{
    Status_t status = E_OK;
    while (status == E_OK)
    {
        status = fetchData (inputMethod);
        if (status == E_OK)
        {
            status = passDataToOutput (outputMethod);
            if ( (status == E_NOT_OK) || (status == E_TEST_OK) )
                break;
        }
    }
    return status;
}
