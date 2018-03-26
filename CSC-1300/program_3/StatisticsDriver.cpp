/*
	By Rus Hoffman
*/
#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)

//#include "BigBadLib_Full.h"
//#include "BigBadLib_CSC.h"

#include "Statistics.h"

#include <vector>
/*
		format:
			vector <DATA TYPE HERE> VARIABLE NAME; //initial zero sized
			vector <DATA TYPE HERE> VARIABLE NAME (INITIALSIZE); //sized with INITIALSIZE size
			vector <DATA TYPE HERE> VARIABLE NAME (INITIALSIZE, OGVARIABLE); //all vals are OGVARIABLE at first
			vector <DATA TYPE HERE> VARIABLE NAME (anothervectorname); //othervectorname is copyed to the new one

		Access/assign:
			myvector[i]


		VECTORNAME.push_back(NUMBER)
			puts somthing at the end of a vector
		VECTORNAME.clear()
			clears vector
		VECTORNAME.size()
			gets size
		VECTORNAME.empty()
			If empty returns a one/true
		VECTORNAME.at(i)
			returns value of ith entry
		VECTORNAME.capacity()
			current max size
		VECTORNAME.reverse()
			reverse orders entries
		VECTORNAME.resize (i, val)
			adds I spaces to vector, and optinally initialzes to val
		VECTORNAME.swap(OTHERVECTORNAME);
			swaps two vectors contents
*/


//#include <windows.h>
/*
	LPCWSTR FOOBARDIRECTERY = L"c:\testdir";
	CreateDirectory(FOOBARDIRECTERY, NULL)
	CreateDirectory("output", NULL);
*/


//#include <ctime>
/*
	http://www.cplusplus.com/reference/ctime/

	Macro:
		CLOCKS_PER_SEC

	seconds = clock() / CLOCKS_PER_SEC

	unsigned int start = clock();
	cout << "waiting for keyhit";
	cin.ignore();
	cout << "Time taken in millisecs: " << clock()-start;
*/




#include <cstdlib>
/*
	system("pause")
	system("CLS")
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


//#include <time.h>
/*
	Has more, all I use is:
	VARIABLE = time(NULL);
*/


#include <iostream>
/*
	system("pause")
		Enter any key to continue..
	cout << "" << endl;
		output things
	cin >> VARNAME;
		Bring in numbers
	cin.get(VARNAME);
		Single Char
	getline(cin, VARNAME);
		get a line
*/


#include <iomanip>
/*
	Manipulates input and output
	cout << setprecision(2) << fixed << showpoint;
	cout << minumum decimal points(VARIABLE OR NUMBER) << cutoff decimal points? << show decimal point always;
*/


#include <fstream>
/* i/ofstream info
	(i or o)fstream FILEIDENT;
	FILEIDENT.open("FILENAME.txt");
	FILEIDENT << VARIABLE << endl;
	FILEIDENT.close();

	General:
		foobar_recognizablename.open(stringVariableName.c_str());



		bar_recognizablename.open("foo/bar_Input.txt");
			Will open file for reading, file must exist to work
		foo_recognizablename.open("bar/foo_Output.txt");
			Will create file, if it already exists it will be deleted and overwritten
		if(!bar_recognizablename){HAPPENS IF ERROR}
			For input validation, you can use infile.fail()

		Closing files:
			bar_recognizablename.close();
			foo_recognizablename.close();
	Input:
		bar_recognizablename >> myVariable;
			Can be used for boolean.. [foo/bar_Input >> myVariable] returns true when it works


	Output:
		foo_recognizablename << "Thing happened" << endl;


	if(!IDENFIFIERWHATEVERYOUWANT){
		happens if it didnt open correctly
	}
*/


//#include <string>
/*
	real strings
	cstringvariable = stringVariableName.c_str();

	StringVariableFooBarWhatever = to_string(IntOrFloatOrWhateverBaZZ);
*/


//#include <cstring>
/*
	Ugly Cstring manipulators
*/


//#include <cmath>
/*
	Functions:
		Trigonometric functions:
				cos(InputFoo)
				sin(InputFoo)
				tan(InputFoo)
		ArcTrigonometric functions:
				acos(InputFoo)
				asin(InputFoo)
				atan(InputFoo)

		Hyperbolic functions:
			cosh(InputFoo)
			sinh(InputFoo)
			tanh(InputFoo)

		Exponential and logarithmic functions
			log(InputFoo)
				Compute natural logarithm (function)
			log10(InputFoo)
				Compute common logarithm (function)

		Power functions
			pow(InputBase, InputPower)
				Raise to power (function)
			sqrt(InputFoo)
				Compute square root (function)

		Rounding and remainder functions
			ceil(InputFoo)
				Round up value (function)
			floor(InputFoo)
				Round down value (function)
			fmod(numerator, denominator)
				Compute remainder of division (function)

		Other functions
			fabs(InputFoo)
				Compute absolute value, floating point only (function)
			abs(InputFoo)
				Compute absolute value, int or floating point (function)
*/



