
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test./catch.hpp"
#include <assert.h>
#include <iostream>
#include "RangeandFrequencyofCurrentReadings.h"

//TEST_CASE("Get the range and frequency of occurance for each range in numerical form for any input"){
//	vector <int> testInput{2,3,4,5,8,9,9,10,12};
//	vector<StringandNumRangeOutput> Observed_range_count_list;
//	vector<StringandNumRangeOutput> Expected_range_count_list;
//	StringandNumRangeOutput ExpectedStringAndNumRangeOutput;
//	ExpectedStringAndNumRangeOutput.rangeValuesAndCount = {2,5,4};
//	Expected_range_count_list.push_back(ExpectedStringAndNumRangeOutput);
//	ExpectedStringAndNumRangeOutput.rangeValuesAndCount ={8,10,4};
//	Expected_range_count_list.push_back(ExpectedStringAndNumRangeOutput);
//	ExpectedStringAndNumRangeOutput.rangeValuesAndCount ={12,12,1};
//	Expected_range_count_list.push_back(ExpectedStringAndNumRangeOutput);
//
//	Observed_range_count_list = GetRangesAndFrequentValue(testInput);
//
//	REQUIRE(Observed_range_count_list[0].rangeValuesAndCount.rangeLower ==  Expected_range_count_list[0].rangeValuesAndCount.rangeLower);
//	REQUIRE(Observed_range_count_list[1].rangeValuesAndCount.rangeLower ==  Expected_range_count_list[1].rangeValuesAndCount.rangeLower);
//	REQUIRE(Observed_range_count_list[2].rangeValuesAndCount.rangeLower ==  Expected_range_count_list[2].rangeValuesAndCount.rangeLower);
//
//
//	REQUIRE(Observed_range_count_list[0].rangeValuesAndCount.rangeUpper ==  Expected_range_count_list[0].rangeValuesAndCount.rangeUpper);
//	REQUIRE(Observed_range_count_list[1].rangeValuesAndCount.rangeUpper ==  Expected_range_count_list[1].rangeValuesAndCount.rangeUpper);
//	REQUIRE(Observed_range_count_list[2].rangeValuesAndCount.rangeUpper ==  Expected_range_count_list[2].rangeValuesAndCount.rangeUpper);
//
//	REQUIRE(Observed_range_count_list[0].rangeValuesAndCount.count ==  Expected_range_count_list[0].rangeValuesAndCount.count);
//	REQUIRE(Observed_range_count_list[1].rangeValuesAndCount.count ==  Expected_range_count_list[1].rangeValuesAndCount.count);
//	REQUIRE(Observed_range_count_list[2].rangeValuesAndCount.count ==  Expected_range_count_list[2].rangeValuesAndCount.count);
//
//
//
//}

TEST_CASE("Get the range and count string output for range and count numerical input"){
	
	RangeValuesAndCount testInput1 = {2,5,4};
	RangeValuesAndCount testInput2 = {8,10,4};
	RangeValuesAndCount testInput3 = {12,12,1};

	REQUIRE(GetRangeandCountOutputAsString(testInput1) == "[2-5]->4");
	REQUIRE(GetRangeandCountOutputAsString(testInput2)  == "[8-10]->4");
	REQUIRE(GetRangeandCountOutputAsString(testInput3) == "[12]->1");
}

TEST_CASE("Convert digital input to analog output"){
int digitalInput1= 1146;
int analogInput1 = 3;
int digitalInput2 =0;
int analogOutput2 = 0;
int digitalInput3 = 4094;
int analogOutput3 = 10;


REQUIRE(convertDigitaltoAnalog(digitalInput1) == analogInput1);
REQUIRE(convertDigitaltoAnalog(digitalInput2) == analogOutput2);
REQUIRE(convertDigitaltoAnalog(digitalInput3) == analogOutput3);

}

TEST_CASE("Test whether the given input is within the max limit"){
	int testInput1 =5000;
	int testInput2 = 4095;
	int testInput3 = 0;
	int testInput4 = 10;
	REQUIRE(IsInputValid(testInput1) == false);
	REQUIRE(IsInputValid(testInput2) == false);
	REQUIRE(IsInputValid(testInput3) == true);
	REQUIRE(IsInputValid(testInput4) == true);
}

TEST_CASE("Convert digital input vector to analog output vector"){
int digitalInput1= 1146;
int analogOutput1 = 3;
int digitalInput2 =0;
int analogOutput2 = 0;
int digitalInput3 = 4094;
int analogOutput3 = 10;
int digitalInput4 = 4096;
vector<int> testdigitalInputVec, testAnalogOutputVec;

testdigitalInputVec.push_back(digitalInput1);
testdigitalInputVec.push_back(digitalInput2);
testdigitalInputVec.push_back(digitalInput3);
testdigitalInputVec.push_back(digitalInput4);

testAnalogOutputVec.push_back(analogOutput1);
testAnalogOutputVec.push_back(analogOutput2);
testAnalogOutputVec.push_back(analogOutput3);


REQUIRE(GetAnalogReadings(testdigitalInputVec) == testAnalogOutputVec);

}


TEST_CASE("End to end test for getting the range and frequency for a set of 12bit array inputs"){

	vector <int> testInput{0,1023,1023,1300,2023,2025,127,1570,8900};//{0,2,2,3,5,5,0,4}
	vector<StringandNumRangeOutput> Observed_range_count_list;
	vector<StringandNumRangeOutput> Expected_range_count_list;
	StringandNumRangeOutput ExpectedStringAndNumRangeOutput;
	ExpectedStringAndNumRangeOutput.rangeValuesAndCount = {0,0,2};
	Expected_range_count_list.push_back(ExpectedStringAndNumRangeOutput);
	ExpectedStringAndNumRangeOutput.rangeValuesAndCount ={2,3,3};
	Expected_range_count_list.push_back(ExpectedStringAndNumRangeOutput);
	ExpectedStringAndNumRangeOutput.rangeValuesAndCount ={4,5,3};
	Expected_range_count_list.push_back(ExpectedStringAndNumRangeOutput);

	Observed_range_count_list = GetRangesAndFrequentValue(testInput);

	REQUIRE(Observed_range_count_list[0].rangeValuesAndCount.rangeLower ==  Expected_range_count_list[0].rangeValuesAndCount.rangeLower);
	REQUIRE(Observed_range_count_list[1].rangeValuesAndCount.rangeLower ==  Expected_range_count_list[1].rangeValuesAndCount.rangeLower);
	REQUIRE(Observed_range_count_list[2].rangeValuesAndCount.rangeLower ==  Expected_range_count_list[2].rangeValuesAndCount.rangeLower);


	REQUIRE(Observed_range_count_list[0].rangeValuesAndCount.rangeUpper ==  Expected_range_count_list[0].rangeValuesAndCount.rangeUpper);
	REQUIRE(Observed_range_count_list[1].rangeValuesAndCount.rangeUpper ==  Expected_range_count_list[1].rangeValuesAndCount.rangeUpper);
	REQUIRE(Observed_range_count_list[2].rangeValuesAndCount.rangeUpper ==  Expected_range_count_list[2].rangeValuesAndCount.rangeUpper);

	REQUIRE(Observed_range_count_list[0].rangeValuesAndCount.count ==  Expected_range_count_list[0].rangeValuesAndCount.count);
	REQUIRE(Observed_range_count_list[1].rangeValuesAndCount.count ==  Expected_range_count_list[1].rangeValuesAndCount.count);
	REQUIRE(Observed_range_count_list[2].rangeValuesAndCount.count ==  Expected_range_count_list[2].rangeValuesAndCount.count);



	}




