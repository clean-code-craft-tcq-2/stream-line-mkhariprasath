#include "sender.h"

float Temperature  [BUFFER_SIZE] = {};
float StateOfCharge[BUFFER_SIZE] = {};

Status_t (*readBMSData[]) (float Temperature[],float StateOfCharge[])={readDataFromFile}; // dataFetchChannel
Status_t (*passBMSData[]) (float Temperature[],float StateOfCharge[])={passToConsole};    // dataOutputChannel

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

Status_t passToConsole(float Temperature[],float StateOfCharge[])
{
    printf("Temperature \t SOC\n ");
    printf("-----------------------");
    for(int i = 0; i<BUFFER_SIZE; i++)
    {
        printf("%f \t\t %f\n",Temperature[i], StateOfCharge[i]);
    }
    return E_OK;
}

Status_t fetchData(dataFetchChannel inputMethod)
{
    return (*readBMSData[inputMethod])(Temperature, StateOfCharge);
}

Status_t passDataToOutput(dataOutputChannel outputMethod)
{
    return (*passBMSData[outputMethod])(Temperature, StateOfCharge);
}
