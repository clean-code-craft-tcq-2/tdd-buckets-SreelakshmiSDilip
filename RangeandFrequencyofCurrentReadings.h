#pragma once
#include <stdio.h>
#include<bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include<numeric>


using namespace std;
const int c_NOTVALID =255;
 float c_ANALOGMAXCURRENT12BIT = 10;
 float c_DIGIMAXCURRENT12BIT = 4094;

  float c_ANALOGMAXCURRENT10BIT = 30;
 float c_DIGIMAXCURRENT10BIT = 1022;

 const int TOTAL_SENSOR_TYPES = 2;

 int m_analogMaxCurrent;
 int m_digiMaxCurrent;

 struct RangeValuesandFrequency{
  int rangeLower;
  int rangeUpper;
  int count;
};
 enum SensorType{
	 e_12bit =0,
	 e_10bit =1
 };

 

int convert12bitDigitalInputstoAnalog(int digitalInput);
int convert10bitDigitalInputstoAnalog(int digitalInput);
vector<int> GetAnalogReadings(vector<int>digitalInput,SensorType sensorType);
bool IsInputValid(int digitalInput);
vector<RangeValuesandFrequency> GetRangesAndFrequentValue(vector<int> inputValues);
vector<string> GetRangeandFrequencyOutputAsString(vector<RangeValuesandFrequency> RangeandFrequency);
vector<RangeValuesandFrequency> ProcessSensorReadingsforRangeandFrequency(vector<int>digitalInput,SensorType sensorType);
void PrintRangeandFrequency(vector<string>rangeandFrequencyString);
void SetConversionFactorsBasedOnSensorType(SensorType sensorType);

typedef int (*convertToAnalog)(int digitalInput);
