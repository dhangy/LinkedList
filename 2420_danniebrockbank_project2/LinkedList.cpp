#include "stdafx.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::~LinkedList()
{
	DestructorHelper(head);
}

void LinkedList::PrintList() const {
	
	PrintListHelper(head);
	cout << endl;
}

void LinkedList::PrintListHelper(Course const *cursor) const {
	//define the base case first because recursion
	if (cursor == nullptr) {
		return;
	}
	else {
		cout << "CS" << cursor->courseNumber << " " << cursor->courseName <<" Grade: " << cursor->grade << " Credits: " << cursor->credits << endl;
		PrintListHelper(cursor->next);
	}
}

void LinkedList::Insert(Course *newCourse) {
	head = InsertHelper(head, newCourse);
}

Course * LinkedList::InsertHelper(Course *cursor, Course *newCourse) {
	
	if (cursor == nullptr) {
		newCourse->next = cursor;
		return newCourse;
	}
	
	if (cursor->next == nullptr) {
			cursor->next = newCourse;
			newCourse->next = nullptr;
			return head;
	} 	
	else if (cursor->courseNumber < newCourse->courseNumber &&  newCourse->courseNumber < cursor->next->courseNumber) {
		newCourse->next = cursor->next;
		cursor->next = newCourse;
		return head;
	}
	else if (cursor->courseNumber > newCourse->courseNumber) {
		newCourse->next = cursor;
		return newCourse;
	}
	else {
		return InsertHelper(cursor->next, newCourse);
	}
}

int LinkedList::Size() const {
	return SizeHelper(head);
}

int LinkedList::SizeHelper(Course const *cursor)const {
	if (cursor == nullptr) {
		return 0;
	}
	else {
		return 1 + SizeHelper(cursor->next);
	}
}



void LinkedList::DestructorHelper(Course * cursor) {
	if (cursor == nullptr) {
		return;
	}
	else {
		DestructorHelper(cursor->next);
		delete cursor;
	}
}

double LinkedList::CalculateTotalGradePoints(Course const *cursor) const  {

	if (cursor == nullptr) {
		return 0;
	}

	double gradePoints = cursor->grade * cursor->credits;
	return gradePoints + CalculateTotalGradePoints(cursor->next);
}

unsigned int LinkedList::CalculateTotalCredits(Course const *cursor) const {
	
	if (cursor == nullptr) {
		return 0;
	}
	int creditsAttempted = cursor->credits;
	return creditsAttempted + CalculateTotalCredits(cursor->next);
}

double LinkedList::CalculateGPA() const {
	double gradePoints = CalculateTotalGradePoints(head);
	int creditsAttempted = CalculateTotalCredits(head);

	double GPA = gradePoints / creditsAttempted;
	return GPA;
}
