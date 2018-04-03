/*
	Created by Rus Hoffman
	permuation selector for card drawer for lab 11
*/
#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)

#include "Permutation.hpp"

#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

//Removes the index at card from the array.
//This function is called by nextPermutation and is never called by the user.
void removePermutation (long* cardsToDrawFrom, long& cardsToDrawFromSize, long cardNum){
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
	//cout << "Setup starting" << endl;
	for (long i = 0; i < n; i++) {
		arrayPointer[i] = i + 1;
		//cout << i << ". " << arrayPointer[i] << endl;
	}
	//cout << "Setup ended" << endl;
	return arrayPointer;
}

//Receives the currect card array and the size of the array, returns the next "card"
//Deck size is passed as a reference variable so it can be modified
long nextPermutation (long* cardsToDrawFrom, long& cardsToDrawFromSize){
	long location = rand() % cardsToDrawFromSize;
	long value = cardsToDrawFrom[location];
	removePermutation(cardsToDrawFrom, cardsToDrawFromSize, location);
	return value;
}
