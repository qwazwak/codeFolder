/*
Function FILE- This is actually making functions and should never be shared. only the compiled (rus_BigBadLib.o) should be shared. If this is found please delete.

INFO: SEE rus-BigBadLib.h

*/
#include "rus_header-program2.h"





#define _WIN64 1 //(also WIN64, __WIN64, and __WIN64__)
#define __MINGW64__ 1
#define __x86_64 1 //(also __x86_64__)
#define __amd64 1 //(also __amd64__)

#include <time.h>
/*
	Has more, all I use is:
	VARIABLE = time(NULL);
*/
#include <cstdlib>
#include <stdlib.h>
/*
Probably does more, all I need is:
rand()
	Generates random number
srand(seed)
	Sets a new seed for pseudorandom generation
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
#include <fstream>
/* i/ofstream info
	General:
		foobar_recognizablename.open(stringVariableName.c_str());
		
		
		
		bar_recognizablename.open("foo/bar_Input.txt");
			Will open file for reading, file must exist to work
		foo_recognizablename.open("bar/foo_Output.txt");
			Will create file, if it already exists it will be deleted and overwritten
		if(!bar_recognizablename){HAPPENS IF ERROR}
			For input validation, you can use infile.fail()
		
		Closing files:
			bar_recognizablename.close();
			foo_recognizablename.close();
	Input:
		bar_recognizablename >> myVariable;
			Can be used for boolean.. [foo/bar_Input >> myVariable] returns true when it works
		
		
	Output:
		foo_recognizablename << "Thing happened" << endl;
		
		
		
*/
#include <string>
/*
	real strings
	cstringvariable = stringVariableName.c_str();
*/
#include <string.h>
/*
	cstring mess
*/
#include <iomanip>
/* <iomanip> info
	Manipulates input and output
	cout << setprecision(2) << fixed << showpoint;
	output stuff << minumum decimal points() << cutoff decimal points? << show decimal point always ;
*/
#include <cmath>
/* <cmath> info
	adds math functions
	
	
	trig- sin(),cos, tan, ect
	pow(base, exponent);
	sqrt(thing to do root of);
	cbrt(thing to do cube root of);
	ceil()
	floor()
	nearbyint(number to round to nearest int)
	copysign(magnitude, sign)
*/
/* Uncomment to add delay support
#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)
	#include <windows.h>
	inline void delay(unsigned long long ms){
		Sleep(ms);
	}
#else //presume POSIX 
	#include <unistd.h>
	inline void delay(unsigned long long ms){
		usleep( ms * 1000 );
	}
#endif
*/
/* Uncomment to add beepingn or noise support
#if (defined(WINDOWS) || defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)) && !defined(LINUX)
	#include <Windows.h>
	inline void dynBeep(int freq, long double timeOfBeep){
		Beep(freq, timeOfBeep);
	}
#elif !(defined(WINDOWS) || defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)) && defined(LINUX)
	#include <stdio.h>
	void dynBeep(int freq, long double timeOfBeep){
		system("echo -e "\007" >/dev/tty10");
	}
#else
	#include <stdio.h>
	void dynBeep(int freq, long double timeOfBeep){
		std::cout << "\a" << std::flush;
	}
#endif
*/
/*
Code gud check input
	Variable Type Check
	Length Check (over/underflow attack)
	Range Check (month should be 1 to 12)
	Reasonable Check (birthyear is reasonable)
	Divide by Zero (and indirect devisions)
	Format Check (MM/DD/YYY vs YYYY/MM/DD)

Useful bits of code:		
	Variables:
		const VARTYPE VARNAME - makes it not change
		int - float - double - long double - increasing size	
	static means it doesnt die
	
	
	
	//for loop
	for(int i = 0; i < limit; i = i + 1){
		stuff
	}

	//real loop
	while(bool){
		stuff;
	}
	
	//do while template
	do{
		
	}while(bool);
	
	
	//switch template
	switch(VARIABLE){
		case ():
			
		break;
		case ():
			
		break;
		default:
			
		break;
	}
*/

using namespace std;

