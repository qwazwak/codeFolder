/*
	By Rus Hoffman
*/
#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)



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
	Directories:
		LPCWSTR FOOBARDIRECTERY = L"c:\testdir";
		CreateDirectory(FOOBARDIRECTERY, NULL);
		CreateDirectory("output", NULL);

	consoleThings:

		SetConsoleTextAttribute(hConsole, k);
				HANDLE  hConsole;
				int k;
			Sets console colours
			colorattribute = foreground + (background * 16)
				colors are:
					0: Black
					1: Navy
					2: Dark green
					3: Teal
					4: Burgundy
					5: Burgundy, but with 10 blue because why not
					6: Olive
					7: Slightly Grey
					8: Grey
					9: BSOD Blue
					10: Lime Green
					11: Cyan
					12: Really Red
					13: Pink
					14: Yellow
					15: Nearly White
	Dialog:
		https://msdn.microsoft.com/en-us/library/windows/desktop/ms645505(v=vs.85).aspx
		MessageBox( 0, "Hello World!", "Greetings", 0 );
		MessageBox( NULL, AcutalBodyMessage, Title, TypeTHingInt );

			int msgboxID = MessageBox(
				NULL,
				"Resource not available\nDo you want to try again?",
				"Account Details",
				MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
			);


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


#include <cstring>
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

/*
Program 4 : Modified Grade Book
	Objective: Learn to use everything we have covered this semester, Learn to create programs across multiple files, Practice creating your own data types
	Concepts: Arrays, Pointers, Structs, Command Line Options, Header Files
	Description
		Doctor Brown maintains a system to monitor and maintain his grades over the course of the semester. His main problems are:
		He does not know, semester to semester, how many tests he will give his students
		He does not know, semester to semester, how many students he will have
		This means he has been forced to be ...creative... in his grading system. Doc maintains a file and every semester it is configured the same way. The first line of the file contains the number of tests the students took that semester. The second line is the first students name, followed on subsequent lines by the test scores on the appropriate number of tests. This information is followed by the next student, etc.
		In addition, Doc will sometimes allow a test to be curved if the class average on that test is under some threshold (usually 70% but he does modify that sometimes) so once you have read in the tests you will need to see if any of the tests are eligible for curving, and if Doc says it is ok, apply the curve to all students in for that test.
		Finally, you will present formatted output showing the students name, their scores (possibly modified by the curve) on each exam followed by their final average in the course showing 2 decimal places.
	Input
		The user will provide the name of a student file and the grade the curve goes to as command line arguments at the time the program is executed.
			If the file does not exist, prompt the user for a new file.
			If the user provided the wrong number of arguments, indicate the issue and exit the program.
			The file will be formatted in the manner outlined in the description.
	Necessary Structs
		Your file should implement an "Array" struct, "Student" struct and a "Students" struct.
			The array struct should contain
				An array of floats
				The number of values in the array
				The maximum number of values in the array
				You array should also contain the information necessary to work with the array. For this array (and only for this array) you can assume you know the size of the array when building it
			The student should contain
				A string for the users name
				An Array that contains the scores this user received on their tests
				You array should also contain the information necessary to work with the Student
			The students should contain
				An array that contains the students in the class
				The current number of elements in the array
				The maximum number of elements in the array
				You array should also contain the information necessary to work with the Student
				Note: You will NOT know the number of students during execution. Because of this, your array should initially be size 2 and be able to expand as necessary to 2 times the size
	Output
		The program should read in the file, storing the information in the necessary structs. It should then present the average on each individual test. If the amount is under the curve value provided by the user, they should be prompted to see if they wish to apply the curve. If they do wish to apply the curve, an amount equal to the curve minus the average score is applied to the individual test scores.
	Sample Output
		C:\CSC1300\Programs> Grades.exe Students.txt 70
		The grades on test 1 average to at 68.3. Do you want to curve? y
		The grades on test 2 average to a 83.3. There is no need to curve.
		The grades on test 3 average to a 58.6. Do you want to curve? n
		The grades on test 4 average to a 71. There is no need to curve.
		The grades on test 5 average to a 69. Do you want to curve? y
		With the curves in place the scores are:

Student Test 1 Test 2 Test 3 Test 4 Test 5 Average
Holly Johnson	83	47	93	45	78	69.74
...



	Provided Files
		Students.txt



Notes and info:


	In addition, Doc will sometimes allow a test to be curved if the class average on that test is under some threshold (usually 70% but he does modify that sometimes) so once you have read in the tests you will need to see if any of the tests are eligible for curving, and if Doc says it is ok, apply the curve to all students in for that test.
	Finally, you will present formatted output showing the students name, their scores (possibly modified by the curve) on each exam followed by their final average in the course showing 2 decimal places.
*/

int main (){
	ifstream readData;
	bool EOFReached = false;
	readData.open("numbers.txt");
	long numHold;
	string tempWord;
	do {
		readData >> tempWord;
		cout << tempWord << endl;
		readData >> numHold;
		cout << numHold << endl;

	} while(!readData.eof());


	cout << "Press enter to close program..." << endl;
	cin.ignore();
	return 0;
}
