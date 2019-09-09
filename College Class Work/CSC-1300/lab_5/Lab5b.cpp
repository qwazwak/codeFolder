/* Heading and info:
	Rus Hoffman and Eric Waggoner	
	
	
*/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctype.h>
#include <stdio.h>
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
//#include <stdio.h>
void dynbeep(int freq, long double timeOfBeep){
	system("echo -e "\007" >/dev/tty10");
}
#else
//#include <stdio.h>
void dynbeep(int freq, long double timeOfBeep){
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

int main(){
	// Fill in the code to define an integer variable called number,
	// a floating point variable called cost,
	// and a character variable called beverage
	bool validBeverage;
	int number;
	long double cost = 0;
	char beverage;
	char junk;
	const float COFFEE_PRICE = 1.00;
	const float TEA_PRICE = 0.75;
	const float HOTCHOCOLATE_PRICE = 1.25;
	const float CAPPUCCINO_PRICE = 2.50;
	
	
	
	
	
	cout << fixed << showpoint << setprecision(2);
	
	
	
	
	do{
		cout << endl << endl;
		cout << "Hot Beverage Menu" << endl << endl;
		
		
		cout << "A: Coffee $1.00" << endl; 
		cout << "B: Tea $ .75" << endl; 
		cout << "C: Hot Chocolate $1.25" << endl;
		cout << "D: Cappuccino $2.50" << endl << endl << endl;
		
		
		cout << "Enter the beverage A, B, C, or D you desire" << endl;
		cout << "Enter E to exit the program" << endl << endl;
				
		// Read in beverage choice as char and convert to uppercase
		cin.get(beverage);
		if(beverage == 'e'){
			beverage = 'E';
		}
		
		switch(beverage){
			case 'a':
			case 'A':
				validBeverage = true;
			break;
			case 'b':
			case 'B':
				validBeverage = true;
			break;
			case 'c':
			case 'C':
				validBeverage = true;
			break;
			case 'd':
			case 'D':
				validBeverage = true;
			break;
			default:
				validBeverage = false;
			break;
		}
		if (validBeverage == true){
			cout << "How many cups would you like?" << endl;
			cin >> number;
			cin.get(junk);
		}
		switch(beverage){
			case 'a':
			case 'A':
				cost = (number * COFFEE_PRICE);
				cout << "The total cost is $ " << cost << endl;
			break;
			case 'b':
			case 'B':
				cost = (number * TEA_PRICE);
				cout << "The total cost is $ " << cost << endl;
			break;
			case 'c':
			case 'C':
				cost = (number * HOTCHOCOLATE_PRICE);
				cout << "The total cost is $ " << cost << endl;
			break;
			case 'd':
			case 'D':
				cost = (number * CAPPUCCINO_PRICE);
				cout << "The total cost is $ " << cost << endl;
			break;
			case 'e':
			case 'E':
				cout << "Please come again" << endl;
			break;
			default:
				cout << "Invalid selection" << endl;
				cout << "Try again please" << endl;
			break;
		}
	}while(beverage != 'E');
	return 0;
}