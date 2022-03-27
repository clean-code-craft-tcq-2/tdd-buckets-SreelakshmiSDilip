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

 struct RangeValuesandFrequency{
  int rangeLower;
  int rangeUpper;
  int count;
};

 struct StringandNumRangeOutput{
	RangeValuesandFrequency RangeValuesandFrequency;
	string stringIndexAndCount;
};

int convertDigitaltoAnalog(int digitalInput);
vector<int> GetAnalogReadings(vector<int>digitalInput);
bool IsInputValid(int digitalInput);
vector<RangeValuesandFrequency> GetRangesAndFrequentValue(vector<int> inputValues);
vector<string> GetRangeandFrequencyOutputAsString(vector<RangeValuesandFrequency> RangeandFrequency);
vector<RangeValuesandFrequency> ProcessSensorReadingsforRangeandFrequency(vector<int>digitalInput);
void PrintRangeandFrequency(vector<RangeValuesandFrequency>printRangeandFrequencyInput);
