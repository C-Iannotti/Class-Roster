#include "degree.h"
#include "student.h"

#include <string>
#include <vector>
#include <iostream>

Student::Student(std::string studentID, std::string firstName, std::string lastName,
	std::string emailAddress, int age, int daysInCourse1, int daysInCourse2,
	int daysInCourse3, DegreeProgram degreeProgram) : daysToComplete(3, 0) {

	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	daysToComplete.at(0) = daysInCourse1;
	daysToComplete.at(1) = daysInCourse2;
	daysToComplete.at(2) = daysInCourse3;
	this->degreeProgram = degreeProgram;
}

//Takes an entered string and assigns it to the student's studentID
void Student::SetStudentID(std::string userString) {
	studentID = userString;
}

//returns student's studentID
std::string Student::GetStudentID() {
	return studentID;
}

//takes an entered integer and assigns it to the student's age
void Student::SetAge(int userInt) {
	age = userInt;
}

//returns student's age
int Student::GetAge() {
	return age;
}

//takes an entered string and assigns it to the student's first name
void Student::SetFirstName(std::string userString) {
	firstName = userString;
}

//returns the student's first name
std::string Student::GetFirstName() {
	return firstName;
}

//takes an entered string and assigns it to the student's last name
void Student::SetLastName(std::string userString) {
	lastName = userString;
}

//returns the student's last name
std::string Student::GetLastName() {
	return lastName;
}

//takes an entered string and assigns it to the student's email address
void Student::SetEmailAddress(std::string userString) {
	emailAddress = userString;
}

//returns the student's email address
std::string Student::GetEmailAddress() {
	return emailAddress;
}

//takes 3 entered integers and assigns them to a list of says it took the student to complete three courses
void Student::SetDaysToComplete(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
	daysToComplete.at(0) = daysInCourse1;
	daysToComplete.at(1) = daysInCourse2;
	daysToComplete.at(2) = daysInCourse3;
}

//returns a list of days to complete three courses
std::vector<int> Student::GetDaysToComplete() {
	return daysToComplete;
}

//takes entered degree program and stores it for the student
void Student::SetDegreeProgram(DegreeProgram userDegreeProgram) {
	degreeProgram = userDegreeProgram;
}

//returns student's degree program
DegreeProgram Student::GetDegreeProgram() {
	return degreeProgram;
}

//prints information for the student
void Student::Print() {
	std::cout << studentID << "\tFirst Name: " << firstName << "\tLast Name: " << lastName << "\tAge: " << age
		<< "\tdaysInCourse: " << "{" << daysToComplete.at(0) << ", " << daysToComplete.at(1) << ", " << daysToComplete.at(2)
		<< "}\tDegree Program: " << degreeProgram << std::endl;
}