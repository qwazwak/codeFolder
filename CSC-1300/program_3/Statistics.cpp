/*
	By Rus Hoffman
*/
#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)

#include "Statistics.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

long* readData (const char* filename, long& size){
	long * array;
	ifstream loadData;
	loadData.open(filename);
	if(!loadData || loadData.fail()){
		//This happens when there is an error opening the file
		cout << "There was an error loading the file '" << filename << "'" << endl;
		cout << "Program will now close" << endl;
		return 0;
	}
	cout << "File Loaded!" << endl;
	//file name is valid and opened
	//load dataset and confirm that there are the said number and makes the array
	loadData >> size;
	if(loadData.fail() || size < 1) {
		cout << "Invalid number of values" << endl;
		return 0;
	}
	array = new long[size];
	//long dataArray[numberOfValues];
	if(array == NULL){
		cout << "Error allocating memory" << endl;
		return 0;
	}

	for (int i = 0; i < size; i++) {
		loadData >> array[i];
	}

	loadData.close();
	return array;
}



double findMean (long* numbers, long size){
	long addUp = 0;
	double mean;
	for(long i = 0; i < size; i = i + 1){
		addUp = addUp + numbers[i];
	}
	mean = static_cast<double>(addUp) / static_cast<double>(size);
	return mean;
}


double findMedian (long* numbers, long size){
	double Median;
	if(size % 2 == 1){
		Median = numbers[static_cast<long>(ceil(static_cast<double>(size) / 2.0))];
	}
	else{
		Median = static_cast<double>(numbers[static_cast<long>(ceil(static_cast<double>(size) / 2.0))] + numbers[static_cast<long>(floor(static_cast<double>(size) / 2.0))]) / 2.0;
	}
	return Median;
}


long findMode (long* numbers, long size){
	long positionFromNumbers;
	long largestNumber = numbers[size - 1];
	long modeInstanceCount;
	long modeValue;
	long * modeArray = new long[largestNumber];
	for(long i = 0; i < largestNumber; i = i + 1){
		modeArray[i] = 0;
	}

	for(long i = 0; i < size; i = i + 1) {
		positionFromNumbers = numbers[i];
		++modeArray[positionFromNumbers];
	}

	modeInstanceCount = modeArray[0];
	for(long i = 0; i < largestNumber; i = i + 1){
		if(modeArray[i] > modeInstanceCount){
			modeValue = i;
			modeInstanceCount = modeArray[i];
		}
	}
	delete[] modeArray;
	return modeValue;
}


void displayInformation (double mean, double median, long mode){
	cout << setw(8) << left << "Mean of the data set provided is :   " << right << setw(15) << mean << setw(1) << endl;
	cout << setw(8) << left << "Median of the data set provided is:  " << right << setw(15) << median << setw(1) << endl;
	cout << setw(8) << left << "Mode of the data set provided is:    " << right << setw(15) << mode << setw(1) << endl;
}
