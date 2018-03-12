/*
Function FILE- This is actually making functions and should never be shared. only the compiled (rus_BigBadLib.o) should be shared. If this is found please delete.

INFO: SEE BigBadCSCLib-Rus.h

*/
#include "BigBadCSCLib-Rus.h"





#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)



//#include "EasyBMP.h"
//#include "EasyBMP_Font.h"
//#include "EasyBMP_Geometry.h"
//#include "EasyBMP_SimpleArray.h"
#include <windows.h>
/*
Lots more, but for now just CreateDirectory("output", NULL);
*/
#include <ctime>
/*
 unsigned int start = clock();
cout << "waiting for keyhit";
cin.ignore();    
cout << "Time taken in millisecs: " << clock()-start;

*/
#include <random>
/*
	random_device rd;
	rd.min() << std::endl;
	cout << "maximum: " << rd.max() << std::endl;
	cout << "entropy: " << rd.entropy() << std::endl;
	cout << "a random number: " << rd() << std::endl;
		
*/
#include <cstdint>
/*
What it adds:
	Signed maximum width integer type
		intmax_t
	Maximum width unsigned integer type 
		uintmax_t
	
	
	
	
	
	Signed integer with width of exactly 8, 16, 32 and 64 bits respectively with no padding bits and using 2's complement for negative values
	(provided only if the implementation directly supports the type) 
		int8_t
		int16_t
		int32_t
		int64_t
	
	Unsigned integer type with width of exactly 8, 16, 32 and 64 bits respectively
	(provided only if the implementation directly supports the type)
		uint8_t
		uint16_t
		uint32_t
		uint64_t
	
	
	
	
	
	fastest signed integer type with width of at least 8, 16, 32 and 64 bits respectively 
		int_fast8_t
		int_fast16_t
		int_fast32_t
		int_fast64_t
	
	fastest unsigned integer type with width of at least 8, 16, 32 and 64 bits respectively 
		uint_fast8_t
		uint_fast16_t
		uint_fast32_t
		uint_fast64_t
	
	
	
	
	
	smallest signed integer type with width of at least 8, 16, 32 and 64 bits respectively 
		int_least8_t
		int_least16_t
		int_least32_t
		int_least64_t
	
	unsigned integer type with width of at least 8, 16, 32 and 64 bits respectively
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
	
	exit(EXIT_FAILURE);
*/
#include <chrono>
#include <time.h>
/*
	Has more, all I use is:
	VARIABLE = time(NULL);
*/
#include <stdlib.h>
/*
Probably does more, all I need is:
rand()
	Generates random number
srand(seed)
	Sets a new seed for pseudorandom generation
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
#include <fstream>
/* i/ofstream info
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
#include <string>
/*
	real strings
	cstringvariable = stringVariableName.c_str();
	
	StringVariableFooBarWhatever = to_string(IntOrFloatOrWhateverBaZZ);
*/
#include <string.h>
/*
	cstring mess
*/
#include <iomanip>
/* <iomanip> info
	Manipulates input and output
	cout << setprecision(2) << fixed << showpoint;
	output stuff << minumum decimal points() << cutoff decimal points? << show decimal point always ;
*/
#include <cmath>
/* <cmath> info
	adds math functions
	
	
	trig- sin(),cos, tan, ect
	pow(base, exponent);
	sqrt(thing to do root of);
	cbrt(thing to do cube root of);
	ceil()
	floor()
	nearbyint(number to round to nearest int)
	copysign(magnitude, sign)
*/
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

using namespace std;



// findAverage
// task: This function receives an array of integers and its size.
// It finds and returns the average of the numbers in the array
// precondition : array of floating point numbers
// postcondition : average of the numbers in the array
double findAverage (const int array[], int size){
	float sum = 0; // holds the sum of all the numbers 
	for (int pos = 0; pos < size; pos++)
		sum = sum + array[pos];
	return (sum / size); //returns the average
}

// findHighest
// task: This function receives an array of integers and its size.
// It finds and returns the highest value of the numbers in the array
// precondition : array of floating point numbers
// postcondition : highest value of the numbers in the array

long int findHighest(const long int array[], int long size){
	long int currentMax = array[0];
	for(long int i = 0; i + 1 <= size; i = i + i){
		if(array[i] >= currentMax){
			currentMax = array[i];
		}
	}
	return currentMax;
}


//findLowest
//task: This function receives an array of integers and its size.
//It finds and returns the lowest value of the numbers in the array
//precondition : array of floating point numbers
//postcondition : lowest value of the numbers in the array
int findLowest (const long int array[], long int size){
	long int currentMin = array[0];
	for(long int i = 0; i + 1 <= size; i = i + i){
		if(array[i] <= currentMin){
			currentMin = array[i];
		}
	}
	return currentMin;
}