// Rus Hoffman and Nick Ford

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


const float stylePrice_AmericanColonial = 85.00;
const float stylePrice_Modern = 57.50;
const float stylePrice_FrenchClassical = 127.75;

int main(){
	
	int styleSoldCount_AmericanColonial = 0;
	int styleSoldCount_Modern = 0;
	int styleSoldCount_FrenchClassical = 0;
	float styleNetSale_AmericanColonial = 0;
	float styleNetSale_Modern = 0;
	float styleNetSale_FrenchClassical = 0;
	float trueNetSale = 0;
	
	
	cout << setprecision(2) << fixed << showpoint;
	

	
	cout << "Please input the number of American Colonial chairs sold" << endl;
	cin >> 	styleSoldCount_AmericanColonial;
	cout << "Please input the number of Modern chairs sold" << endl;
	cin >> 	styleSoldCount_Modern;
	cout << "Please input the number of French Classical chairs sold" << endl;
	cin >> 	styleSoldCount_FrenchClassical;
	
	styleNetSale_AmericanColonial = stylePrice_AmericanColonial * styleSoldCount_AmericanColonial;
	styleNetSale_Modern = stylePrice_Modern * styleSoldCount_Modern;
	styleNetSale_FrenchClassical = stylePrice_FrenchClassical * styleSoldCount_FrenchClassical;
	trueNetSale = styleNetSale_AmericanColonial + styleNetSale_Modern + styleNetSale_FrenchClassical;
	
	
	cout << "The total sales of American Colonial chairs : $" << styleNetSale_AmericanColonial << endl;
	cout << "The total sales of Modern chairs : $" << styleNetSale_Modern << endl;
	cout << "The total sales of French Classical chairs : $" << styleNetSale_FrenchClassical << endl;
	cout << "The total sales of all chairs : $" << trueNetSale << endl;
	
	
	return 0;
}