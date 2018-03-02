/* Heading and info:
	Rus Hoffman, Duncan Stewart, and Eric Waggoner
	
	
	
	This function takes cents as an integer and converts it to dollars and cents
	The default value for cents is 150 which is converted to 1.50 and stored in dollars
*/
#include <iostream>
/*
	system("pause")
		Enter any key to continue..
	cout << "" << endl;
		output things
	cin >> VARNAME;
		Bring in numbers
	cin.get(VARNAME);
		Single Char
	getline(cin, VARNAME);
		get a line
*/
//#include <ifstream>
//#include <ofstream>
/* i/ofstream info
	General:
		inFile.open(stringVariable.c_str());
		bar_recognizablename.open("foo/bar_Input.txt");
			Will open file for reading, file must exist to work
		foo_recognizablename.open("bar/foo_Output.txt");
			Will create file, if it already exists it will be deleted and overwritten
		if(!bar_recognizablename){HAPPENS IF ERROR}
			For input validation, you can use infile.fail()
		
		Closing files:
			bar_recognizablename.close();
			foo_recognizablename.close();
	Input:
		foo/bar_Input >> myVariable;
			Can be used for boolean.. [foo/bar_Input >> myVariable] returns true when it works
		
		
	Output:
		bar/foo_Output.txt << "Thing happened" << endl;
		
		
		
*/
#include <string>
/*
	real strings
	cstringvariable = stringVariableName.c_str();
*/
#include <string.h>
/*
	cstring mess
*/
#include <iomanip>
/* <iomanip> info
	Manipulates input and output
	cout << setprecision(2) << fixed << showpoint;
	output stuff << minumum decimal points() << cutoff decimal points? << show decimal point always ;
*/
#include <cmath>
/* <cmath> info
	adds math functions
	
	
	trig- sin(),cos, tan, ect
	pow(base, exponent);
	sqrt(thing to do root of);
	cbrt(thing to do cube root of);
	ceil()
	floor()
	nearbyint(number to round to nearest int)
	copysign(magnitude, sign)
*/
using namespace std;


/* Useful bits of code:
	#include <iostream>
		const VARTYPE VARNAME - makes it not change
		int - float - double - long double - increasing size	
	
	
	//#include <ctype.h>

	
	
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



void normalizeMoney(float& dollars, int cents = 150);

int main(){
	int cents;
	float dollars;
	cout << setprecision(2) << fixed << showpoint;
	cents = 95;
	cout << "\n We will now add 95 cents to our dollar total\n";
	// Fill in the code to call normalizeMoney to add 95 cents
	normalizeMoney(dollars, 95);

	cout << "Converting cents to dollars resulted in " << dollars << " dollars\n";
	cout << "\n We will now add 193 cents to our dollar total\n";
	normalizeMoney(dollars, 193);
	
	
	// Fill in the code to call normalizeMoney to add 193 cents
	cout << "Converting cents to dollars resulted in " << dollars << " dollars\n";
	cout << "\n We will now add the default value to our dollar total\n";
	
	normalizeMoney(dollars);
	
	
	// Fill in the code to call normalizeMoney to add the default value of cents
	cout << "Converting cents to dollars resulted in " << dollars << " dollars\n";
	system("pause");
	return 0;
}
/* //*******************************************************************************
// normalizeMoney
//
// task: This function is given a value in cents. It will convert cents
// to dollars and cents which is stored in a local variable called
// total which is sent back to the calling function through the
// parameter dollars. It will keep a running total of all the money
// processed in a local static variable called sum.
//
// data in: cents which is an integer
// data out: dollars (which alters the corresponding actual parameter)
//
//
//********************************************************************************* */
void normalizeMoney(float& dollars, int cents){
	float total = 0;
	static float sum = 0.0;	
	
	// Fill in the code to convert cents to dollars
	dollars = cents / 100.0;
	
	
	total = total + dollars;
	sum = sum + dollars;
	cout << "We have added another $" << dollars <<" to our total" << endl;
	cout << "Our total so far is $" << sum << endl;
	cout << "The value of our local variable total is $" << total << endl;
}