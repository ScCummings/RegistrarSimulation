/*
a.Scott Cummings
b.2317991
c.scummings@chapman.edu
d.CPSC 350 - Section 1
e.Assignment 4
Summary: The implementation of the window class. Contains the logic for each of the Window functions.
*/
#include "Window.h"
#include "Student.h"
#include <typeinfo>
#include <iostream>
using namespace std;
Window::Window()
{
	m_isIdle = true;
	m_idleTime = 0.0;
	m_currentStudent = nullptr;
}
Window::~Window()
{
	//delete m_currentStudent;
	//there is nothing to destruct here, there is no dynamically allocated memory
}
bool Window::getIsIdle()
{
	return m_isIdle;
}
void Window::setIsIdle(bool isIdle)
{
	m_isIdle = isIdle;
}
double Window::getIdleTime()
{
	return m_idleTime;
}
void Window::setIdleTime(double idelTime)
{
	m_idleTime = idelTime;
}
Student* Window::getCurrentStudent()
{
	return m_currentStudent;
}
void Window::setCurrentStudent(Student* currentStudent)
{
	m_isIdle = false;
	m_currentStudent = currentStudent;
}
Student* Window::clearWindow()
{
	Student* temp = m_currentStudent;
	m_currentStudent = nullptr;
	m_isIdle = true;
	return temp;
}
