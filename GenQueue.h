/*
a.Scott Cummings
b.2317991
c.scummings@chapman.edu
d.CPSC 350 - Section 1
e.Assignment 4
Summary: Template class for the Generic Queue
*/
#ifndef GENQUEUE_H
#define GENQUEUE_H
#include <iostream>
#include "GenDoublyLinkedList.h"
using namespace std;

template<typename T>
class GenQueue
{
public:
	GenQueue(); //default constructor
	GenQueue(int maxSize); //overloaded constructor
	~GenQueue(); //destructor

	void insert(T d); //aka enqueue()
	T remove(); //aka dequeue
	T front(); // tells who is at the front of the outline aka peek
	int getTail();

	int getSize();
	//GenDoublyLinkedList<T>* getMyQueue();
	bool isEmpty();
	void printQueue();
	GenDoublyLinkedList<T>* getMyGenDoublyLinkedList();
private:
	int head;
	int tail;
	int numElements;
	int mSize;

	GenDoublyLinkedList<T>* myGenDoublyLinkedList;
};
/*
a. GenQueue - GenQueue constructor
b. @return - NA
c. @param - none
d. no exceptions thrown
*/
template<typename T>
GenQueue<T>::GenQueue()
{
	myGenDoublyLinkedList = new GenDoublyLinkedList<T>(0);
	head = 0;
	tail = -1;
	numElements = 0;
}
/*
a. GenQueue(int maxSize) - an overloaded constructor of GenQueue
b. @return - NA
c. @param - int maxSize - an integer value that represents the max size of the queue
d. no exceptions thrown
*/
template <typename T>
GenQueue<T>::GenQueue(int maxSize)
{
	myGenDoublyLinkedList = new GenDoublyLinkedList<T>(maxSize);
	head = 0;
	tail = -1;
	numElements = 0;
}
/*
a. ~GenQueue() - destructor for GenQueue
b. @return - NA
c. @param - none
d. no exceptions thrown
*/
template<typename T>
GenQueue<T>::~GenQueue()
{
	delete myGenDoublyLinkedList;
}
/*
a. insert(T d) - inserts a value into the Queue
b. @return - void
c. @param - T d - the data that we wish to insert
d. no exceptions thrown
*/
template<typename T>
void GenQueue<T>::insert(T d)
{
	myGenDoublyLinkedList->insertBack(d);
	++tail;
	numElements++;
}
/*
a. remove() - removes an element from the Queue
b. @return - T - the data that we are removing
c. @param - none
d. no exceptions thrown
*/
template<typename T>
T GenQueue<T>::remove()
{
	if (numElements == 0)
	{
		cout << "This queue is empty, there is no value to remove." << endl;
		return NULL;
	}
	myGenDoublyLinkedList->removeFront();
	--numElements;
	--tail;
	return myGenDoublyLinkedList->getFront()->getData();
}
/*
a. front() - returns the data contained at the front of the list
b. @return - T - the data contained at the front of the list
c. @param - none
d. no exceptions thrown
*/
template<typename T>
T GenQueue<T>::front()
{
	return myGenDoublyLinkedList->getFront()->getData();
}
/*
a. isEmpty
b. @return - boolean value that indicates whether or not the queue is empty
c. @param - none
d. no exceptions thrown
*/
template<typename T>
bool GenQueue<T>::isEmpty()
{
	return (numElements == 0);
}
/*
a. getSize()
b. @return - an integer value that represents the size of the queue
c. @param - none
d. no exceptions thrown
*/
template<typename T>
int GenQueue<T>::getSize()
{
	return numElements;
}
/*
a. getTail()
b. @return - an integer value that represents the index of the tail
c. @param - none
d. no exceptions thrown
*/
template<typename T>
int GenQueue<T>::getTail()
{
	return tail;
}
/*
a. printQueue() - prints out the queue
b. @return - NA
c. @param - none
d. no exceptions thrown
*/
template<typename T>
void GenQueue<T>::printQueue()
{
	myGenDoublyLinkedList->printList();
}
/*
a. getMyGenDoublyLinkedList
b. @return - a pointer to the Queue's doubly linked list
c. @param - none
d. no exceptions thrown
*/
template<typename T>
GenDoublyLinkedList<T>* GenQueue<T>::getMyGenDoublyLinkedList()
{
	return myGenDoublyLinkedList;
}
#endif
