#include "ut_Sender.h"

Status_t testWithNoInputFile()
{
    return E_NOT_OK;
}

Status_t testOutput()
{
    return E_TEST_OK;
}

Status_t fillRandomData()
{
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        Temperature[i] = optimumValuesRandom(MINIMUM_TEMPERATURE, MAXIMUM_TEMPERATURE);
        StateOfCharge[i] = optimumValuesRandom(MINIMUM_CHARGESTATE, MAXIMUM_CHARGESTATE);
    }
}
