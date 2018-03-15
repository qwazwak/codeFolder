/*
	By Rus Hoffman
*/
#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)

//#include "BigBadLib_Full.h"
//#include "BigBadLib_CSC.h"


//#include "EasyBMP.h"
//#include "EasyBMP_Font.h"
//#include "EasyBMP_Geometry.h"
//#include "EasyBMP_SimpleArray.h"





#include <bitset>
/*
	bitset<NUMBEROFBITSMEEP>(FOOBARVARIABLENAME)

*/


#include <windows.h>
/*
	LPCWSTR FOOBARDIRECTERY = L"c:\testdir";
	CreateDirectory(FOOBARDIRECTERY, NULL)
	CreateDirectory("output", NULL);
*/


#include <ctime>
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


#include <random>
//All of this library is c++11 and requires compiler support
/*
	C++11
	random_device FOOBARNAMEME;
	cout << "Minumum: " << FOOBARNAMEME.min() << endl;
	cout << "Maximum: " << FOOBARNAMEME.max() << endl;
	cout << "Entropy: " << FOOBARNAMEME.entropy() << endl;
	This is real random. Only use it to seed a pseduo random generator - SEE cstdlib and rand()

*/


#include <cstdint>
//All of this library is c++11 and requires compiler support
/*
	C++11
	What it adds:
		Signed maximum width integer type
			intmax_t
		Maximum width unsigned integer type
			uintmax_t

		Integer with width of exactly 8, 16, 32 and 64 bits respectively with no padding bits and using 2's complement for negative values
		(provided only if the implementation directly supports the type)
			Signed:
				int8_t
				int16_t
				int32_t
				int64_t
			Unsigned:
				uint8_t
				uint16_t
				uint32_t
				uint64_t

		Fastest integer type with width of at least 8, 16, 32 and 64 bits respectively
			Signed:
				int_fast8_t
				int_fast16_t
				int_fast32_t
				int_fast64_t
			Unsigned:
				uint_fast8_t
				uint_fast16_t
				uint_fast32_t
				uint_fast64_t

		Smallest integer type with width of at least 8, 16, 32 and 64 bits respectively
			Signed:
				int_least8_t
				int_least16_t
				int_least32_t
				int_least64_t
			Unsigned:
				uint_least8_t
				uint_least16_t
				uint_least32_t
				uint_least64_t

		Constants: (max value)
			INTMAX_MAX
			INT8_MAX
			INT16_MAX
			INT32_MAX
			INT64_MAX
			INT_FAST8_MAX
			INT_FAST16_MAX
			INT_FAST32_MAX
			INT_FAST64_MAX
			INT_LEAST8_MAX
			INT_LEAST16_MAX
			INT_LEAST32_MAX
			INT_LEAST64_MAX
*/


#include <cstdlib>
/*
	Quicksort:
		qsort (SOURCEARRAY, NumberOfElements, SizeOfEachElementInBytes/sizeof(int), compareMyType);

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


	random:
		srand(SEEDGOESHERE);
			seed sources:
				time(NULL)

				if c++ 11 is avalible use a real random generator to seed
		rand() to generate random numbers


	String to XXX Conversions:
		To use these the format is VARIABLEWITHTARGETTYPE = functionName(SOURCEVARIABLE)
			atof
				Convert string to double (function )
			atoi
				Convert string to integer (function )
			atol
				Convert string to long integer (function )
			atoll
				C++11
				Convert string to long long integer (function )
			strtod
				Convert string to double (function )
			strtof
				C++11
				Convert string to float (function )
			strtol
				Convert string to long integer (function )
			strtold
				C++11
				Convert string to long double (function )
			strtoll
				C++11
				Convert string to long long integer (function )
			strtoul
				Convert string to unsigned long integer (function )
			strtoull
				C++11
				Convert string to unsigned long long integer (function )
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



	Convert from number to string:
		ALL C++11
			to_string
				Convert numerical value to string (function )
			to_wstring
				Convert numerical value to wide string (function )
	Convert from string to number:
		ALL C++11
			stoi
				Convert string to integer (function template )
			stol
				Convert string to long int (function template )
			stoul
				Convert string to unsigned integer (function template )
			stoll
				Convert string to long long (function template )
			stoull
				Convert string to unsigned long long (function template )
			stof
				Convert string to float (function template )
			stod
				Convert string to double (function template )
			stold
				Convert string to long double (function template )
*/


