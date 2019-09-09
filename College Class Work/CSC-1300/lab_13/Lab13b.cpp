// This program demonstrates how to use an array of structures
// Created by Rus Hoffman
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	struct taxPayer {
		float taxRate;
		float income;
		float taxes;
	};
	const long NUMCITZ = 5;
	taxPayer* citizen = new taxPayer[NUMCITZ];
	cout << fixed << showpoint << setprecision(2);
	cout << "Please enter the annual income and tax rate for 5 tax payers: ";
	cout << endl << endl;
	for(long count = 0; count < 5; count++){
		cout << "Enter this year's income for tax payer " << count + 1 << ": ";
		cin >> citizen[count].income;
		while(cin.fail() || citizen[count].income <= 0){
			cin.clear();
			cin.ignore();
			cout << "Enter this year's income for tax payer " << count + 1 << ": ";
			cin >> citizen[count].income;
		}
		
		cout << "(note: tax rate is in a decimal form. IE: enter '.32' not '32')" << endl;
		cout << "Enter the tax rate for tax payer # " << count + 1 << ": ";
		cin >> citizen[count].taxRate;
		while(cin.fail() || citizen[count].taxRate < 0 || citizen[count].taxRate > 1){
			cin.clear();
			cin.ignore();
			cout << "(note: tax rate is in a decimal form. IE: enter '.32' not '32')" << endl;
			cout << "Enter the tax rate for tax payer # " << count + 1 << ": ";
			cin >> citizen[count].taxRate;
		}
		cout << endl;
		citizen[count].taxes = citizen[count].taxRate * citizen[count].income;
	}
	cout << "Taxes due for this year: " << endl << endl;
	for (long i = 0; i < NUMCITZ; i++) {
		cout << "  Tax Payer # " << (i + 1) << ": " << "$ "<< citizen[i].taxes << endl;
	}
	delete[] citizen;
	return 0;
}
