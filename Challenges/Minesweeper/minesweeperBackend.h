/*
	Created by Rus Hoffman
	This should my template, and should change
*/
#if !defined MINESWEEPBACK
	#define MINESWEEPBACK
	#include <cstdint>

	struct sweepSquare{
		bool isKnown = false;
		bool isBomb = false;
		bool isEmpty = true;
		int numBombNear = 0;
		bool isFlag = false;
	};
	/*
		Pre:
		Post:
	*/
	sweepSquare** generateBoard(int_fast64_t ySize, int_fast64_t xSize, int_fast64_t bombCount);

	/*
		Pre:
		Post:
	*/
	void displayBoard(int_fast64_t yGameSize, int_fast64_t xGameSize, sweepSquare** array/*, int_fast64_t userPickingY, int_fast64_t userPickingX*/);

	void knownFlood(int_fast64_t yGameSize, int_fast64_t xGameSize, sweepSquare** array, int_fast64_t ySelectionPosition, int_fast64_t xSelectionPosition);
#endif
