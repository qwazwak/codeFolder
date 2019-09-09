/*
	Program 4: Modified Gradebook

	Class Functions file
	
	Created by Rus Hoffman
*/
#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)

#include "P4Func.hpp"
#include <iostream>
#include <string>
#include <cmath>


using namespace std;



void classDatabase::setupVal (long numTests) {
	testCount = numTests;
	testAverage = new double[testCount];
	for (long i = 0; i < testCount; i++) {
		testAverage[i] = -1;
	}
	studentCount = 0;
	studentCapacity = 1;
	studentArray = new student[0];
	studentArray[0].grade = new double[testCount];
}


void classDatabase::updateInternals (void) {
	longestNameID = 0;
	longestNameSize = static_cast<long>(studentArray[0].name.length());
	long* sumHolder = new long[testCount];
	long singleHold = 0;
	for (long x = 0; x < testCount; x++) {
		sumHolder[x] = 0;
	}
	for (long j = 0; j < studentCount; j++) {
		if (static_cast<long>(studentArray[j].name.length()) > longestNameSize) {
			longestNameSize = static_cast<long>(studentArray[j].name.length());
			longestNameID = j;
		}
		singleHold = 0;
		for (long i = 0; i < testCount; i++) {
			singleHold = singleHold + studentArray[j].grade[i];
			sumHolder[i] = sumHolder[i] + studentArray[j].grade[i];
		}
		studentArray[j].average = static_cast<double>(singleHold) / static_cast<double>(testCount);
	}
	for (long i = 0; i < testCount; i++) {
		testAverage[i] = static_cast<double>(sumHolder[i]) / static_cast<double>(studentCount);
	}
	delete[] sumHolder;
}

void classDatabase::addStudent (student inputStudent){
	student* newArray = new student[studentCapacity + 1];
	for (long i = 0; i < studentCount; i++) {
		newArray[i].name = studentArray[i].name;
		newArray[i].grade = new double[testCount];
		for (long j = 0; j < testCount; j++) {
			newArray[i].grade[j] = studentArray[i].grade[j];
		}
	}
	newArray[studentCount].grade = new double[testCount];

	newArray[studentCount].name = inputStudent.name;
	for (long i = 0; i < testCount; i++) {
		newArray[studentCount].grade[i] = inputStudent.grade[i];
	}
	for (long i = 0; i < studentCount; i++) {
		delete[] studentArray[i].grade;
	}
	delete[] studentArray;
	studentArray = newArray;
	studentCapacity++;
	studentCount++;
}



void classDatabase::curveGrades (long curveVal, long testID){
	updateInternals ();
	if (testCount <= testID) {
		cout << "ERROR" << endl;
	}
	else{
		long deltaVal = curveVal - testAverage[testID];
		for (long i = 0; i < studentCount; i++) {
			studentArray[i].grade[testID] = studentArray[i].grade[testID] + deltaVal;
			if (studentArray[i].grade[testID] > 100) {
				studentArray[i].grade[testID] = 100;
			}
		}
	}
}

long classDatabase::getTestCount (void){
	return testCount;
}
long classDatabase::getStudentCount (void){
	return studentCount;
}
long classDatabase::getLongNameSize (void){
	return longestNameSize;
}

student classDatabase::getStudent (long studentID){
	if (studentID < studentCount){
		return studentArray[studentID];
	}
}
string classDatabase::getName (long studentID){
	if (studentID < studentCount){
		return studentArray[studentID].name;
	}
}
double classDatabase::getStudentGrade (long studentID, long testID){
	if (studentID < studentCount && testID < testCount){
		return studentArray[studentID].grade[testID];
	}
}
double classDatabase::getStudentAverage (long studentID){
	if (studentID < studentCount){
		return studentArray[studentID].average;
	}
}
double classDatabase::getClassTestAverage (long testID){
	if (testID < testCount){
		return testAverage[testID];
	}
}
