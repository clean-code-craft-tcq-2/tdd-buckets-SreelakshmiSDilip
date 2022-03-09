#include <stdio.h>
#include<bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include<numeric>

#pragma once
using namespace std;
const int c_NOTVALID =255;


 struct RangeValuesAndCount{
  int rangeLower;
  int rangeUpper;
  int count;
};

 struct StringandNumRangeOutput{
	RangeValuesAndCount rangeValuesAndCount;
	string stringIndexAndCount;
};


vector<StringandNumRangeOutput> GetRangesAndFrequentValue(int inputValues[],int numOfElements);
string GetRangeandCountOutputAsString(RangeValuesAndCount currentRangeandCount , int inputValues[] );
