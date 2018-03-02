/* Heading and info:
	Rus Hoffman, Duncan Stewart, Eric Waggoner
	Create a program to list the prime numbers between two numbers supplied in a text file.
A number is considered prime if it is greater than 1 and has no factors between 2 and the square root of the number rounded up, inclusive. Write a program that finds all the prime numbers within a range specified and outputs the results to a second text file named primes.txt. To accomplish this, write a driver program Main.cpp that obtains the range from a text file range.txt and then uses the appropriate loops and mathematical expressions to find the prime numbers. Hint: You should create a bool function that accepts the number to be checked, handles all the math and then returns true or false if the number is actually a prime number. The format of the input file should always be identical - the first line will contain the lowest number to be included, the second line will contain the upper limit. The input file will be called range.txt.
Second hint : I will check your file with multiple input files, and not all of them will begin at 1 so make sure you handle all special cases.
Sample output of the program is :
Prime numbers between 1 and 20 have been printed to primes.txt
Contents of Primes.txt should be:

Below are the primes from 1 to 20
2
3
5
7
11
13
17
19
*/
#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <iomanip>
#include <cmath>
using namespace std;

bool isEven (int input){
	if(input % 2 == 0)
		return true;
	return false;
}
//Precheck for primes to speed up code
bool primePrecheck(int input){
	if(input > 2){
		if(input % 2 == 1)
			return true;
		else
			return false;
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
		if(input % 2 != 0){
			for(long long int i = 3; i <= ceil(sqrt(static_cast<double>(input))); i = i + 2){
				//Decimals of number == 0?
				if(((static_cast<double>(input) / static_cast<double>(i)) - floor(static_cast<double>(input) / static_cast<double>(i))) == 0){
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

int main (){
	//Setup fstream
	ifstream inFile_rangeTXT;
	ofstream outFile_PrimesTXT;
	inFile_rangeTXT.open("range.txt");
	outFile_PrimesTXT.open("primes.txt");
	
	//Variables
	signed long long int lowerLimit;
	signed long long int upperLimit;
	signed long long int modlowerLimit;
	
	inFile_rangeTXT >> lowerLimit;
	inFile_rangeTXT >> upperLimit;
	
	while(!inFile_rangeTXT || lowerLimit < 1 || upperLimit <= lowerLimit){
		cout << "The file 'range.txt' does not exist or is formatted incorrectly" << endl;
		cout << "Make sure there is a text file in the same folder as this executable with:" << endl;
		cout << "The name 'range.txt'" << endl;
		cout << "The file has the lower limit on the first line" << endl;
		cout << "~ and the lower limit is an integer number greater than 0" << endl;
		cout << "The upper limit on the second line" << endl;
		cout << "~ and the upper limit is an integer number greater than the lower limit" << endl;
		system("pause");
		inFile_rangeTXT.open("range.txt");
		inFile_rangeTXT >> lowerLimit;
		inFile_rangeTXT >> upperLimit;
	}
	
	if(isEven(lowerLimit) == true){
		modlowerLimit = lowerLimit + 1;
	}
	else if(isEven(lowerLimit) == false){
		modlowerLimit = lowerLimit;
	}
	else{
		cout << "REALLY BAD ERROR" << endl;
		inFile_rangeTXT.close();
		outFile_PrimesTXT.close();
		return 0;
	}
	outFile_PrimesTXT << "Below are the primes from " << lowerLimit << " to " << upperLimit << endl;
	for(long long int i = modlowerLimit; i <= upperLimit; i = i + 2){
		if(checkIfPrime(i)){
			outFile_PrimesTXT << i << endl;
			cout << i << " is prime" << endl;
		}
		else{
			cout << i << " is not prime" << endl;
		}
	}
	cout << "DONE" << endl;
	cout << "All even numbers have been omitted to save time" << endl;
	
	system("pause");
	inFile_rangeTXT.close();
	outFile_PrimesTXT.close();
	return 0;
}