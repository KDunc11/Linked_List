#include "pch.h"
#include "LinkedList.h"

//Constructor
template<typename T>
LinkedList<T>::LinkedList()
{
	head = tail = iterator = nullptr;
}

//Destructor
template<typename T>
LinkedList<T>::~LinkedList()
{
}


//Public Member Functions
template<typename T>
bool LinkedList<T>::insert(const T &new_Data)
{
	if (head == nullptr) //Inserting into an empty list
	{
		Node<T> *node = new Node<T>(new_Data);

		head = node;
		tail = node;
		return true;
	}
	else if (head->prev == nullptr && head->next == nullptr) //Inserting into a list with one node
	{
		Node<T> *node = new Node<T>(new_Data);

		if (node->data < head->data) //If data to be inserted is smaller than existing data insert beforehand
		{
			node->next = head;
			head->prev = node;
			head = node;
			tail = head->next;
			return true;
		}
		else //If data to be inserted is larger than existing data insert afterwards
		{
			head->next = node;
			node->prev = head;
			tail = node;
			return true;
		}
	}
	else //Inserting with more than two nodes in the list
	{
		Node<T> *node = new Node<T>(new_Data);
		Node<T> *temp = head;

		while (temp->next != nullptr) //Updates the temporary node until reaching the last node in the list if the node cannot be inserted
		{
			if (node->data < temp->data) //Insert node if data is less than the temporary node's data
			{
				if (head->data == temp->data)//Needs to be inserted before head
				{
					node->next = head;
					head->prev = node;
					head = node;
					return true;
				}
				else //Handles inserting in the list anywhere in the list after head and before the last node
				{
					node->next = temp;
					node->prev = temp->prev;
					temp->prev = node;
					return true;
				}
			}
			temp = temp->next;
		}
		if (node->data < temp->data) //If the node being inserted is less than the last node's data then insert before the last node
		{
			node->next = temp;
			node->prev = temp->prev;
			temp->prev->next = node;
			temp->prev = node;
			return true;
		}
		else //If the node being inserted is greater than the last node's data than insert after the last node and update tail to the new node
		{
			node->prev = tail;
			tail = node;
			temp->next = node;
			return true;
		}
	}
	return false;
}

template<typename T>
Node<T>* LinkedList<T>::search(const T &search_Data)
{
	if (head == nullptr) //Checks for an empty list
		return head;
	else
	{
		Node<T> *temp = head;

		while (temp->next != nullptr) //Traverses through the list until reaching the last node in the list
		{
			if (temp->data == search_Data) //If data the user is searching for is in the list return the node where the data was found
				return temp;
			temp = temp->next;
		}
		if (temp->data == search_Data) //If the last node in the list is the data the user is searching for, return the last node in the list
			return temp;
		else
			return nullptr; //Data was not found in the list
	}
}

template<typename T>
bool LinkedList<T>::contains(const T &inList)
{
	if (search(inList) == nullptr) //Data was not found in the list or the list was empty
		return false;
	else
		return true; //The data being searched for was found in the list
}

template<typename T>
bool LinkedList<T>::remove(const T &target)
{
	if (contains(target) == false) //Either the target node the user is searching for is not in the list or the list is empty
		return false;
	else
	{
		Node<T> *remove = search(target); //Will assign the remove node to the target node
		
		if (remove->next == nullptr && remove->prev == nullptr) //If the node being removed is the only node in the list
		{
		head = tail = nullptr;
		delete remove;
		return true;
		}
		else if (remove->next == nullptr) //If the node being removed is the last node in the list
		{
			tail = remove->prev;
			tail->next = nullptr;
			delete remove;
			return true;
		}
		else if (remove->prev == nullptr) //If the node being delete is the first node in the list
		{
			head = head->next;
			head->prev = nullptr;
			delete remove;
			return true;
		}
		else //If the node is somewhere in the middle of the list (not the first or last node in the list)
		{
			Node<T> *storePrev = remove->prev; //Stores the previous pointer that belongs to the node being deleted
			Node<T> *storeNext = remove->next; //Stores the next pointer that belongs to the node being deleted

			storePrev->next = storeNext;
			storeNext->prev = storePrev;
			delete remove;
			return true;
		}
	}
}

template<typename T>
ostream& operator<<(ostream& ostrm, LinkedList<T> list) //Operator overloading
{
	Node<T> *temp = list.head;

	while (temp != nullptr) //Displays contents of list until reaching the end of the list
		ostrm << list.temp->data << endl;
	return ostrm;
}

template<typename T>
void LinkedList<T>::resetIterator()
{
	iterator = head; //Sets iterator back to the beginning node
}


template<typename T>
void LinkedList<T>::print()
{
	resetIterator();//Moves iterator the first node

	while (iterator != nullptr) //Moves through the list until reaching the end
	{
		cout << iterator->data << endl; //Displays the data in each node
		iterator = iterator->next; //Moves the iterator to the next node
	}
}

template<typename T>
bool LinkedList<T>::operator==(const LinkedList<T> &list)
{
	if (head->data == list.head->data) //Checks if data is equivalent
		return true;
	else
		return false;
}

template<typename T>
bool LinkedList<T>::isEmpty()
{
	if (head == nullptr) //If head is equal to nullptr then the list is empty
		return true;
	else
		return false; //Otherwise the list contains at list one node
}