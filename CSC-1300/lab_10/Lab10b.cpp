// This program demonstrates the use of dynamic arrays

// By Rus Hoffman and

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	// a pointer used to point to an array holding monthly sales
		double *monthSales = NULL;
	// total of all sales
		double total = 0;
	// average of monthly sales
		double average;
	// number of sales to be processed
		long int numOfSales;
	// loop counter
		long int count;
	// month Names
		string monthNames[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	cout << fixed << showpoint << setprecision(2);

	//Have user enter number of entries to enter
	cout << "How many monthly sales will be processed? ";
	cin >> numOfSales;
	while(cin.fail() || numOfSales < 1){
		cin.clear();
		cin.ignore();
		cout << "Invalid Input" << endl;
		cout << "Be sure you enter only a positive, integer number" << endl;
		cout << endl;
		cout << "How many monthly sales will be processed? ";
		cin >> numOfSales;
	}

	
	//If memory cannot be allocated, give an error
	monthSales = new double[numOfSales];
	if(monthSales == NULL){
		cout << "Error allocating memory!" << endl;
		return 1;
	}


	//Have user enter the sales
	cout << "Enter the sales below" << endl;
	for (count = 0; count < numOfSales; count++){
		cout << "Sales for " << monthNames[count % 12] << ": ";
		cin >> monthSales[count];
		while(cin.fail() || monthSales[count] < 0){
			cin.clear();
			cin.ignore();
			cout << "Invalid Input" << endl;
			cout << "Be sure you enter only a positive number or zero" << endl;
			cout << endl;
			cout << "Sales for " << monthNames[count % 12] << ": ";
			cin >> monthSales[count];
		}
	}


	// Fill in code to find the average
	for(count = 0; count < numOfSales; count++){
		total = total + monthSales[count];
	}
	average = total / static_cast <double> (numOfSales);

	//Display average
	cout << "Average Monthly sale is $" << average << endl;
	//Deallocate memory assigned to the array.
	delete[] monthSales;
	return 0;
}
