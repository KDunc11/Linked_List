#include "pch.h"
#include <string>
#include "FlightList.h"

//Constructor
FlightList::FlightList()
{
	head = tail = nullptr;
}

//Destructor
FlightList::~FlightList()
{
}

//Public Member Functions
bool FlightList::insertFlight(const int &flight)
{
	if (containsFlight(flight) == true) //Flight is already in the list
		return false;
	else
	{
		Node<FlightData> *temp = head;

		if (head == nullptr) //Creates a new flight in an empty flight list
		{
			head = new Node<FlightData>;
			head->data.flightNum = flight;
			cout << "Flight " << flight << " was successfully created." << endl;
			return true;
		}
		else if (head->next == nullptr) //Inserts a flight in a flight list containing only one flight
		{
			head->next = new Node<FlightData>;
			head->next->data.flightNum = flight;
			cout << "Flight " << flight << " was successfully created." << endl;
			tail = head->next;
			return true;
		}
		else
		{
			while (temp->next != nullptr) //Moves to the end of the list
				temp = temp->next;

			temp->next = new Node<FlightData>; //Inserts a new flight at the end of the list
			temp->next->data.flightNum = flight;
			cout << "Flight " << flight << " was successfully created." << endl;
			return true;
		}
	}
}

bool FlightList::insertPassenger(const string &passengerName, const int &flight)
{
	if (containsPassenger(passengerName) == true) //Checks if passenger is in any flights
		return false;

	if (head == nullptr)
		return false;
	else if (head->next == nullptr)
	{
		if (head->data.flightNum == flight && head->data.passengers->contains(passengerName) == false) //Only one flight in the list and passenger is not in that flight
		{
			head->data.passengers->insert(passengerName); //Inserts a new passenger into the flight
			cout << "Reservation for flight " << flight << " for passenger " << passengerName << " successful." << endl;
			return true;
		}
		else
			return false; //Passenger was already in the list;
	}
	else
	{
		Node<FlightData> *temp = head;

		while (temp->next != nullptr)
		{
			if (temp->data.flightNum == flight && temp->data.passengers->contains(passengerName)) //Passenger was found in a list
						return false;
			else if (temp->data.flightNum == flight && temp->data.passengers->contains(passengerName) == false) //Passneger was not found in a list
			{
				temp->data.passengers->insert(passengerName);
				cout << "Reservation for flight " << flight << " for passenger " << passengerName << " successful." << endl;
				return true;
			}
			temp = temp->next; //Look in next flight's list of passengers
		}
		if (temp->data.flightNum == flight && temp->data.passengers == nullptr)
		{
			temp->data.passengers->insert(passengerName); //Inserts a passenger into the last node when the last node 
			cout << "Reservation for flight " << flight << " for passenger " << passengerName << " successful." << endl;
			return true;
		}
		if (temp->data.flightNum == flight && temp->data.passengers->contains(passengerName) == true) //Checks if last node contains the passenger
			return false;
		else if (temp->data.flightNum == flight)
		{
			temp->data.passengers->insert(passengerName); //If last node doesn't contain desired passenger, insert the passenger into the list
			cout << "Reservation for flight " << flight << " for passenger " << passengerName << " successful." << endl;
			return true;
		}
		else
			return false; //Passenger could not be inserted into the flight number provided
	}
}

bool FlightList::removePassenger(const string &passengerName)
{
	if (containsPassenger(passengerName) == false) //Checks if passenger is in any lists
		return false;
	else
	{
		Node<FlightData> *temp = head;

		if (head == nullptr) //List is empty
			return false;
		else
		{
			while (temp->next != nullptr) //Searches for passenger until the last node is reached
			{
				if (temp->data.passengers->contains(passengerName) == true) //Removes the passenger from the list
				{
					temp->data.passengers->remove(passengerName);
					cout << "Reservation for flight " << temp->data.flightNum << " for passenger " << passengerName << " was cancelled." << endl;
					cout << "***Reservation Deleted***\n" << endl;
					return true;
				}
				temp = temp->next;
			}
			if (temp->data.passengers->contains(passengerName))  //If last node doesn't contain desired passenger, delete the passenger from the list
			{
				temp->data.passengers->remove(passengerName);
				cout << "Reservation for flight " << temp->data.flightNum << " for passenger " << passengerName << " was cancelled." << endl;
				cout << "***Reservation Deleted***\n" << endl;
				return true;
			}
			else
				return false;
		}
	}
}

