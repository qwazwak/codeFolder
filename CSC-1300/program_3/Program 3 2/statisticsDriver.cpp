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

using namespace std;

int compare(const void * a, const void * b){
	return *(long*)a - *(long*)b;
}

int main(int argc, char* argv[]){
	//variables:
		//Data validation
			ifstream fooAccessFileIdent;
			int dataValidator;
		//Array things
			long NumberOfElements;
			long * dataArray = NULL;

	//Data validation
		if(argc != 2){
			cout << "you done fucked the program, fix it" << endl;
			return 1;
		}
		fooAccessFileIdent.open(argv[1]);
		fooAccessFileIdent >> dataValidator;
		if(!fooAccessFileIdent || fooAccessFileIdent.fail() || dataValidator < 1) {
			cout << "you done fucked the program, fix it" << endl;
			fooAccessFileIdent.close();
			return 1;
		}
		fooAccessFileIdent.close();

	//Load and sort array
	dataArray = readData(argv[1], NumberOfElements);
	qsort(dataArray, NumberOfElements, sizeof(long), compare);

	double median = findMedian(dataArray, NumberOfElements);
	displayInformation(findMean(dataArray, NumberOfElements), median, 42069);


	delete[] dataArray;
	cout << "Press enter to close program..." << endl;
	cin.ignore();
	return 0;
}
