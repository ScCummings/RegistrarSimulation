/*
a.Scott Cummings
b.2317991
c.scummings@chapman.edu
d.CPSC 350 - Section 1
e.Assignment 4
Summary: Driver class for the project
*/
#include "GenDoublyLinkedList.h"
#include "GenQueue.h"
#include "Registrar.h"
#include "Simulation.h"
#include "Student.h"
#include "Window.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool fileExists(string fileName);

string numWindowsOpenString;
int numWindowsOpen;
string filePath = "";
ifstream inputStream;
int clockTickArrived;
string clockTickArrivedString;
int numStudentsArrived;
string numStudentsArrivedString;
int waitTimeExpected;
string waitTimeExpectedString;
int totalStudents = 0;
string totalStudentsStrings;
size_t* numCharacters = 0;
int base = 10;
GenQueue<Student>* myStudents = new GenQueue<Student>();
GenQueue<Student>* totalStudentsQueue = new GenQueue<Student>();
bool readLineSentinel = true;
int clockTick;
bool endOfSimulation = false;

bool checkAllWindowsEmpty(Window** myWindows, int numWindowsOpen);
int main(int argc, char** argv)
{

//read in file
if (argc > 1)
{
 filePath = argv[1];
 if (fileExists(filePath))
 {
  inputStream.open(filePath, ios::out);
  getline(inputStream, numWindowsOpenString);
  if (inputStream.eof())
  {
   cout << "End of file reached. Breaking." << endl;
  }
  try
  {
   numWindowsOpen = atoi(numWindowsOpenString.c_str());
  }
  catch (exception& e)
  {
   cout << "First line of file could not be converted to an int. Please check file format." << endl;
   exit(0);
  }
 }
}
else
{
 cout << "Please enter a file path as a command line argument." << endl;
 exit(0);
}
Window** myWindows = new Window*[numWindowsOpen];
for (int i = 0; i < numWindowsOpen; ++i)
{
 Window* window = new Window();
 myWindows[i] = window;
}
while (!inputStream.eof() || !checkAllWindowsEmpty(myWindows, numWindowsOpen))
{
 if (readLineSentinel)
 {
  try
  {
   getline(inputStream, clockTickArrivedString);
   clockTickArrived = atoi(clockTickArrivedString.c_str());
  }
  catch (exception& e)
  {
   cout << "Clock Tick Arrived: This value in your file could not be converted into an int: " << clockTickArrivedString << " Please check the format of your file." << endl;
   exit(0);
  }
 }
 if (clockTickArrived != clockTick)
 {
  readLineSentinel = false;
 }
 else
 {
  readLineSentinel = true;
  try
  {
   getline(inputStream, numStudentsArrivedString);
   numStudentsArrived = atoi(numStudentsArrivedString.c_str());
  }
  catch (exception& e)
  {
   cout << "Num Students Arrived: This value in your file could not be converted into an int: " << numStudentsArrivedString << " Please check the format of your file." << endl;
   exit(0);
  }
  for (int i = 0; i < numStudentsArrived; ++i)
  {
   try
   {
    getline(inputStream, waitTimeExpectedString);
    waitTimeExpected = atoi(waitTimeExpectedString.c_str());
   }
   catch (exception& e)
   {
    cout << "Wait Time: This value in your file could not be converted into an int: " << waitTimeExpectedString << " Please check the format of your file." << endl;
    exit(0);
   }
   //create those student objects
   Student student(waitTimeExpected);
   //add those students to the QUEUE
   myStudents->insert(student);
   ++totalStudents;
  }
 }
 ////////WINDOW IDLE STUFF
 for (int j = 0; j < numWindowsOpen; ++j)
 {
   if (myWindows[j]->getIsIdle() && myStudents->getMyGenDoublyLinkedList()->getSize() > 0)
   {
    myWindows[j]->setCurrentStudent(myStudents->getMyGenDoublyLinkedList()->getFront()->getData());
    myStudents->getMyGenDoublyLinkedList()->removeFront();
    myWindows[j]->setIsIdle(false);
   }
   else if (myWindows[j]->getIsIdle())
   {
    myWindows[j]->setIdleTime(myWindows[j]->getIdleTime() + 1);
   }
   else if (myWindows[j]->getCurrentStudent()->getTimeAtWindow() == myWindows[j]->getCurrentStudent()->getTimeRequired())
   {
    totalStudentsQueue->insert(*myWindows[j]->clearWindow());
   }
   else if (myWindows[j]->getCurrentStudent() != nullptr) //Student at window
   {
    myWindows[j]->getCurrentStudent()->setTimeAtWindow(myWindows[j]->getCurrentStudent()->getTimeAtWindow() + 1);
   }
   else //Nobody at window
   {
    //Nothing :(
   }
 }
 if (!myStudents->getMyGenDoublyLinkedList()->isEmpty())
 {
  GenListNode<Student>* curr = myStudents->getMyGenDoublyLinkedList()->getFront();
  while (true)
  {
   curr->getData()->setIsWaiting(true);
   curr->getData()->setTimeWaited(curr->getData()->getTimeWaited() + 1);
   curr = curr->next;
   if (curr == nullptr)
   {
    break;
   }
  }
 }
 clockTick++;
}
Registrar r(totalStudents, numWindowsOpen, totalStudentsQueue, myWindows);
Simulation s(&r, numWindowsOpen);
s.calculate();
}
/*
a. bool fileExists - checks to see if the passed in file exists
b. @return - a boolean value that represents whether or not the file exists
c. @param - none
d. no exceptions thrown
*/
bool fileExists(string filename)
{
ifstream f(filename.c_str());
return f.good();
}
/*
a. bool checkAllWindowsEmpty - checks to see if each of the current windows are empty
b. @return - a boolean value that represents whether or not each of the current windows are empty
c. @param - Window** myWindows - a Window double pointer that represents the collection of windows within the registrar - int numWindowsOpen - an integer value that represents the number of windows open within the registrar
d. no exceptions thrown
*/
bool checkAllWindowsEmpty(Window** myWindows, int numWindowsOpen)
{
for (int i = 0; i < numWindowsOpen; ++i)
{
 if (myWindows[i]->getIsIdle() == false)
 {
  return false;
 }
}
return true;
}
