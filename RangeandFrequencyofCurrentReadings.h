#include <stdio.h>
#include<bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include<numeric>

#pragma once
using namespace std;
const int c_NOTVALID =255;
const int c_ANALOGMAXCURRENTOUTPUT =10;
const int c_DIGIMAXCURRENTINPUT = 4094;


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
vector<StringandNumRangeOutput> GetRangesAndFrequentValue(int inputValues[],int numOfElements);
string GetRangeandCountOutputAsString(RangeValuesAndCount currentRangeandCount );
