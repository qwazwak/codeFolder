// This program demonstrates the use of pointer variables
// It finds the area of a rectangle given length and width
// It prints the length and width in ascending order
// By Rus Hoffman &

#include <iostream>
using namespace std;

int main(){
	int length; // holds length
	int width; // holds width
	int area; // holds area
	int *lengthPtr = NULL; // int pointer which will be set to point to length
	int *widthPtr = NULL; // int pointer which will be set to point to width
	do{
		cout << "Please input the length of the rectangle" << endl;
		cin >> length;
		cin.clear();
		cin.ignore();
	}while(cin.fail() || length <= 0);
	do{
		cout << "Please input the width of the rectangle" << endl;
		cin >> width;
		cin.clear();
		cin.ignore();
	}while(cin.fail() || width <= 0);

	// Fill in code to make lengthPtr point to length (hold its address)
	lengthPtr = &length;
	// Fill in code to make widthPtr point to width (hold its address)
	widthPtr = &width;

	area = (*widthPtr) * (*lengthPtr);// Fill in code to find the area by using only the pointer variables

	cout << "The area is " << area << endl;
	if(*lengthPtr > *widthPtr){// Fill in the condition length > width by using only the pointer variables)
		cout << "The length is greater than the width" << endl;
	}
	else if (*lengthPtr < *widthPtr){
		cout << "The width is greater than the length" << endl;
	}
	else{
		cout << "The width and length are the same" << endl;
	}
	return 0;
}
