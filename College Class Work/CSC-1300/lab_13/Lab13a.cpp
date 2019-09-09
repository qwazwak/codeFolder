// This program uses a structure to hold data about a rectangle, created by Rus Hoffman
#include <iostream>
#include <iomanip>
int main(){
	struct rectangle {
		double length, width, perimiter, area;
	} box;
	std::cout << "Enter the length of a rectangle: ";
	std::cin >> box.length;
	while(std::cin.fail() || box.length <= 0){
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Enter the length of a rectangle: ";
		std::cin >> box.length;
	}
	std::cout << "Enter the width of a rectangle: ";
	std::cin >> box.width;
	while(std::cin.fail() || box.width <= 0){
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Enter the width of a rectangle: ";
		std::cin >> box.width;
	}
	box.area = box.width * box.length;
	box.perimiter = (2 * box.width) + (2 * box.length);
	std::cout << std::endl << std::endl << std::fixed << std::showpoint << std::setprecision(2) << "Rectangle area: " << box.area << std::endl << "Rectangle perimiter: " << box.perimiter << std::endl;
	return 0;
}
