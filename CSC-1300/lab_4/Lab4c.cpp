/*
Heading and info:
Rus Hoffman and Jacob Forbess
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
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
*/

int main()
{
	long double averageBillA;
	long double averageBillB;
	long double averageBillC;
	long double averageBillD;
	long double averageBillNet;
	cout << "You are about to enter your last four quarterly water bills" << endl;
	cout << "Enter the first:" << endl;
	cin >> averageBillA;
	if(averageBillA > 0){
		cout << "Enter the second:" << endl;
		cin >> averageBillB;
		if(averageBillB > 0){
			cout << "Enter the third:" << endl;
			cin >> averageBillC;
			if(averageBillC > 0){
				cout << "Enter the fourth:" << endl;
				cin >> averageBillD;
			}
		}
	}
	while(averageBillA <= 0 || averageBillB <= 0 || averageBillC <= 0 || averageBillD <= 0){
		cout << "One or more of your enteries were zero, or negative" << endl;
		cout << "Please reenter your last four quarterly water bills" << endl;
		cout << "Enter the first:" << endl;
		cin >> averageBillA;
		if(averageBillA > 0){
			cout << "Enter the second:" << endl;
			cin >> averageBillB;
			if(averageBillB > 0){
				cout << "Enter the third:" << endl;
				cin >> averageBillC;
				if(averageBillC > 0){
					cout << "Enter the fourth:" << endl;
					cin >> averageBillD;
				}
			}
		}
	}
	averageBillNet = (averageBillA + averageBillB + averageBillC + averageBillD) / 12;
	cout << "Your average monthly water usage is: " << averageBillNet << endl;
	if(averageBillNet > 75){
		cout << "You are required to receive a message indicating that too much water is being used" << endl;
	}
	else if(averageBillNet <= 75 && averageBillNet >= 25){
		cout << "You are required to receive a message indicating that a typical amount of water is being used" << endl;
	}
	else if(averageBillNet < 25){
		cout << "You are required to receive a message indicating that a typical amount of water is being used" << endl;
	}
	return 0;
}