/* Heading and info:
	Rus Hoffman
	
*/

#include <iostream>
#include <fstream>
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
		
	
add to notes: cin is numbers

Case study

general crates

ask user for HW and L of crate

calculate volume cost price profit

display that
*/


const float pricePVCompany = 0.23;
const float pricePVConsumer = 0.50;
const float profitPV = pricePVConsumer - pricePVCompany;
bool numbersAreGood = false;
int dimentions;
float currentVolume = 1;



/*bool validateInputs(int sizeOfArray, int inputTest []){
	bool testAnswer;
	for(int i = 0; i < sizeof(inputTest); i = i + 1){
		if(inputTest[i] <= 0){
			testAnswer = false;
		}
		else
	}
	return testAnswer;
}*/


int main(){
	
	cout << setprecision(2) << fixed << showpoint;
	cout << "Current cost/volume to company is: " << pricePVCompany << endl;
	cout << "Current cost/volume to consumer is: " << pricePVConsumer << endl;
	cout << "Program Starting.." << endl;
	for(int i = 0; i < 10; i = i + 1){
		cout << endl << endl;
	}
	cout << "Enter the number of spacial dimentions: ";
	cin >>  dimentions;
	while(dimentions < 1){
		cout << "Invalid input, Enter the number of spacial dimentions: ";
		cin >>  dimentions;
	}
	float crateSize[dimentions-1];
	for(int i = 0; i < dimentions; i = i + 1){
		cout << "Please enter the crate's size in the " << (i + 1) << "th dimention:" << endl;
		cin >> crateSize[i];
	}
	
	for(int i = 0; i < dimentions; i = i + 1){
		currentVolume = currentVolume * crateSize[i];
	}
	
	cout << "The volume of the crate is: " << currentVolume << endl;
	cout << "The cost per crate to manufacture is: " << (currentVolume * pricePVCompany) << endl;
	cout << "The cost per crate to the consumer is: " << (currentVolume * pricePVConsumer) << endl;
	cout << "The profit per crate for the manufacture is: " << (currentVolume * profitPV) << endl;
	
	
	cout << "End Program" << endl;
	return 0;
}