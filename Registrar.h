/*
a.Scott Cummings
b.2317991
c.scummings@chapman.edu
d.CPSC 350 - Section 1
e.Assignment 4
Summary: Header file for the registrar class.
*/
//Registrar class
//contains the queue of students and the linked list of windows
#ifndef REGISTRAR_H
#define REGISTRAR_H
#include "Student.h"
#include "Window.h"
#include "GenQueue.h"
class Registrar
{
private:
	int m_numStudents;
	int m_numWindowsOpen;
	GenQueue<Student>* m_studentsQueue;
	Window** m_myWindows;
public:
	Registrar();
	Registrar(int numStudents, int numWindowsOpen, GenQueue<Student>* m_studentsQueue, Window** myWindows);
	~Registrar();
	int getNumStudents();
	void setNumStudents(int numStudents);
	int getNumWindowsOpen();
	void setNumWindowsOpen(int numWindowsOpen);
	GenQueue<Student>* getStudentsQueue();
	void setStudentsQueue(GenQueue<Student>* studentsQueue);
	Window** getMyWindows();
	void setMyWindows(Window** myWindows);
};
#endif

