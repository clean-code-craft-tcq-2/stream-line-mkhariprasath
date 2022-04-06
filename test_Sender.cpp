#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sender.h"

TEST_CASE("Get the data temperature and soc data from file") {
    dataFetchChannel inputMethod = viaFile;
    REQUIRE(fetchData (inputMethod) == E_OK);
}

TEST_CASE("Check the data is printed on console") {
    dataFetchChannel inputMethod = viaFile;
    dataOutputChannel outputMethod = viaConsole;
    REQUIRE(fetchData (inputvaluefetch) == E_OK);
    REQUIRE(passDataToOutput (outputvaluefetch) == E_OK);
}
