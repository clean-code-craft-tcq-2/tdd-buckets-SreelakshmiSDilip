#include "RangeandFrequencyofCurrentReadings.h"
#include <stdio.h>
#include<bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include<math.h>


bool IsInputValid(int digitalInput)
{
	bool isValid = false;
	if((digitalInput > 0) && (digitalInput <= c_DIGIMAXCURRENTINPUT))
	{
		isValid = true;
	}
	return isValid;
}

int convertDigitaltoAnalog(int digitalInput)
{
		return((int)ceil(c_ANALOGMAXCURRENTOUTPUT * (digitalInput)/c_DIGIMAXCURRENTINPUT));

}

vector<int> GetAnalogReadings(vector<int>digitalInput)
{
	int l_analogOutput;
	int l_digitalInput;
	vector <int> analogCurrentReadings;
	for(int l_index = 0;l_index < digitalInput.size();l_index++)
	{
		l_digitalInput = digitalInput.at(l_index);
		if(IsInputValid(l_digitalInput) ==  true)
		{
			l_analogOutput = convertDigitaltoAnalog(l_digitalInput);
		   analogCurrentReadings.push_back(l_analogOutput);
		}
	}
	return analogCurrentReadings;
     
}


vector<StringandNumRangeOutput> GetRangesAndFrequentValue(vector<int> inputValues)
{
	int length = 1;
	//sort the array
	 sort(inputValues.begin(), inputValues.end());
	int  numOfElements = inputValues.size();
	//find the ranges
	vector<StringandNumRangeOutput> combinedRangeCountList;
	// Traverse the array from first position
	for(int iter = 1; iter <= numOfElements; iter++)
	{
		// Check the difference between the
		// current and the previous elements
		// If the difference doesn't equal to 1
		// just increment the length variable.
		if (iter == numOfElements || inputValues[iter] - inputValues[iter - 1] > 1)
		{
			// If the range contains
			// only one element.
			// add it into the range_list.
			
			StringandNumRangeOutput rangeFromReadingOutput;
			RangeValuesAndCount currentRangeandCount;
			

			currentRangeandCount.rangeLower=  inputValues[iter - length];
			currentRangeandCount.rangeUpper =  inputValues[iter - 1];
			currentRangeandCount.count = length;

			rangeFromReadingOutput.rangeValuesAndCount= currentRangeandCount;
			rangeFromReadingOutput.stringIndexAndCount= GetRangeandCountOutputAsString(currentRangeandCount);
			combinedRangeCountList.push_back(rangeFromReadingOutput);

			// After finding the first range
			// initialize the length by 1 to
			// build the next range.
			length = 1;
		}
		else
		{
			length++;
		}	
	}


	return combinedRangeCountList;
}

string GetRangeandCountOutputAsString(RangeValuesAndCount currentRangeandCount)
{
	int rangeLowerBound = currentRangeandCount.rangeLower ;
	int rangeUpperBound = currentRangeandCount.rangeUpper ;
	int count            = currentRangeandCount.count;
	string temp = "[" + to_string(rangeLowerBound) + "-" + to_string(rangeUpperBound) + "]" + "->" + to_string(count) ;
	if(rangeUpperBound == rangeLowerBound)
	{
		temp = "[" + to_string(rangeLowerBound) + "]"+ "->" + to_string(count);
	}
	return temp;
}











