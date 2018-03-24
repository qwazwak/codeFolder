#include "MakeUnsortedFile.h"
#include <ctime>
//#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

void generateNewData(){
	long long int numOfNum;
	long long int maxValue;
	ofstream writeData;
	srand(time(NULL));
	do{
		cout << "How many values should be" << endl;
		cout << "made for unsorted.txt" << endl;
		cin >> numOfNum;
		cin.clear();
		cin.ignore();
	}while(cin.fail() || numOfNum < 1);


	cout << "Enter the maximum value" << endl;
	cin >> maxValue;
	while(cin.fail() || maxValue < 2){
		cin.clear();
		cin.ignore();
		cout << "Invalid input" << endl;
		cout << "Must be an integer number" << endl;
		cout << "greater than or equal to 2" << endl;
		cout << endl;
		cout << "Enter the maximum value" << endl;
		cin >> maxValue;
	}

	writeData.open("unsorted.txt");
	writeData << numOfNum << endl;
	for (long long int i = 0; i < numOfNum; i = i + 1) {
		writeData << rand() % maxValue << endl;
	}
	writeData.close();
}