void clearScreen(int long lines){
	if((lines % 11) == 0){
		for(int i = 0; i < lines; i = i + 11){
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		}
	}
	else if((lines % 7) == 0){
		for(int i = 0; i < lines; i = i + 7){
			cout << endl << endl << endl << endl << endl << endl << endl;
		}
	}
	else if((lines % 5) == 0){
		for(int i = 0; i < lines; i = i + 5){
			cout << endl << endl << endl << endl << endl;
		}
	}
	else if((lines % 3) == 0){
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
void displayBoard(char* board){
	system ("CLS");
	cout << "   |   |   " << endl;
	cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
	cout << "   |   |   " << endl;
	cout << "-----------" << endl;
	cout << "   |   |   " << endl;
	cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
	cout << "   |   |   " << endl;
	cout << "-----------" << endl;
	cout << "   |   |   " << endl;
	cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
	cout << "   |   |   " << endl;
}
bool isWinning (char* board, char player){
	if((board[0] == player && board[1] == player && board[2] == player) ||
		(board[3] == player && board[4] == player && board[5] == player) ||
		(board[6] == player && board[7] == player && board[8] == player) ||
		(board[0] == player && board[3] == player && board[6] == player) ||
		(board[1] == player && board[4] == player && board[7] == player) ||
		(board[2] == player && board[5] == player && board[8] == player) ||
		(board[0] == player && board[4] == player && board[8] == player) ||
		(board[2] == player && board[4] == player && board[6] == player)){
		return true;
	}
	else{
 		return false;
	}
}
void getMove (char* board, char player){
	int userChoice;
	do{
		cout << "It is " << player <<"'s turn - pick a space : ";
		cin >> userChoice;
	}while (userChoice <= 0 || userChoice >= 10 || board[userChoice - 1] == 'O' || board[userChoice -1] == 'X');
	board[userChoice - 1] = player;
}
char* setupGame(){
	char* board = new char[10];
	for (int i = 0; i < 9; i++){
		board[i] = '0' + (i + 1);
	}
	return board;
}
void swap (char& current, char& old){
	char rearrange;
	rearrange = current;
	current = old;
	old = rearrange;
}
int evaluate (char* board, int player){
}
int play1PGame (){
	int moves = 1;
	bool winner = false;
	char* board = setupGame();
	int player = 1;
}
int play2PGame(){
	int moves = 1;
	bool winner = false; 
	char* board = setupGame ();
	char player = 'X';
	char lastPlayer = 'O';
	displayBoard (board);
	do{
		getMove(board, player);
		moves++;
		winner = isWinning(board, player);
		swap(player, lastPlayer);
		displayBoard(board);
	}while(moves <= 9 && !(winner));
	if(!winner){
		return 3;
	}
	else if(isEven(moves)){
		return 1; 
	}
	else if(isEven (moves - 1)){
		return 2;
	}
	else{
		cout << "an error has occured" << endl;
		return  0;
	}
}
void updateHistory(int numGamesPlayed, int numWinsX, int numWinsO, int numTies){
	ifstream fromTTTStats;
	int readnumGamesPlayed;
	int readnumWinsX;
	int readnumWinsO;
	int readnumTies;
	fromTTTStats.open("TTTStats.txt");
	if(!fromTTTStats){
		fromTTTStats.close();
			ofstream sendTTTStats;
			sendTTTStats.open("TTTStats.txt");
			sendTTTStats << 0 << endl;
			sendTTTStats << 0 << endl;
			sendTTTStats << 0 << endl;
			sendTTTStats << 0 << endl;
			sendTTTStats.close();
		fromTTTStats.open("TTTStats.txt");
	}
	fromTTTStats >> readnumGamesPlayed;
	fromTTTStats >> readnumWinsX;
	fromTTTStats >> readnumWinsO;
	fromTTTStats >> readnumTies;
	fromTTTStats.close();
	ofstream sendTTTStats;
	sendTTTStats.open("TTTStats.txt");
	sendTTTStats << readnumGamesPlayed + numGamesPlayed << endl;
	sendTTTStats << readnumWinsX + numWinsX << endl;
	sendTTTStats << readnumWinsO + numWinsO << endl;
	sendTTTStats << readnumTies + numTies << endl;
	sendTTTStats.close();
}
int getHistory(int statID){
	int stat;
	ifstream fromTTTStats;
	fromTTTStats.open("TTTStats.txt");
	switch(statID){
		case 4:
			fromTTTStats >> stat;
		case 3:
			fromTTTStats >> stat;
		case 2:
			fromTTTStats >> stat;
		case 1:
			fromTTTStats >> stat;
		break;
		default:
			stat = 0;
		break;
	}
	fromTTTStats.close();
	return stat;
}