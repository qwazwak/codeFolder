/*
	By Rus Hoffman
*/
#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)

#include "Statistics.h"

//#include <vector>
#include <cstdlib>
/*
	Quicksort:
		qsort (SOURCEARRAY, numberOfValues, SizeOfEachElementInBytes/sizeof(int), compareMyType);

		Outside main you must make a fucnction that quicksort references when checking how things are related
			prototype
				int compar (const void* p1, const void* p2);
			Actuall function:
				int compareMyType (const void * a, const void * b){
					if( *(MyType*)a <  *(MyType*)b ){
						return -1;
					}
					if( *(MyType*)a == *(MyType*)b ){
						return 0;
					}
					if( *(MyType*)a >  *(MyType*)b ){
						return 1;
					}
				}
			What returns do:
				<0	p1 goes before p2
				0	p1 is the same as p2
				>0	p1 goes after p2

		The actual call to quicksort:
			qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));
				Parameters
					base
						Pointer to the first object of the array to be sorted, converted to a void*.
					num
						Number of elements in the array pointed to by base.
						size_t is an unsigned integral type.
					size
						Size bytes of each element in the array.
						size_t is an unsigned integral type.
					compar
						Pointer to a function that compares two elements.
						This function is called repeatedly by qsort to compare two elements. It shall follow the following prototype:

*/
#include <iostream>
#include <iomanip>
#include <fstream>
//#include <cmath>

using namespace std;

int compare(const void * a, const void * b){
	return *(long*)a - *(long*)b;
}

int main (int argc, char* argv[]){
	//Variables!
		//Arguments:
			//string userArgumentOGSingleString;
			//if(argc == 2){
			//	userArgumentOGSingleString = argv[1];
			//}
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
	//now we know there are 2 arguments, the exe name and somthing else
	//Make sure the argument is a valid file name
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
		loadData >> numberOfValues;
		if(loadData.fail() || numberOfValues < 1) {
			cout << "Invalid number of values" << endl;
			cout << "Program will now close" << endl;
			return 0;
		}
		dataArray = new long[numberOfValues];
		if(dataArray == NULL){
			cout << "Error allocating memory" << endl;
			cout << "Program will now close" << endl;
			return 0;
		}
		for (int i = 0; i < numberOfValues; i++) {
			loadData >> dataArray[i];
		}

		loadData.close();
	//data is loaded
	//sort data
		qsort(dataArray, numberOfValues, sizeof(long), compare);
	//data is sorted

	displayInformation(findMean(dataArray, numberOfValues), findMedian(dataArray, numberOfValues), findMode(dataArray, numberOfValues));


	//Program is over clean up the heap
	delete[] dataArray;
	return 1;
}
