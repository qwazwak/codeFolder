/*
	Created by Rus Hoffman
	This should my template, and should change
*/
#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)

#include "minesweeperBackend.h"


//#include <algorithm>


//#include "BigBadLib_Full.h"
//#include "BigBadLib_CSC.h"
//#include "EasyBMP.h"
//#include "EasyBMP_Font.h"
//#include "EasyBMP_Geometry.h"
//#include "EasyBMP_SimpleArray.h"

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



//#include <vector>
/*
		Vectors:
		ONE DATA TYPE
		Varibale size

		format:
			vector <DATA TYPE HERE> VARIABLE NAME; // initial zero sized
			vector <DATA TYPE HERE> VARIABLE NAME (INITIALSIZE); // sized with INITIALSIZE size
			vector <DATA TYPE HERE> VARIABLE NAME (INITIALSIZE, OGVARIABLE); // all vals are OGVARIABLE at first
			vector <DATA TYPE HERE> VARIABLE NAME (anothervectorname); // othervectorname is copyed to the new one

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




		random_device rd; // call random numbers with rd()
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


#include <string>
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

using namespace std;

int_fast64_t numDigits(int_fast64_t input){
	int_fast64_t digits = 0;
	if(input < 0){
		digits = 1; // remove this line if '-' counts as a digit
	}
	while (input) {
		input /= 10;
		digits++;
	}
	return digits;
}

bool isOdd(int_fast64_t input){
	return input % 2;
}
bool isEven(int_fast64_t input){
	return !(input % 2);
}


void removePermutation (int_fast64_t* locationsArr, int_fast64_t& sizeLeft, int_fast64_t location){
	for(long i = 0; i < sizeLeft; i++){
		if(i >= location){
			locationsArr[i] = locationsArr[i + 1];
		}
	}
	sizeLeft = sizeLeft - 1;
}


//Creates a dynamic array of size n, initializes it with the correct values and returns the array to the user
int_fast64_t* initPermuation (int_fast64_t n){
	int_fast64_t* arrayPointer = new int_fast64_t[n];
	for (int_fast64_t i = 0; i < n; i++) {
		arrayPointer[i] = i + 1;
	}
	return arrayPointer;
}

//Receives the currect card array and the size of the array, returns the next "card"
//Deck size is passed as a reference variable so it can be modified
int_fast64_t nextPermutation (int_fast64_t* locationsLeft, int_fast64_t& remainingValues){
	int_fast64_t location = rand() % remainingValues;
	int_fast64_t value = locationsLeft[location];
	removePermutation(locationsLeft, remainingValues, location);
	return value;
}



sweepSquare** generateBoard(const int_fast64_t ySize, const int_fast64_t xSize, const int_fast64_t bombCount){
	int_fast64_t tempXLoc;
	int_fast64_t tempYLoc;
	int_fast64_t tempEncodedLoc;

	random_device randomSource;
	int_fast64_t seed = clock();
	if(randomSource.entropy() != 0) {
		seed = randomSource();
	}
	mt19937_64 generator(seed);

	int_fast64_t* locationsArray = initPermuation(xSize * ySize);
	int_fast64_t locationsToGenerate = xSize * ySize;



	sweepSquare** array = new sweepSquare*[ySize];
	for(int_fast64_t i = 0; i < ySize; i++) {
		array[i] = new sweepSquare[xSize];
		for (int_fast64_t j = 0; j < xSize; j++) {
			array[i][j].isKnown = false;
			array[i][j].isBomb = false;
			array[i][j].isEmpty = true;
			array[i][j].numBombNear = 0;
			array[i][j].isFlag = false;
		}
	}








	for (int_fast64_t bNum = 0; bNum < bombCount; bNum++){
		tempEncodedLoc = nextPermutation (locationsArray, locationsToGenerate);
		/* {
			tempYLoc = generator() % ySize;
			tempXLoc = generator() / xSize;
		} while(array[tempYLoc][tempXLoc].isBomb == true);*/
			tempYLoc = tempEncodedLoc % ySize;
			tempXLoc = tempEncodedLoc / xSize;


		array[tempYLoc][tempXLoc].isBomb = true;
		array[tempYLoc][tempXLoc].numBombNear = -1;
		array[tempYLoc][tempXLoc].isEmpty = false;


		//top left
			if((tempYLoc - 1 >= 0) && (tempYLoc - 1 <= ySize - 1)
			&& (tempXLoc - 1 >= 0) && (tempXLoc - 1 <= xSize - 1)
			&& (array[tempYLoc - 1][tempXLoc - 1].isBomb == false)){

					array[tempYLoc - 1][tempXLoc - 1].numBombNear++;
					array[tempYLoc - 1][tempXLoc - 1].isEmpty = false;

			}


		//top center
			if((tempYLoc - 1 >= 0) && (tempYLoc - 1 <= ySize - 1)
			&& (tempXLoc + 0 >= 0) && (tempXLoc + 0 <= xSize - 1)
			&& (array[tempYLoc - 1][tempXLoc + 0].isBomb == false)){

					array[tempYLoc - 1][tempXLoc + 0].numBombNear++;
					array[tempYLoc - 1][tempXLoc + 0].isEmpty = false;

			}


		//top Right
			if((tempYLoc - 1 >= 0) && (tempYLoc - 1 <= ySize - 1)
			&& (tempXLoc + 1 >= 0) && (tempXLoc + 1 <= xSize - 1)
			&& (array[tempYLoc - 1][tempXLoc + 1].isBomb == false)){

					array[tempYLoc - 1][tempXLoc + 1].numBombNear++;
					array[tempYLoc - 1][tempXLoc + 1].isEmpty = false;

			}


		//Left center
			if((tempYLoc + 0 >= 0) && (tempYLoc + 0 <= ySize - 1)
			&& (tempXLoc - 1 >= 0) && (tempXLoc - 1 <= xSize - 1)
			&& (array[tempYLoc + 0][tempXLoc - 1].isBomb == false)){

					array[tempYLoc + 0][tempXLoc - 1].numBombNear++;
					array[tempYLoc + 0][tempXLoc - 1].isEmpty = false;

			}


		//right center
			if((tempYLoc + 0 >= 0) && (tempYLoc + 0 <= ySize - 1)
			&& (tempXLoc + 1 >= 0) && (tempXLoc + 1 <= xSize - 1)
			&& (array[tempYLoc + 0][tempXLoc + 1].isBomb == false)){

					array[tempYLoc + 0][tempXLoc + 1].numBombNear++;
					array[tempYLoc + 0][tempXLoc + 1].isEmpty = false;

			}


		//bottom left
			if((tempYLoc + 1 >= 0) && (tempYLoc + 1 <= ySize - 1)
			&& (tempXLoc - 1 >= 0) && (tempXLoc - 1 <= xSize - 1)
			&& (array[tempYLoc + 1][tempXLoc - 1].isBomb == false)){

					array[tempYLoc + 1][tempXLoc - 1].numBombNear++;
					array[tempYLoc + 1][tempXLoc - 1].isEmpty = false;

			}


		//bottom center
			if((tempYLoc + 1 >= 0) && (tempYLoc + 1 <= ySize - 1)
			&& (tempXLoc + 0 >= 0) && (tempXLoc + 0 <= xSize - 1)
			&& (array[tempYLoc + 1][tempXLoc + 0].isBomb == false)){

					array[tempYLoc + 1][tempXLoc + 0].numBombNear++;
					array[tempYLoc + 1][tempXLoc + 0].isEmpty = false;

			}


		//bottom right
			if((tempYLoc + 1 >= 0) && (tempYLoc + 1 <= ySize - 1)
			&& (tempXLoc + 1 >= 0) && (tempXLoc + 1 <= xSize - 1)
			&& (array[tempYLoc + 1][tempXLoc + 1].isBomb == false)){

					array[tempYLoc + 1][tempXLoc + 1].numBombNear++;
					array[tempYLoc + 1][tempXLoc + 1].isEmpty = false;

			}


	}

	delete[] locationsArray;
	return array;
}



