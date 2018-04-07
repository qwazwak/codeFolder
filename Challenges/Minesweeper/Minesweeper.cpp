/*
	By Rus Hoffman
*/
#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)

#include "minesweeperBackend.h"


//#include "BigBadLib_Full.h"
//#include "BigBadLib_CSC.h"
//#include "EasyBMP.h"
//#include "EasyBMP_Font.h"
//#include "EasyBMP_Geometry.h"
//#include "EasyBMP_SimpleArray.h"

//#include <quadmath.h>
//Needed for more than just float128


//#include <boost/multiprecision/cpp_int.hpp>
/*
	// Fixed precision unsigned inegers:
		boost::multiprecision::cpp_int::uint128_t
		boost::multiprecision::cpp_int::uint256_t
		boost::multiprecision::cpp_int::uint512_t
		boost::multiprecision::cpp_int::uint1024_t
	// Fixed precision signed inegers:
		boost::multiprecision::cpp_int::int128_t
		boost::multiprecision::cpp_int::int256_t
		boost::multiprecision::cpp_int::int512_t
		boost::multiprecision::cpp_int::int1024_t
*/


//#include <boost\multiprecision\float128.hpp>
/*
	boost::multiprecision::float128 variableName;
*/


//#include <vector>
/*
		Vectors:
		ONE DATA TYPE
		Varibale size

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


//#include <random>
//All of this library is c++11 and requires compiler support
/*
	C++11
	random_device FOOBARNAMEME;
	cout << "Minumum: " << FOOBARNAMEME.min() << endl;
	cout << "Maximum: " << FOOBARNAMEME.max() << endl;
	cout << "Entropy: " << FOOBARNAMEME.entropy() << endl;
	This is real random. Only use it to seed a pseduo random generator - SEE cstdlib and rand()




		random_device rd; //call random numbers with rd()
		int seed = rd() * clock()
		mt19937_64 generator(seed);  // mt19937 is a standard mersenne_twister_engine
		srand(seed);
		Call randoms with generator() or rand()

		cout << "Seed: " << seed << endl;
		cout << "Minimum: " << rd.min() << endl;
		cout << "Maximum: " << rd.max() << endl;
		cout << "Entropy: " << rd.entropy() << endl;
		cout << "setup done" << endl;
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
			remainder(numerator, denominator);
				REQUIRES C++11
				Gives floating point remainder
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


/*
	Variables:
		static means it doesnt die

	cin problems can be found by cin.fail()
	fixes cin problems:
		cin.clear();
		cin.ignore();

	(i or o)fstream FILEIDENT;
	FILEIDENT.open("FILENAME.txt");
	FILEIDENT << VARIABLE << endl;
	FILEIDENT.close();

	#pragma omp parallel for reduction(+:VariableThatCallCanAccess)
	for(long long int i = min; i <= max; i = i + 1){

	}

	vector <DATA TYPE HERE> VARIABLE NAME (INITIALSIZE, OGVARIABLE);
*/
using namespace std;


