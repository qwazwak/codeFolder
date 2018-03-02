/* Heading and info:
	Rus Hoffman
	
	Pretty easy this week, it is all on you - write a program to calculate a persons BMI based on inputs for height and weight.
	BMI is equal to Weight/Height^2 * 703 (imperial)
	
*/
#define _WIN64 1
#define __MINGW64__ 1
#define __x86_64 1
#define __amd64 1
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
/*

*/

int main (){
	//Variables
	int option;
	long double mass;
	long double height;
	bool metric;
	cout << "~~~BMI Calculator~~~" << endl;
	cout << "Enter the value of  " << endl;
	cout << " the option you want" << endl;
	cout << endl;
	//cout << "Do you want to use: " << endl;
	cout << "   1. Metric        " << endl;
	cout << "   2. Imperial.. Ew " << endl;
	cin >> option;
	while(option < 1 || option > 2){
		cout << "~~~BMI Calculator~~~" << endl;
		cout << "   INVALID  INPUT   " << endl;
		cout << "     TRY  AGAIN     " << endl;
		cout << "Enter the value of  " << endl;
		cout << " the option you want" << endl;
		cout << endl;
		//cout << "Do you want to use: " << endl;
		cout << "   1. Metric        " << endl;
		cout << "   2. Imperial.. Ew " << endl;
		cin >> option;
	}
	if(option == 1){
		metric = true;
	}
	else{
		metric = false;
	}
	
	
	
	//Getting Mass
	if(metric == true){
		cout << "~~~BMI Calculator~~~" << endl;
		cout << "Enter mass in       " << endl;
		cout << "  decimal kilograms " << endl;
		cin >> mass;
	}
	else if(metric == false){
		cout << "~~~BMI Calculator~~~" << endl;
		cout << "Enter weight in     " << endl;
		cout << "  decimal pounds    " << endl;
		cin >> mass;
	}
	while(mass <= 0){
		if(metric == true){
			cout << "~~~BMI Calculator~~~" << endl;
			cout << "   Invalid  Input   " << endl;
			cout << " Enter a value      " << endl;
			cout << "  greater than zero " << endl;
			cout << "Enter mass in       " << endl;
			cout << "  decimal kilograms " << endl;
			cin >> mass;
		}
		else if(metric == false){
			cout << "~~~BMI Calculator~~~" << endl;
			cout << "   Invalid  Input   " << endl;
			cout << " Enter a value      " << endl;
			cout << "  greater than zero " << endl;
			cout << "Enter weight in     " << endl;
			cout << "  decimal pounds    " << endl;
			cin >> mass;
		}
	}
	
	
	//Getting height
	if(metric == true){
		cout << "~~~BMI Calculator~~~" << endl;
		cout << "Enter height in     " << endl;
		cout << "    decimal meters: " << endl;
		cin >> height;
	}
	else if(metric == false){
		cout << "~~~BMI Calculator~~~" << endl;
		cout << "Enter height in     " << endl;
		cout << "      decimal feet: " << endl;
		cin >> height;
	}
	while(height <= 0){
		if(metric == true){
			cout << "~~~BMI Calculator~~~" << endl;
			cout << "   Invalid  Input   " << endl;
			cout << " Enter a value      " << endl;
			cout << "  greater than zero " << endl;
			cout << "Enter height in     " << endl;
			cout << "    decimal meters: " << endl;
			cin >> height;
		}
		else if(metric == false){
			cout << "~~~BMI Calculator~~~" << endl;
			cout << "   Invalid  Input   " << endl;
			cout << " Enter a value      " << endl;
			cout << "  greater than zero " << endl;
			cout << "Enter height in     " << endl;
			cout << "      decimal feet: " << endl;
			cin >> height;
		}
	}
	
	if(metric == true){
		cout << "~~~BMI Calculator~~~" << endl;
		cout << "  Calculated BMI:   " << endl;
		cout << (mass /(pow(height, 2))) << endl;
	}
	else if(metric == false){
		cout << "~~~BMI Calculator~~~" << endl;
		cout << "  Calculated BMI:   " << endl;
		cout << (mass /(pow(height, 2))) * 703 << endl;
	}
	system("pause");
	return 0;
}