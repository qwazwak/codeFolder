/*
	Created by Rus Hoffman
	This should my template, and should change
*/
#if !defined MINESWEEPBACK
	#define MINESWEEPBACK
	#include <cstdint>

	struct sweepSquare{
		bool isKnown;
		bool isBomb;
		bool isEmpty;
		int numBombNear;
	};
	/*
		Pre:
		Post:
	*/
	//void displayBoard();
	/*
		Pre:
		Post:
	*/
	sweepSquare** generateBoard(int_fast64_t ySize, int_fast64_t xSize, int_fast64_t bombCount);


	/*
		Pre:
		Post:
	*/
	void displayBoard(int_fast64_t yGameSize, int_fast64_t xGameSize, sweepSquare** array);

#endif
