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

int main (int argc, char* argv[]){
	//Variables!
		//Fstream things:
			ifstream loadData;
			char* filename = argv[1];
			long numberOfValues;
		//Sorting/DATA
			long * dataArray = NULL;
	//Variables are done being made
	//Confirm there are any arguments
		if(argc != 2){
			cout << "To use this program use this format:" << endl;
			cout << "EX: " << argv[0] << " filename.txt" << endl;
			cout << endl;
			cout << "NOTE:" << endl;
			cout << "\tthe file's first line should be the number values" << endl;
			cout << "\tafter that, each value is on its own line" << endl;
			return 0;
		}
	//now we know there are 2 arguments, the exe name and something else
	//Make sure the argument is a valid file name
		loadData.open(filename);
		if(!loadData || loadData.fail()){
			//This happens when there is an error opening the file
			cout << "There was an error loading the file '" << filename << "'" << endl;
			cout << "Either a real error happened, or the filename is invalid" << endl;
			return 0;
		}
		loadData.close();
	//Argument is a valid file name
	//Load data
		dataArray = readData(filename, numberOfValues);
	//data is loaded

	//Sort data...
		qsort(dataArray, numberOfValues, sizeof(long), compare);
	//Data is now sorted

	//Calculate and display the mean, median, and mode
		cout << "The statistics for the " << numberOfValues << " provided values are:" << endl;
		displayInformation(findMean(dataArray, numberOfValues), findMedian(dataArray, numberOfValues), findMode(dataArray, numberOfValues));


	//Program is over clean up the heap
		delete[] dataArray;
	//End program
		return 1;
}
