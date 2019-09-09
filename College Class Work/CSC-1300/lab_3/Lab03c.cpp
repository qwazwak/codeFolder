// This program will input the value of two sides of a right triangle and then
// determine the size of the hypotenuse.

// Rus Hoffman and Nick Ford

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath> //Needed for things like sqrt()
using namespace std;

int main()
{
	float a;
	float b; 		// the smaller two sides of the triangle 
	float hyp; 		// the hypotenuse calculated by the program
	
	cout << setprecision(3);
	cout << "Please input the value of the two sides" << endl;
	cin >> a;
	cin >> b;
	hyp = sqrt(pow(2, a) + pow(2, b));
	// Fill in the assignment statement that determines the hypotenuse
	cout << "The sides of the right triangle are: " << a << " and " << b << endl;
	cout << "The hypotenuse is: " << hyp << endl;
	return 0;
}