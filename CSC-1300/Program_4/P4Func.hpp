/*
	Program 4: Modified Gradebook

	class header file

	Created by Rus Hoffman
*/
#if !defined GRADINGFUNC
	#define GRADINGFUNC

	#include <string>
	using namespace std;

	struct student {
		string name;
		double* grade = NULL;
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
		public:
			long getLongNameSize (void);
			void setupVal (long numTests);
			void updateInternals (void);
			void addStudent (student inputStudent);

			long getTestCount(void);
			long getStudentCount(void);
			void curveGrades (long curveVal, long testID);


			student getStudent (long studentID);
			string getName(long studentID);
			double getStudentGrade(long studentID, long testID);
			double getStudentAverage(long studentID);
			double getClassTestAverage (long testID);


			~ classDatabase(){
				delete[] testAverage;

				for (long i = 0; i < studentCount; i++) {
					delete[] studentArray[i].grade;
					//delete[] studentArray[i].nameCString;
				}

				delete[] studentArray;
				//Delete dynamic variables
			}
	};


#endif
