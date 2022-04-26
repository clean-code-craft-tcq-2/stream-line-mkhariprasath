// #define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include"test/catch.hpp"
#include"receiver.h"


TEST_CASE("Checks maximum value finding function")
 {
	float TemperatureInput[]= {2.5,10,14,22.5,47,14.5,22,0.5,2.5};
	float expectedOutput  = 47;
	float actualOutput  = findMaxValue( TemperatureInput,9);
        REQUIRE(actualOutput==expectedOutput);
}


TEST_CASE("Checks Minimum value finding function")
 {
	float TemperatureInput[]= {2.5,10,14,22.5,47,14.5,22,0.5,2.5};
	float expectedOutput  = 0.5;
	float actualOutput  = findMinValue( TemperatureInput,9);
       REQUIRE(actualOutput==expectedOutput);
}

TEST_CASE("Checks average value finding function")
 {
	float TemperatureInput[]= {2.5,10,14,22.5,47,14.5,22,0.5,2.5};
	float expectedOutput  = 17.299999;
	float actualOutput  = aveOfLastConsecutiveValues(TemperatureInput,9);
        REQUIRE(actualOutput==expectedOutput);
}

