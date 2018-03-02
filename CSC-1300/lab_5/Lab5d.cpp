/* Heading and info:
	Rus Hoffman and Eric Waggoner	
*/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctype.h>
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


int main (){
	
	int userDefinedTimeTaken;
	long double userDefinedBridgeHight;
	//long long int userDefinedInterval;
	const float GRAVITYACCELCONSTANT = 9.80665;
	
	
	cout << "Input the integer number of seconds that the watermelon falls" << endl;
	cin >> userDefinedTimeTaken;
	while(userDefinedTimeTaken <= 0){
		cout << "That value is invalid, please enter another integer number greater than 0" << endl;
		cin >> userDefinedTimeTaken;
	}
	cout << "Input the height of the bridge above the water" << endl;
	cin >> userDefinedBridgeHight;
	while(userDefinedBridgeHight <= 0){
		cout << "That value is invalid, please enter another ineger number greater than 0" << endl;
		cin >> userDefinedBridgeHight;
	}
	/*cout << "Enter a value such that the height will be displayed every 1/YOURVALUE seconds" << endl;
	cin >> userDefinedInterval;
	while(userDefinedInterval < 1){
		cout << "That value is invalid, please enter another ineger number greater than 0" << endl;
		cin >> userDefinedInterval;
	}*/
	//Inputs are now validated
	
	for(int i = 1; i <= userDefinedTimeTaken; i = i + 1){
		if((GRAVITYACCELCONSTANT * pow(static_cast<float>(i), 2)/2) - userDefinedBridgeHight > 0){
			cout << "the distance fallen is not valid" << endl;
			return 0;
		}
		cout << (GRAVITYACCELCONSTANT * pow(i, 2)/2) << endl;
	}
	
	
	/*
	Suppose Doc Brown drops a watermelon off a high bridge and lets it fall until it hits the water.
	the distance d in meters fallen by the watermelon after t seconds is d = 0.5 * g * t^2
	where the acceleration of gravity g = 9.8 meters/second^2
	Write a program that asks the user to input the number of seconds that the watermelon falls and the height h of the bridge above the water
	The program should then calculate the distance fallen for each second from t = 0 until the value of t input by the user
	If the total distance fallen is greater than the height of the bridge, then the program should tell the user that the distance fallen is not valid.
	
	find dist fallen from t=0 
	detlaY=(GRAVITYACCELCONSTANT * pow(whatevertyimeat, 2)/2
	
	
	*/
	return 0;
}