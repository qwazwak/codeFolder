/*
	Makes a file with random numbers in it
*/
#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)

//#include "EasyBMP.h"
//#include "EasyBMP_Font.h"
//#include "EasyBMP_Geometry.h"
//#include "EasyBMP_SimpleArray.h"
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
	for(int i = 0; i < limit; i = i + 1){
		stuff
	}

	//real loop
	while(bool){
		stuff;
	}
	
	//do while template
	do{
		
	}while(bool);
	
	
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

int main (){
	srand(time(NULL));
	random_device rd;
	uint64_t seed = rand() * chrono::system_clock::now().time_since_epoch().count();
	mt19937 generator(seed);  // mt19937 is a standard mersenne_twister_engine
	int_least64_t numOfFiles;
	int_least64_t numOfCol;
	int_least64_t numOfLines;
	int_least64_t rowsTillUpdate;
	ofstream randomFilesOutput;
	
	
	cout << "Minimum: " << rd.min() << endl;
	cout << "Maximum: " << rd.max() << endl;
	cout << "Entropy: " << rd.entropy() << endl;
	cout << "setup done" << endl;
	
	
	
	cout << "|    Random Files Generator    |" << endl;
	cout << "|                              |" << endl;
	cout << "|                              |" << endl;
	cout << "|    Enter the number of       |" << endl;
	cout << "|       files to make:         |" << endl;
	cout << "|       ";
	cin >> numOfFiles;
	cin.clear();
	cin.ignore();
	while(cin.fail() || numOfFiles < 1){
		cout << "|    Random Files Generator    |" << endl;
		cout << "|                              |" << endl;
		cout << "|   Invalid input, Try again   |" << endl;
		cout << "|    Enter the number of       |" << endl;
		cout << "|       files to make:         |" << endl;
		cout << "|       ";
		cin >> numOfFiles;
		cin.clear();
		cin.ignore();
	}
	
	cout << "|    Random Files Generator    |" << endl;
	cout << "|                              |" << endl;
	cout << "|                              |" << endl;
	cout << "|    Enter the number of       |" << endl;
	cout << "|       coloumns per row:      |" << endl;
	cout << "|       ";
	cin >> numOfCol;
	cin.clear();
	cin.ignore();
	while(cin.fail() || numOfCol < 1){
		cout << "|    Random Files Generator    |" << endl;
		cout << "|                              |" << endl;
		cout << "|   Invalid input, Try again   |" << endl;
		cout << "|    Enter the number of       |" << endl;
		cout << "|       coloumns per row:      |" << endl;
		cout << "|       ";
		cin >> numOfCol;
		cin.clear();
		cin.ignore();
	}
	
	
	cout << "|    Random Files Generator    |" << endl;
	cout << "|                              |" << endl;
	cout << "|                              |" << endl;
	cout << "|    Enter the number of       |" << endl;
	cout << "|       Rows per file:         |" << endl;
	cout << "|       ";
	cin >> numOfLines;
	cin.clear();
	cin.ignore();
	while(cin.fail() || numOfLines < 1){
		cout << "|    Random Files Generator    |" << endl;
		cout << "|                              |" << endl;
		cout << "|   Invalid input, Try again   |" << endl;
		cout << "|    Enter the number of       |" << endl;
		cout << "|       Rows per file:         |" << endl;
		cout << "|       " << endl;
		cin >> numOfLines;
		cin.clear();
		cin.ignore();
	}
	
	cout << "|    Random Files Generator    |" << endl;
	cout << "|                              |" << endl;
	cout << "|                              |" << endl;
	cout << "|   After how many rows should |" << endl;
	cout << "|    progress be displayed?    |" << endl;
	cout << "|       ";
	cin >> rowsTillUpdate;
	cin.clear();
	cin.ignore();
	while(cin.fail() || rowsTillUpdate < 1 || rowsTillUpdate > numOfLines){
		cout << "|    Random Files Generator    |" << endl;
		cout << "|                              |" << endl;
		cout << "|   Invalid input, Try again   |" << endl;
		cout << "|   After how many rows should |" << endl;
		cout << "|    progress be displayed?    |" << endl;
		cout << "|       ";
		cin >> rowsTillUpdate;
		cin.clear();
		cin.ignore();
	}
	
	uint_least64_t [numOfLines][numOfCol];
	
	
	
	
	
	
	for(int_least64_t currentFileNumber = 1; currentFileNumber <= numOfFiles; currentFileNumber = currentFileNumber + 1){
		randomFilesOutput.open("RandomFiles-Part" + to_string(currentFileNumber) + "of" + to_string(numOfFiles) + ".txt");
		for(int_least64_t currentLine = 1; currentLine <= numOfLines; currentLine = currentLine + 1){
			randomFilesOutput << "L" << currentLine << ". " << endl;									
			
			for(int_least64_t currentCol = 1; currentCol <= numOfCol; currentCol = currentCol + 1){
				currentRow = currentRow + to_string(generator()) + ", ";
				//randomFilesOutput << generator() << ", ";
			}
			randomFilesOutput << currentRow << endl;
			
			if(currentLine % rowsTillUpdate == 0){
				cout << endl << endl << endl << endl << endl << endl;
				cout << "|    Random Files Generator    |" << endl;
				cout << "|                              |" << endl;
				cout << "| File Progress           - " << setprecision (4) << fixed << 100.0 * (static_cast<long double>(currentFileNumber) / static_cast<long double>(numOfFiles)) << endl << scientific;
				cout << "|" << endl;;
				cout << "| Row Progress           - " << setprecision (4) << fixed << 100.0 * (static_cast<long double>(currentLine) / static_cast<long double>(numOfLines)) << endl << scientific;
				cout << "|                              |" << endl;
			}
			
			
		}
		
		
		randomFilesOutput.close();
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	cout << endl << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl << endl;
	cout << "|    Random Files Generator    |" << endl;
	cout << "|                              |" << endl;
	cout << "| Number of files    - " << numOfFiles << endl;
	cout << "| Number of rows     - " << numOfLines << endl;
	cout << "| Number of coloumns - " << numOfCol << endl;
	
	
	system("pause");
	return 0;
}