void displayBoard (int_fast64_t yGameSize, int_fast64_t xGameSize, sweepSquare** array/*, int_fast64_t userPickingY, int_fast64_t userPickingX*/){
	int_fast64_t bombCount = 0;
	for (int_fast64_t i = 0; i < yGameSize; i++) {
		for (int_fast64_t j = 0; j < xGameSize; j++) {
			if (array[i][j].isBomb == true) {
				bombCount++;
			}
		}
	}
	int_fast64_t numberWidth = numDigits(yGameSize) + 1;


	const int COLORBLACK = 0;
	const int COLORNAVY = 1;
	const int COLORDARKGREEN = 2;
	const int COLORTEAL = 3;
	const int COLORBURGUNDY = 4;
	const int COLORBURGUNDYBLUE = 5;
	const int COLOROLIVE = 6;
	const int COLORSLIGHTLYGREY = 7;
	const int COLORGREY = 8;
	const int COLORBSODBLUE = 9;
	const int COLORLIMEGREEN = 10;
	const int COLORCYAN = 11;
	const int COLORREALLYRED = 12;
	const int COLORPINK = 13;
	const int COLORYELLOW = 14;
	const int COLORNEARLYWHITE = 15;


	int defaultColor = COLORNEARLYWHITE + (COLORBLACK * 16);
	int unknown = COLORSLIGHTLYGREY;
	int baseBlockColor = COLORSLIGHTLYGREY;
	int bombBlock = COLORREALLYRED + (COLORPINK * 16);
	int flagBlock = COLOROLIVE + (baseBlockColor * 16);
		int block0 = COLORNEARLYWHITE + (baseBlockColor * 16);
		int block1 = COLORBSODBLUE + (baseBlockColor * 16);
		int block2 = COLORDARKGREEN + (baseBlockColor * 16);
		int block3 = COLORREALLYRED + (baseBlockColor * 16);
		int block4 = COLORBSODBLUE + (baseBlockColor * 16);
		int block5 = COLORBURGUNDY + (baseBlockColor * 16);
		int block6 = COLORTEAL + (baseBlockColor * 16);
		int block7 = COLORBLACK + (baseBlockColor * 16);
		int block8 = COLORGREY + (baseBlockColor * 16);
		int blockError = COLORREALLYRED + (baseBlockColor * 16);
	HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, defaultColor);
	const char bomb = 157; // Ø
	const char flag = 80; // P

