/*
	Program 4: Modified Gradebook

	core code

	Created by Rus Hoffman
*/
#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)

#include "P4Func.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>


#include <cmath>
using namespace std;



int main (int argc, char* argv[]){
	const long NAMESPACEBUFFER = 3;
	char filename[255];
	//Verify Input
		if (argc != 3) {
			cout << "Ivalid argument count" << endl;
			cout << "To use this program you must specify the grades file and curve value" << endl;
			cout << "ex: " << argv[0] << " gradesFile.txt 75" << endl;
			return 0;
		}
		{
			strcpy(filename, argv[1]);
			char tempHolder;
			ifstream inputTester;
			inputTester.open(filename);
			inputTester >> tempHolder;
			while (inputTester.fail()) {
				inputTester.close();
				cout << "Error, File name is invalid" << endl;
				cout << "Enter a new file name: ";
				cin >> filename;
				while(cin.fail()){
				cin.clear();
					cin.ignore();
					cout << "Enter a new file name: ";
					cin >> filename;
				}
				inputTester.open(filename);
				inputTester >> tempHolder;
				inputTester.close();
			}
			inputTester.close();
		}
	//Input is now validated
	ifstream dataLoader;
	classDatabase studentBase;
	student loaderStudent;
	student readerStudent;
	string stringToPrint;
	long localNumTest;
	char curveOption;
	long nameWidth;
	long curveVal = atol(argv[2]);

	//Variables are made



	dataLoader.open(filename);
	dataLoader >> localNumTest;
	studentBase.setupVal(localNumTest);
	loaderStudent.grade = new double[studentBase.getTestCount()];
	do {
		dataLoader.ignore();
		getline(dataLoader, loaderStudent.name);
		//cout << "Name: " << loaderStudent.name << endl;
		if (dataLoader.fail()) {
			cout << "funk" << endl;
		}
		for (long gn = 0; gn < studentBase.getTestCount(); gn++) {
			dataLoader >> loaderStudent.grade[gn];
			//cout << loaderStudent.grade[gn] << "    ";
			if (dataLoader.fail()) {
				cout << "funk";
			}
		}
		//cout << endl;
		studentBase.addStudent (loaderStudent);
		//cout << "Count: " << studentBase.getStudentCount() << endl;
		} while(!dataLoader.eof());
	dataLoader.close();
	studentBase.updateInternals();
	//Data is now laoded, and the internals of the classDatabase are updated


	//See if user wants to curve any grades
	for (long testID = 0; testID < studentBase.getTestCount(); testID++) {
		cout << "The average grade on test " << testID+1 << " is " << studentBase.getClassTestAverage(testID);
		if (studentBase.getClassTestAverage(testID) < curveVal) {
			cout << "      Do you want to curve? Enter Y or N: ";
			cin >> curveOption;
			curveOption = toupper(curveOption);
			while (cin.fail() || (curveOption != 'Y' && curveOption != 'N')) {
				cin.ignore();
				cin.clear();
				cout << "      Do you want to curve? Enter Y or N: ";
				cin >> curveOption;
				curveOption = toupper(curveOption);
			}
			if (curveOption == 'N') {
			}
			else if (curveOption == 'Y') {
				studentBase.curveGrades(curveVal, testID);
			}
			else {
				cout << "ERROR" << endl;
				return 1;
			}
		}
		else if (studentBase.getClassTestAverage(testID) > curveVal) {
			cout << "      No curve necessary" << endl;;
		}
		else {
			cout << "funk" << endl;
		}
	}
	//Update internals and display grades
	studentBase.updateInternals();
	nameWidth = studentBase.getLongNameSize() + NAMESPACEBUFFER;
	cout << left << setw(static_cast<long>(floor(static_cast<double>(nameWidth)))) << "   Name:   ";
	for (long i = 1; i <= studentBase.getTestCount(); i++) {
		if (i < 10) {
			cout << setw(0) << "     T0" << i;
		}
		else{
			cout << setw(0) << "     T" << i;
		}
	}
	cout << setw(0) << "    Avg:" << endl;
	cout << endl;
	for (long studID = 0; studID < studentBase.getStudentCount(); studID++) {
		cout << left << setw(nameWidth) << studentBase.getName(studID);
		for (long testID = 0; testID < studentBase.getTestCount(); testID++) {
			cout << setw(0) << left << "  ";
			if (studentBase.getStudentGrade(studID, testID) == 100) {
				cout << setprecision(2) << right << setw(6) << 100;
			}
			else{
				cout << setprecision(2) << right << setw(6) << studentBase.getStudentGrade(studID, testID);
			}
		}
		cout << setprecision(2) << right << setw(7) << studentBase.getStudentAverage(studID);
		cout << endl;
	}
	//Only the loader student needs manual deallocation. classDatabase has a deconstructor
	delete[] loaderStudent.grade;
	return 0;
}
