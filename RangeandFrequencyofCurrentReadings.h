#include <stdio.h>
#include<bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include<numeric>

#pragma once
using namespace std;
const int c_NOTVALID =255;

typedef struct __length__{
  int int_count;
  string char_count;
}Rangelength;

typedef struct __index__{
  int rangeLower;
  int rangeUpper;
  int count;
}RangeValuesAndCount;

typedef struct __numAndString__{
	RangeValuesAndCount rangeValuesAndCount;
	string stringIndexAndCount;
}StringandNumRangeOutput;


vector<StringandNumRangeOutput> GetRangesAndFrequentValue(int inputValues[],int numOfElements);
string GetRangeandCountOutputAsString(RangeValuesAndCount currentRangeandCount , int inputValues[] );