//#include <cstring>
/*
	Ugly Cstring manipulators
*/





//#include <cmath>
//Some parts of this library have C++11 requirments
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
		Area Hyperbolic functions:
			acosh(InputFoo)
				REQUIRES C++11
			asinh(InputFoo)
				REQUIRES C++11
			atanh(InputFoo)
				REQUIRES C++11

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
			cbrt(InputFoo)
				REQUIRES C++11
				Compute cubic root (function)
			hypot(InputA, InputB)
				REQUIRES C++11
				Compute hypotenuse (function)

		Rounding and remainder functions
			ceil(InputFoo)
				Round up value (function)
			floor(InputFoo)
				Round down value (function)
			fmod(numerator, denominator)
				Compute remainder of division (function)
			trunc(InputFoo)
				REQUIRES C++11
				Truncate value  IE rounds towards zero (function)
			round(InputFoo)
				REQUIRES C++11
				Round to nearest (function)
			lround(InputFoo)
				REQUIRES C++11
				Round to nearest and cast to long integer (function)
			llround(InputFoo)
				REQUIRES C++11
				Round to nearest and cast to long long integer (function)
			rint(InputFoo)
				REQUIRES C++11
				Round to integral value (function)
			lrint(InputFoo)
				REQUIRES C++11
				Round and cast to long integer (function)
			llrint(InputFoo)
				REQUIRES C++11
				Round and cast to long long integer (function)
			nearbyint(InputFoo)
				REQUIRES C++11
				Round to nearby integral value (function)

		Floating-point manipulation functions
			copysign(InputMagnitude, InputSign)
				REQUIRES C++11
				Copy sign (function)

		Other functions
			fabs(InputFoo)
				Compute absolute value, floating point only (function)
			abs(InputFoo)
				Compute absolute value, int or floating point (function)
*/



/* Delay and dynamic noise making
#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)
	#include <windows.h>
	inline void delay(unsigned long long ms){
		Sleep(ms);
	}
#else //presume POSIX
	#include <unistd.h>
	inline void delay(unsigned long long ms){
		usleep( ms * 1000 );
	}
#endif
#if (defined(WINDOWS) || defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)) && !defined(LINUX)
	#include <Windows.h>
	inline void dynBeep(int freq, intmax_t timeOfBeep){
		Beep(freq, timeOfBeep);
	}
#elif !(defined(WINDOWS) || defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)) && defined(LINUX)
	#include <stdio.h>
	void dynBeep(int freq, intmax_t timeOfBeep){
		system("echo -e "\007" >/dev/tty10");
	}
#else
	#include <stdio.h>
	void dynBeep(int freq, intmax_t timeOfBeep){
		std::cout << "\a" << std::flush;
	}
#endif
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
	Variables:
		const VARTYPE VARNAME - makes it not change
		int - float - intmax_t - long intmax_t - increasing size
	static means it doesnt die

	cin >> variable;


	cin problems can be found by cin.fail()
	fixes cin problems:
		cin.clear();
		cin.ignore();


	cout << "text" << endl;

	//for loop
	for(int i = 1; i <= limit; i = i + 1){

	}

	//real loop
	while(){

	}

	//do while template
	do{

	}while();


	//switch template
	switch(VARIABLE){
		case ():

		break;
		case ():

		break;
		default:

		break;
	}

	(i or o)fstream FILEIDENT;
	FILEIDENT.open("FILENAME.txt");
	FILEIDENT << VARIABLE << endl;
	FILEIDENT.close();
*/

using namespace std;

uint_fast64_t combineNumbers(uint_fast64_t a, uint_fast64_t b){
	uint_fast64_t times = 1;
	while(times <= b){
		times = times * 10;
	}
	return (a * times ) + b;
}


