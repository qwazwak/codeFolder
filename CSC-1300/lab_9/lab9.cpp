/*
	Lab 9, multithreaded prime summer
	By Rus Hoffman
*/
#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)

#include "Timer.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;

bool primePrecheck(long long int input){
	if(input > 2){
		if(input % 2 == 1){
			return true;
		}
		else{
			return false;
		}
	}
	else if(input == 2){
		return true;
	}
	else{
		return false;
	}
}

bool checkIfPrime(long long int input){
	if(input > 2){
		if(input % 2 == 1){
			for(long long int i = 3; i <= ceil(sqrt(static_cast<long double>(input))); i = i + 2){
				if(((static_cast<long double>(input) / static_cast<long double>(i)) - floor(static_cast<long double>(input) / static_cast<long double>(i))) == 0){
					return false;
				}
			}
			return true;
		}
		else{
			return false;
		}
	}
	else if(input == 2){
		return true;
	}
	else{
		return false;
	}
}


int main(){
	time_t startTime;
	long double timeTaken;
	long long int max = 500;
	long long int min = 0;
	long long int primeSum = 0;
	int mode;
	ifstream inputLimits;

	inputLimits.open("Range.txt");
	inputLimits >> min;
	inputLimits >> max;
	inputLimits.close();

	if(inputLimits.fail() == true || min == max || max <= min || max <= min){
		cout << "|   Sum of primes calculator   |" << endl;
		cout << "|                              |" << endl;
		cout << "|     An error has occured     |" << endl;
		cout << "|     The program will end     |" << endl;
		cout << "|  after you press any button  |" << endl;
		cout << "|                              |" << endl;
		cout << "|                              |" << endl;
		cout << "|   One of these has happend:  |" << endl;
		cout << "|                              |" << endl;
		cout << "|   The file does not exist    |" << endl;
		cout << "|                              |" << endl;
		cout << "| Line one is equal to line 2  |" << endl;
		cout << "|                              |" << endl;
		cout << "|Line one is larger than line 2|" << endl;
		system("pause");
		return 0;
	}


	do{
		cout << "|   Sum of primes calculator   |" << endl;
		cout << "|                              |" << endl;
		cout << "|    Select desired mode by    |" << endl;
		cout << "|     entering its number      |" << endl;
		cout << "|                              |" << endl;
		cout << "|     1. Single-Threaded       |" << endl;
		cout << "|     2. Multi-Threaded        |" << endl;
		cout << "|                              |" << endl;
		cout << "|   Mode: ";
		cin >> mode;
		system("CLS");
		cin.clear();
		cin.ignore();
	}while(cin.fail() || mode < 1 || mode > 2);



	startTime = getTime();
	cout << "working..." << endl;
	#pragma omp parallel for reduction(+:primeSum)
	for(long long int i = min; i <= max; i = i + 1){
		if(primePrecheck(i) == true){
			if(checkIfPrime(i) == true){
				primeSum = primeSum + i;
			}
		}
	}
	system("CLS");
	timeTaken = totalTime(startTime, getTime());



	cout << "Time taken: " << timeTaken << endl;
	cout << "Lower Limit: " << min << endl;
	cout << "Upper Limit: " << max << endl;
	cout << "Sum of primes: " << primeSum << endl;
	system("pause");
	return 0;
}
