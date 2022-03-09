

//#include "catch.hpp"
#include <assert.h>
#include <iostream>
#include "RangeandFrequencyofCurrentReadings.h"

void testOutputRangeandCount(){
 int testInput[9] = {2,3,4,5,8,9,9,10,12};
 vector<StringandNumRangeOutput> Observed_range_count_list;
 vector<StringandNumRangeOutput> Expected_range_count_list;
 Expected_range_count_list[0].rangeValuesAndCount = {2,5,4};
 Expected_range_count_list[1].rangeValuesAndCount ={8,10,4};
 Expected_range_count_list[2].rangeValuesAndCount ={12,12,1};

 Observed_range_count_list = GetRangesAndFrequentValue(testInput,9);

  assert(Observed_range_count_list[0].rangeValuesAndCount.rangeLower ==  Expected_range_count_list[0].rangeValuesAndCount.rangeLower);
  assert(Observed_range_count_list[1].rangeValuesAndCount.rangeLower ==  Expected_range_count_list[1].rangeValuesAndCount.rangeLower);
  assert(Observed_range_count_list[2].rangeValuesAndCount.rangeLower ==  Expected_range_count_list[2].rangeValuesAndCount.rangeLower);


  assert(Observed_range_count_list[0].rangeValuesAndCount.rangeUpper ==  Expected_range_count_list[0].rangeValuesAndCount.rangeUpper);
  assert(Observed_range_count_list[1].rangeValuesAndCount.rangeUpper ==  Expected_range_count_list[1].rangeValuesAndCount.rangeUpper);
  assert(Observed_range_count_list[2].rangeValuesAndCount.rangeUpper ==  Expected_range_count_list[2].rangeValuesAndCount.rangeUpper);

  assert(Observed_range_count_list[0].rangeValuesAndCount.count ==  Expected_range_count_list[0].rangeValuesAndCount.count);
  assert(Observed_range_count_list[1].rangeValuesAndCount.count ==  Expected_range_count_list[1].rangeValuesAndCount.count);
  assert(Observed_range_count_list[2].rangeValuesAndCount.count ==  Expected_range_count_list[2].rangeValuesAndCount.count);

}



void testOutRangeandCountString() {
	int testReadings[9] = {2,3,4,5,8,9,9,10,12};
	RangeValuesAndCount testInput1 = {2,5,4};
	RangeValuesAndCount testInput2 = {8,10,4};
	RangeValuesAndCount testInput3 = {12,12,1};
 
  assert(GetRangeandCountOutputAsString(testInput1,testReadings) == "[2-5]->4");
  assert(GetRangeandCountOutputAsString(testInput2,testReadings)  == "[8-10]->4");
  assert(GetRangeandCountOutputAsString(testInput3,testReadings) == "[12]->1");
}

int main()
{
	
	testOutRangeandCountString();
	
	testOutputRangeandCount();
	return 0;
}



