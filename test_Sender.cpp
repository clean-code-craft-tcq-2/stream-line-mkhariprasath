#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sender.h"
#include "ut_Sender.h"
#include <string.h>

TEST_CASE("Get the data temperature and soc data from file") {
    Status_t (*fp_InputFunction)() = readDataFromFile;
    REQUIRE(fetchData (fp_InputFunction) == E_OK);
}

TEST_CASE("Get the data temperature and soc data from file which doesn't exist") {
    char fname = "./InputDummy.txt";
    strcpy(fileName, fname);
    Status_t (*fp_InputFunction)() = readDataFromFile;
    REQUIRE(fetchData (fp_InputFunction) == E_OK);
}


TEST_CASE("Get the data temperature and soc data from random number generator") {
    Status_t (*fp_InputFunction)() = fillRandomData;
    REQUIRE(fetchData (fp_InputFunction) == E_OK);
}

TEST_CASE("Check the data is printed on console") {
    Status_t (*fp_InputFunction)() = readDataFromFile;
    Status_t (*fp_OutputFunction)() = passToConsole;
    REQUIRE(fetchData (fp_InputFunction) == E_OK);
    REQUIRE(passDataToOutput (fp_OutputFunction) == E_OK);
}

TEST_CASE("Test the main fuction of the sender without input file") {
    Status_t (*fp_InputFunction)() = testWithNoInputFile;
    Status_t (*fp_OutputFunction)() = testOutput;

    REQUIRE(senderMain(fp_InputFunction, fp_OutputFunction) == E_NOT_OK);
}

TEST_CASE("Test the main fuction of the sender ") {
    Status_t (*fp_InputFunction)() = readDataFromFile;
    Status_t (*fp_OutputFunction)() = testOutput;

    REQUIRE(senderMain(fp_InputFunction, fp_OutputFunction) == E_TEST_OK);
}