//	const char arrowL = 60; // <
//	const char arrowR = 62; // >
//	const char arrowT = 118; // v
//	const char arrowB = 94; // ^


	const char cornerDTL = 201; // ╔
	const char cornerDTR = 187; // ╗
	const char cornerDBL = 200; // ╚
	const char cornerDBR = 188; // ╝
//	const char cornerSTL = 218; // ┌
//	const char cornerSBL = 192; // └
//	const char cornerSTR = 191; // ┐
//	const char cornerSBR = 217; // ┘

	const char wallSV = 179; // │
	const char wallSH = 196; // ─
	const char wallDV = 186; // ║
	const char wallDH = 205; // ═


//	const char wallTSD = 194; // ┬
//	const char wallTSL = 180; // ┤
//	const char wallTSR = 195; // ├
//	const char wallTSU = 193; // ┴
//	const char wallTDD = 203; // ╦
	const char wallTDL = 185; // ╣
	const char wallTDR = 204; // ╠
//	const char wallTDU = 202; // ╩

//	const char crossS = 197; // ┼
//	const char crossD = 206; // ╬

	const char solidS = 219; // █
//	const char solidD = 178; // ▓
//	const char solidN = 177; // ▒
	const char solidL = 176; // ░
//	const char solidE = 32; // SPACE

	const char errorSymbol = 245; // §

	int_fast64_t xBoardSize = xGameSize + 2;


	cout << setw(numberWidth) << " " << setw(0);
	cout << cornerDTL;
	for (int_fast64_t x = 0; x < xBoardSize - 2; x++) {
		cout << wallDH;
	}
	cout << cornerDTR << endl;

