#include "sender.h"

bmsData_t batteryParam[BUFFER_SIZE] = {0};

Status_t (*readBMSData[]) (bmsData_t batteryParam)={readDataFromFile}; // dataFetchChannel
Status_t (*passBMSData[]) (bmsData_t batteryParam)={passToConsole};    // dataOutputChannel

Status_t readDataFromFile(bmsData_t batteryParam)
{
    float temp, soc;
    Status_t Status= E_NOT_OK;
    FILE * fp= fopen("./InputData.txt","r");  
    if (fp) 
    {
        for(int i=0; fscanf(fp, "%f,%f\n", &temp, &soc)!=EOF; i++)
        {
            batteryParam[i].batteryTemperature = temp;
            batteryParam[i].stateOfCharge = soc;
        }
        Status= E_OK;
    }
    fclose(file);
    return Status;
}

Status_t passToConsole(bmsData_t batteryParam)
{
    printf("Temperature \t SOC\n ");
    printf("-----------------------");
    for(int i = 0; i<BUFFER_SIZE; i++)
    {
        printf("%f \t\t %f\n",batteryParam[i].batteryTemperature,batteryParam[i].stateOfCharge);
    }
    return E_OK;
}

Status_t fetchData(dataFetchChannel inputMethod)
{
    return (*readBMSData[inputMethod])(batteryParam);
}

Status_t passDataToOutput(dataOutputChannel outputMethod)
{
    return (*passBMSData[outputMethod])(batteryParam);
}
