#include "RangeandFrequencyofCurrentReadings.h"
#include <stdio.h>
#include<bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include<math.h>

convertToAnalog convertBasedOnSensorType[TOTAL_SENSOR_TYPES] = {convert12bitDigitalInputstoAnalog, convert10bitDigitalInputstoAnalog};
 
bool IsInputValid(int digitalInput,SensorType sensorType)
{
	bool isValid = false;
	int digMaxCurrent = c_DIGIMAXCURRENT12BIT;
	if(sensorType == SensorType::e_10bit)
	{
		digMaxCurrent = c_DIGIMAXCURRENT10BIT;
	}
	if((digitalInput >=  0) && (digitalInput <= m_digiMaxCurrent))
	{
		isValid = true;
	}
	return isValid;
}

int convert12bitDigitalInputstoAnalog(int digitalInput)
{
	float analogVal =  c_ANALOGMAXCURRENT12BIT * digitalInput/c_DIGIMAXCURRENT12BIT ;
	return(round(analogVal));

}

int convert10bitDigitalInputstoAnalog(int digitalInput)
{
    float analogVal =  c_ANALOGMAXCURRENT10BIT * digitalInput/c_DIGIMAXCURRENT10BIT ;
    analogVal = abs(analogVal - 15);//convert to positive value
    return(round(analogVal));

}


vector<int> GetAnalogReadings(vector<int>digitalInput,SensorType sensorType)
{
	int l_analogOutput;
	int l_digitalInput;
	int maxIndex = digitalInput.size();
	vector <int> analogCurrentReadings;
	for(int l_index = 0;l_index < maxIndex;l_index++)
	{
		l_digitalInput = digitalInput.at(l_index);
		if(IsInputValid(l_digitalInput,sensorType) ==  true)
		{
			convertToAnalog conversion_callback = convertBasedOnSensorType[sensorType];
			l_analogOutput = conversion_callback(l_digitalInput);
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

vector<RangeValuesandFrequency> ProcessSensorReadingsforRangeandFrequency(vector<int>digitalInput, SensorType sensorType)
{
	vector<int>AnalogReadingsVec = GetAnalogReadings(digitalInput,sensorType);
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
		cout <<rangeandFrequencyString[l_index]<<"\n";
	}
}












