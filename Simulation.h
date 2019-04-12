/*
a.Scott Cummings
b.2317991
c.scummings@chapman.edu
d.CPSC 350 - Section 1
e.Assignment 4
Summary: Header file for the Simulation class.
*/
#ifndef SIMULATION_H
#define SIMULATION_H
#include "Registrar.h"
class Simulation
{
private:
	double m_meanStudentWaitTime;
	int m_medianStudentWaitTime;
	int m_longestStudentWaitTime;
	int m_numberOfStudentsWaitingOver10Minutes;
	double m_meanWindowIdleTime;
	int m_longestWindowIdleTime;
	int m_numberOfWindowsIdleForOver5Minutes;
	int m_numberOfWindows;
	Registrar* m_r;
	int m_numStudents;
public:
	Simulation();
	Simulation(Registrar* r, int numberOfWindows);
	~Simulation();
	double getMeanStudentWaitTime();
	void setMeanStudentWaitTime(double meanStudentWaitTime);
	double calcMeanStudentWaitTime();
	int getMedianStudentWaitTime();
	void setMedianStudentWaitTime(int medianStudentWaitTime);
	int calcMedianStudentWaitTime();
	int getLongestStudentWaitTime();
	void setLongestStudentWaitTime(int longestStudentWaitTime);
	int calcLongestStudentWaitTime();
	int getNumberOfStudentsWaitingOver10Minutes();
	void setNumberOfStudentsWaitingOver10Minutes(int numberOfStudentsWaitingOver10Minutes);
	int calcNumberOfStudentsWaitingOver10Minutes();
	double getMeanWindowIdleTime();
	void setMeanWindowIdleTime(double meanWindowIdleTime);
	double calcMeanWindowIdleTime();
	int getLongestWindowIdleTime();
	void setLongestWindowIdleTime(int longestWindowIdleTime);
	int calcLongestWindowIdleTime();
	int getNumberOfWindowsIdleForOver5Minutes();
	void setNumberOfWindowsIdleForOver5Minutes(int numberOfWindowsIdleForOver5Minutes);
	int calcNumberOfWindowsIdleForOver5Minutes();
	Registrar* getRegistrar();
	void setRegistrar(Registrar* r);
	void calculate();
	void swapIntegers(int& a, int& b);
	void sortIntegers(int* myIntArray, int sizeOfArray);
	int getNumStudents();
	void setNumStudents(int numStudents);
};
#endif
