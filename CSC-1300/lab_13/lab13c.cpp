/*
	CSC 1300 lab 13c, takes in statistics for an airport, then displays some more
	By Rus Hoffman
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main (){
	const long NUM_OF_MONTHS = 12;
	const string MONTHTEXT[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	struct statsType {
		long landCount;
		long departCount;
		long mostLand;
		long leastLand;
	};
	double averageLanding = 0;
	double averageDepart = 0;
	long totalPlanes = 0;
	long mostLandingMonth = 0;
	long mostLandingCount;
	long leastLandingMonth = 0;
	long leastLandingCount;
	statsType* portBase = new statsType[NUM_OF_MONTHS];
	for (long index = 0; index < NUM_OF_MONTHS; index++) {
		do{
			cout << "Enter the number of planes that landed in " << MONTHTEXT[index%NUM_OF_MONTHS] << ": ";
			cin >> portBase[index].landCount;
			cin.clear();
			cin.ignore();
		}while(cin.fail() || portBase[index].landCount < 0);

		do{
			cout << "Enter the number of planes that departed in " << MONTHTEXT[index%NUM_OF_MONTHS] << ": ";
			cin >> portBase[index].departCount;
			cin.clear();
			cin.ignore();
		}while(cin.fail() || portBase[index].departCount < 0);
		do{
			do{
				cout << "Enter the number of most number of planes departed in a single day in " << MONTHTEXT[index%NUM_OF_MONTHS] << ": ";
				cin >> portBase[index].mostLand;
				cin.clear();
				cin.ignore();
			}while(cin.fail() || portBase[index].mostLand < 0 || portBase[index].mostLand < portBase[index%NUM_OF_MONTHS].landCount);

			do{
				cout << "Enter the number of least number of planes departed in a single day in " << MONTHTEXT[index%NUM_OF_MONTHS] << ": ";
				cin >> portBase[index].leastLand;
				cin.clear();
				cin.ignore();
			}while(cin.fail() || portBase[index].leastLand < 0 || portBase[index].leastLand > portBase[index].landCount);
		}while(portBase[index].leastLand > portBase[index].mostLand);
		cout << endl << endl << endl;
	}
	mostLandingCount = portBase[0].mostLand;
	leastLandingCount = portBase[0].leastLand;
	for (long i = 0; i < NUM_OF_MONTHS; i++) {
		if (portBase[i].mostLand > mostLandingCount) {
			mostLandingCount = portBase[i].mostLand;
			mostLandingMonth = i;
		}
		if (portBase[i].leastLand < leastLandingCount) {
			leastLandingCount = portBase[i].mostLand;
			leastLandingMonth = i;
		}
		totalPlanes = totalPlanes + portBase[i].landCount + portBase[i].departCount;
		averageLanding = averageLanding + portBase[i].landCount;
		averageDepart = averageDepart + portBase[i].departCount;
	}
	averageLanding = averageLanding / static_cast<float>(NUM_OF_MONTHS);
	averageDepart = averageDepart / static_cast<float>(NUM_OF_MONTHS);
	cout << endl << endl << endl << endl << endl << endl;
	cout << "Average monthly landing planes:    " << averageLanding << endl;
	cout << "Average monthly departinng planes: " << averageDepart << endl;
	cout << "Total number of landing and departinng planes: " << totalPlanes << endl;
	cout << "The most number of landing planes was on a single day was " << mostLandingCount << ",  in the month of "<< MONTHTEXT[mostLandingMonth%NUM_OF_MONTHS] << endl;
	cout << "The least number of landing planes was on a single day was " << leastLandingCount << ",  in the month of "<< MONTHTEXT[leastLandingMonth%NUM_OF_MONTHS] << endl;
	return 0;
}
