#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sender.h"

TEST_CASE("Get the data temperature and soc data from file") {
    dataFetchChannel inputMethod = viaFile;
    REQUIRE(fetchData (inputMethod) == E_OK);
}

TEST_CASE("Get the data temperature and soc data from random number generator") {
    dataFetchChannel inputMethod = viaRandomNumberGenerator;
    REQUIRE(fetchData (inputMethod) == E_OK);
}

TEST_CASE("Check the data is printed on console") {
    dataFetchChannel inputMethod = viaFile;
    dataOutputChannel outputMethod = viaConsole;
    REQUIRE(fetchData (inputMethod) == E_OK);
    REQUIRE(passDataToOutput (outputMethod) == E_OK);
}

TEST_CASE("Test the main fuction of the sender without input file") {
    dataFetchChannel inputMethod = TestWithNoInput;
    dataOutputChannel outputMethod = OutputChannelTest;
    REQUIRE(senderMain(inputMethod, outputMethod) == E_TEST_OK);
}


TEST_CASE("Test the main fuction of the sender ") {
    dataFetchChannel inputMethod = viaFile;
    dataOutputChannel outputMethod = OutputChannelTest;
    REQUIRE(senderMain(inputMethod, outputMethod) == E_TEST_OK);
}
