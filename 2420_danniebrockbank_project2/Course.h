#ifndef __Course__
#define __Course__

#include <string>

class Course
{
public:
	// parameterized constructor
	Course(int courseNumber, std::string courseName, unsigned int credits, double grade);

	// next Course in the linked list
	Course *next;

	unsigned int courseNumber;	// ie: 1400, 1410, 2420, etc...
	std::string courseName;
	unsigned int credits;		// 0 - 4
	double grade;				// 0.0 - 4.0
};

#endif