/* Heading and info:
	Rus Hoffman
	
	
	
*/
#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)
#include <iostream>
/*
	system("pause")
		Enter any key to continue..
	cout << "" << endl;
	
	
	cin >> VARNAME;
		Bring in numbers
	cin.get(VARNAME);
		Single Char
	getline(cin, VARNAME);
		get a line
*/
#include <fstream>
#include <string>
#include <iomanip>
/*
	Manipulates input and output
	cout << setprecision(2) << fixed << showpoint;
	output stuff << minumum decimal points() << cutoff decimal points? << show decimal point always ;
*/
#include <cmath>
/*
	adds math functions
	
	
	trig- sin(),cos, tan, ect
	pow
	sqrt
	cbrt
	
	
*/
//#include <ctype.h>
/*
	char things:
		//convert char to lowercase: 		putchar(tolower(char here));
		//convert to uppercase: putchar(tolower(char here));
	check if it is upper or lower case:
	isupper(CHAR);
	islower(CHAR);
	
	
	//check if it is alphabetic
	isalpha(char here);
*/
#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)
	#include <windows.h>
	inline void delay(unsigned long long ms){
		Sleep(ms);
	}
#else /* presume POSIX */
	#include <unistd.h>
	inline void delay(unsigned long long ms){
		usleep( ms * 1000 );
	}
#endif
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
using namespace std;


/* Useful bits of code:

		
		
	Variables:
		const VARTYPE VARNAME - makes it not change
		int - float - double - long double - increasing size	
	
	
	
	
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
int clearScreen(int lines){
	for(int i = 0; i < lines; i = i + 1){
		cout << endl;
	}
	return 0;
}
bool isEven(int input){
	if(input % 2 == 0){
		return true;
	}
	else{
		return false;
	}
}

int main (){
	
		system("pause");

	
	for(int i = 2; i <= 2500; i = i + 50 ){
		dynBeep(i, 200);
		cout << i << endl;
		delay(220);
	}

	
		system("pause");

	
	return 0;
}