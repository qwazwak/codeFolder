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
	char grade;

	cout << "What grade did you earn in Programming I?" << endl;
	cin >> grade;
	if(grade != 'A' && grade != 'B' && grade != 'C' && grade != 'D' && grade != 'F'){
		cout << "You did not enter an A, B, C, D, or F" << endl;
	}
	else if(grade == 'A'){
		cout << "an A - excellent work!" << endl;
	}
	else if(grade == 'B'){
		cout << "you got a B - good job" << endl;
	}
	else if(grade == 'C'){
		cout << "earning a C is satisfactory" << endl;
	}
	else if(grade == 'D'){
		cout << "while D is passing, there is a problem" << endl;
	}
	else if(grade == 'F'){
		cout << "you failed - better luck next time" << endl;
	}
	return 0;
}