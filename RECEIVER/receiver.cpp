#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include"../test/catch.hpp"
#include"receiver.h"


TEST_CASE("Checks maximum value finding function")
 {
	int TemperatureInput[]= {2,10,14,22,47,14,22,5,1};
	int expectedOutput  = 47;
	int actualOutput  = findMaxValue( TemperatureInput,9);
        REQUIRE(actualOutput==expectedOutput);
}


TEST_CASE("Checks Minimum value finding function")
 {
	int TemperatureInput[]= {2,10,14,22,47,14,22,5,1};
	int expectedOutput  = 1;
	int actualOutput  = findMinValue( TemperatureInput,9);
       REQUIRE(actualOutput==expectedOutput);
}

TEST_CASE("Checks average value finding function")
 {
	int TemperatureInput[]= {2,10,14,22,47,14,22,5,2};
	int expectedOutput  = 18;
	int actualOutput  = aveOfLastConsecutiveValues(TemperatureInput,9);
        REQUIRE(actualOutput==expectedOutput);
}

TEST_CASE("Checks sender receiver pipelining")
 {
receiverMainFunction(&printOnConsole);
}
	
