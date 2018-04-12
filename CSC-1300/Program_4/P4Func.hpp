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
	struct student {
		string name;
		double* grades = NULL;
	};


	class studentArrayShell{
		long numTests;
		long numOfStudents;
		long numOfPossible;
		student* studentsArr = NULL;
		double* gradeAvg = NULL;

		void expandArray(){
			student* newArray = new student[numOfPossible * 2];
			for (long i = 0; i < numOfPossible; i++) {
				newArray[i] = studentsArr[i];
			}
			studentsArr = newArray;
			delete[] newArray;
		}
		void updateAverage(){
			delete[] gradeAvg;
			double sumHolder[numTests];
			for (long x = 0; x < numTests; x++) {
				sumHolder[x] = 0;
			}
			for (long j = 0; j < numTests; j++) {
				for (long i = 0; i < numOfStudents; i++) {
					sumHolder[j] = sumHolder[j] + studentsArr[i].grades[j];
				}
			}
			gradeAvg = new double[numTests];
			for (long i = 0; i < numTests; i++) {
				gradeAvg[i] = (sumHolder[i] / static_cast<double>(numTests));
			}
		}

		public:
			void initializeValues(){
				numOfStudents = 0;
				numOfPossible = 1;
				studentsArr = new student[1];
			}
			void addStudent (string name, double* inputGrades) {
				if (numOfStudents >= numOfPossible) {
					expandArray();
					}
				studentsArr[numOfStudents].name = name;
				for (long i = 0; i < numTests; i++) {
					studentsArr[numOfStudents].grades[i] = inputGrades[i];
				}
				numOfStudents++;
			}
			void applyCurve(long testID, double curveVal){
				updateAverage();
				if((curveVal - gradeAvg[testID]) >= 0){
					for (long i = 0; i < numOfStudents; i++) {
						studentsArr[i].grades[testID] = studentsArr[i].grades[testID] + (curveVal - gradeAvg[testID]);
					}
				}
			}

	};


	/*
		Pre:
		Post:
	*/
	void function();

#endif