/*
Code gud check input
	Variable Type Check
	Length Check (over/underflow attack)
	Range Check (month should be 1 to 12)
	Reasonable Check (birthyear is reasonable)
	Divide by Zero (and indirect devisions)
	Format Check (MM/DD/YYY vs YYYY/MM/DD)

Useful bits of code:
	cin problems can be found by cin.fail()
	fixes cin problems:
		cin.clear();
		cin.ignore();

	#pragma omp parallel for reduction(+:VariableThatCallCanAccess)
	for(long long int i = start; i <= max; i = i + 1){

	}

	vector <DATA TYPE HERE> VARIABLE NAME (INITIALSIZE, OGVARIABLE);
*/

using namespace std;

/*
Things to make for code:
	meanFromVector
	modeFromVector
	medianFromVector


When dealing with large groups of numbers, it is often statistically relevant to find out the median, mean and mode of the data set.


For this program, you will create multiple files that will allow the program to read in a selection of data points and generate the required information.
The format of the file is described in detail below. The files you will create will include:
	Statistics.h
		Statistics.h will include an include guard and the functional prototypes required to calculate the information required by this program. Namely:
		int* readData (const char* filename, int& size);
		float findMean (int* numbers, int size);
		float findMedian (int* numbers, int size);
		int findMode (int* numbers, int size);
		void displayInformation (float mean, float median, int mode);
	Statistics.cpp
		Statistics.cpp will contain all of the code necessary to implement the functions that are prototyped in Statistics.h
	StatisticsDriver.cpp
		StatisticsDriver.cpp will read in a filename from the user via command line arguments, then use the functions from Statistics.h/.cpp to create the necessary data structures, find the necessary information and display the results.
	Input
The user will provide the file name containing all information via command line argument at the time the program is executed. If the file does not exist, the user should be prompted for a new file. The input fill I will provide (numbers20.txt) and all test files I use will follow the same formatting. The first line of the file contains the number of integer values in the file, after that line, the numbers are listed one per line.
After all of the information has been read in, the functions outlined in Statistics.h should be run to get the required data and finally the information should be displayed in a nicely formatted table to the user.
Sample Output:
	C:\CSC1300\Programs> Statistics.exe numbers20.txt
	Welcome to the statistics program.
	The statistics for the 20 read in values are :
	The mean of the data set provided is :     65.2
	The median of the data set provided is :   70.5
	The mode of the data set provided is :       47
	Thank you and have a nice day

Keep in mind:
	A word about Mode
		Since mode is the item that appears most often in your data set it is possible to have multiple modes within the same dataset.
		Your program should return the FIRST of the data points that occurs if a tie exists.

Provided Files:
	Numbers20.txt
	BasicSort.h
	BasicSort.cpp






*/
int compare(const void * a, const void * b){
	return *(long*)a - *(long*)b;
}

int main (int argc, char* argv[]){
	//Variables!
		//Arguments:
			string executableName = argv[0];
			string userArgument;
			string userArgumentOGSingleString;
			if(argc == 2){
				userArgumentOGSingleString = argv[1];
			}
		//Fstream things:
			ifstream loadData;
			char* filename = argv[1];

			long numberOfValues = 5;
		//Sorting/DATA
			long * dataArray = NULL;
	//Variables are done being made
	//Confirm there /are/ any arguments
		if(argc != 2){
			cout << "To use this program use this format:" << endl;
			cout << "EX: " << executableName << " filename.txt" << endl;
			cout << endl;
			cout << "NOTE:" << endl;
			cout << "\tthe file's first line should be the number values" << endl;
			cout << "\tafter that, each value is on its own line" << endl;
			return 0;
		}
	//now we know there are 2 arguments, the exe name and somthing else
	//Make sure the argument is a valid file name
	//MAYBE THIS WORKS IDK
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
		//long dataArray[numberOfValues];
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


	/*cout << "Sorted Array:" << endl;
	for (long i = 0; i < numberOfValues; i++) {
		cout << i + 1 << ".    " << dataArray[i] << endl;
	}*/


/*
	cout << "Statistics:" << endl;
	cout << setw(8) << left << "Mean:   " << right << setw(15) << findMean(dataArray, numberOfValues) << setw(1) << endl;
	cout << setw(8) << left << "Median: " << right << setw(15) << findMedian(dataArray, numberOfValues) << setw(1) << endl;
	cout << setw(8) << left << "Mode:   " << right << setw(15) << findMode(dataArray, numberOfValues) << setw(1) << endl;
	*/

	displayInformation(findMean(dataArray, numberOfValues), findMedian(dataArray, numberOfValues), findMode(dataArray, numberOfValues));


	//Program is over clean up the heap
	delete[] dataArray;
	return 1;
}
