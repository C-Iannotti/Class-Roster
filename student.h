#pragma once

#include "degree.h"

#include <string>
#include <vector>

class Student {
public:
	Student(std::string studentID, std::string firstName, std::string lastName,
		std::string emailAddress, int age, int daysInCourse1, int daysInCourse2,
		int daysInCourse3, DegreeProgram degreeProgram);
	void SetStudentID(std::string userInt);
	std::string GetStudentID();
	void SetAge(int userInt);
	int GetAge();
	void SetFirstName(std::string userString);
	std::string GetFirstName();
	void SetLastName(std::string userString);
	std::string GetLastName();
	void SetEmailAddress(std::string userString);
	std::string GetEmailAddress();
	void SetDaysToComplete(int daysInCourse1, int daysInCourse2, int daysInCourse3);
	std::vector<int> GetDaysToComplete();
	void SetDegreeProgram(DegreeProgram userDegreeProgram);
	DegreeProgram GetDegreeProgram();
	void Print();
private:
	std::string studentID;
	int age;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	std::vector<int> daysToComplete; // Holds list of days it takes for the student to complete courses (3 in program)
	DegreeProgram degreeProgram;
};