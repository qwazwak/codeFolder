/*
	Makes a file with random numbers in it
*/
#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)

#include "EasyBMP.h"
#include <chrono>
#include <random>
/*
	random_device rd;
	 rd.min() << std::endl;
	d::cout << "maximum: " << rd.max() << std::endl;
	d::cout << "entropy: " << rd.entropy() << std::endl;
	d::cout << "a random number: " << rd() << std::endl;
		
*/
#include <cstdint>
#include <cstdlib>
/*
	
	exit(EXIT_FAILURE);
*/
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
/* Uncomment to add delay support
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
*/
/* Uncomment to add beepingn or noise support
#if (defined(WINDOWS) || defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)) && !defined(LINUX)
	#include <Windows.h>
	inline void dynBeep(int freq, long intmax_t timeOfBeep){
		Beep(freq, timeOfBeep);
	}
#elif !(defined(WINDOWS) || defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)) && defined(LINUX)
	#include <stdio.h>
	void dynBeep(int freq, long intmax_t timeOfBeep){
		system("echo -e "\007" >/dev/tty10");
	}
#else
	#include <stdio.h>
	void dynBeep(int freq, long intmax_t timeOfBeep){
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
*/

using namespace std;


int main (){
	ofstream randFileOutput;
	ofstream fibFileOutputB;
	srand(time(NULL));
	uint64_t lines;
	random_device rd;
	uint64_t seed = rand() * chrono::system_clock::now().time_since_epoch().count();
	mt19937 generator (seed);  // mt19937 is a standard mersenne_twister_engine
	int gen;
	BMP AnImage;
	const int XSIZE = 128;
	const int YSIZE = 128;
	RGBApixel Temp;
	/*
	do{
		cout << "Random file maker" << endl;
		cout << "How many lines to generate?" << endl;
		cin >> lines;
		cin.clear();
		cin.ignore();
	}while(lines < 1 || cin.fail());
	bool arrayOfRandomA[lines];
	bool arrayOfRandomB[lines];
	*/
	
	cout << "Minimum: " << rd.min() << endl;
	cout << "Maximum: " << rd.max() << endl;
	cout << "Entropy: " << rd.entropy() << endl;
	
	
	AnImage.SetBitDepth(24);
	AnImage.SetSize(XSIZE,YSIZE);
	//randFileOutput.open("randomNumberA.txt");
	for(int x = 0; x <= XSIZE; x = x + 1){
		for(int y = 0; y <= YSIZE - 1; y = y + 1){
			//randFileOutput << generator() << generator() << generator() << generator() << generator() << generator() << generator() << generator() << endl;
			Temp.Red = x % 255;
			Temp.Green = y % 255;
			Temp.Blue = (x + y) % 255;
			Temp.Alpha = 0;
			AnImage.SetPixel(x, y, Temp);
		}
	}
	AnImage.WriteToFile("random.bmp");
	
	//randFileOutput.close();	
	/*
	randFileOutput.open("randomNumberA.txt");
	for(intmax_t j = 0; j <= lines - 1; j = j + 1){
		randFileOutput << arrayOfRandomA[j] << endl;
	}
	randFileOutput.close();
	*/
	
	
	system("pause");
	return 0;
}