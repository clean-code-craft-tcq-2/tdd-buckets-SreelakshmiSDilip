
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test./catch.hpp"
#include <assert.h>
#include <iostream>
#include "RangeandFrequencyofCurrentReadings.h"

TEST_CASE("Convert 12 bit digital input to analog output"){
	int digitalInput1= 1146;
	int analogInput1 = 3;
	int digitalInput2 =0;
	int analogOutput2 = 0;
	int digitalInput3 = 4094;
	int analogOutput3 = 10;


	REQUIRE(convert12bitDigitalInputstoAnalog(digitalInput1) == analogInput1);
	REQUIRE(convert12bitDigitalInputstoAnalog(digitalInput2) == analogOutput2);
	REQUIRE(convert12bitDigitalInputstoAnalog(digitalInput3) == analogOutput3);

}

TEST_CASE("Convert 10 bit digital input to analog output"){
	int digitalInput1= 1022;
	int analogInput1 = 15;
	int digitalInput2 =511;
	int analogOutput2 = 0;
	int digitalInput3 = 0;
	int analogOutput3 = 15;


	REQUIRE(convert10bitDigitalInputstoAnalog(digitalInput1) == analogInput1);
	REQUIRE(convert10bitDigitalInputstoAnalog(digitalInput2) == analogOutput2);
	REQUIRE(convert10bitDigitalInputstoAnalog(digitalInput3) == analogOutput3);

}

TEST_CASE("Test whether the given input is within the max limit"){
	int testInput1 =5000;
	int testInput2 = 4095;
	int testInput3 = 0;
	int testInput4 = 10;
	int testInput5 = 1023;
	REQUIRE(IsInputValid(testInput1,SensorType::e_12bit) == false);
	REQUIRE(IsInputValid(testInput2,SensorType::e_12bit) == false);
	REQUIRE(IsInputValid(testInput3,SensorType::e_12bit) == true);
	REQUIRE(IsInputValid(testInput4,SensorType::e_12bit) == true);
	
	
	REQUIRE(IsInputValid(testInput5,SensorType::e_10bit) == false);
	REQUIRE(IsInputValid(testInput2,SensorType::e_10bit) == false);
	REQUIRE(IsInputValid(testInput3,SensorType::e_10bit) == true);
	REQUIRE(IsInputValid(testInput4,SensorType::e_10bit) == true);
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


REQUIRE(GetAnalogReadings(testdigitalInputVec,SensorType::e_12bit) == testAnalogOutputVec);

}


TEST_CASE("Get the range and frequency of occurance for each range in numerical form for digital input"){
	vector<int>testInput{1023,1300,1700,2023,3300,3800,3700,4094,6000};
	// correspomding analog input would be vector <int> testInput{2,3,4,5,8,9,9,10,12};
	vector<RangeValuesandFrequency> Observed_range_count_list;
	vector<RangeValuesandFrequency> Expected_range_count_list;
	RangeValuesandFrequency ExpectedrangeValuesandFrequency = {2,5,4};
	Expected_range_count_list.push_back(ExpectedrangeValuesandFrequency);
	ExpectedrangeValuesandFrequency= {8,10,4};
	Expected_range_count_list.push_back(ExpectedrangeValuesandFrequency);



	Observed_range_count_list = ProcessSensorReadingsforRangeandFrequency(testInput,SensorType::e_12bit);

	REQUIRE(Observed_range_count_list[0].rangeLower ==  Expected_range_count_list[0].rangeLower);
	REQUIRE(Observed_range_count_list[1].rangeLower ==  Expected_range_count_list[1].rangeLower);



	REQUIRE(Observed_range_count_list[0].rangeUpper ==  Expected_range_count_list[0].rangeUpper);
	REQUIRE(Observed_range_count_list[1].rangeUpper ==  Expected_range_count_list[1].rangeUpper);


	REQUIRE(Observed_range_count_list[0].count ==  Expected_range_count_list[0].count);
	REQUIRE(Observed_range_count_list[1].count ==  Expected_range_count_list[1].count);




}

TEST_CASE("Get the range and count string output for range and count numerical input"){

	vector<RangeValuesandFrequency>testInput;
	RangeValuesandFrequency rangeValuesandFrequency = {2,5,4};
	testInput.push_back(rangeValuesandFrequency);
	rangeValuesandFrequency= {8,10,4};
	testInput.push_back(rangeValuesandFrequency);

	vector<string> Observed_range_frequency_string;
	vector<string> Expected_range_frequency_string;
	string range_frequency_string1 = "[2-5]->4";
	string range_frequency_string2 = "[8-10]->4";

	Expected_range_frequency_string.push_back(range_frequency_string1);
	Expected_range_frequency_string.push_back(range_frequency_string2);


	REQUIRE(GetRangeandFrequencyOutputAsString(testInput) == Expected_range_frequency_string);
}
	



