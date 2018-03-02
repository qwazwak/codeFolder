// This program will determine the batting average of a player.
// The number of hits and at bats are set internally in the program.

// Rus Hoffman and Nick Ford

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath> //Needed for things like sqrt()
using namespace std;

const long double AT_BAT = 421;
const long double HITS = 123;

int main(){
	cout << setprecision(3);
	long double batAvg;
	batAvg = HITS / AT_BAT; // an assignment statement 
	cout << "The batting average is " << batAvg << endl; // output the result
	return 0;
}