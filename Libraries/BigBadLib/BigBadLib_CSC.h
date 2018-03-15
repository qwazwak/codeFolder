/*
HEADER FILE- This is just declaring or prototyping functions and telling people how to use it
To use Rus's Big Bad Library:
	Include it with #include "BigBadCSCLib-Rus.h"
	and when LINKING make sure that this header and the BigBadCSCLib-Rus.o are in the same directory as your file, and link them IE: g++ -o myprogram.exe mypProgram.o BigBadCSCLib-Rus.o
	
Comment GALORE!




DEFINES - If you have a program that needs certain specific functions that are usually skipped use a define
example: for a tictactoe program make sure to have #define TicTacToe
*/
//Include gaurd - If this pseudolibrary is already defined, dont add it again
#if !defined BIGBADLIB_CSC
	#define BIGBADLIB_CSC

	/*
		//function determines...
		//Precondition: What MUST BE DONE BEFOREHAND
		//postconditions: what will happen as outputs
		bool foo(int bar, double baz);
	*/
	
	void mclearScreen(unsigned int long lines = 10);
	
	
	//End My handy code, this is now class code
	
	
	
	// findAverage
		// task: This function receives an array of integers and its size.
		// It finds and returns the average of the numbers in the array
		// precondition : array of floating point numbers
		// postcondition : average of the numbers in the array
	float findAverage(const int[], int); // finds average of all grades
	
	
	// findHighest
		// task: This function receives an array of integers and its size.
		// It finds and returns the highest value of the numbers in the array
		// precondition : array of floating point numbers
		// postcondition : highest value of the numbers in the array
	int findHighest(const int[], int); // finds highest of all grades
	
	
	//findLowest
		//task: This function receives an array of integers and its size.
		//It finds and returns the lowest value of the numbers in the array
		//precondition : array of floating point numbers
		//postcondition : lowest value of the numbers in the array
	int findLowest(const int[], int); // finds lowest of all grades
	
	
	// getPrices
		// task: This procedure asks the user to input the number of rows and
		// columns. It then asks the user to input (rows * columns) number of
		// prices. The data is placed in the array.
		// Precondition : none
		// Postcondition : an array filled with numbers and the number of rows
		// and columns used.
	void getPrices(double [MAXROWS][MAXCOLS], int&, int&);
	
	
	// printPrices
		// task: This procedure prints the table of prices
		// Precondition : an array of floating point numbers and the number of rows
		// and columns used.
		// Postcondition : none
	void printPrices(const double [MAXROWS][MAXCOLS], int, int);
#endif