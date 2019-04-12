/*
a.Scott Cummings
b.2317991
c.scummings@chapman.edu
d.CPSC 350 - Section 1
e.Assignment 4
Summary: Header file for the student class.
*/
#ifndef STUDENT_H
#define STUDENT_H
class Student
{
private:
	double m_waitTime;
	bool m_isWaiting;
	double m_timeRequired;
	int m_timeWaited;
	int m_timeAtWindow;
public:
	Student();
	Student(double timeRequired);
	~Student();
	double getWaitTime();
	void setWaitTime(double waitTime);
	bool getIsWaiting();
	void setIsWaiting(bool isWaiting);
	double getTimeRequired();
	void setTimeRequired(double timeRequired);
	int getTimeWaited();
	void setTimeWaited(int timeWaited);
	int getTimeAtWindow();
	void setTimeAtWindow(int timeAtWindow);
};
#endif
