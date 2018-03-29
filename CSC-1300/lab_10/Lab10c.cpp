/*
This program asks for the total number of grades and has the user enter them, then drops the lowest and displayes the average
By Rus Hoffman and Rebekah Brandt
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>

using namespace std;

int compare(const void * a, const void * b){
	return *(double*)a - *(double*)b;
}

int main(){
	// a pointer used to point to an array holding monthly sales
		double *grades = NULL;
	// total of all sales
		double total = 0;
	// average of monthly sales
		double average;
	// number of sales to be processed
		long int numOfGrades;
	//Smallest value
		// smallest;

	cout << fixed << showpoint << setprecision(3);

	//Have user enter number of entries to enter
	cout << "How many grades will be entered? ";
	cin >> numOfGrades;
	while(cin.fail() || numOfGrades < 1){
		cin.clear();
		cin.ignore();
		cout << "Invalid Input" << endl;
		cout << "Be sure you enter only a positive integer" << endl;
		cout << endl;
		cout << "How many grades will be entered? ";
		cin >> numOfGrades;
	}

	grades = new double[numOfGrades];

	//Have user enter the grades
	cout << "Enter the grades below" << endl;
	for (long int i = 0; i < numOfGrades; i++){
		cout << "Enter grade #" << i + 1 << ": ";
		cin >> grades[i];
		while(cin.fail() || grades[i] < 0 || grades[i] > 100){
			cin.clear();
			cin.ignore();
			cout << "Invalid Input" << endl;
			cout << "Be sure you enter only number between 0 and 100" << endl;
			cout << endl;
			cout << "Enter grade #" << i + 1 << ": ";
			cin >> grades[i];
		}
	}

	qsort(grades, numOfGrades, sizeof(double), compare);
	
	//Calculate average but drop the first value
	for(long int i = 1; i < numOfGrades; i++){
			total = total + grades[i];
	}
	average = total / static_cast <double> (numOfGrades - 1);

	cout << "Average grade is " << average << "%" << endl;

	//Deallocate memory assigned to the array and end program
	delete[] grades;
	return 0;
}
