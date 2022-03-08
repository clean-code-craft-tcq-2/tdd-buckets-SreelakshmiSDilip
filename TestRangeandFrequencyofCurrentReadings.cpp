#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

//#include "catch.hpp"
#include <assert.h>
#include <iostream>
#include "RangeandFrequencyofCurrentReadings.h"

void testOutputRangeandCount(){
 int testInput[9] = {2,3,4,5,8,9,9,10,12};
 vector<StringandNumRangeOutput> Observed_range_count_list;
 vector<StringandNumRangeOutput> Expected_range_count_list;
 Expected_range_count_list[0].numIndexAndCount = {2,5,4};
 Expected_range_count_list[1].numIndexAndCount ={8,10,4};
 Expected_range_count_list[2].numIndexAndCount ={12,c_NOTVALID,1};

 Observed_range_count_list = GetRangesAndFrequentValue(testInput,9);

  assert(Observed_range_count_list[0].numIndexAndCount ==  Expected_range_count_list[0].numIndexAndCount);
  assert(Observed_range_count_list[1].numIndexAndCount ==  Expected_range_count_list[1].numIndexAndCount);
  assert(Observed_range_count_list[2].numIndexAndCount ==  Expected_range_count_list[2].numIndexAndCount);

}



void testOutRangeandCountString() {
	int testReadings[9] = {2,3,4,5,8,9,9,10,12};
	RangeIndicesandCount testInput1 = {2,5,4};
	RangeIndicesandCount testInput2 = {8,10,4};
	RangeIndicesandCount testInput3 = {12,c_NOTVALID};
 
  assert(GetCombinedRangeandCountString(testInput1,testReadings) == "[2-5]->4");
  assert(GetCombinedRangeandCountString(testInput2,testReadings)  == "[8-10]->4");
  assert(GetCombinedRangeandCountString(testInput3,testReadings) == "[12]->1");
}

int main()
{
	testOutputRangeandCount();
	testOutRangeandCountString();

}



