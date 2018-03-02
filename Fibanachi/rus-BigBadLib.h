/*
HEADER FILE- This is just declaring or prototyping functions and telling people hwo to use it
To use Rus's Big Bad Library:
	Include it with #include "rus-BigBadLib.h"
	and when LINKING make sure that this header and the rus_BigBadLib.o are in the same directory as your file, and link them IE: g++ -o myprogram.exe mypProgram.o rus-BigBadLib.o
	
Comment GALORE!




DEFINES - If you have a program that needs certain specific functions that are usually skipped use a define
example: for a tictactoe program make sure to have #define TicTacToe
*/
//Include gaurd - If this pseudolibrary is already defined, dont add it again
#if !defined RUS_BIGBADLIB
	#define RUS_BIGBADLIB

	/*
		//function determines...
		//Precondition: What MUST BE DONE BEFOREHAND
		//postconditions: what will happen as outputs
		bool foo(int bar, double baz);
	*/
	
	//Pre: Assumes lines is a reasonable positive integer 
	//Post: Will output N number of lines to the command terminal. WIll do some minor optimization 
	void clearScreen(int long lines);
	//Pre: Assumes input is a reasonable positive integer 
	//Post: if input is even, will return true, if odd will return false
	bool isEven(int input);
	//Pre: Assumes input is a reasonable positive integer 
	//Post: if input is odd, will return true, if even will return false
	bool isOdd(int input);
	
	
	//Tic Tac Toe Section:
	#ifdef TicTacToe
		void updateHistory(int numGamesPlayed, int numWinsX, int numWinsO, int numTies);
		//IDS: 4-Games played, 3-X wins, 2-O wins, 1-ties
		//Reads TTTStats.txt 
		int getHistory(int statID);
		
		void displayBoard(char* board);
		bool isWinning (char* board, char player);
		void getMove (char* board, char player);
		char* setupGame();
		void swap (char& current, char& old);
		int evaluate (char* board, int player);
		int play1PGame ();
		int play2PGame();
	#endif
#endif