
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test./catch.hpp"
#include <assert.h>
#include <iostream>
#include "RangeandFrequencyofCurrentReadings.h"

TEST_CASE("Get the range and frequency of occurance for each range in numerical form for any input"){
 int testInput[9] = {2,3,4,5,8,9,9,10,12};
 vector<StringandNumRangeOutput> Observed_range_count_list;
 vector<StringandNumRangeOutput> Expected_range_count_list;
 StringandNumRangeOutput ExpectedStringAndNumRangeOutput;
 ExpectedStringAndNumRangeOutput.rangeValuesAndCount = {2,5,4};
 Expected_range_count_list.push_back(ExpectedStringAndNumRangeOutput);
 ExpectedStringAndNumRangeOutput.rangeValuesAndCount ={8,10,4};
 Expected_range_count_list.push_back(ExpectedStringAndNumRangeOutput);
 ExpectedStringAndNumRangeOutput.rangeValuesAndCount ={12,12,1};
 Expected_range_count_list.push_back(ExpectedStringAndNumRangeOutput);

 Observed_range_count_list = GetRangesAndFrequentValue(testInput,9);

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



TEST_CASE("Get the range and count output as a string for any input"){
	int testReadings[9] = {2,3,4,5,8,9,9,10,12};
	RangeValuesAndCount testInput1 = {2,5,4};
	RangeValuesAndCount testInput2 = {8,10,4};
	RangeValuesAndCount testInput3 = {12,12,1};
 
  REQUIRE(GetRangeandCountOutputAsString(testInput1,testReadings) == "[2-5]->4");
  REQUIRE(GetRangeandCountOutputAsString(testInput2,testReadings)  == "[8-10]->4");
  REQUIRE(GetRangeandCountOutputAsString(testInput3,testReadings) == "[12]->1");
}





