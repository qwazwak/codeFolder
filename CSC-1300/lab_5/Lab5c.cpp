/* Heading and info:
	Rus Hoffman and Eric Waggoner
	This program has the user input a number n,
	then finds the mean of the first n positive integers

	
	
*/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctype.h>
#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)
	#include <windows.h>
		inline void delay(unsigned long long ms){
			Sleep(ms);
		}
#else /* presume POSIX */
	#include <unistd.h>
		inline void delay(unsigned long long ms){
			usleep(ms * 1000);
		}
#endif 


#ifdef WINDOWS
	#include <windows.h>
	inline void dynBeep(unsigned long int freq, unsigned long int timeOfBeep){
		Beep(freq, timeOfBeep);
	}
#elseif LINUX
	#include <stdio.h>
	inline void dynBeep(int freq, long double timeOfBeep){
		system("echo -e "\007" >/dev/tty10");
	}
#else
	#include <stdio.h>
	inline void dynBeep(int freq, long double timeOfBeep){
		std::cout << "\a" << std::flush;
	}
#endif
using namespace std;


/* Useful bits of code:
	cout << "" << endl;
	cin >> A >> B >> C;
	cin >> VARIABLE; number only
	cout << setprecision(2) << fixed << showpoint;
		output stuff << decimal points << cutoff decimal points? << show decimal point always ;
	Variables:
		const VARTYPE VARNAME - makes it not change
		int - float - double - long double - increasing size
	cout << setprecision(3) << fixed << showpoint;
	
	
	
	
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
	

	//This program has the user input a number n,
	//then finds the mean of the first n positive integers
	signed long long int userDefinedN; //in the original code, this was value. some number N
	unsigned long long int firstNSum;
	long double average;
	char method;
	bool methodIsValid;
	int junk;
	
	cout << "This program calculates the summation and average of the first N positive integers." << endl;
	cout << "There are two ways to do this..";
	cout << "enter either A or B to select that method" << endl << endl;
	cout << "A: Using a for loop (bad)" << endl;
	cout << "B: Using the equation N(N-1)/2 (good)" << endl;
	cin.get(method);

	cout << "Enter a positive integer" << endl;
	cin >> userDefinedN;
	while(userDefinedN <= 0){
		cout << "Input is invalid" << endl <<"Try again" << endl << endl << endl;
		cout << "Enter a positive integer" << endl;
		cin >> userDefinedN;
	}
	
	if(method == 'A' || method == 'a'){
		for (unsigned long long int i = 1; i <= userDefinedN; i++){
			firstNSum = firstNSum + i;
			if(i % static_cast<int>(floor(static_cast<float>(userDefinedN)/20)) == 0){
				Beep(((static_cast<float>(i) / static_cast<float>(userDefinedN))*1000), 100);
				cout << i << endl << endl;
			}
		}
		average = static_cast<float>(firstNSum) / static_cast<float>(userDefinedN); // note the use of the typecast operator here 
		cout << "The average of the first " << userDefinedN << " positive integers is " << average << endl;	
		cout << "press any key to end program" << endl;
		cin >> junk;
	}
	else if(method == 'B' || method == 'b'){
	
		firstNSum = ((pow(static_cast<float>(userDefinedN), 2) + static_cast<float>(userDefinedN)) / static_cast<float>(2));
		average = (((pow(static_cast<float>(userDefinedN), 2) + static_cast<float>(userDefinedN)) / static_cast<float>(2)) / userDefinedN);
		cout << "The sum of the first " << userDefinedN << " numbers is: " << firstNSum << endl;
		cout << "The average value of the first " << userDefinedN << " numbers is: " << average << endl;
		cout << "press any key to end program" << endl;
		cin >> junk;
	}
	else{
		cout << "an invalid input has been entered or an error has occured" << endl;
		cout << "program will end in 5.0 seconds" << endl;
		delay(500);
		cout << "program will end in 4.5 seconds" << endl;
		delay(500);
		cout << "program will end in 4.0 seconds" << endl;
		delay(500);
		cout << "program will end in 3.5 seconds" << endl;
		delay(500);
		cout << "program will end in 3.0 seconds" << endl;
		delay(500);
		cout << "program will end in 2.5 seconds" << endl;
		delay(500);
		cout << "program will end in 2.0 seconds" << endl;
		delay(500);
		cout << "program will end in 1.5 seconds" << endl;
		delay(500);
		cout << "program will end in 1.0 seconds" << endl;
		delay(500);
		cout << "program will end in 0.5 seconds" << endl;
		delay(500);
		cout << "program ending" << endl;
	}
	return 0;
}