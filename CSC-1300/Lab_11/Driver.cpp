/*
	By Rus Hoffman
*/
#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)

#include "Permutation.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;




void manyEndl (){
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
}

int main (){
	long n;
	long* drawFromDeck = NULL;



	//Ask the user for the size of the deck, call it n
		do{
			cout << endl;
			cout << "Enter the number of cards:" << endl;
			cin >> n;
			cin.clear();
			cin.ignore();
			manyEndl();
		}while(cin.fail() || n < 1);

	//Generate a deck using the initPermutation function
		drawFromDeck = initPermuation(n);


	//Loop through the size of the deck (hint: do not use your deckSize variable for this)
		cout << "Generated Cards:" << endl;
		for (long i = n; i >= 1; i--){
			//Call nextPermutation
				cout << nextPermutation(drawFromDeck, i) << endl;
		}
	//Release the dynamically allocated memory
	delete[] drawFromDeck;
	return 0;
}
