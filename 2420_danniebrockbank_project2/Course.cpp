#include "stdafx.h"
#include "Course.h"



Course::Course(int courseNumber, std::string courseName, unsigned int credits, double grade) {

	this->courseNumber = courseNumber;
	this->courseName = courseName;
	this->credits = credits;
	this->grade = grade;

}

