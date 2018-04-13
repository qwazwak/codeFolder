/*
	Created by Rus Hoffman
	This should my template, and should change
*/
#if !defined GRADINGFUNC
	#define GRADINGFUNC

	#include <string>
	using namespace std;

	struct student;
	struct studentArrayShell;

	struct studentArrayShell{
		long testCount;
		double* testAvg;
		long studentCount;
		long studentCapacity;
		student* students = NULL;
	};
	struct student {
		string name;
		long* grade = NULL;
		double average;
	};

	//void setupValues(studentArrayShell& inputShell);
	void expandStudentArray(studentArrayShell& inputBase);
	//void updateStats(studentArrayShell& dataShell);
	//void addStudent(studentArrayShell& dataShell, student inputToAdd);
	//void applyCurve(studentArrayShell& dataShell, long testID, double curveVal);

	/*
		Pre:
		Post:
	*/
	void function();

#endif