bool FlightList::checkReservation(const string &str)
{
	if (head == nullptr) //List is empty
	{
		cout << "No reservations found for this flight." << endl;
		return false;
	}
	else
	{
		Node<FlightData> *temp = head;

		while (temp->next != nullptr) //Searches through lists for correct passenger
		{
			if (temp->data.passengers->contains(str))
			{
				cout << "***Reservation Found***" << endl;
				cout << "Passenger: " << str << "\nFlight Number: " << temp->data.flightNum << endl;
				return true;
			}
			temp = temp->next;
		}
		if (temp->data.passengers->contains(str)) //If last list contains the passenger then print out the passenger's info
		{
			cout << "***Reservation Found***" << endl;
			cout << "Passenger: " << str << "\nFlight Number: " << temp->data.flightNum << endl;
			return true;
		}
		else
			return false; //No reservation for the desired passenger on any flights
	}
}

void FlightList::printFlight(const int &num)
{
	if (head == nullptr) //List is empty
		cout << "Cannot print, list is empty" << endl;
	else
	{
		Node<FlightData> *temp = head;
		while (temp->next != nullptr) //Searches through lists for correct passenger
		{
			if (temp->data.flightNum == num && temp->data.passengers->isEmpty() == false)
			{
				cout << "\n***Flight " << temp->data.flightNum << " ***" << endl;
				cout << "Passengers:\n";
				temp->data.passengers->print();
				cout << endl;
			}
			temp = temp->next;
		}
		if (temp->data.flightNum == num && temp->data.passengers->isEmpty() == false)
		{
			cout << "\n***Flight " << temp->data.flightNum << " ***" << endl; //If last list contains the flight then print out all passengers
			cout << "Passengers:\n";
			temp->data.passengers->print();
			cout << endl;
		}
	}

}

void FlightList::printManifest()
{
	Node<FlightData> *temp = head;
	
	if (head == nullptr)
		cout << "No flights have been created" << endl;
	else
	{
		int count = 0;

		while (temp != nullptr) //Continues till last node is printed out
		{
			if (temp->data.passengers->isEmpty()) //Makes sure not to print a flight that contains no passengers
				temp = temp->next;
			else
			{
				if (count == 0)
					cout << "\n____MANIFEST_FOR_ALL_FLIGHTS____" << endl;
				cout << "***Flight " << temp->data.flightNum << " ***" << endl;
				cout << "Passengers:\n";
				temp->data.passengers->print(); //Prints out all passengers
				cout << endl;
				count++;
				temp = temp->next;
			}
		}
	}
}


//Private Member Functions
bool FlightList::containsFlight(const int &numToFind)
{
	if (findFlight(numToFind) == NULL) //Flight number was not found or list was empty
		return false;
	else
		return true; //The flight number was found
}

int FlightList::findFlight(const int &search_Data)
{
	if (head == nullptr) //Checks for an empty list
		return NULL;
	else
	{
		Node<FlightData> *temp = head;

		while (temp->next != nullptr) //Traverses through the list until reaching the last node in the list
		{
			if (temp->data.flightNum == search_Data) //If data the user is searching for is in the list return the flight number
				return temp->data.flightNum;
			temp = temp->next;
		}
		if (temp->data.flightNum == search_Data) //If the last node in the list contains the data the user is searching for, return the last node's flight number
			return temp->data.flightNum;
		else
			return NULL; //Data was not found in the list
	}
}

bool FlightList::containsPassenger(const string &nameToFind)
{
	if (findPassenger(nameToFind) == "\0") //Passenger name was not found for that flight number or the list was empty
		return false;
	else
		return true; //The passenger name was found
}

string FlightList::findPassenger(const string &search_Data)
{
	Node<FlightData> *temp = head;

	if (temp == nullptr) //Checks for an empty list
		return "\0";
	else
	{
		while (temp->next != nullptr)
		{

			if (temp->data.passengers == nullptr) //Checks if there are no passengers in the list
				return "\0";
			else
			{
				if (temp->data.passengers->contains(search_Data)) //If data the user is searching for is in the list return the name
					return search_Data;
			}
			temp = temp->next;
		}
		if (temp->data.passengers == nullptr) //Passenger list is enmpty
			return "\0";
		else if (temp->data.passengers->contains(search_Data) == true) //If the last node in the list contains the data the user is searching for, return the last node's passenger name
			return search_Data;
		else
			return "\0"; //Data was not found in the list
	}
}