uint_fast64_t getDataSizeFromUser(){
	int userWantedUnits;
	uint_fast64_t userEnteredValue;
	long double userWantedSize;



	cout << "|    Random Files Generator    |" << endl;
	cout << "|                              |" << endl;
	cout << "| Only enter a value less than |" << endl;
	cout << "|  18,446,744,073,709,552,046  |" << endl;
	cout << "|   Which is ~18 Quintillion   |" << endl;
	cout << "|IE: keep it under 20 digits|" << endl;
	cout << "|    Select units for amount   |" << endl;
	cout << "|      of data to make:        |" << endl;
	cout << "|        1- Bits               |" << endl;
	cout << "|        2- Bytes              |" << endl;
	cout << "|        3- Kilobytes          |" << endl;
	cout << "|        4- Megabytes          |" << endl;
	cout << "|        5- Gigabytes          |" << endl;
	cout << "|                              |" << endl;
	cout << "|   -";
	cin >> userWantedUnits;
	system("CLS");
	while(cin.fail() || userWantedUnits < 1 || userWantedUnits > 5){
		cout << "|    Random Files Generator    |" << endl;
		cout << "|                              |" << endl;
		cout << "| Only enter a value less than |" << endl;
		cout << "|  18,446,744,073,709,552,046  |" << endl;
		cout << "|   Which is ~18 Quintillion   |" << endl;
		cout << "|IE: keep it under 20 digits|" << endl;
		cout << "|        INVALID  INPUT        |" << endl;
		if(cin.fail()){
			cout << "|     Only enter a number      |" << endl;
		}
		else if(userWantedUnits < 1 || userWantedUnits > 5) {
			cout << "|   Only a 1, 2, 3, 4, or 5    |" << endl;
		}
		cout << "|                              |" << endl;
		cout << "|    Select units for amount   |" << endl;
		cout << "|      of data to make:        |" << endl;
		cout << "|        1- Bits               |" << endl;
		cout << "|        2- Bytes              |" << endl;
		cout << "|        3- Kilobytes          |" << endl;
		cout << "|        4- Megabytes          |" << endl;
		cout << "|        5- Gigabytes          |" << endl;
		cout << "|                              |" << endl;
		cout << "|   -";
		cin >> userWantedUnits;
		system("CLS");
		cin.clear();
		cin.ignore();
	}






	cout << "|    Random Files Generator    |" << endl;
	cout << "|                              |" << endl;
	cout << "|  Enter the number            |" << endl;
	cout << "|   of ";
	switch(userWantedUnits){
		case 1:
		  cout << "Bits     ";
		break;
		case 2:
		  cout << "Bytes    ";
		break;
		case 3:
		  cout << "Kilobytes";
		break;
		case 4:
		  cout << "Megabytes";
		break;
		case 5:
		  cout << "Gigabytes";
		break;
		default:
		  cout << "KilerEror";
			return -1;
		break;
	}
			      cout << " to generate |" << endl;
	cout << "|                              |" << endl;
	cout << "|   -";
	cin >> userWantedSize;
	system("CLS");
	while(cin.fail() || userWantedSize < 1 || userWantedSize > 5){
		cout << "|    Random Files Generator    |" << endl;
		cout << "|                              |" << endl;
		cout << "|        INVALID  INPUT        |" << endl;
		if(cin.fail()){
			cout << "|     Only enter a number      |" << endl;
		}
		else if(userWantedSize < 1){
			cout << "| Only enter a positive number |" << endl;
		}
		cout << "|                              |" << endl;
		cout << "|    Select units for amount   |" << endl;
		cout << "|                              |" << endl;
		cout << "|                              |" << endl;
		cout << "|                              |" << endl;
		cout << "|                              |" << endl;
		cout << "|                              |" << endl;
		cout << "|        5- Gigabytes          |" << endl;
		cout << "|                              |" << endl;
		cout << "|   -";
		cin >> userWantedSize;
		system("CLS");
		cin.clear();
		cin.ignore();
	}




























	return choice;
}


Planning:

Things for ui:

Total size vs size per files

total: max size then #Files
perfile: num files then


















