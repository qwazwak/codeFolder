//This program tests if an input of 50 or less chars is a palindrome
//By Rus hoffman and Sam O'Heron
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
void removeSpaces(char *str){
	int count = 0;
	for (int i = 0; str[i]; i++){
		if (str[i] != ' '){
			str[count++] = tolower(str[i]);
		}
	}
	str[count] = '\0';
}
int main(){
	char* userInput = new char[51];
	cout << "Enter some text: " << endl;
	cin.getline(userInput, 51);
	removeSpaces(userInput);
	string stringVersion = userInput;
	if(stringVersion == string(stringVersion.rbegin(), stringVersion.rend()))
		cout << "Entered text is a palindrome" << endl;
	else if(stringVersion != string(stringVersion.rbegin(), stringVersion.rend()))
		cout << "Entered text is not a palindrome" << endl;
	else
		cout << "Error" << endl;
	return 0;
}
