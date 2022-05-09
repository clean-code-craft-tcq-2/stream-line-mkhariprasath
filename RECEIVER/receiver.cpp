#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include"../test/catch.hpp"
#include"receiver.h"

TEST_CASE("Check Sensor ID is taken properly from the console data")
 {
	int sensorID[50];
	char consoleData[5][20] = { "1, 20, 40",
				  " 2, 22, 42",
				  " 4, 33,43",
				   "3,44,54",
				  " 5,55,65"};
	
	collectIdData( consoleData, sensorID, 5);
				  
	   REQUIRE(sensorID[0] == 1);
            REQUIRE(sensorID[1] == 2);
                REQUIRE(sensorID[2] == 4);
                REQUIRE(sensorID[3] == 3);
	REQUIRE(sensorID[4] == 5);
}

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

