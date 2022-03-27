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
	if((digitalInput >=  0) && (digitalInput <= c_DIGIMAXCURRENTINPUT))
	{
		isValid = true;
	}
	return isValid;
}

int convertDigitaltoAnalog(int digitalInput)
{
	float analogVal =  c_ANALOGMAXCURRENTOUTPUT * digitalInput/c_DIGIMAXCURRENTINPUT ;
	return(round(analogVal));

}

vector<int> GetAnalogReadings(vector<int>digitalInput)
{
	int l_analogOutput;
	int l_digitalInput;
	int maxIndex = digitalInput.size();
	vector <int> analogCurrentReadings;
	for(int l_index = 0;l_index < maxIndex;l_index++)
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


vector<RangeValuesandFrequency> GetRangesAndFrequentValue(vector<int> inputValues)
{
	int length = 1;
	//sort the array
	 sort(inputValues.begin(), inputValues.end());
	int  numOfElements = inputValues.size();
	//find the ranges
	vector<RangeValuesandFrequency> rangeValuesandFrequency;
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

			RangeValuesandFrequency rangeandFrequency;
			

			rangeandFrequency.rangeLower=  inputValues[iter - length];
			rangeandFrequency.rangeUpper =  inputValues[iter - 1];
			rangeandFrequency.count = length;

			rangeValuesandFrequency.push_back(rangeandFrequency);

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


	return rangeValuesandFrequency;
}

vector<string> GetRangeandFrequencyOutputAsString(vector<RangeValuesandFrequency> RangeandFrequency)
{
	vector<string>rangeAndFrequencyString;
	int maxIndex = RangeandFrequency.size();
	for(int index = 0; index <  maxIndex;index++)
	{
		int rangeLowerBound = RangeandFrequency[index].rangeLower ;
		int rangeUpperBound = RangeandFrequency[index].rangeUpper ;
		int count           = RangeandFrequency[index].count;
		string temp = "[" + to_string(rangeLowerBound) + "-" + to_string(rangeUpperBound) + "]" + "->" + to_string(count) ;
		if(rangeUpperBound == rangeLowerBound)
		{
			temp = "[" + to_string(rangeLowerBound) + "]"+ "->" + to_string(count);
		}
		rangeAndFrequencyString.push_back(temp);
	}
	return rangeAndFrequencyString;
}

vector<RangeValuesandFrequency> ProcessSensorReadingsforRangeandFrequency(vector<int>digitalInput)
{
	vector<int>AnalogReadingsVec = GetAnalogReadings(digitalInput);
	vector<RangeValuesandFrequency>rangeandFrequencyfromReadings = GetRangesAndFrequentValue(AnalogReadingsVec);
	vector<string>rangeandFrequencyString = GetRangeandFrequencyOutputAsString(rangeandFrequencyfromReadings);
	PrintRangeandFrequency(rangeandFrequencyString);
	return rangeandFrequencyfromReadings;
}

void PrintRangeandFrequency(vector<string>rangeandFrequencyString)
{
	int maxIndex = rangeandFrequencyString.size();
	for(int l_index = 0;l_index < maxIndex;l_index++)
	{
		cout <<rangeandFrequencyString[l_index];
	}
}










