/*
	This program will:
		read in a group of test scores (positive integers from 1 to 100) from the keyboard
		then calculate and output the average score as well as the highest and lowest score
		There will be a maximum of 100 scores.
	By Rus Hoffman
	Partner: Dalton Minon
*/
#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)

#include <windows.h>
#include <iostream>
#include <iomanip>

using namespace std;




float findAverage(const int array[], int size){
	float sum = 0; // holds the sum of all the numbers 
	for (int pos = 0; pos < size; pos++)
		sum = sum + array[pos];
	return (sum / size); //returns the average
}


int findHighest(const int array[], int size){
	int currentMax = array[0];
	for(int i = 0; i < size; i = i + 1){
		if(array[i] > currentMax){
			currentMax = array[i];
		}
	}
	return currentMax;
}

int findLowest (const int array[], int size){
	int currentMin = array[0];
	for(int i = 0; i + 1 <= size; i = i + 1){
		if(array[i] < currentMin){
			currentMin = array[i];
		}
	}
	return currentMin;
}



int main (){
	//Temporary holding area for user input
	int userInputTemp;
	
	//the array holding the grades.
	int grades[100]; 
	
	//the number of grades read.
	int numberOfGrades = 0;
	
	//index to the array.
	int pos = 0;
	
	//contains the average of the grades
	float avgOfGrades;
	
	//contains the highest grade
	int highestGrade;
	
	// contains the lowest grade
	int lowestGrade;
	
	bool keepInput = true;
	
	
	
	// Read in the values into the array pos = 0;
	cout << "Enter a grade from 1 to 100" << endl;
	cout << "Grade #" << pos + 1 << ": ";
	cin >> userInputTemp;
	cin.clear();
	cin.ignore();
	cout << endl << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl << endl;
	while(userInputTemp < 1 || userInputTemp > 100 || cin.fail()){
		cout << "Invalid Entry" << endl;
		cout << "Enter a grade from 1 to 100" << endl;
		cout << "Grade #" << pos + 1 << ": ";
		cin >> userInputTemp;
		cin.clear();
		cin.ignore();
		cout << endl << endl << endl << endl << endl << endl;
		cout << endl << endl << endl << endl << endl << endl;
	}		
	//userInputTemp now holds a validated user defined grade
	
	grades[pos] = userInputTemp;
	pos = pos + 1;
	numberOfGrades = numberOfGrades + 1;
	// Fill in the code to read the grades
	
	
	while(keepInput == true){
		cout << "Enter a grade from 1 to 100, (or -99 to stop)" << endl;
		cout << "Grade #" << pos + 1 << ": ";
		cin >> userInputTemp;
		cout << endl << endl << endl << endl << endl << endl;
		while((userInputTemp < 1 && userInputTemp != -99) || userInputTemp > 100 || cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "Invalid Entry" << endl;
			cout << "Enter a grade from 1 to 100, (or -99 to stop)" << endl;
			cout << "Grade #" << pos + 1 << ": ";
			cin >> userInputTemp;
			cout << endl << endl << endl << endl << endl << endl;
		}
		//userInputTemp now holds a validated user defined grade
		if(userInputTemp == (-99)){
			keepInput = false;	
		}
		else{
			grades[pos] = userInputTemp;
			pos = pos + 1;
			numberOfGrades = numberOfGrades + 1;
			if(numberOfGrades >= 100){
				keepInput = false;	
			}
		}
	}
	
	
	//avgOfGrades = findAverage(grades, numberOfGrades);
	//highestGrade = findHighest(grades, numberOfGrades);
	//lowestGrade = findLowest(grades, numberOfGrades);
	cout << "The average of all the grades is " << findAverage(grades, numberOfGrades) << endl;
	cout << "The highest grade is " << findHighest(grades, numberOfGrades) << endl;
	cout << "The lowest grade is " << findLowest(grades, numberOfGrades) << endl;
	system("pause");
	return 0;
}