
#include "Statistics.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

long* readData (const char* filename, long& size){
	long *arrayFile;
	ifstream accessFile;
	accessFile.open(filename);
	accessFile >> size;
	arrayFile = new long [size];


	for (long i = 0; i < size; i++)
	{
		accessFile >> arrayFile[i];
	}
	return arrayFile;
}



double findMean (long* numbers, long size){
	long sum = 0;
	for (long i = 0; i <size; i++){
			sum = sum + numbers[i];
	}
	return static_cast<double>(sum) / static_cast<double>(size);
}


double findMedian (long* numbers, long size){
	double middleDec;
	long lower;
	long upper;
	if(size % 2 == 1){
		return static_cast<double>(numbers[size / 2]);
	}
	else{
		middleDec = static_cast<double>(size) / 2.0;
		lower = numbers[static_cast<long>(floor(middleDec))];
		upper = numbers[static_cast<long>(ceil(middleDec))];
		return (static_cast<double>(lower) + static_cast<double>(upper)) / 2.0;
	}
}


long findMode (long* numbers, long size){
	long modeInstanceCount;
	long modeValue;
	long * modeArray = new long[numbers[size - 1]];
	for(long i = 0; i < numbers[size - 1]; i = i + 1){
		modeArray[i] = 0;
	}
	for(long i = 0; i < size; i = i + 1) {
		modeArray[numbers[i]] = modeArray[numbers[i]] + 1;
	}

	modeInstanceCount = modeArray[0];
	modeValue = 0;
	for(long i = 0; i < numbers[size - 1]; i = i + 1){
		if(modeArray[i] > modeInstanceCount){
			modeValue = i;
			modeInstanceCount = modeArray[i];
		}
	}
	delete[] modeArray;
	return modeValue;
}


void displayInformation (double mean, double median, long mode){
	cout << "The mean of numbers is : "<< mean << endl;
	cout << "The median of the numbers is : "<< median << endl;
	cout << "The mode of the numbers is : " << mode << endl;
}
