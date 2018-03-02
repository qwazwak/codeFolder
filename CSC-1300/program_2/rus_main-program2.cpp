/* Heading and info:
	Rus Hoffman
	
	In this program you will modify the code you created for program 1 - Tic Tac Toe
	Playing one game of Tic-Tac-Toe is nice, but we usually want to play several games to account for mistakes, errors, or simply bad play
	For this reason, you will enclose your existing code in a user-controlled loop that will continue to play the game until the user decides to terminate the loop
	While the game is running, you will keep track of :
		Number of individual games won
		Number of games won by X
		Number of games won by O
	In addition, if the user makes an invalid menu selection or chooses to play a 1 player game you should present them with an appropriate message and return them to the menu rather than exiting the program.
	After the user terminates the game, the program should return to the menu
	If the user decides to end the game, you are required to report :
		The total number of games played during this "session"
		The total number of games won by X this "session"
		The total number of games won by O this "session"
		The total number of games resulting in a tie this "session"
	In addition, you will report the same information with a "historical" context by reading the statistics from a file you will create called "TTTStats.txt"
	The file will be read in, used and then you will update the values stored in the file when the user exits the program
	
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
#define TicTacToe
#include "rus_header-program2.h"
using namespace std;


int main (){
	//Which player won?
	int winner;
	//User input for number of players
	int	userSelection;
	//does the user want to end the program?
	bool EndProgram = false;
	//does the user want to keep playing?
	bool keepPlaying = true;
	int numTimesXWins = 0;
	int numTimesOWins = 0;
	int numTies = 0;
	int numGames = 0;
	int userKeepPlayingSelection;
	
	while(EndProgram == false){
		cout << "~~~~~~~Tic-Tac-Toe~~~~~~~" << endl << endl;
		cout << "Enter the corresponding number to select one of the following options:" << endl << endl << endl;
		cout << "  1.  1 Player Game <NOT SUPPORTED>" << endl;
		cout << "  2.  2 Player Game" << endl;
		cout << "  3.  Exit" << endl;
		cout << "Enter your choice : ";
		cin >> userSelection;
		
		//Input validation
		while(!((userSelection == 2) || (userSelection == 3)) || cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "~~~~~~~Tic-Tac-Toe~~~~~~~" << endl << endl;
			if(userSelection == 1){
				cout << "Single player mode is not currently supported" << endl;
			}
			else if(userSelection < 1 || userSelection > 3){
				cout << "The entered value was invald. Try again" << endl << endl;
			}
			else{
				cout << "A very bad error has occurred" << endl;
			}
			cout << "Enter the corresponding number to select one of the following options:" << endl << endl << endl;
			cout << "  1.  1 Player Game <NOT SUPPORTED>" << endl;
			cout << "  2.  2 Player Game" << endl;
			cout << "  3.  Exit" << endl;
			cout << "Enter your choice : ";
			cin >> userSelection;
		}
		
		switch(userSelection){
			case 2:
				while(keepPlaying == true){
					winner = play2PGame ();
					numGames = numGames + 1;
					if (winner == 1){
						cout << "Congrats X, you win!" << endl;
						numTimesXWins = numTimesXWins + 1;
					}
					else if(winner == 2){
						cout << "Congrats O, you win!" << endl;
						numTimesOWins = numTimesOWins + 1;
					}
					else{
						cout << "Oh no! It was a tie!" << endl;
						numTies = numTies + 1;
					}
					
					do{
						cin.clear();
						cin.ignore();
						cout << "Would you like to keep playing?" << endl;
						cout << "  1. Yes" << endl;
						cout << "  2. No" << endl;
						cout << "Enter your choice : ";
						cin >> userSelection;
					}while((!((userSelection == 1) || (userSelection == 2))) || cin.fail());
					if(userSelection == 1){
						keepPlaying = true;
					}
					else{
						keepPlaying = false;
					}
				}
				cout << "Stats for this session:" << endl;
				cout << "   Number of games played: " << numGames << endl;
				cout << "   Number of times X won: " << numTimesXWins << endl;
				cout << "   Number of times O won: " << numTimesOWins << endl;
				cout << "   Number of times X and O tied: " << numTies << endl;
				system("pause");
			break;
			case 3:
				cout << "Ending game" << endl << endl;
				EndProgram = true;
			break;
			default:
				cout << "A very bad error has occurred" << endl;
				return 0;
			break;
		}
	}
	updateHistory(numGames, numTimesXWins, numTimesOWins, numTies);
	
	
	cout << "Historical stats from TTTStats.txt:" << endl;
	cout << "   Number of games played: " << getHistory(4) << endl;
	cout << "   Number of times X won: " << getHistory(3) << endl;
	cout << "   Number of times O won: " << getHistory(2) << endl;
	cout << "   Number of times X and O tied: " << getHistory(1) << endl;
	
	system("pause");
	return 0;
}