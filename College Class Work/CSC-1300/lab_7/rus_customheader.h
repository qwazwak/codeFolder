//HEADER FILE
//File is called rus_customheader.h
//Comment GALORE!
//JUST DECLARING FUNCTION
//Include gaurd
#if !defined rus_customheader.h
	#define rus_customheader.h

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
#endif