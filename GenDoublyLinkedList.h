/*
a.Scott Cummings
b.2317991
c.scummings@chapman.edu
d.CPSC 350 - Section 1
e.Assignment 4
*/

#ifndef GENDOUBLYLINKEDLIST_H
#define GENDOUBLYLINKEDLIST_H
#include <iostream>

using namespace std;

template <typename T>
class GenListNode
{
public:
	GenListNode();
	GenListNode(const T& d);
	~GenListNode();
	T data;
	GenListNode* next;
	GenListNode* prev;
	T* getData();
	GenListNode* getNext();
	GenListNode* getPrev();
	bool isEmpty = true;
};
/*
a. getNext()
b. @return - returns a GenListNode pointer that represents the next node in the doubly linked list
c. @param - none
d. no exceptions thrown
*/
template <typename T>
GenListNode<T>* GenListNode<T>::getNext()
{
	return next;
}
/*
a. GenListNode(const T& d) - a GenListNode overloaded constructor
b. @return - NA
c. @param - a const & value that data for the node gets set to
d. no exceptions thrown
*/
template <typename T>
GenListNode<T>::GenListNode(const T& d)
{
	data = d;
	next = NULL;
	prev = NULL;
	isEmpty = false;
}
/*
a. GenListNode destructor
b. @return - NA
c. @param - none
d. no exceptions thrown
*/
template <typename T>
GenListNode<T>::~GenListNode()
{
	/*curr->prev.next = curr->next;
	curr->next.prev = curr->prev;*/
	//data = NULL;
	//next = NULL;
	//prev = NULL;
	//isEmpty = NULL;
	/*delete data;
	delete next;
	delete prev;
	delete isEmpty;//set everything o null  and delete
	/*
	curr.prev points to curr.next for its next
	curr.next points to curr.prev for its prev
	*/
	//ill let you guys research what goes here
}
/*
a. getData()
b. @return - returns a T value that represents the data found inside the GenListNode
c. @param - none
d. no exceptions thrown
*/
template <typename T>
T* GenListNode<T>::getData()
{
	if (isEmpty)
	{
		cout << "there is no data to be returned in the node" << endl;
		return 0; //need something to return because reference to a generic
	}
	return &data;
}
template <typename T>
//////LinkedList Class(Doubly linked list)/////
class GenDoublyLinkedList
{
private:
	GenListNode<T>* front;
	GenListNode<T>* tail;
	unsigned int m_size;
public:
	GenDoublyLinkedList();
	GenDoublyLinkedList(int size);
	~GenDoublyLinkedList();
	void insertFront(const T& d);
	GenListNode<T>* getFront();
	T removeFront();
	T deletePos(int pos);
	void printList();
	int find(T d); //search method
	bool isEmpty();
	unsigned int getSize();
	void insertBack(const T& data);
	GenListNode<T>* remove(T key);
	GenListNode<T>* getTail();
};
/*
a. GenDoublyLinkedList - default constructor
b. @return - NA
c. @param - none
d. no exceptions thrown
*/
template <typename T>
GenDoublyLinkedList<T>::GenDoublyLinkedList()
{
	front = NULL;
	m_size = 0;
	tail = NULL;
}
/*
a. GenDoublyLinkedList(int size) - an overloaded constructor for the GenDoublyLinkedList class
b. @return - NA
c. @param - int size - an int parameter that sets the size member variable
d. no exceptions thrown
*/
template <typename T>
GenDoublyLinkedList<T>::GenDoublyLinkedList(int size)
{
	front = NULL;
	m_size = size;
	tail = NULL;
}
/*
a. GenDoublyLinkedList destructor
b. @return - NA
c. @param - none
d. no exceptions thrown
*/
template <typename T>
GenDoublyLinkedList<T>::~GenDoublyLinkedList()
{
	/*while (!isEmpty())
	{
	removeFront();
	}
	if (front == NULL)
	{
	delete front;
	}*/
	//build some character (if front = null), delete front
	//doubly linked list differ a bit from a single linked list
}
/*
a. getSize() - an accessor function that accesses the size member variable for the class
b. @return - an unsigned int that represents the size of the doubly linked list
c. @param - none
d. no exceptions thrown
*/
template <typename T>
unsigned int GenDoublyLinkedList<T>::getSize()
{
	return m_size;
}
/*
a. printList()
b. @return - void
c. @param - none
d. no exceptions thrown
*/
template <typename T>
void GenDoublyLinkedList<T>::printList()
{
	GenListNode<T>* curr = front;
	while (true)
	{
		cout << curr->data << endl;
		if (curr == tail)
		{
			break;
		}
		curr = curr->next;
	}
}
/*
a. insertFront()
b. @return - void
c. @param - const T& d - a const & value that represents becomes the data for for the new GenListNode
d. no exceptions thrown
*/
template <typename T>
void GenDoublyLinkedList<T>::insertFront(const T& d)
{
	GenListNode<T>* node = new GenListNode<T>(d);
	if (isEmpty())//this is a check for empty
	{
		front = node;
		tail = node;
	}
	if (m_size == 0)
	{
		tail = node;
	}
	else
	{
		front->prev = node;
		node->next = front;
	}
	front = node;
	m_size++;
}
/*
a. insertBack()
b. @return - void
c. @param - a const & value that represents the data that gets added to the new GenListNode
d. no exceptions thrown
*/
template <typename T>
void GenDoublyLinkedList<T>::insertBack(const T& data)
{
	GenListNode<T>* node = new GenListNode<T>(data);
	if (isEmpty())//this is a check for empty
	{
		front = node; //idk if this will work
		tail = node;
	}
	if (m_size == 0)
	{
		front = node;
	}
	else
	{
		tail->next = node;
		node->prev = tail;
	}
	tail = node;
	m_size++;
}
/*
a. getNext()
b. @return - a T value that represents the data within the front node
c. @param - none
d. no exceptions thrown
*/
template <typename T>
T GenDoublyLinkedList<T>::removeFront()
{
	T temp = front->data;
	GenListNode<T>* ft = front;
	if (front->next != nullptr)
	{
		front = front->next;
		ft->next = NULL;
	}
	else
	{
		front = NULL;
		tail = NULL;
	}
	m_size--;
	return temp;
}
/*
a. find()
b. @return - an int value that represents the index at which the value is found
c. @param - T d - a T value that represents the data we are searching for
d. no exceptions thrown
*/
template <typename T>
//return position of value if exists
int GenDoublyLinkedList<T>::find(T d) // AKA search()
{
	int idx = -1;
	GenListNode<T>* curr = front;
	while (curr != NULL)
	{
		++idx;
		if (curr->data == d)//we found it
		{
			break;
		}
		else
		{
			curr = curr->next;
		}
	}
	if (curr == NULL)
	{
		idx = -1;
		return idx;
	}
}
/*
a. remove()
b. @return - GenListNode* - a GenListNode pointer that is a pointer to the node we wish to remove
c. @param - T key - a T value that represents the data we wish to remove
d. no exceptions thrown
*/
template <typename T>
GenListNode<T>* GenDoublyLinkedList<T>::remove(T key)
{
	GenListNode<T>* curr = front;
	while (curr->data != key)
	{
		curr = curr->next;
		if (curr == NULL)
		{
			return NULL;
		}
	}
	//we found our ListNode
	//need to check if its the front ListNode
	if (curr == front)
	{
		front = curr->next;
	}
	else
	{
		curr->prev->next = curr->next;
	}
	//check if back ListNode
	if (curr == tail)
	{
		tail = curr->prev;
	}
	else
	{
		curr->next->prev = curr->prev;
	}
	curr->next = NULL;
	curr->prev = NULL;
	m_size--;
	int pos = find(key);
	deletePos(pos);
	return curr;
}
/*
a. deletePos()
b. @return - a T value that represents the data inside the position that we delete
c. @param - int pos - an int value that represents the index that we wish to remove
d. no exceptions thrown
*/
template <typename T>
T GenDoublyLinkedList<T>::deletePos(int pos)
{
	int idx = 0;
	GenListNode<T>* current = front;
	for (int i = 0; i < getSize() - 1; i++)
	{
		current = current->next;
		if (current->data == NULL) //keep as this because data is a ptr
		{
			return NULL;
		}
	}
	GenListNode<T>* curr = front;
	GenListNode<T>* prev = front;
	while (idx != pos)
	{
		prev = curr;//stay back
		curr = curr->next;
		++idx;
	}
	//when we find the correct position, update pointers.
	prev->next = curr->next;
	curr->next = NULL;
	T temp = curr->data;
	delete curr;
	m_size--;

	return temp;
}
/*
a. isEmpty()
b. @return - a bool value that represents whether or not the list is empty
c. @param - none
d. no exceptions thrown
*/
template <typename T>
bool GenDoublyLinkedList<T>::isEmpty()
{
	if (front == NULL)
	{
		return true;
	}
	return false;
}
/*
a. getFront()
b. @return - GenListNode* - a GenListNode pointer that points to the front of the list
c. @param - none
d. no exceptions thrown
*/
template <typename T>
GenListNode<T>* GenDoublyLinkedList<T>::getFront()
{
	return front;
}
/*
a. getTail()
b. @return - GenListNode* - a GenListNode pointer that points to the tail of the list
c. @param - none
d. no exceptions thrown
*/
template<typename T>
GenListNode<T>* GenDoublyLinkedList<T>::getTail()
{
	return tail;
}
#endif
