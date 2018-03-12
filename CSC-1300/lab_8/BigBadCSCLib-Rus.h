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
#if !defined BIGBADCSCLIB_RUS
	#define BIGBADCSCLIB_RUS

	/*
		//function determines...
		//Precondition: What MUST BE DONE BEFOREHAND
		//postconditions: what will happen as outputs
		bool foo(int bar, double baz);
	*/
	
	
	// findAverage
		// task: This function receives an array of integers and its size.
		// It finds and returns the average of the numbers in the array
		// precondition : array of floating point numbers
		// postcondition : average of the numbers in the array
	float findAverage(const int[], long int); // finds average of all grades
	
	
	// findHighest
		// task: This function receives an array of integers and its size.
		// It finds and returns the highest value of the numbers in the array
		// precondition : array of floating point numbers
		// postcondition : highest value of the numbers in the array
	long int findHighest(const long int[], long int); // finds highest of all grades
	
	
	//findLowest
		//task: This function receives an array of integers and its size.
		//It finds and returns the lowest value of the numbers in the array
		//precondition : array of floating point numbers
		//postcondition : lowest value of the numbers in the array
	long int findLowest(const long int[], long int); // finds lowest of all grades
#endif