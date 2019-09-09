//CSC_1300 Program 1: Tic-Tac-Toe board

//Rus Hoffman

//Include any library files needed

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

void clearScreen (int lines){
	for(int i = 0; i < lines; i = i + 1 ){
		cout << endl;
	}
}

/* Useful bits of code:
	cout << "" << endl;
	cin >> A >> B >> C;
	cin >> VARIABLE; number only
	cout << setprecision(2) << fixed << showpoint;
		output stuff << decimal points << cutoff decimal points? << show decimal point always ;
	Variables:
		const VARTYPE VARNAME - makes it not change
		int - float - double - long double - increasing size
	cout << setprecision(3) << fixed << showpoint;
*/

void displayBoard (char* board);
bool isWinning (char* board, char player);
void getMove (char* board, char player);
bool isEven (int digit);
char* setupGame ();
int play2PGame ();
void swap (char& current, char& old);


int main (){
	// Which player won?
	int winner;
	
	// Number of players (1 or 2)
	int	numPlayers;
	
	
	
	
	
	cout << "Tic-Tac-Toe" << endl;
	cout << "To select an option enter the associated number" << endl;
	cout << "1 -  Single player game" << endl;
	cout << "2 -  Two player game" << endl;
	cin >> numPlayers;
	while (numPlayers > 2 || numPlayers < 1){
		cout << "Invalid input entered" << endl;
		cout << "Ensure selected option is valid" << endl;
		cout << "Tic-Tac-Toe" << endl;
		cout << "To select an option enter the associated number" << endl;
		cout << "1 -  Single player game" << endl;
		cout << "2 -  Two player game" << endl;
		cin >> numPlayers;
	}
	switch(numPlayers){
		case 1:
			cout << "This is not currently supported" << endl;
			return 0;
		break;
		case 2:
			cout << "Starting two player game..." << endl;
			clearScreen(20);
			winner = play2PGame();
		break;
		default:
			cout << "an error has occured" << endl << "program will end" << endl;
			return 0;
		break;		
	}
	switch(winner){
		case 1:
			cout << "X is the winner" << endl;
		break;
		case 2:
			cout << "O is the winner" << endl;
		break;
		case 3:
			cout << "X and O tied" << endl;
		break;
		default:
			cout << "an error has occured" << endl << "program will end" << endl;
		break;		
	}
	cout << "program end" << endl;
	
	

	// The variable winner will be the player number of the winner
	// 1 is X, 2 is O, 3 is a tie.
	// Let the players know who won...
	
	//setup the return to terminate the program
	return 0;
}



void displayBoard (char* board)
{
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

bool isEven (int digit){
	if (digit % 2 == 0){
		return true;
	}
	else
	return false;
}

bool isWinning (char* board, char player){
	if (
		(board[0] == player && board[1] == player && board[2] == player) ||
		(board[3] == player && board[4] == player && board[5] == player) ||
		(board[6] == player && board[7] == player && board[8] == player) ||
		(board[0] == player && board[3] == player && board[6] == player) ||
		(board[1] == player && board[4] == player && board[7] == player) ||
		(board[2] == player && board[5] == player && board[8] == player) ||
		(board[0] == player && board[4] == player && board[8] == player) ||
		(board[2] == player && board[4] == player && board[6] == player)
 		) 
		return true;
  	else 
 		return false;
}

void getMove (char* board, char player){
	int userChoice;

	do{
		cout << "It is " << player <<"'s turn - pick a space : ";
		cin >> userChoice;
	}while (userChoice < 0 || userChoice > 10 || board[userChoice - 1] == 'O' || board[userChoice -1] == 'X');
	board[userChoice - 1] = player;
}

char* setupGame (){
	char* board = new char[10];
	for (int i = 0; i < 9; i++)
		board[i] = '0' + (i + 1);
	return board;
}

void swap (char& current, char& old){
	char rearrange;
	rearrange = current;
	current = old;
	old = rearrange;
}

int play2PGame (){
	int moves = 1;
	bool winner = false; 
	char* board = setupGame ();
	char player = 'X';
	char lastPlayer = 'O';

	displayBoard (board);
	do {

		getMove (board, player);
		moves++;
		winner = isWinning (board, player);
		swap (player, lastPlayer);
		displayBoard (board);
	} while (moves <= 9 && !(winner));
	if (!winner)
		return 3;
	else if (isEven(moves))
		return 1; 
	else if (isEven (moves - 1))
		return 2;

}