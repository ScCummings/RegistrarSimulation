/*
a.Scott Cummings
b.2317991
c.scummings@chapman.edu
d.CPSC 350 - Section 1
e.Assignment 4
Summary: Header file for the window class.
*/
#ifndef WINDOW_H
#define WINDOW_H
#include "Student.h"
class Window
{
private:
	bool m_isIdle;
	double m_idleTime;
	Student* m_currentStudent;
public:
	Window();
	~Window();
	bool getIsIdle();
	void setIsIdle(bool isIdle);
	double getIdleTime();
	void setIdleTime(double idleTime);
	Student* getCurrentStudent();
	void setCurrentStudent(Student* currentStudent);
	Student* clearWindow();
};
#endif
