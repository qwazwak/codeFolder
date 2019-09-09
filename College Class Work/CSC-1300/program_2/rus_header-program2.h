//HEADER FILE
//File is called rus_program-2-header.h
//Comment GALORE!
//JUST DECLARING FUNCTION
//Include gaurd
#if !defined RUS_HEADER_WTB
	#define RUS_HEADER_WTB
	
	//Pre: Assumes lines is a reasonable positive integer 
	//Post: Will output N number of lines to the command terminal. WIll do some minor optimization 
	void clearScreen(int long lines);
	//Pre: Assumes input is a reasonable positive integer 
	//Post: if input is even, will return true, if odd will return false
	bool isEven(int input);
	//Pre: Assumes input is a reasonable positive integer 
	//Post: if input is odd, will return true, if even will return false
	bool isOdd(int input);
	
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