/* Heading and info:
	Rus Hoffman, Duncan Stewart, and Eric Waggoner
	
	Write a program that will convert miles to kilometers and kilometers to miles
	The user will indicate both a number (representing a distance) and a choice of whether that number is in miles to be converted to kilometers or kilometers to be converted to miles
	Each conversion is done with a value returning function
	Hint: Your program will contain 3 functions including main() 
	Compile and run your program several times to verify the output.
	
*/
#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Constents
const double KILOMETERS_PER_MILE = 1.61;
const double MILE_PER_KILOMETER = 0.621;
const int LINESTOCLEAR = 32;



//Functions
void clearScreen(){
	for(int i = 0; i < LINESTOCLEAR; i = i + 1){
		cout << endl;
	}
}
double convertMilesKilometers(double miles){
	return miles * KILOMETERS_PER_MILE;
}
double convertKilometersMiles(double kilo){
	return kilo * MILE_PER_KILOMETER;
}

//main
int main(){
	//Variables
	double userSelection;
	double userInputForConversion;
	double convertedValue;
	
	
	
	clearScreen();
	cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "|  Miles and Kilometer Converter" << endl;
	cout << "|" << endl;
	cout << "|  Options:" << endl;
	cout << "|   1. Kilometer to Miles" << endl;
	cout << "|   2. Miles to Kilometers" << endl;
	cout << "|" << endl;
	cout << "|  Enter the corresponding" << endl;
	cout << "|  number to select that entry" << endl;
	cout << "|" << endl;
	cin >> userSelection;
	clearScreen();
	while(!(userSelection == 1 || userSelection == 2)){
		cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "|  Miles and Kilometer Converter" << endl;
		cout << "|" << endl;
		cout << "|  Selected option is invalid" << endl;
		cout << "|           Try again" << endl;
		cout << "|" << endl;
		cout << "|  Enter a '1' or a '2'" << endl;
		cout << "|  Corresponding to:" << endl;
		cout << "|   1. Kilometer to Miles" << endl;
		cout << "|   2. Miles to Kilometers" << endl;
		cout << "|" << endl;
		cin >> userSelection;
		clearScreen();
	}
	cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "|  Miles and Kilometer Converter" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	cout << "|      Selected mode:" << endl;
	if(userSelection == 1){
		cout << "|      Miles To Kilometers" << endl;		
	}else if(userSelection == 2){
		cout << "|      Kilometers To Miles" << endl;	
	}
	else{
		cout << "A really bad error has happened. Program Ending" << endl;
		return 0;
	}
	cout << "|" << endl;
	cout << "| Enter your value" << endl;
	if(userSelection == 1){
		cout << "| Miles: ";
	}else if(userSelection == 2){
		cout << "| Kilometers: ";
	}
	else{
		cout << "A really bad error has happened. Program Ending" << endl;
		return 0;
	}
	cin >> userInputForConversion;
	clearScreen();
	
	if(userSelection == 1){
		convertedValue = convertMilesKilometers(userInputForConversion);
	}
	else if(userSelection == 2){
		convertedValue = convertKilometersMiles(userInputForConversion);
	}
	else{
		cout << "A really bad error has happened. Program Ending" << endl;
	}
	
	cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "|  Miles and Kilometer Converter" << endl;
	cout << "|" << endl;
	cout << "|" << endl;
	if(userSelection == 1){
		cout << "| " << userInputForConversion << " miles converted to kilometers is:" << endl;
	}
	else if(userSelection == 2){
		cout << "| " << userInputForConversion << " kilometers converted to miles is:" << endl;
	}
	else{
		cout << "A really bad error has happened. Program Ending" << endl;
	}
	cout << "|    " << convertedValue << endl;
	system("pause");	
	return 0;
}