int main (int argc, char* argv[]){

//		const char errorSymbol = 245; // §

//		const char bomb = 157; // Ø
//		const char flag = 80; // P

//		const char arrowL = 60; // <
//		const char arrowR = 62; // >
//		const char arrowT = 118; // v
//		const char arrowB = 94; // ^


//		const char cornerDTL = 201; // ╔
//		const char cornerDBL = 200; // ╚
//		const char cornerDTR = 189; // ╗
//		const char cornerDBR = 188; // ╝
//		const char cornerSTL = 218; // ┌
//		const char cornerSBL = 192; // └
//		const char cornerSTR = 191; // ┐
//		const char cornerSBR = 217; // ┘

//		const char wallSV = 179; // │
//		const char wallSH = 196; // ─
//		const char wallDV = 186; // ║
//		const char wallDH = 205; // ═


//		const char wallTSD = 194; // ┬
//		const char wallTSL = 180; // ┤
//		const char wallTSR = 195; // ├
//		const char wallTSU = 193; // ┴
//		const char wallTDD = 203; // ╦
//		const char wallTDL = 189; // ╣
//		const char wallTDR = 204; // ╠
//		const char wallTDU = 202; // ╩

//		const char crossS = 197; // ┼
//		const char crossD = 206; // ╬

//		const char solidS = 219; // █
//		const char solidD = 178; // ▓
//		const char solidN = 177; // ▒
//		const char solidL = 176; // ░
//		const char solidE = 32; // SPACE

	string fillme;

	int_fast64_t userWantBoardSizeX;
	int_fast64_t userWantBoardSizeY;
	int_fast64_t userWantBombCount;
	sweepSquare** dataBoard = NULL;

	int_fast64_t userMoveX;
	int_fast64_t userMoveY;
	bool hasEnteredX = false;
	bool hasEnteredY = false;
	int_fast64_t userMoveType;

	bool hasLost = false;

	//cout << "█▓▒░┏╋┓┣┫┃┗┳┻━┛◦●◌○!→←↑↓P" << endl;

	do{
		cout << "Enter the width of the board: " << endl;
		cout << "" << endl;
		cin >> userWantBoardSizeX;
		cin.clear();
		cin.ignore();
	}while(cin.fail() || userWantBoardSizeX < 1);
	do{
		cout << "Enter the height of the board: " << endl;
		cout << "" << endl;
		cin >> userWantBoardSizeY;
		cin.clear();
		cin.ignore();
	}while(cin.fail() || userWantBoardSizeY < 1);
	if (userWantBoardSizeX < userWantBoardSizeY) {
		int_fast64_t swap = userWantBoardSizeX;
		cout << "The height and width have been swapped" << endl;
		userWantBoardSizeX = userWantBoardSizeY;
		userWantBoardSizeY = swap;
	}
	do{
		cout << "Enter the number of bombs on the board: " << endl;
		cout << "" << endl;
		cin >> userWantBombCount;
		cin.clear();
		cin.ignore();
	}while(cin.fail() || userWantBombCount < 1 || userWantBombCount >= (userWantBoardSizeY * userWantBoardSizeX));


	dataBoard = generateBoard(userWantBoardSizeY, userWantBoardSizeX, userWantBombCount);

	do {
		do{
			hasEnteredX = false;
			hasEnteredY = false;
			do{
				displayBoard(userWantBoardSizeY, userWantBoardSizeX, dataBoard);
				cout << "Selected location is ( <entering>, <not-entered>)" << endl;
				cout << "Enter the 'X' location: " << endl;
				cin >> userMoveX;
			}while(userMoveX < 1 || userMoveX > userWantBoardSizeX);
			hasEnteredX = true;
			do{
				displayBoard(userWantBoardSizeY, userWantBoardSizeX, dataBoard);
				cout << "Selected location is ( " << userMoveX << ", <entering>)" << endl;
				cout << "Enter the 'Y' location: " << endl;
				cin >> userMoveY;
			}while(userMoveY < 1 || userMoveY > userWantBoardSizeY);
			hasEnteredY = true;
			do{
				displayBoard(userWantBoardSizeY, userWantBoardSizeX, dataBoard);
				cout << "Selected location is (" << userMoveX << ", " << userMoveY << ")" << endl;
				cout << "Select your move:" << endl;
				cout << "   1: Click Square" << endl;
				cout << "   2. Flag Square NOT YET HAR" << endl;
				cout << "   0. Pick a different location" << endl;
				cin >> userMoveType;

				userMoveY--;
				userMoveX--;
			}while(userMoveType < 0 || userMoveType > 1);
		}while(userMoveType == 0 || ((userMoveType == 1 || userMoveType == 2) && dataBoard[userMoveY][userMoveX].isKnown == true));
		if(dataBoard[userMoveY][userMoveX].isBomb == true && userMoveType == 1) {
			hasLost = true;
			break;
		}
		if (userMoveType == 1 && dataBoard[userMoveY][userMoveX].isKnown == false && dataBoard[userMoveY][userMoveX].isBomb == false) {
			dataBoard[userMoveY][userMoveX].isKnown = true;
			if (dataBoard[userMoveY][userMoveX].isEmpty == true) {
				knownFlood(userWantBoardSizeY, userWantBoardSizeX, dataBoard, userMoveY, userMoveX);
			}
		}

	} while(hasLost == false);





	for(int_fast64_t i = 0; i < userWantBoardSizeY; ++i){
		delete[] dataBoard[i];
	}
	delete [] dataBoard;
	cout << "The end" << endl;
	return 0;
}
