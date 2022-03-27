#pragma once
#include <stdio.h>
#include<bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include<numeric>


using namespace std;
const int c_NOTVALID =255;
const float c_ANALOGMAXCURRENTOUTPUT =10;
const float c_DIGIMAXCURRENTINPUT = 4094;


 struct RangeValuesAndCount{
  int rangeLower;
  int rangeUpper;
  int count;
};

 struct StringandNumRangeOutput{
	RangeValuesAndCount rangeValuesAndCount;
	string stringIndexAndCount;
};

int convertDigitaltoAnalog(int digitalInput);
vector<int> GetAnalogReadings(vector<int>digitalInput);
bool IsInputValid(int digitalInput);
vector<StringandNumRangeOutput> GetRangesAndFrequentValue(vector<int> inputValues);
string GetRangeandCountOutputAsString(RangeValuesAndCount currentRangeandCount );
void PrintRangeandFrequency(vector<StringandNumRangeOutput>printRangeandFrequencyInput);
vector<StringandNumRangeOutput> ProcessSensorReadingsforRangeandFrequency(vector<int>digitalInput); ProcessSensorReadingsforRangeandFrequency(vector<int>digitalInput);
