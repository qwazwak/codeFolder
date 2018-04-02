/*
	Created by Rus Hoffman
	This should my template, and should change
*/
#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)

#include "Permutation.hpp"

#include <ctime>
#include <cstdlib>
//#include <time.h>
/*
	Has more, all I use is:
	VARIABLE = time(NULL);
*/
#include <iostream>
/*
	system("pause")
		Enter any key to continue..
	cout << "" << endl;
		output things
	cin >> VARNAME;
		Bring in numbers
	cin.get(VARNAME);
		Single Char
	getline(cin, VARNAME);
		get a line
*/


//#include <iomanip>
/*
	Manipulates input and output
	cout << setprecision(2) << fixed << showpoint;
	cout << minumum decimal points(VARIABLE OR NUMBER) << cutoff decimal points? << show decimal point always;
*/

using namespace std;

//Removes the index at card from the array.
//This function is called by nextPermutation and is never called by the user.
void removePermutation (long* cardsToDrawFrom, long cardsToDrawFromSize, long cardNum){
	for(long i = 0; i < cardsToDrawFromSize; i++){
		if(i >= cardNum){
			cardsToDrawFrom[i] = cardsToDrawFrom[i + 1];
		}
	}
	cardsToDrawFromSize = cardsToDrawFromSize - 1;
}



//Creates a dynamic array of size n, initializes it with the correct values and returns the array to the user
long* initPermuation (long n){
	long* arrayPointer = new long[n];
	cout << "Setup starting" << endl;
	for (long i = 1; i <= n; i++) {
		arrayPointer[i] = i;
		cout << i << ". " << arrayPointer[i] << endl;
	}
	cout << "Setup ended" << endl;
	return arrayPointer;
}

//Receives the currect card array and the size of the array, returns the next "card"
//Deck size is passed as a reference variable so it can be modified
long nextPermutation (long* cardsToDrawFrom, long& cardsToDrawFromSize){
	//srand(time(NULL));

	long location = rand() % cardsToDrawFromSize;
	long value = cardsToDrawFrom[location];
	removePermutation(cardsToDrawFrom, cardsToDrawFromSize, location);
	return value + 1;
}
