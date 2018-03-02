// This program will read in the quantity of a particular item and its price.
// It will then print out the total price.
// The input will come from the keyboard and the output will go to
// the screen.

// Rus Hoffman and Nick Ford

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;



int quantity; 									// contains the amount of items purchased 
float itemPrice; 								// contains the price of each item
float totalBill; 								// contains the total bill.
string itemName;

int main(){

	cout << setprecision(2) << fixed << showpoint; 	// formatted output 
	
	cout << "Please input the name of the purchased item" << endl;
	getline(cin, itemName);
	
	
	cout << "Please input the number of items bought" << endl;
	//Input statement to bring in the quantity
	cin >> 	quantity;
	
	
	//Output message
	cout << "Please input the price per unit" << endl;
	//Input statement to bring in the price perunit
	cin >> 	itemPrice;
	
	totalBill = quantity * itemPrice;
	
	cout << "The item you bought is:" << endl;
	cout << itemName << endl;
	cout << "Total Bill is:" << endl;
	cout << totalBill << endl;
	
	
	// Fill in the assignment statement to determine the total bill.
	// Fill in the output statement to print total bill, with a label to the screen.
	
	return 0;
}