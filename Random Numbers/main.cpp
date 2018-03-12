/*
	Makes a file with random numbers in it
	By Rus Hoffman
*/
#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)
#include <windows.h>
#include <ctime>
#include <random>
#include <cstdint>
#include <chrono>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <iomanip>
#include <cmath>


using namespace std;

int main (){
	mt19937 generator(clock() * chrono::system_clock::now().time_since_epoch().count());  // mt19937 is a standard mersenne_twister_engine
	int_least64_t seed = generator();
	srand(seed);
	random_device rd;
	int_least64_t numOfFiles;
	int_least64_t numOfValuesToGenerate;
	int_least64_t gensTillUpdate;
	uint_least64_t stopwatchStart;
	uint_least64_t stopwatch;
	long double timePerFileAverage;
	ofstream randomFilesOutput;
	uint_least64_t timePerFileTotal = 0;
	long double globalStopwatchStart;
	int_least64_t userOkayWithPercent;
	
	cout << "Seed: " << seed << endl;
	cout << "Minimum: " << rd.min() << endl;
	cout << "Maximum: " << rd.max() << endl;
	cout << "Entropy: " << rd.entropy() << endl;
	cout << "setup done" << endl;
	
	
	do{
		cout << "|    Random Files Generator    |" << endl;
		cout << "|                              |" << endl;
		cout << "|                              |" << endl;
		cout << "| Enter the number of          |" << endl;
		cout << "|   files to make:             |" << endl;
		cout << "|      ";
		cin >> numOfFiles;
		cin.clear();
		cin.ignore();
	}while(cin.fail() || numOfFiles < 1);
	
	do{
		cout << "|    Random Files Generator    |" << endl;
		cout << "|                              |" << endl;
		cout << "|                              |" << endl;
		cout << "| Enter the number of          |" << endl;
		cout << "|   generations per file:      |" << endl;
		cout << "|      ";
		cin >> numOfValuesToGenerate;
		cin.clear();
		cin.ignore();
	}while(cin.fail() || numOfValuesToGenerate < 1);
	
	/*do{
		do{
			cout << "|    Random Files Generator    |" << endl;
			cout << "|                              |" << endl;
			cout << "|                              |" << endl;
			cout << "| After how many values should |" << endl;
			cout << "|   progress be displayed?     |" << endl;
			cout << "|      ";
			cin >> gensTillUpdate;
			cin.clear();
			cin.ignore();
		}while(cin.fail() || gensTillUpdate < 1 || gensTillUpdate >= numOfValuesToGenerate);
		
		
		do{
			cout << "|    Random Files Generator    |" << endl;
			cout << "|                              |" << endl;
			cout << "| This will display updates    |" << endl;
			cout << "|   every: " << setprecision(4) << (100.0 * (static_cast<long double>(gensTillUpdate) / static_cast<long double>(numOfValuesToGenerate))) << "%" << endl;
			cout << "|                              |" << endl;
			cout << "|Is this okay?  1: Yes    0: No|" << endl;
			cout << "|      ";
			cin >> userOkayWithPercent;
		}while(cin.fail() || userOkayWithPercent < 0 || userOkayWithPercent > 1);
	}while(userOkayWithPercent != 1);*/
	
	globalStopwatchStart = clock();
	
	
	//Generate and output numbers and files
	CreateDirectory("output", NULL);
	for(uint_least64_t currentFileNumber = 1; currentFileNumber <= numOfFiles; currentFileNumber = currentFileNumber + 1){
		stopwatchStart = clock();
		randomFilesOutput.open(".\\output\\RandomNumbers___Seed-" + to_string(seed) + "___values-" + to_string(numOfValuesToGenerate) + "___Part" + to_string(currentFileNumber) + "of" + to_string(numOfFiles) + ".txt");

		
		for(uint_least64_t currentNumGeneration = 1; currentNumGeneration <= numOfValuesToGenerate; currentNumGeneration = currentNumGeneration + 1){
			randomFilesOutput << rd();
			
			
			/*if(currentNumGeneration % gensTillUpdate == 0){
				cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
				cout << "|    Random Files Generator    |" << endl;
				cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
				cout << "| Single file progress - " << setprecision (1) << fixed << 100.0 * (static_cast<long double>(currentNumGeneration) / static_cast<long double>(numOfValuesToGenerate)) << "%" << endl;
				cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
			}*/
			
		}
		randomFilesOutput << flush;
		randomFilesOutput.close();
		
		cout << endl << endl << endl << endl << endl << endl << endl;
		cout << "|    Random Files Generator    |" << endl;
		cout << "|                              |" << endl;
		cout << "| Progress - " << setprecision (1) << fixed << 100.0 * (static_cast<long double>(currentFileNumber) / static_cast<long double>(numOfFiles)) << "%" << endl;
		cout << "|                              |" << endl;
		cout << "| Time for this file - ";
		stopwatch = clock() - stopwatchStart;
		cout << stopwatch << "ms" << endl;
		cout << "|                              |" << endl;
		cout << "| Badly estimated time left - " << setprecision(2) << floor((static_cast<long double>(stopwatch) * (static_cast<long double>(numOfFiles) - static_cast<long double>(currentFileNumber)))/60000.0) << " minutes and " << (((static_cast<long double>(stopwatch) * (static_cast<long double>(numOfFiles) - static_cast<long double>(currentFileNumber)))/60000.0) - floor((static_cast<long double>(stopwatch) * (static_cast<long double>(numOfFiles) - static_cast<long double>(currentFileNumber)))/60000.0)) * 60 << " seconds" << endl;
		cout << "|                              |" << endl;
	}
	
	//Display Stats
	cout << endl << endl << endl << endl << endl << endl;
	cout << endl << endl << endl << endl << endl << endl;
	cout << "|    Random Files Generator    |" << endl;
	cout << "|                              |" << endl;
	cout << "| Number of files    - " << numOfFiles << endl;
	cout << "| Number of values per file  - " << numOfValuesToGenerate << endl;
	cout << "| Time Taken - " << ((clock() - globalStopwatchStart)/1000) << " seconds" << endl;
	cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
	system("pause");
	return 0;
}