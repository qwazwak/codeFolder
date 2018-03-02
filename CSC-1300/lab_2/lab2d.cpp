// This program will output area and perimeter of a rectangle

//Rus Hoffman

#include <iostream>
using namespace std;


long double WIDTH = 3;
long double LENGTH = 8;
long double perm;
long double area;
int main()
{
	perm = WIDTH + WIDTH + LENGTH +LENGTH;// computes perimeter;

	area = WIDTH * LENGTH;// computes area;

	//output perimeter and area:
	cout << "The perimeter of the rectangle is: " << perm << endl;
	cout << "The area of the rectangle is: " << area << endl;
	return 0;

}