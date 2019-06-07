#ifndef __LinkedList__
#define __LinkedList__

#include "Course.h"

class LinkedList
{
public:
	LinkedList() { head = nullptr; }
	~LinkedList();

	// prints the contents of the list of courses to cout
	void PrintList() const;

	// precondition: list is in sorted order
	// postcondition: newCourse is inserted into the list so the list maintains
	//                sorted order. using recursison.
	void Insert(Course * newCourse);

	// postcondition: size is returned. Must be calculated using recursion.
	int Size() const;

	// calculates the Cumulative GPA of all courses in the list.
	// Cumulative GPA is the sum of all "grade points" divided by the sum of all credits
	// "grade points" is found by multiplying the grade of a course by the number of 
	// credits for that course
	// this must be calculated recursively.
	double CalculateGPA() const;


private:
	Course *head;	// start of linked list

	Course* InsertHelper(Course *head, Course *newCourse); // recursive helper for insert()
	int SizeHelper(Course const *cursor) const; // recursive helper for size()
	void PrintListHelper(Course const *cursor) const; // recursive helper for PrintList()
	void DestructorHelper(Course *cursor); // recursive helper for ~LinkedList()

										   // for help understanding the next two, google how to calulate Cumulative GPA
	double CalculateTotalGradePoints(Course const *cursor) const;	// total of all earned Grade Points in list of courses
	unsigned int CalculateTotalCredits(Course const *cursor) const; // total of all credits in list of courses
};

#endif
