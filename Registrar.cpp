/*
a.Scott Cummings
b.2317991
c.scummings@chapman.edu
d.CPSC 350 - Section 1
e.Assignment 4
Summary: Implementation for the registrar class. Contains all the logic for the registrar functions.
*/
#include "Registrar.h"
#include "Student.h"
#include "Window.h"
#include "GenQueue.h"
/*
a. Registrar() - Registrar constructor
b. @return - NA
c. @param - none
d. no exceptions thrown
*/
Registrar::Registrar()
{
	//default constructor shouldn't be called
}
/*
a. Registrar(int numStudents, int numWindowsOpen, GenQueue<Students>* studentQueue, Window** myWindows)
b. @return - NA
c. @param - int numStudents - number of students in the registrar - int numWindowsOpen - number of windows open at the registrar - GenQueue<Students>* studentQueue - Queue of students who came to the registrar - Window** myWindows - collection of windows
d. no exceptions thrown
*/
Registrar::Registrar(int numStudents, int numWindowsOpen, GenQueue<Student> *studentsQueue, Window** myWindows)
{
	m_numStudents = numStudents;
	m_numWindowsOpen = numWindowsOpen;
	m_studentsQueue = studentsQueue;
	m_myWindows = myWindows;
}
/*
a. ~Registrar - Registrar destructor
b. @return - NA
c. @param - none
d. no exceptions thrown
*/
Registrar::~Registrar()
{
	//nothing needs to happen here
}
/*
a. getNumStudents()
b. @return - int of the number of student
c. @param - none
d. no exceptions thrown
*/
int Registrar::getNumStudents()
{
	return m_numStudents;
}
/*
a. setNumStudents()
b. @return - void
c. @param - int that represents the number of students
d. no exceptions thrown
*/
void Registrar::setNumStudents(int numStudents)
{
	m_numStudents = numStudents;
}
/*
a. getNumWindowsOpen
b. @return - int of the number of windows open
c. @param - none
d. no exceptions thrown
*/
int Registrar::getNumWindowsOpen()
{
	return m_numWindowsOpen;
}
/*
a. setNumWindowsOpen
b. @return - void
c. @param - int of the number of windows open
d. no exceptions thrown
*/
void Registrar::setNumWindowsOpen(int numWindowsOpen)
{
	m_numWindowsOpen = numWindowsOpen;
}
/*
a. getStudentsQueue
b. @return - pointer to a queue
c. @param - none
d. no exceptions thrown
*/
GenQueue<Student>* Registrar::getStudentsQueue()
{
	return m_studentsQueue;
}
/*
a. setStudentsQueue
b. @return - void
c. @param - pointer to the student's queue
d. no exceptions thrown
*/
void Registrar::setStudentsQueue(GenQueue<Student>* studentsQueue)
{
	m_studentsQueue = studentsQueue;
}
/*
a. getMyWindows
b. @return - window** (collection of windows)
c. @param - none
d. no exceptions thrown
*/
Window** Registrar::getMyWindows()
{
	return m_myWindows;
}
/*
a. setMyWindows
b. @return - void
c. @param - Window** - collection of windows
d. no exceptions thrown
*/
void Registrar::setMyWindows(Window** myWindows)
{
	m_myWindows = myWindows;
}
