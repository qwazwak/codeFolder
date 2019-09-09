//This program tests a password to see if the format is correct
//By Rus hoffman and Sam O'Heron
#include <iostream>
#include <cctype>
#include <cstring>
// countLetters: counts the letters of digits in the string. Takes in a cstring and returns number of letters in it
long countLetters(char *strPtr){
	long occurs = 0;
	while(*strPtr != '\0'){
		if (isalpha(*strPtr))
			occurs++;
		strPtr++;
	}
	return occurs;
}
// countDigits: counts the number of digits in the string. Takes in a cstring and returns number of digits in it
long countDigits(char *strPtr){
	long occurs = 0;
	while(*strPtr != '\0'){
		if (isdigit(*strPtr))
			occurs++;
		strPtr++;
	}
	return occurs;
}
// testPassWord: determines if the word in the character array passed to it, contains exactly 5 letters and 3 digits.
// Precondition: a word contained in a character array
// Postcondition: true if the word contains 5 letters & 3 digits, false otherwise
bool testPassWord(char custPass[]){
	if (countLetters(custPass) == 5 && countDigits(custPass) == 3 && strlen(custPass) == 8 )
		return true;
	else
		return false;
}
int main(){
	char passWord[20];
	std::cout << "Enter a password consisting of exactly 5 letters and 3 digits:" << std::endl;
	std::cin.getline(passWord, 20);
	if(testPassWord(passWord))
		std::cout << "Please wait - your password is being verified" << std::endl;
	else
		std::cout << "Invalid password. Please enter a password with exactly 5 letters and 3 digits" << std::endl << "For example, my37RuN9 is valid" << std::endl;
	std::cout << "Number of letters contained: " << countLetters(passWord) << std::endl << "Number of numbers contained: " << countDigits(passWord) << std::endl;
	return 0;
}