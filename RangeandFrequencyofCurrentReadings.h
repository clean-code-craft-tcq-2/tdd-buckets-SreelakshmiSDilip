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
  int min_Index;
  int max_Index;
  int count;
}RangeIndicesandCount;

typedef struct __numAndString__{
	RangeIndicesandCount numIndexAndCount;
	string stringIndexAndCount;
}StringandNumRangeOutput;


vector<StringandNumRangeOutput> GetRangesAndFrequentValue(int inputValues[]);
string GetRangeandCountOutputAsString(RangeIndicesandCount currentIndicesandCount , int inputValues[] );
