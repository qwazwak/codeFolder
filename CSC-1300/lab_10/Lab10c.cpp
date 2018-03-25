/*
This program asks for the total number of grades and has the user enter them, then drops the lowest and displayes the average

Ask user for sized
read in test scores
find lowest and do average:

	add up all
	find lowest
	total - lowest
	devide by count - 1

display to 3 decimal places


nt values[] = { 40, 10, 100, 90, 20, 25 };

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main ()
{
  int n;
  qsort (values, 6, sizeof(int), compare);
  for (n=0; n<6; n++)
     printf ("%d ",values[n]);
  return 0;
}







By Rus Hoffman and

*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>

using namespace std;

/*
Ask user for sized
read in test scores
find lowest and do average:

	add up all
	find lowest
	total - lowest
	devide by count - 1
*/
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
		double smallest;
	// loop counter
	//	long int count;

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
	
	//If memory cannot be allocated, give an error
	grades = new double[numOfGrades];
	if(grades == NULL){
		cout << "Error allocating memory!" << endl;
		return 1;
	}


	//Have user enter the grades
	cout << "Enter the grades below" << endl;
	for (long int i = 0; i < numOfGrades; i++){
		cout << "Enter grade #" << i + 1 << ":";
		cin >> grades[i];
		while(cin.fail() || grades[i] < 0 || grades[i] > 100){
			cin.clear();
			cin.ignore();
			cout << "Invalid Input" << endl;
			cout << "Be sure you enter only number between 0 and 100" << endl;
			cout << endl;
			cout << "Enter grade #" << i + 1 << ":";
			cin >> grades[i];
		}
	}


	//Calculate average but drop the lowest value
	smallest = grades[0];
	for(long int i = 0; i < numOfGrades; i++){
		if(grades[i] <= smallest){
			total = total + smallest;
			smallest = grades[i];
		}
		else{
			total = total + grades[i];
		}
	}
	average = total / static_cast <double> (numOfGrades - 1);


	cout << "Average grade is " << average << "%" << endl;
	
	
	//Deallocate memory assigned to the array.
	delete[] grades;
	return 0;
}
