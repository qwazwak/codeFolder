/*
Function FILE- This is actually making functions and should never be shared. only the compiled (rus_BigBadLib.o) should be shared. If this is found please delete.

INFO: SEE BigBadCSCLib-Rus.h

*/
#include "BigBadLib_CSC.h"




#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)

//#include "EasyBMP.h"
//#include "EasyBMP_Font.h"
//#include "EasyBMP_Geometry.h"
//#include "EasyBMP_SimpleArray.h"



//#include <windows.h>
/*
	Lots more, but for now just
	CreateDirectory("output", NULL);
	system("pause");
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





//#include <random>
//All of this library is c++11 and requires compiler support
/*
	C++11
	random_device FOOBARNAMEME;
	cout << "Minumum: " << FOOBARNAMEME.min() << endl;
	cout << "Maximum: " << FOOBARNAMEME.max() << endl;
	cout << "Entropy: " << FOOBARNAMEME.entropy() << endl;
	This is real random. Only use it to seed a pseduo random generator - SEE cstdlib and rand()
	
*/





//#include <cstdint>
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





//#include <cstdlib>
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





//#include <iostream>
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





//#include <iomanip>
/*
	Manipulates input and output
	cout << setprecision(2) << fixed << showpoint;
	cout << minumum decimal points(VARIABLE OR NUMBER) << cutoff decimal points? << show decimal point always;
*/





//#include <fstream>
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


void mclearScreen(unsigned int long lines){
	else if((lines % 5) == 0){
		for(unsigned int long i = 0; i < lines; i = i + 5){
			cout << endl << endl << endl << endl << endl;
		}
	}
	else if((lines % 3) == 0){
		for(unsigned int long i = 0; i < lines; i = i + 3){
			cout << endl << endl << endl;
		}
	}
	else if((lines % 2) == 0){
		for(unsigned int long i = 0; i < lines; i = i + 2){
			cout << endl << endl;
		}
	}
	else{
		for(unsigned int long i = 0; i < lines; i = i + 1){
			cout << endl;
		}
	}
}



//End My handy code, this is now class code

// findAverage
// task: This function receives an array of integers and its size.
// It finds and returns the average of the numbers in the array
// precondition : array of floating point numbers
// postcondition : average of the numbers in the array
float findAverage(const int array[], int size){
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

int findHighest(const int array[], int size){
	int currentMax = array[0];
	for(int i = 0; i < size; i = i + 1){
		if(array[i] > currentMax){
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
int findLowest (const int array[], int size){
	int currentMin = array[0];
	for(int i = 0; i + 1 <= size; i = i + 1){
		if(array[i] < currentMin){
			currentMin = array[i];
		}
	}
	return currentMin;
}


// getPrices
	// task: This procedure asks the user to input the number of rows and
	// columns. It then asks the user to input (rows * columns) number of
	// prices. The data is placed in the array.
	// Precondition : none
	// Postcondition : an array filled with numbers and the number of rows
	// and columns used.
void getPrices(double table[int& MAXROWS][int& MAXCOLS], int& numOfRows, int& numOfCols){
	do{
		cout << "Please enter the number of rows. This can be an integer from 1 to " << MAXROWS << endl;
		cin >> numOfRows;
		if(cin.fail() || numOfRows < 1 || numOfRows > MAXROWS){
			cin.clear();
			cin.ignore();
			cout << "Invalid entry" << endl;
		}
	}while(cin.fail() || numOfRows < 1 || numOfRows > MAXROWS);
	
	do{
		cout << "Please enter the number of columns. This can be an integer from 1 to " << MAXCOLS << endl;
		cin >> numOfCols;
		if(cin.fail() || numOfCols < 1 || numOfCols > MAXCOLS){
			cin.clear();
			cin.ignore();
			cout << "Invalid entry" << endl;
		}
	}while(cin.fail() || numOfCols < 1 || numOfCols > MAXCOLS);
	
	
	for (unsigned int y = 0; y < numOfRows; y = y + 1){
		for (unsigned int x = 0; x < numOfCols; x = x + 1){
			do{
				cout << "Please enter the value for:" << endl;
				cout << "Row " << y + 1 << ", column " << x + 1 << ": ";
				cin >> table[y][x];
				if(cin.fail()){
					cin.clear();
					cin.ignore();
					cout << "Invalid entry, enter a number" << endl;
				}
			}while(cin.fail());
		}
	}
}


// printPrices
	// task: This procedure prints the table of prices
	// Precondition : an array of floating point numbers and the number of rows
	// and columns used.
	// Postcondition : none
void printPrices(const double table[MAXROWS] [MAXCOLS], int numOfRows, int numOfCols){
	cout << fixed << showpoint << setprecision(2);
	for (int row = 0; row < numOfRows; row++){
		for (int col = 0; col < numOfCols; col++){
			// Fill in the code to print the table
		}
	}
}