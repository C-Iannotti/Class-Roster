#include "student.h"
#include "degree.h"
#include "roster.h"

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

//Adds students from data set upon creation
Roster::Roster(const std::vector<std::string>& studentData) {
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	int daysInCourse1;
	int daysInCourse2;
	int daysInCourse3;
	std::string degreeProgramString; //stores string with degree program to compare with valid degree programs
	DegreeProgram degreeProgram;

	int pos1 = 0;  //keeps track of parsing
	int pos2 = 0;
	//parses each string into information for Student object and creates Student object
	for (int i = 0; i < studentData.size(); ++i) {
		pos1 = 0;
		pos2 = studentData.at(i).find(',');
		studentID = studentData.at(i).substr(pos1, studentData.at(i).find(','));

		pos1 = pos2 + 1;
		pos2 = studentData.at(i).find(',', pos1);
		firstName = studentData.at(i).substr(pos1, pos2 - pos1);

		pos1 = pos2 + 1;
		pos2 = studentData.at(i).find(',', pos1);
		lastName = studentData.at(i).substr(pos1, pos2 - pos1);

		pos1 = pos2 + 1;
		pos2 = studentData.at(i).find(',', pos1);
		emailAddress = studentData.at(i).substr(pos1, pos2 - pos1);

		pos1 = pos2 + 1;
		pos2 = studentData.at(i).find(',', pos1);
		age = stoi(studentData.at(i).substr(pos1, pos2 - pos1));

		pos1 = pos2 + 1;
		pos2 = studentData.at(i).find(',', pos1);
		daysInCourse1 = stoi(studentData.at(i).substr(pos1, pos2 - pos1));

		pos1 = pos2 + 1;
		pos2 = studentData.at(i).find(',', pos1);
		daysInCourse2 = stoi(studentData.at(i).substr(pos1, pos2 - pos1));

		pos1 = pos2 + 1;
		pos2 = studentData.at(i).find(',', pos1);
		daysInCourse3 = stoi(studentData.at(i).substr(pos1, pos2 - pos1));

		pos1 = pos2 + 1;
		pos2 = studentData.at(i).find(',', pos1);
		degreeProgramString = studentData.at(i).substr(pos1, pos2 - pos1);

		if (degreeProgramString == "SECURITY") {
			degreeProgram = SECURITY;
		}
		else if (degreeProgramString == "NETWORK") {
			degreeProgram = NETWORK;
		}
		else {
			degreeProgram = SOFTWARE;
		}

		classRosterArray.push_back(new Student(studentID, firstName, lastName, emailAddress,
			age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram));
	}
}

//Adds new student to roster
void Roster::Add(std::string studentID, std::string firstName, std::string lastName,
	std::string emailAddress, int age, int daysInCourse1, int daysInCourse2,
	int daysInCourse3, DegreeProgram degreeProgram) {

	classRosterArray.push_back(new Student(studentID, firstName, lastName, emailAddress, age,
		daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram));
}

//Deletes student from roster
void Roster::Remove(std::string studentID) {
	for (int i = 0; i < classRosterArray.size(); ++i) {
		if (classRosterArray.at(i)->GetStudentID() == studentID) {
			delete classRosterArray.at(i);
			classRosterArray.erase(classRosterArray.begin() + i);
			return;
		}
	}
	std::cout << "Student with ID " << studentID << " not found!" << std::endl;
}

//Prints out all students' information
void Roster::PrintAll() {
	for (int i = 0; i < classRosterArray.size(); ++i) {
		classRosterArray.at(i)->Print();
	}
}

//Prints out average time spent within the three courses for a student
void Roster::PrintAverageDaysInCourse(std::string studentID) {
	std::vector<int> calculateAverageDays;
	int sum = 0;

	for (int i = 0; i < classRosterArray.size(); ++i) {
		if (classRosterArray.at(i)->GetStudentID() == studentID) {
			calculateAverageDays = classRosterArray.at(i)->GetDaysToComplete();
		}
	}

	for (int i = 0; i < calculateAverageDays.size(); ++i) {
		sum += calculateAverageDays.at(i);
	}

	std::cout << "Student " << studentID << " has a average days in course of " 
		<< double(sum) / calculateAverageDays.size() << "." << std::endl;
}

//Prints out all student email address that are invalid
void Roster::PrintInvalidEmails() {
	for (int i = 0; i < classRosterArray.size(); ++i) {
		std::string emailAddress = classRosterArray.at(i)->GetEmailAddress();
		if ((emailAddress.find(' ') != std::string::npos) || (emailAddress.find('@') == std::string::npos)
			|| (emailAddress.find('.') == std::string::npos)) {

			std::cout << emailAddress << std::endl;
		}
	}
}

//Prints out students that are in a certain degree program
void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < classRosterArray.size(); ++i) {
		if (classRosterArray.at(i)->GetDegreeProgram() == degreeProgram) {
			classRosterArray.at(i)->Print();
		}
	}
}

//Destroys each object created to avoid memory leak
Roster::~Roster() {
	while (classRosterArray.size() != 0) {
		delete classRosterArray.at(0);
		classRosterArray.erase(classRosterArray.begin());
	}
}