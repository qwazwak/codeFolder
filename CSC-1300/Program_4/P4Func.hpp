/*
	Created by Rus Hoffman
	This should my template, and should change
*/
#if !defined GRADINGFUNC
	#define GRADINGFUNC

	#include <string>
	using namespace std;
	struct student;
	class studentArrayShell;

	struct studentArrayShell{
		long testCount;
		long* testAvg;
		long studentCountMaxID;
		//long studentCapacity;
		student* students = NULL;
	};
	struct student {
		string name;
		long* grade = NULL;
	};

	void setupValues(studentArrayShell& inputShell);
	void expandStudentHolderArray(studentArrayShell& dataShell);
	void updateAverage(studentArrayShell& dataShell);
	void addStudent(studentArrayShell& dataShell, student inputToAdd);
	void applyCurve(studentArrayShell& dataShell, long testID, double curveVal);

	/*
		Pre:
		Post:
	*/
	void function();

#endif
