/*
	This program will:
		read in a group of test scores (positive integers from 1 to 100) from a file
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
#include <fstream>

using namespace std;




float findAverage(int *array, int size){
	float sum = 0; // holds the sum of all the numbers 
	for (int pos = 0; pos < size; pos++)
		sum = sum + array[pos];
	return (sum / size); //returns the average
}


int findHighest(int *array, int size){
	int currentMax = array[0];
	for(int i = 0; i < size; i = i + 1){
		if(array[i] > currentMax){
			currentMax = array[i];
		}
	}
	return currentMax;
}

int findLowest (int *array, int size){
	int currentMin = array[0];
	for(int i = 0; i + 1 <= size; i = i + 1){
		if(array[i] < currentMin){
			currentMin = array[i];
		}
	}
	return currentMin;
}



int main (){
	ifstream dataInputFile;
	
	
	//Temporary holding area for user input
	int fileInputtemp;
	
	//the array holding the grades.
	int grades[100]; 
	
	//the number of grades read.
	int numberOfGrades = 0;
	
	//contains the average of the grades
	float avgOfGrades;
	
	//contains the highest grade
	int highestGrade;
	
	// contains the lowest grade
	int lowestGrade;
	
	bool keepInput = true;
	
	
	
	// Read in the values into the array pos = 0;
	cout << "Starting loading" << endl;
	// Fill in the code to read the grades
	
	dataInputFile.open("Lab8.txt");
	for(long int i = 0; i < 100; i = i + 1){
		dataInputFile >> fileInputtemp;
		if(fileInputtemp == -99){
			break;
		}
		grades[i] = fileInputtemp;
		numberOfGrades = numberOfGrades + 1;
	}
	dataInputFile.close();
	
	
	
	//avgOfGrades = findAverage(grades, numberOfGrades);
	//highestGrade = findHighest(grades, numberOfGrades);
	//lowestGrade = findLowest(grades, numberOfGrades);
	cout << "The average of all the grades is " << findAverage(grades, numberOfGrades) << endl;
	cout << "The highest grade is " << findHighest(grades, numberOfGrades) << endl;
	cout << "The lowest grade is " << findLowest(grades, numberOfGrades) << endl;
	system("pause");
	return 0;
}