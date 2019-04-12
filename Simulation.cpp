/*
a.Scott Cummings
b.2317991
c.scummings@chapman.edu
d.CPSC 350 - Section 1
e.Assignment 4
Summary: Implementation for the simulation class. Contains all the logic for the simulation functions.
*/
#include "Simulation.h"
#include <iostream>
using namespace std;
Simulation::Simulation()
{
	m_meanStudentWaitTime = -1;
	m_medianStudentWaitTime = -1;
	m_longestStudentWaitTime = -1;
	m_numberOfStudentsWaitingOver10Minutes = -1;
	m_meanWindowIdleTime = -1;
	m_longestWindowIdleTime = -1;
	m_numberOfWindowsIdleForOver5Minutes = -1;
	m_numberOfWindows = -1;
	m_numStudents = -1;
}
Simulation::Simulation(Registrar* r, int numberOfWindows)
{
	m_meanStudentWaitTime = -1;
	m_medianStudentWaitTime = -1;
	m_longestStudentWaitTime = -1;
	m_numberOfStudentsWaitingOver10Minutes = -1;
	m_meanWindowIdleTime = -1;
	m_longestWindowIdleTime = -1;
	m_numberOfWindowsIdleForOver5Minutes = -1;
	m_r = r;
	m_numberOfWindows = numberOfWindows;
}
/*
a. Simulation constructor
b. @return - NA
c. @param - none
d. no exceptions thrown
*/
Simulation::~Simulation()
{
	//nothing needs to happen here
	//delete m_r;
}
/*
a. getMeanStudentWaitTime
b. @return - double - student's wait time
c. @param - none
d. no exceptions thrown
*/
double Simulation::getMeanStudentWaitTime()
{
	return m_meanStudentWaitTime;
}
/*
a. setMeanStudentWaitTime
b. @return - void
c. @param - double - student's wait time
d. no exceptions thrown
*/
void Simulation::setMeanStudentWaitTime(double meanStudentWaitTime)
{
	m_meanStudentWaitTime = meanStudentWaitTime;
}
/*
a. calcStudentWaitTime
b. @return - double - the mean student wait time
c. @param - none
d. no exceptions thrown
*/
double Simulation::calcMeanStudentWaitTime()
{
	double sum = 0;
	int incrementer = 0;
	//m_r->getStudentsQueue();
	GenListNode<Student>* curr = m_r->getStudentsQueue()->getMyGenDoublyLinkedList()->getFront();
	GenListNode<Student>* tail = m_r->getStudentsQueue()->getMyGenDoublyLinkedList()->getTail();
	while (true)
	{

		sum += curr->getData()->getTimeWaited();
		incrementer++;
		if (curr == tail)
		{
			break;
		}
		curr = curr->getNext();

	}
	return sum / incrementer;
}
/*
a. getMedianStudentWaitTime
b. @return - int - the median student wait time
c. @param - none
d. no exceptions thrown
*/
int Simulation::getMedianStudentWaitTime()
{
	return m_medianStudentWaitTime;
}
/*
a. setMedianStudentWaitTime
b. @return - void
c. @param - int - the median student wait time
d. no exceptions thrown
*/
void Simulation::setMedianStudentWaitTime(int medianStudentWaitTime)
{
	m_medianStudentWaitTime = medianStudentWaitTime;
}
/*
a. calcMedianStudentWaitTime
b. @return - int
c. @param - none
d. no exceptions thrown
*/
int Simulation::calcMedianStudentWaitTime()
{
	GenListNode<Student>* curr = m_r->getStudentsQueue()->getMyGenDoublyLinkedList()->getFront();
	GenListNode<Student>* tail = m_r->getStudentsQueue()->getMyGenDoublyLinkedList()->getTail();
	int incrementer = 0;
	int* myIntArray = new int[m_numStudents];
	while (true)
	{
		myIntArray[incrementer] = curr->getData()->getTimeWaited();
		curr = curr->getNext();
		incrementer++;
		if (curr == tail)
		{
			break;
		}
	}
	sortIntegers(myIntArray, incrementer + 1);
	double indexWeNeedToFindDouble = incrementer / (double)2;
	if (incrementer % 2 == 0)
	{
		int firstNum = myIntArray[(int)indexWeNeedToFindDouble];
		int secondNum = myIntArray[(int)indexWeNeedToFindDouble + 1];
		return (double)(firstNum + secondNum) / 2;
	}
	return myIntArray[(int)indexWeNeedToFindDouble];
}
/*
a. getLongestStudentWaitTime()
b. @return - int
c. @param - none
d. no exceptions thrown
*/
int Simulation::getLongestStudentWaitTime()
{
	return m_longestStudentWaitTime;
}
/*
a. calcLongestStudentWaitTime
b. @return - void
c. @param - int - an int that represents the longestStudentWaitTime
d. no exceptions thrown
*/
void Simulation::setLongestStudentWaitTime(int longestStudentWaitTime)
{
	m_longestStudentWaitTime = longestStudentWaitTime;
}
/*
a. calcLongestStudentWaitTime
b. @return - int
c. @param - none
d. no exceptions thrown
*/
int Simulation::calcLongestStudentWaitTime()
{
	GenListNode<Student>* curr = m_r->getStudentsQueue()->getMyGenDoublyLinkedList()->getFront();
	GenListNode<Student>* tail = m_r->getStudentsQueue()->getMyGenDoublyLinkedList()->getTail();
	int max = 0;
	while (true)
	{
		if (curr->getData()->getTimeWaited() > max)
		{
			max = curr->getData()->getTimeWaited();
		}
		if (curr == tail)
		{
			break;
		}
		curr = curr->getNext();
	}
	return max;
}
/*
a. getNumberOfStudentsWaitingOver10Minutes
b. @return - int
c. @param - none
d. no exceptions thrown
*/
int Simulation::getNumberOfStudentsWaitingOver10Minutes()
{
	return m_numberOfStudentsWaitingOver10Minutes;
}
/*
a. setNumberOfStudentsWaitingOver10Minutes
b. @return - void
c. @param - int - number of students waiting over 10 minutes
d. no exceptions thrown
*/
void Simulation::setNumberOfStudentsWaitingOver10Minutes(int numberOfStudentsWaitingOver10Minutes)
{
	m_numberOfStudentsWaitingOver10Minutes = numberOfStudentsWaitingOver10Minutes;
}
/*
a. calcNumberOfStudentsWaitingOver10Minutes
b. @return - int
c. @param - none
d. no exceptions thrown
*/
int Simulation::calcNumberOfStudentsWaitingOver10Minutes()
{
	GenListNode<Student>* curr = m_r->getStudentsQueue()->getMyGenDoublyLinkedList()->getFront();
	GenListNode<Student>* tail = m_r->getStudentsQueue()->getMyGenDoublyLinkedList()->getTail();
	int count = 0;
	while (true)
	{
		if (curr->getData()->getTimeWaited() > 10)
		{
			++count;
		}
		curr = curr->next;
		if (curr == tail)
		{
			break;
		}
	}
	return count;
}
/*
a. calcMeanWindowIdleTime
b. @return - double
c. @param - none
d. no exceptions thrown
*/
double Simulation::getMeanWindowIdleTime()
{
	return m_meanWindowIdleTime;
}
/*
a. setMeanWindowIdleTime
b. @return - void
c. @param - double - mean window idle time
d. no exceptions thrown
*/
void Simulation::setMeanWindowIdleTime(double meanWindowIdleTime)
{
	m_meanWindowIdleTime = meanWindowIdleTime;
}
/*
a. calcMeanWindowIdleTime
b. @return - double
c. @param - none
d. no exceptions thrown
*/
double Simulation::calcMeanWindowIdleTime()
{
	double sum = 0;
	int incrementer = 0;
	for (int i = 0; i < m_numberOfWindows; ++i)
	{
		sum += (m_r->getMyWindows())[i]->getIdleTime();
		++incrementer;
	}
	return sum / incrementer;
}
/*
a. getLongestWindowIdleTime
b. @return - int
c. @param - none
d. no exceptions thrown
*/
int Simulation::getLongestWindowIdleTime()
{
	return m_longestWindowIdleTime;
}
/*
a. setLongestWindowIdleTime
b. @return - void
c. @param - int longestWindowIdleTime
d. no exceptions thrown
*/
void Simulation::setLongestWindowIdleTime(int longestWindowIdleTime)
{
	m_longestWindowIdleTime = longestWindowIdleTime;
}
/*
a. calcLongestWindowIdleTime
b. @return - int
c. @param - none
d. no exceptions thrown
*/
int Simulation::calcLongestWindowIdleTime()
{
	int max = 0;
	for (int i = 0; i < m_numberOfWindows; ++i)
	{
		if (m_r->getMyWindows()[i]->getIdleTime() > max)
		{
			max = m_r->getMyWindows()[i]->getIdleTime();
		}
	}
	return max;
}
/*
a. getNumberOfWindowsIdleForOver5Minutes
b. @return - int
c. @param - none
d. no exceptions thrown
*/
int Simulation::getNumberOfWindowsIdleForOver5Minutes()
{
	return m_numberOfWindowsIdleForOver5Minutes;
}
/*
a. setNumberOfWindowsIdleForOver5Minutes
b. @return - void
c. @param - int number of windows idle for over 5 minutes
d. no exceptions thrown
*/
void Simulation::setNumberOfWindowsIdleForOver5Minutes(int numberOfWindowsIdleForOver5Minutes)
{
	m_numberOfWindowsIdleForOver5Minutes = numberOfWindowsIdleForOver5Minutes;
}
/*
a. calcNumberOfWindowsIdleForOver5Minutes
b. @return - int
c. @param - none
d. no exceptions thrown
*/
int Simulation::calcNumberOfWindowsIdleForOver5Minutes()
{
	int count = 0;
	for (int i = 0; i < m_numberOfWindows; ++i)
	{
		if (m_r->getMyWindows()[i]->getIdleTime() > 5)
		{
			++count;
		}
	}
	return count;
}
/*
a. getRegistrar
b. @return - Registrar*
c. @param - none
d. no exceptions thrown
*/
Registrar* Simulation::getRegistrar()
{
	return m_r;
}
/*
a. setRegistrar
b. @return - int
c. @param - Registrar*
d. no exceptions thrown
*/
void Simulation::setRegistrar(Registrar* r)
{
	m_r = r;
}
/*
a. calculate
b. @return - void
c. @param - none
d. no exceptions thrown
*/
void Simulation::calculate()
{
	setMeanStudentWaitTime(calcMeanStudentWaitTime());
	setMedianStudentWaitTime(calcMedianStudentWaitTime());
	setLongestStudentWaitTime(calcLongestStudentWaitTime());
	setNumberOfStudentsWaitingOver10Minutes(calcNumberOfStudentsWaitingOver10Minutes());
	setMeanWindowIdleTime(calcMeanWindowIdleTime());
	setLongestWindowIdleTime(calcLongestWindowIdleTime());
	setNumberOfWindowsIdleForOver5Minutes(calcNumberOfWindowsIdleForOver5Minutes());
	cout << "Mean Student Wait Time: " << getMeanStudentWaitTime() << endl;
	cout << "Median Student Wait Time: " << getMedianStudentWaitTime() << endl;
	cout << "Longest Student Wait Time: " << getLongestStudentWaitTime() << endl;
	cout << "Number of Students Waiting over 10 Minutes: " << getNumberOfStudentsWaitingOver10Minutes() << endl;
	cout << "Mean Window Idle Time: " << getMeanWindowIdleTime() << endl;
	cout << "Longest Window Idle Time: " << getLongestWindowIdleTime() << endl;
	cout << "Number of Windows Idle for over 5 minutes: " << getNumberOfWindowsIdleForOver5Minutes() << endl;
}
/*
a. swapIntegers
b. @return - void
c. @param - int& - int&
d. no exceptions thrown
*/
void Simulation::swapIntegers(int& a, int& b)
{
	int cup;
	cup = a;
	a = b;
	b = cup;
}
/*
a. sortIntegers
b. @return - void
c. @param - int* - int
d. no exceptions thrown
*/
void Simulation::sortIntegers(int* myIntArray, int sizeOfArray)
{
	int i, j;
	bool swapped;
	int*tempIntArray = myIntArray;
	for (i = 0; i < sizeOfArray - 1; i++)
	{
		swapped = false;
		for (j = 0; j < sizeOfArray - i - 1; j++)
		{
			if (tempIntArray[j] > tempIntArray[j + 1])
			{
				swapIntegers(tempIntArray[j], tempIntArray[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
		{
			break;
		}
	}
}
/*
a. getNumStudents
b. @return - int
c. @param - none
d. no exceptions thrown
*/
int Simulation::getNumStudents()
{
	return m_numStudents;
}
/*
a. setNumStudents
b. @return - void
c. @param - int
d. no exceptions thrown
*/
void Simulation::setNumStudents(int numStudents)
{
	m_numStudents = numStudents;
}
