#pragma once

#include "degree.h"
#include "student.h"

#include <vector>
#include <string>

class Roster {
public:
	Roster(const std::vector<std::string>& studentData);
	void Add(std::string studentID, std::string firstName, std::string lastName,
		std::string emailAddress, int age, int daysInCourse1, int daysInCourse2,
		int daysInCourse3, DegreeProgram degreeProgram);
	void Remove(std::string studentID);
	void PrintAll();
	void PrintAverageDaysInCourse(std::string studentID);
	void PrintInvalidEmails();
	void PrintByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();

	std::vector<Student*> classRosterArray;
};