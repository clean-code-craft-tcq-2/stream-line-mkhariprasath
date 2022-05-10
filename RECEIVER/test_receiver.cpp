#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include"../test/catch.hpp"
#include"receiver.h"


TEST_CASE("Check temperature data is taken properly from the console data")
 {
	int temp[50];
	char consoleData[5][20] = { "1, 20, 40",
				  " 2, 22, 42",
				  " 4, 33,43",
				   "3,44,54",
				  " 5,55,65"};
	
	collectTempData( consoleData, temp, 5);
				  
	   REQUIRE(temp[0] == 20);
           REQUIRE(temp[1] == 22);
           REQUIRE(temp[2] == 33);
           REQUIRE(temp[3] == 44);
	   REQUIRE(temp[4] == 55);
}
TEST_CASE("Check SOC value is taken properly from the console data")
 {
	int SOC[50];
	char consoleData[5][20] = { "1, 20, 40",
				  " 2, 22, 42",
				  " 4, 33,43",
				   "3,44,54",
				  " 5,55,65"};
	
	collectSocData( consoleData, SOC, 5);				  
	   REQUIRE(SOC[0] == 40);
           REQUIRE(SOC[1] == 42);
           REQUIRE(SOC[2] == 43);
           REQUIRE(SOC[3] == 54);
	   REQUIRE(SOC[4] == 65);
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

