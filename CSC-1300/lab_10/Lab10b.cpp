// This program demonstrates the use of dynamic arrays

// By Rus Hoffman and

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	// a pointer used to point to an array holding monthly sales
		double *monthSales = nullptr;
	// total of all sales
		double total = 0;
		// average of monthly sales
		double average;
	// number of sales to be processed
		int numOfSales;
	// loop counter
		int count;

	cout << fixed << showpoint << setprecision(2);


	cout << "How many monthly sales will be processed? ";
	cin >> numOfSales;
	while(cin.fail() || numOfSales < 1){
		system("CLS");
		cin.clear();
		cin.ignore();
		cout << "Invalid Input" << endl;
		cout << "Be sure you enter only a positive, integer number" << endl;
		cout << endl;
		cout << "How many monthly sales will be processed? ";
		cin >> numOfSales;
	}
	system("CLS");

	// Fill in the code to allocate memory for the array pointed to by monthSales.

	if ( ) 		// Fill in the condition to determine if memory has been
				// allocated (or eliminate this if construct if your instructor
				// tells you it is not needed for your compiler)
	{
		cout << "Error allocating memory!\n";
		return 1;
	}
	cout << "Enter the sales below\n";

	for (count = 0; count < numOfSales; count++)
	{
		cout << "Sales for Month number "
			 << // Fill in code to show the number of the month
			 << ":";
		// Fill in code to bring sales into an element of the array
	}

	for (count = 0; count < numOfSales; count++)
	{
		total = total + monthSales[count];
	}

	average = // Fill in code to find the average
	cout << "Average Monthly sale is $" << average << endl;
	// Fill in the code to deallocate memory assigned to the array.

	return 0;
}
