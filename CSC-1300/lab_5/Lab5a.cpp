// This program illustrates the use of a sentinel in a while loop.
// The user is asked for monthly rainfall totals until a sentinel
// value of -1 is entered. Then the total rainfall is displayed.
// Rus Hoffman and Eric Waggoner
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#ifdef WINDOWS
#include <Windows.h>
void dynBeep(int freq, int timeOfBeep){
	beep(freq, timeOfBeep);
}
#elif LINUX
#include <stdio.h>
void dynBeep(int freq, int timeOfBeep){
	system("echo -e "\007" >/dev/tty10");
}
#else
void dynBeep(int freq, int timeOfBeep){
	std::cout << "\a";
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
	
	
	
	for(int i = 0; i < 20; i = i + 1){
		stuff
	}
	
	do{
		stuff
	}while(BOOL);
*/

int clearScreen(int lines){
	for(int i = 0; i < lines; i = i + 1){
		cout << endl;
	}
	return 0;
}



int main()
{
	// Fill in the code to define and initialize to 1 the variable month
	long double userInput;
	long double total = 0;
	int monthReal = 1;
	int monthDisplay = monthReal;
	string monthWord;
	bool continueInput = false;
	
	
	
	
	const int LINESFORCLEARING = 80;

	//cout << "Enter the total rainfall for month " << month << endl;
	//cout << "Enter -1 when you are finished" << endl;
	// Fill in the code to read in the value for rain
	// Fill in the code to start a while loop that iterates while rain does not equal -1
	// Fill in the code to update total by adding it to rain
	// Fill in the code to increment month by one
	
	do{
		dynBeep(440, 500);
		switch(monthDisplay){
			case(1):
				monthWord= "January";
			break;
			case(2):
				monthWord= "February";
			break;
			case(3):
				monthWord= "March";
			break;
			case(4):
				monthWord= "April";
			break;
			case(5):
				monthWord= "May";
			break;
			case(6):
				monthWord= "June";
			break;
			case(7):
				monthWord= "July";
			break;
			case(8):
				monthWord= "August";
			break;
			case(9):
				monthWord= "September";
			break;
			case(10):
				monthWord= "October";
			break;
			case(11):
				monthWord= "November";
			break;
			case(12):
				monthWord= "December";
			break;
			default:
				monthWord= "error";
			break;
		}
		cout << "Enter the total rainfall for " << monthWord << endl << "If finished, enter '-1'" << endl;
		cin >> userInput;
		clearScreen(LINESFORCLEARING);
		if(userInput == -1){
			continueInput = false;
		}
		else{
			continueInput = true;
			total = total + userInput;
			monthReal = monthReal + 1;
			
			monthDisplay = monthDisplay % 12;
			if(monthDisplay == 0){
				monthDisplay = 1;
			}
			
			
			/*
			if(monthDisplay < 12 && monthDisplay >=1){
				monthDisplay = monthDisplay + 1;
				
			}else if(monthDisplay == 12){
				monthDisplay = 1;
			}
			else if(monthDisplay > 12){
				monthDisplay = monthDisplay % 12;
			}
			else if(monthDisplay < 1){
				cout << "an error has occured, ending program" << endl;
				return 0;
			}*/
		}
	}while(continueInput !=	false);
	
	cout << total << endl;
	
	
	if (monthReal == 1){
		cout << "No data has been entered" << endl;
	}else
		cout << "The total rainfall for the last " << monthReal-1 << " months is "<< total << " inches" << endl;
		cout << "The average rainfall for the last " << monthReal-1 << " months is "<< total/monthReal << " inches per month" << endl;
	return 0;
}

/* Copy me month name gen
	switch(inputNumber){
		case(1):
			monthWord= "January";
		break;
		case(2):
			monthWord= "February";
		break;
		case(3):
			monthWord= "March";
		break;
		case(4):
			monthWord= "April";
		break;
		case(5):
			monthWord= "May";
		break;
		case(6):
			monthWord= "June";
		break;
		case(7):
			monthWord= "July";
		break;
		case(8):
			monthWord= "August";
		break;
		case(9):
			monthWord= "September";
		break;
		case(10):
			monthWord= "October";
		break;
		case(11):
			monthWord= "November";
		break;
		case(12):
			monthWord= "December";
		break;
		default:
			monthWord= "error";
		break;
	}
*/





