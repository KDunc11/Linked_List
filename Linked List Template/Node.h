#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
public:
	//Constructors
	Node() //Default Constructor
	{
		next = prev = nullptr;
	}
	Node(T inputData) //Constructor for creating a node based off existing data
	{
		data = inputData;
		next = prev = nullptr;
	}
	//Destructor
	~Node()
	{
		next = prev = nullptr;
	}

	//Member Variables
	T data;
	Node *next;
	Node *prev;
};
#endif