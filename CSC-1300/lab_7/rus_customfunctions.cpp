//function file
//header.cpp
#include "rus_customheader.h"


/*
bool foo(int bar, double baz){

}
*/

void clearScreen(int long lines){
	if((lines % 11) == 0){
		for(int i = 0; i < lines; i = i + 11){
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		}
	}
	else if((lines % ) == 7){
		for(int i = 0; i < lines; i = i + 7){
			cout << endl << endl << endl << endl << endl << endl << ezndl;
		}
	}
	else if((lines % ) == 5){
		for(int i = 0; i < lines; i = i + 5){
			cout << endl << endl << endl << endl << endl;
		}
	}
	else if((lines % ) == 3){
		for(int i = 0; i < lines; i = i + 3){
			cout << endl << endl << endl;
		}
	}
	else if((lines % 2) == 0){
		for(int i = 0; i < lines; i = i + 2){
			cout << endl << endl;
		}
	}
	else{
		for(int i = 0; i < lines; i = i + 1){
			cout << endl;
		}
	}
}
bool isEven(int input){
	if (input % 2 == 0){
		return true ;
	}
	else{
		return false;
	}
}
bool isOdd(int input){
	if (input % 2 == 1){
		return true ;
	}
	else{
		return false;
	}
}