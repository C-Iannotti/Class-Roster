#include "degree.h"
#include "student.h"
#include "roster.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	cout << "Course: Scripting and Programming - Applications" << endl;
	cout << "Language used: C++" << endl;
	cout << "WGU Student ID: 001363048" << endl;
	cout << "Name: Conner Iannotti" << endl << endl;

	const string studentDataArray[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Conner,Iannotti,conneriannotti@outlook.com,18,11,19,17,SOFTWARE" }; //Data for project

	vector<string> studentDataVector;  //converting an array to a vector to have more functions readily available and protection from calling out of index
	studentDataVector.push_back(studentDataArray[0]);
	studentDataVector.push_back(studentDataArray[1]);
	studentDataVector.push_back(studentDataArray[2]);
	studentDataVector.push_back(studentDataArray[3]);
	studentDataVector.push_back(studentDataArray[4]);

	Roster classRoster(studentDataVector);

	classRoster.PrintAll();
	cout << endl;

	classRoster.PrintInvalidEmails();
	cout << endl;

	for (int i = 0; i < classRoster.classRosterArray.size(); ++i) {
		classRoster.PrintAverageDaysInCourse(classRoster.classRosterArray.at(i)->GetStudentID());
	}
	cout << endl;

	classRoster.PrintByDegreeProgram(SOFTWARE);
	cout << endl;

	classRoster.Remove("A3");
	classRoster.PrintAll();
	cout << endl;

	classRoster.Remove("A3");
	return 0;
}