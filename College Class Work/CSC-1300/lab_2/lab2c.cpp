// This program will output circumference and area
// of the circle with a given radius

//Rus Hoffman

#include <iostream>
using namespace std;

const double PI = 3.14;
const double RADIUS = 5.4;
long double area;
long double circumference;

int main()
{

	//_______________ area 				// definition of area of a circle

	//float circumference;				// definition of circumference

	circumference = 2 * PI * RADIUS;// computes circumference;

	area = PI * RADIUS * RADIUS;// computes area;

	// Fill in the code for the cout statement that will output (with description)
	// the circumference
	cout << "The circumference of the circle is: " << circumference << endl;

	// Fill in the code for the cout statement that will output (with description)
	// the area of the circle
	cout << "The area of the circle is: " << area << endl;
	return 0;

}