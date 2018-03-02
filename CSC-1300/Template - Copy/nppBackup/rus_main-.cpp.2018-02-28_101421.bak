/* Heading and info:
	Rus Hoffman
	
	In this program you will modify the code you created for program 1 - Tic Tac Toe
	Playing one game of Tic-Tac-Toe is nice, but we usually want to play several games to account for mistakes, errors, or simply bad play
	For this reason, you will enclose your existing code in a user-controlled loop that will continue to play the game until the user decides to terminate the loop
	While the game is running, you will keep track of :
		Number of individual games won
		Number of games won by X
		Number of games won by O
	In addition, if the user makes an invalid menu selection or chooses to play a 1 player game you should present them with an appropriate message and return them to the menu rather than exiting the program.
	After the user terminates the game, the program should return to the menu
	If the user decides to end the game, you are required to report :
		The total number of games played during this "session"
		The total number of games won by X this "session"
		The total number of games won by O this "session"
		The total number of games resulting in a tie this "session"
	In addition, you will report the same information with a "historical" context by reading the statistics from a file you will create called "TTTStats.txt"
	The file will be read in, used and then you will update the values stored in the file when the user exits the program
	
*/
#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)


#include <cstdint>


#include <time.h>
/*
	Has more, all I use is:
	VARIABLE = time(NULL);
*/
#include <cstdlib>
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
	inline void dynBeep(int freq, long double timeOfBeep){
		Beep(freq, timeOfBeep);
	}
#elif !(defined(WINDOWS) || defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)) && defined(LINUX)
	#include <stdio.h>
	void dynBeep(int freq, long double timeOfBeep){
		system("echo -e "\007" >/dev/tty10");
	}
#else
	#include <stdio.h>
	void dynBeep(int freq, long double timeOfBeep){
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
		int - float - double - long double - increasing size	
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
	ofstream fibFileOutput;
	fibFileOutput.open("FibonacciNumbers.txt");
	srand(time(NULL));
	
	//Variables:
	uint64_t userLimit;
	uint64_t fibNumLast = 0;
	uint64_t fibNumCurrent = 1;
	uint64_t swapper;	
	
	do{
	cout << "Fibonacci Number Calculator - Starting with 1, 1" << endl;
	cout << "Enter the number of terms you want to calculate to?" << endl;
	cin >> userLimit;
	}while(userLimit < 1);
	
	uint64_t arrayOfFib[userLimit];
	
	if(userLimit >= 1){
		for(uint64_t i = 1; i <= userLimit; i = i + 1){
			swapper = fibNumCurrent;
			fibNumCurrent = fibNumCurrent + fibNumLast; 
			fibNumLast = swapper;
			arrayOfFib[i - 1] = fibNumLast;
			//fibFileOutput << arrayOfFib[i - 1] << endl;
			cout << fibNumLast << endl;
		}
	}
	else if(userLimit < 0){
		cout << "Error" << endl;
		return 0;
	}
	
	
	//for(uintmax_t j = 1; j <= userLimit; j = j + 1){
	//	fibFileOutput << arrayOfFib[j - 1] << endl;
	//}
	
	
	//fibFileOutput << 
	
	
	system("pause");
	fibFileOutput.close();
	return 0;
}