//yBoardSize
//xBoardSize

	for(int_fast64_t yDisplay = 0; yDisplay < yGameSize; yDisplay++){
		cout << setw(numberWidth) << right << yDisplay + 1 << setw(0) << left;
		cout << wallDV;
		for (int_fast64_t xDisplay = 0; xDisplay < xGameSize; xDisplay++) {
			if (array[yDisplay][xDisplay].isFlag == true) {
				SetConsoleTextAttribute(hConsole, flagBlock);
				cout << flag;
				SetConsoleTextAttribute(hConsole, defaultColor);
			}
			else if (array[yDisplay][xDisplay].isFlag == false) {
				if (array[yDisplay][xDisplay].isKnown == false) {
					SetConsoleTextAttribute(hConsole, unknown);
					cout << solidS;
					SetConsoleTextAttribute(hConsole, defaultColor);
				}
				else if (array[yDisplay][xDisplay].isKnown == true) {
					if (array[yDisplay][xDisplay].isEmpty == true) {
						SetConsoleTextAttribute(hConsole, block0);
						cout << solidL;
						SetConsoleTextAttribute(hConsole, defaultColor);
					}
					else if (array[yDisplay][xDisplay].isBomb == false) {
						switch (array[yDisplay][xDisplay].numBombNear) {
							case 0:
								SetConsoleTextAttribute(hConsole, block0);
									cout << solidS;
								SetConsoleTextAttribute(hConsole, defaultColor);
							break;
							case 1:
								SetConsoleTextAttribute(hConsole, block1);
									cout << "1";
								SetConsoleTextAttribute(hConsole, defaultColor);
							break;
							case 2:
								SetConsoleTextAttribute(hConsole, block2);
									cout << "2";
								SetConsoleTextAttribute(hConsole, defaultColor);
							break;
							case 3:
								SetConsoleTextAttribute(hConsole, block3);
									cout << "3";
								SetConsoleTextAttribute(hConsole, defaultColor);
							break;
							case 4:
								SetConsoleTextAttribute(hConsole, block4);
									cout << "4";
								SetConsoleTextAttribute(hConsole, defaultColor);
							break;
							case 5:
								SetConsoleTextAttribute(hConsole, block5);
									cout << "5";
								SetConsoleTextAttribute(hConsole, defaultColor);
							break;
							case 6:
								SetConsoleTextAttribute(hConsole, block6);
									cout << "6";
								SetConsoleTextAttribute(hConsole, defaultColor);
							break;
							case 7:
								SetConsoleTextAttribute(hConsole, block7);
									cout << "7";
								SetConsoleTextAttribute(hConsole, defaultColor);
							break;
							case 8:
								SetConsoleTextAttribute(hConsole, block8);
									cout << "8";
								SetConsoleTextAttribute(hConsole, defaultColor);
							break;
							default:
								SetConsoleTextAttribute(hConsole, blockError);
									cout << errorSymbol;
								SetConsoleTextAttribute(hConsole, defaultColor);
							break;

						}
					}
					else if(array[yDisplay][xDisplay].isBomb == true) {
						SetConsoleTextAttribute(hConsole, bombBlock);
						cout << bomb;
						SetConsoleTextAttribute(hConsole, defaultColor);
					}
					else{
						cout << errorSymbol;
					}
				}
			}
			else{
				cout << errorSymbol;
			}
		}
		cout << wallDV;
		cout << endl;
	}
	cout << setw(numberWidth) << " " << setw(0);
	cout << cornerDBL;
	for (int_fast64_t x = 0; x < xBoardSize - 2; x++) {
		cout << wallDH;
	}
	cout << cornerDBR << endl;
}

