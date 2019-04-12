/*
a.Scott Cummings
b.2317991
c.scummings@chapman.edu
d.CPSC 350 - Section 1
e.Assignment 4
Summary: Implementation for the student class. Contains all the logic for the student functions.
*/
#include "Student.h"
#include <iostream>
using namespace std;
Student::Student()
{
	m_waitTime = 0;
	m_isWaiting = false;
	m_timeRequired = 0;
	m_timeWaited = 0;
	m_timeAtWindow = 0;
}
/*
a. Student(double required)
b. @return - int
c. @param - none
d. no exceptions thrown
*/
Student::Student(double timeRequired)
{
	m_waitTime = 0;
	m_isWaiting = false;
	m_timeRequired = timeRequired;
	m_timeWaited = 0;
	m_timeAtWindow = 0;
}
Student::~Student()
{
	//nothing happens here, no dynamically allocated memory
}
double Student::getWaitTime()
{
	return m_waitTime;
}
void Student::setWaitTime(double waitTime)
{
	m_waitTime = waitTime;
}
bool Student::getIsWaiting()
{
	return m_isWaiting;
}
void Student::setIsWaiting(bool isWaiting)
{
	m_isWaiting = isWaiting;
}
double Student::getTimeRequired()
{
	return m_timeRequired;
}
void Student::setTimeRequired(double timeRequired)
{
	m_timeRequired = timeRequired;
}
int Student::getTimeWaited()
{
	return m_timeWaited;
}
void Student::setTimeWaited(int timeWaited)
{
	m_timeWaited = timeWaited;
}
int Student::getTimeAtWindow()
{
	return m_timeAtWindow;
}
void Student::setTimeAtWindow(int timeAtWindow)
{
	m_timeAtWindow = timeAtWindow;
}
