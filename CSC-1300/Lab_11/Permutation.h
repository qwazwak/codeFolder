/*
	Created by Rus Hoffman and James Bigler
	permuation selector for card drawer for lab 11
*/
#if !defined PERMUTE
	#define PERMUTE

	// Creates a dynamic array of size n, initializes it with the correct values and returns the array to the user
	long* initPermuation (long n);

	// Receives the currect card array and the size of the array, returns the next "card"
	//Deck size is passed as a reference variable so it can be modified
	long nextPermutation (long* cardsToDrawFrom, long& cardsToDrawFromSize);
#endif
