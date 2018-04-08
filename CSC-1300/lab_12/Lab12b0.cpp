//This program tests a password to see if the format is correct
//By Rus hoffman and
#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;



char* makeCopyWithOnlyLowerAlpha(char *strPtr){
	long strPtrSize = 0;
	long positionForNew = 0;
	long counterAlso = 0;
	long counter = 0;




	while(strPtr[counter] != '\0'){
		strPtrSize++;
		counter++;
	}


	char* newCharArr = new char[strPtrSize];



	while(strPtr[counterAlso] != '\0'){
		if(isalpha(strPtr[counterAlso]) == true){
			newCharArr[positionForNew] = strPtr[counterAlso];
			positionForNew++;
		}
		counterAlso++;
	}
	return newCharArr;
}

long countDigits(char *strPtr){
	long occurs = 0;
	while(*strPtr != '\0'){
		if (isdigit(*strPtr))
			occurs++;
		strPtr++;
	}
	return occurs;
}

/*
Promps the user to input a string of a size 50 characters or less.

Your program should then determine whether or not the entered string is a palindrome.
A message should be displayed to the user informing them whether or not their string is a palindrome
*/

int main(){
	char* userInput = new char[51];
	char* shrinkText;
	string stringVersion;
	cout << "Enter some text: " << endl;
	cin.getline(userInput, 51);
	shrinkText = makeCopyWithOnlyLowerAlpha(userInput);
	stringVersion = shrinkText;
	cout << shrinkText << endl;
	if(stringVersion == string(stringVersion.rbegin(), stringVersion.rend())){
		cout << "Entered text is a palindrome" << endl;
	}
	else if(stringVersion != string(stringVersion.rbegin(), stringVersion.rend())){
		cout << "Entered text is not a palindrome" << endl;
	}
	else{
		cout << "Error" << endl;
	}

	delete[] shrinkText;
	return 0;
}
