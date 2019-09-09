/*
Heading and info:
Rus Hoffman and Jacob Forbess
*/
// This program prints "You Pass" if a student's average is
// 60 or higher and prints "You Fail" otherwise

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

#include <iostream>
using namespace std;

int main(){
	float average;
	cout << "Input your average grade:" << endl;
	cin >> average;
	while(average > 100 || average < 0){
		cout << "Invald input, please reenter grade:" << endl;
		cin >> average;
	}
	if(average >=  80){
		if(average >= 90 && average <= 100){
			cout << "A" << endl;
		}
		else if(average >= 80 && average < 90){
			cout << "B" << endl;
		}
		else{
			cout << "Error" << endl;
		}
	}
	if(average < 80){
		if(average >= 60 && average < 80){
			cout << "You Pass" << endl;
		}
		else if(average >= 0 && average < 60){
			cout << "You Fail" << endl;
		}
		else{
			cout << "Error" << endl;
		}
	}
	return 0;
}