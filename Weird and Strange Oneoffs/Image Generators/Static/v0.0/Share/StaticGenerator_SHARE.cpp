/*
	By Rus Hoffman
*/
#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)


#include "EasyBMP.h"
#include <random>
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
*/


#include <cstdlib>
/*
	system("pause")
	system("CLS")
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


#include <time.h>
/*
	Has more, all I use is:
	VARIABLE = time(NULL);
*/


#include <iostream>
#include <iomanip>
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
#include <string.h>

using namespace std;


int main (){
	//Random Things
		random_device trueRandom;
		//mt19937_64 generator();
		uint_fast16_t seedTime = clock();
		uint_fast16_t seedRandom = trueRandom();
		uint_fast16_t seedUsed;
	//Image Things:
		BMP AnImage;
		AnImage.SetBitDepth(16);
		int_fast32_t resolution;
		RGBApixel Temp;

	if(trueRandom.entropy() == 0){
		seedUsed = seedTime;
		cout << "Hardware does not support nondeterministic seeds" << endl;
		cout << "Using current time as seed: " << seedUsed << endl;
	}
	else{
		seedUsed = seedRandom * seedTime;
		cout << "Using mersenne twister engine seeded with nondeterministic seed" << endl;
		cout << "  Entropy: " << trueRandom.entropy() << endl;
		cout << "  Minimum: " << trueRandom.min() << endl;
		cout << "  Maximum: " << trueRandom.max() << endl;
		cout << "  Random seed combined with time: " << seedUsed << endl;
	}
	mt19937 randomGen (seedUsed);
	srand(seedUsed);
	cout << "setup done" << endl;


	do{
		cout << "Enter the square resolution" << endl;
		cout << "IE: For 64x64 enter 64" << endl;
		cin >> resolution;
		cin.clear();
		cin.ignore();
	}while(cin.fail() || resolution < 1);
	AnImage.SetSize(resolution,resolution);

	Temp.Alpha = 255;
	for (int_fast32_t y = 0; y < resolution; y++){
		for (int_fast32_t x = 0; x < resolution; x++){
			Temp.Red = randomGen();
			Temp.Green = randomGen();
			Temp.Blue = randomGen();
			AnImage.SetPixel(y,x,Temp);
		}
	}
	AnImage.WriteToFile("static.bmp");
	return 0;
}