void knownFlood(int_fast64_t yGameSize, int_fast64_t xGameSize, sweepSquare** array, int_fast64_t ySelectionPosition, int_fast64_t xSelectionPosition){
	int_fast64_t yTop = ySelectionPosition - 1;
	int_fast64_t yMid = ySelectionPosition + 0;
	int_fast64_t yBot = ySelectionPosition + 1;
	int_fast64_t xLeft = xSelectionPosition - 1;
	int_fast64_t xMid = xSelectionPosition + 0;
	int_fast64_t xRight = xSelectionPosition + 1;

	if(array[ySelectionPosition][xSelectionPosition].isEmpty == true) {
		//top left
			if((yTop >= 0) && (yTop <= yGameSize - 1)
			&& (xLeft >= 0) && (xLeft <= xGameSize - 1)
			&& (array[yTop][xLeft].isEmpty == true || array[yTop][xLeft].numBombNear >= 1)
			&& (array[yTop][xLeft].isKnown == false)
			&& array[yTop][xLeft].isFlag == false){
					array[yTop][xLeft].isKnown = true;
					if (array[yTop][xLeft].isEmpty == true) {
						knownFlood(yGameSize, xGameSize, array, yTop, xLeft);
					}
			}

		//top center
			if((yTop >= 0) && (yTop <= yGameSize - 1)
			&& (xMid >= 0) && (xMid <= xGameSize - 1)
			&& (array[yTop][xMid].isEmpty == true || array[yTop][xMid].numBombNear >= 1)
			&& (array[yTop][xMid].isKnown == false)
			&& array[yTop][xMid].isFlag == false){
					array[yTop][xMid].isKnown = true;
					if (array[yTop][xMid].isEmpty == true) {
						knownFlood(yGameSize, xGameSize, array, yTop, xMid);
					}
			}

		//top Right
			if((yTop >= 0) && (yTop <= yGameSize - 1)
			&& (xRight >= 0) && (xRight <= xGameSize - 1)
			&& (array[yTop][xRight].isEmpty == true || array[yTop][xRight].numBombNear >= 1)
			&& (array[yTop][xRight].isKnown == false)
			&& array[yTop][xRight].isFlag == false){
					array[yTop][xRight].isKnown = true;
					if (array[yTop][xRight].isEmpty == true) {
						knownFlood(yGameSize, xGameSize, array, yTop, xRight);
					}
			}

		//Left center
			if((yMid >= 0) && (yMid <= yGameSize - 1)
			&& (xLeft >= 0) && (xLeft <= xGameSize - 1)
			&& (array[yMid][xLeft].isEmpty == true || array[yMid][xLeft].numBombNear >= 1)
			&& (array[yMid][xLeft].isKnown == false)
			&& array[yMid][xLeft].isFlag == false){
					array[yMid][xLeft].isKnown = true;
					if (array[yMid][xLeft].isEmpty == true) {
						knownFlood(yGameSize, xGameSize, array, yMid, xLeft);
					}
			}

		//right center
			if((yMid >= 0) && (yMid <= yGameSize - 1)
			&& (xRight >= 0) && (xRight <= xGameSize - 1)
			&& (array[yMid][xRight].isEmpty == true || array[yMid][xRight].numBombNear >= 1)
			&& (array[yMid][xRight].isKnown == false)
			&& array[yMid][xRight].isFlag == false){
					array[yMid][xRight].isKnown = true;
					if (array[yMid][xRight].isEmpty == true) {
						knownFlood(yGameSize, xGameSize, array, yMid, xRight);
					}
			}

		//bottom left
			if((yBot >= 0) && (yBot <= yGameSize - 1)
			&& (xLeft >= 0) && (xLeft <= xGameSize - 1)
			&& (array[yBot][xLeft].isEmpty == true || array[yBot][xLeft].numBombNear >= 1)
			&& (array[yBot][xLeft].isKnown == false)
			&& array[yBot][xLeft].isFlag == false){
					array[yBot][xLeft].isKnown = true;
					if (array[yBot][xLeft].isEmpty == true) {
						knownFlood(yGameSize, xGameSize, array, yBot, xLeft);
					}
			}

		//bottom center
			if((yBot >= 0) && (yBot <= yGameSize - 1)
			&& (xMid >= 0) && (xMid <= xGameSize - 1)
			&& (array[yBot][xMid].isEmpty == true || array[yBot][xMid].numBombNear >= 1)
			&& (array[yBot][xMid].isKnown == false)
			&& array[yBot][xMid].isFlag == false){
					array[yBot][xMid].isKnown = true;
					if (array[yBot][xMid].isEmpty == true) {
						knownFlood(yGameSize, xGameSize, array, yBot, xMid);
					}
			}

		//bottom right
			if((yBot >= 0) && (yBot <= yGameSize - 1)
			&& (xRight >= 0) && (xRight <= xGameSize - 1)
			&& (array[yBot][xRight].isEmpty == true || array[yBot][xRight].numBombNear >= 1)
			&& (array[yBot][xRight].isKnown == false)
			&& array[yBot][xRight].isFlag == false){
					array[yBot][xRight].isKnown = true;
					if (array[yBot][xRight].isEmpty == true) {
						knownFlood(yGameSize, xGameSize, array, yBot, xRight);
					}
			}

	}

	cout << endl << endl;
}
