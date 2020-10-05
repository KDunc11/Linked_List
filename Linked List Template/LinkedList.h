//Template Class for a Linked List
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <cstdlib>
#include "Node.h"

using namespace std;

template<typename T>
class LinkedList
{
public:
	//Constructor
	LinkedList<T>();
	//Destructor
	virtual ~LinkedList();

	//Public Member Functions
	bool insert(const T &new_Data); //Used to insert a node into the list
	bool remove(const T &target); //Removes a node from the list
	bool contains(const T &inList); //Checks if data is in the list
	Node<T> *search(const T &search_Data); //Searches through the list for data
	friend ostream& operator<<(ostream& ostrm, LinkedList<T> list); //Operator overloading
	bool operator==(const LinkedList<T> &list); //Checks if data from the list are equal or not
	bool isEmpty(); //Checks if a list is empty
	void resetIterator(); //Resets the iterator member variable
	void print(); //Prints out the content on the list
private:
	//Private Member Variables
	Node<T> *head;
	Node<T> *tail;
	Node<T> *iterator;
};
#endif