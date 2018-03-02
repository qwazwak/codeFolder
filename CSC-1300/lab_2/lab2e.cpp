// This program demonstrates the use of characters and strings

//Rus Hoffman

#include <iostream>
#include <string>
using namespace std;

// Definition of Constants
const string FAVORITESODA = "Dr. Dolittle";		// Note the double quotes
const char BESTRATING = 'A';					// Note the single quotes

int main()
{

	char rating = 'B';								// 2nd highest product rating
	string favoriteSnack = "crackers";						// Most preferred snack
	int numberOfPeople = 250;							// The number of people in the survey
	int topChoiceTotal = 148;							// The number of people who prefer the top choice

	// Fill in the code to do the following:
	// Assign the value of "crackers" to favoriteSnack
	// Assign the grade of 'B' to rating
	// Assign the number 250 to the numberOfPeople
	// Assign the number 148 to the topChoiceTotal

	// Fill in the blanks of the following:
	cout << "The preferred soda is " << FAVORITESODA << endl;
	cout << "The preferred snack is " << favoriteSnack << endl;
	cout << "Out of " << numberOfPeople << " people surveyed " << topChoiceTotal << " chose those items!" << endl;
	cout << "Each of thse products were given a rating of " << BESTRATING;
	cout << " from our expert tasters" << endl;
	cout << "The other products were rated no higher than a " << rating << endl;

	return 0;

}