int main(){
	//Initialization
		//Random Things
			random_device trueRandom;
			uint_fast64_t seedTime = clock();
			uint_fast64_t seedTrueRandom = trueRandom();
			uint_fast64_t seedReal = combineNumbers(seedTime, seedTrueRandom);
		//What the user wants:
			int userWantedUnits;
			long double userInputSize;
			int_least64_t realSizePerFile;



			int_least64_t numOfFiles;
			int_least64_t numOfValuesToGenerate;
			int_least64_t numIntOfValPerFile;
		 	long double numFloatOfValPerFile;







	if( trueRandom.entropy() == 0 ){
		mt19937_64 generator(seedTime);
		cout << "Hardware does not support nondeterministic seeds" << endl;
		cout << "Using current time as seed: " << seedTime << endl;
	}
	else{
		mt19937_64 generator(seedReal);
		cout << "Using mersenne twister engine seeded with nondeterministic seed" << endl;
		cout << "  Random seed combined with time: " << seedReal << endl;
		cout << "  Entropy: " << trueRandom.entropy() << endl;
	}
	cout << "  Minimum: " << trueRandom.min() << endl;
	cout << "  Maximum: " << trueRandom.max() << endl;
	cout << "setup done" << endl;
	system("pause");
	system("CLS");


	int_least64_t gensTillUpdate;
	uint_least64_t stopwatchStart;
	uint_least64_t stopwatch;
	long double timePerFileAverage;
	ofstream randomFilesOutput;
	uint_least64_t timePerFileTotal = 0;
	long double globalStopwatchStart;
	int_least64_t userOkayWithPercent;

bitset<NUMBEROFBITSMEEP>(FOOBARVARIABLENAME)


	int_least64_t userInputSize;
	int_least64_t userRealSize;








	cout << "|    Random Files Generator    |" << endl;
	cout << "|                              |" << endl;
	cout << "|                              |" << endl;
	cout << "| Enter the number of          |" << endl;
	cout << "|   files to make:             |" << endl;
	cout << "|      ";
	cin >> numOfFiles;
	system("CLS");
	do{
		cin.clear();
		cin.ignore();
		cout << "|    Random Files Generator    |" << endl;
		cout << "|                              |" << endl;
		cout << "|        Invalid  Entry        |" << endl;
		cout << "| Enter the number of          |" << endl;
		cout << "|   files to make:             |" << endl;
		cout << "|      ";
		cin >> numOfFiles;
		system("CLS");
	}while(cin.fail() || numOfFiles < 1);








	globalStopwatchStart = clock();


	//Generate and output numbers and files
	CreateDirectory("output", NULL);
	for(uint_least64_t currentFileNumber = 1; currentFileNumber <= numOfFiles; currentFileNumber = currentFileNumber + 1){
		stopwatchStart = clock();
		randomFilesOutput.open(".\\output\\RandomNumbers___Seed-" + to_string(seed) + "___values-" + to_string(numOfValuesToGenerate) + "___Part" + to_string(currentFileNumber) + "of" + to_string(numOfFiles) + ".txt");


		for(uint_least64_t currentNumGeneration = 1; currentNumGeneration <= numOfValuesToGenerate; currentNumGeneration = currentNumGeneration + 1){
			randomFilesOutput << generate();


		}
		randomFilesOutput << flush;
		randomFilesOutput.close();

		cout << endl << endl << endl << endl << endl << endl << endl;
		cout << "|    Random Files Generator    |" << endl;
		cout << "|                              |" << endl;
		cout << "| Progress - " << setprecision (1) << fixed << 100.0 * (static_cast<long double>(currentFileNumber) / static_cast<long double>(numOfFiles)) << "%" << endl;
		cout << "|                              |" << endl;
		cout << "| Time for this file - ";
		stopwatch = clock() - stopwatchStart;
		cout << stopwatch << "ms" << endl;
		cout << "|                              |" << endl;
		cout << "| Badly estimated time left - " << setprecision(2) << floor((static_cast<long double>(stopwatch) * (static_cast<long double>(numOfFiles) - static_cast<long double>(currentFileNumber)))/60000.0) << " minutes and " << (((static_cast<long double>(stopwatch) * (static_cast<long double>(numOfFiles) - static_cast<long double>(currentFileNumber)))/60000.0) - floor((static_cast<long double>(stopwatch) * (static_cast<long double>(numOfFiles) - static_cast<long double>(currentFileNumber)))/60000.0)) * 60 << " seconds" << endl;
		cout << "|                              |" << endl;
	}

	//Display Stats
	cout << endl << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl << endl;
	cout << "|    Random Files Generator    |" << endl;
	cout << "|                              |" << endl;
	cout << "| Number of files    - " << numOfFiles << endl;
	cout << "| Number of values per file  - " << numOfValuesToGenerate << endl;
	cout << "| Time Taken - " << ((clock() - globalStopwatchStart)/1000) << " seconds" << endl;
	cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
	system("pause");
	return 1;
}
