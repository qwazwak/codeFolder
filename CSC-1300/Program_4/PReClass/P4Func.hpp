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
	class classDatabase;
	struct studentArrayShell{
		long testCount;
		double* testAvg;
		long studentCount;
		long studentCapacity;
		student* students = NULL;
	};
	struct student {
		string name;
		char* nameCString;
		long* grade = NULL;
		double average;
	};
	class classDatabase {
		protected:
			long longestNameID;
			long longestNameSize;

			long testCount;
			double* testAverage = NULL;
			long studentCount;
			long studentCapacity;
			student* studentArray = NULL;
		private:
			void setupVal (long numTests);
			void updateInternals (void);
			void addStudent (student inputStudent);

			student getStudent (long studentID);
			double getTestAverage (long testID);


			~classDatabase(){
				delete[] testAverage;

				for (long i = 0; i < testCount; i++) {
					delete[] studentArray[i].grade;
					delete[] studentArray[i].nameCString;
				}

				delete[] studentArray;
				//Delete dynamic variables
			}
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
