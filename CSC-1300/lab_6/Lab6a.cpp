// This function takes take in the miles travelled
// and the time in hours travelled and will calculate
// the miles per hour.  This value is calculated in a 
// value returning function and printed in main.

/* Heading and info:
	Rus Hoffman, Duncan Stewart, and Eric Waggoner
	
	
	
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
//#include <ctype.h>
#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)
	#include <windows.h>
		inline void delay(unsigned long long ms){
			Sleep( ms );
		}
#else /* presume POSIX */
	#include <unistd.h>
		inline void delay(unsigned long long ms){
			usleep( ms * 1000 );
		}
#endif 
#ifdef WINDOWS
	#include <Windows.h>
	void dynbeep(int freq, long double timeOfBeep){
		Beep(freq, timeOfBeep);
	}
#elif LINUX
	#include <stdio.h>
	void dynbeep(int freq, long double timeOfBeep){
		system("echo -e "\007" >/dev/tty10");
	}
#else
	#include <stdio.h>
	void dynbeep(int freq, long double timeOfBeep){
		std::cout << "\a" << std::flush;
	}
#endif
using namespace std;


/* Useful bits of code:
	#include <iostream>
		system("pause")
		cout << "" << endl;
		cin >> A >> B >> C;
		cin >> VARIABLE;
		cout << setprecision(2) << fixed << showpoint;
		output stuff << minumum decimal points() << cutoff decimal points? << show decimal point always ;
		
		
	Variables:
		const VARTYPE VARNAME - makes it not change
		int - float - double - long double - increasing size	
	
	
	//#include <ctype.h>
	char things:
		//convert char to lowercase
		putchar(tolower(char here));
		//convert to uppercase
		putchar(tolower(char here));

		
		
		check if it is upper or lower case:
		isupper(CHAR);
		islower(CHAR);
		
		
		//check if it is alphabetic
		isalpha(char here);
	
	
	//for loop
	for(int i = 0; i < 20; i = i + 1){
		stuff
	}

	//real loop
	while(bool){
		stuff;
	}
	
	//do while garbage
	do{
		stuff
	}while(BOOL);
	
	
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


//*******************************************************************************
// 
//
// task: This function is given two integer values for miles travelled and
// hours travelled and calculates and returns the miles per hour travelled
//
// Precondition: miles and hours which are both integers
// Postcondition: miles per hour which is a float is returned.
//
//*********************************************************************************
double calculateMPH(double miles, double hours){
	double MPH = miles/hours;
	//Calculate the miles per hour and return to main
	return MPH;
}


int main (){
	double miles;
	double hours;
	double mph;
	//Set output to 2 decimal place notation
	cout << setprecision(2);
	
	//Read in the miles travelled
	cout << "Enter the miles travelled" << endl;
	cout << "Miles : ";
	cin >> miles;
	while(miles <= 0){
		cout << "invalid entry" << endl << "try again" << endl;
		cout << "Miles : ";
		cin >> miles;
		cout << endl;
	}
	//Read in the hours travelled
	cout << "Enter the hours travelled" << endl;
	cout << "Hours : ";
	cin >> hours;
	while(hours <= 0){
		cout << "invalid entry" << endl << "try again" << endl;
		cout << "Hours : ";
		cin >> hours;
		cout << endl;
	}
	
	// Fill in code necessary to call milesPerHour
	mph = calculateMPH(miles, hours);
	
	// Print result
	cout << "Average miles per hour is " << mph << endl;
	system("pause");
	
	
	
	return 0;
}