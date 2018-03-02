//Describe program

// PUT YOUR NAME HERE

//Include any library files needed

using namespace std;

void displayBoard (char* board);
bool isWinning (char* board, char player);
void getMove (char* board, char player);
bool isEven (int digit);
char* setupGame ();
int play2PGame ();
void swap (char& current, char& old);


int main ()
{
	int winner,				// Which player won?
		numPlayers;			// Number of players (1 or 2)

	// Produce a menu mentioning the name of the game etc
	// Ask the user for the number of players
	// If the enter 1, tell them that is not an option yet and exit
	// If they enter 2, then winner = play2PGame();
	// Any other entry should lead to an error message
	// The variable winner will be the player number of the winner
	// 1 is X, 2 is O, 3 is a tie.
	// Let the players know who won...


	//setup the return to terminate the program
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

bool isEven (int digit)
{
	if (digit % 2 == 0)
		return true;
	return false;
}

bool isWinning (char* board, char player)
{
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

void getMove (char* board, char player)
{
	int userChoice;

	do {
		cout << "It is " << player <<"'s turn - pick a space : ";
		cin >> userChoice;
	} while (userChoice < 0 || userChoice > 10 || board[userChoice - 1] == 'O' || board[userChoice -1] == 'X');
	board[userChoice - 1] = player;
}

char* setupGame ()
{
	char* board = new char[10];
	for (int i = 0; i < 9; i++)
		board[i] = '0' + (i + 1);
	return board;
}

void swap (char& current, char& old)
{
	char rearrange;
	rearrange = current;
	current = old;
	old = rearrange;
}

int play2PGame ()
{
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