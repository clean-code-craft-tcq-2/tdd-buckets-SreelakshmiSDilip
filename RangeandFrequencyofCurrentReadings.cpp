#include "RangeandFrequencyofCurrentReadings.h"
#include <stdio.h>
#include<bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>

//using namespace std;



vector<StringandNumRangeOutput> GetRangesAndFrequentValue(int* inputValues)
{
	int numOfElements = sizeof(inputValues)/sizeof(inputValues[0]);
	int length = 1;
	//sort the array
	sort(inputValues, inputValues + numOfElements);
	//find the ranges
	vector<StringandNumRangeOutput> combined_range_count_list;

     
    // If the array is empty,
    // return the range_list
    if (numOfElements == 0)
    {
        return combined_range_count_list;
    }
     
    // Traverse the array from first position
    for(int iter = 1; iter <= numOfElements; iter++)
    {
		
		StringandNumRangeOutput rangeFromReadingOutput;
     
        // Check the difference between the
        // current and the previous elements
        // If the difference doesn't equal to 1
        // just increment the length variable.
        if (iter == numOfElements || inputValues[iter] - inputValues[iter - 1] != 1)
        {
     
            // If the range contains
            // only one element.
            // add it into the range_list.
			RangeIndicesandCount currentIndicesandCount;
			currentIndicesandCount.min_Index =  iter - length;
            currentIndicesandCount.max_Index =  iter - 1;
			currentIndicesandCount.count = length;

			
            string rangeString = GetRangeandCountOutputAsString(currentIndicesandCount,&inputValues);
			rangeFromReadingOutput.numIndexAndCount = currentIndicesandCount;
			rangeFromReadingOutput.stringIndexAndCount = rangeString;


            // After finding the first range
            // initialize the length by 1 to
            // build the next range.
            length = 1;
			
        }
        else
        {
            length++;
			
        }
		
		combined_range_count_list.push_back(rangeFromReadingOutput);
    }


    return combined_range_count_list;
}

string GetRangeandCountOutputAsString(RangeIndicesandCount currentIndicesandCount,int* inputValues )
{
	int min_elementIndex = currentIndicesandCount.min_Index ;
    int max_elementIndex = currentIndicesandCount.max_Index ;
	int count            = currentIndicesandCount.count;
    string temp = "[" + to_string(inputValues[min_elementIndex]) + "-" + to_string(max_elementIndex) + "]" + "->" to_string(count) ;
	if(min_elementIndex == max_elementIndex)
	{
		temp = "[" + to_string(inputValues[min_elementIndex]) + "]"+ "->" to_string(count);
	}
	//range_list.push_back(temp);
	return temp;
}











