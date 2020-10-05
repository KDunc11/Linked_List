#ifndef FLGIHTLIST_H
#define FLIGHTLIST_H

#include "LinkedList.h"
#include "Node.h"
#include "LinkedList.cpp"

class FlightData
{
public:
	//Constructor
	FlightData()
	{
		passengers = new LinkedList<string>; //Used to create list of passengers 
	}
	//Destructor
	~FlightData()
	{
		delete passengers;
	}
	//Public Member Variables
	int flightNum; //Holds Passenger's Flight Numbers
	LinkedList<string> *passengers;  // Holds the Passenger's Names on Each Flight
};

class FlightList : protected LinkedList<FlightData> //Inherits a linked list of type FlightData
{
public:
	//Constructor
	FlightList();
	//Destructor
	~FlightList();
	
	//Public Member Functions
	bool insertFlight(const int &flight); //Used to create new flights and insert them into the list
	bool insertPassenger(const string &passengerName, const int &flight); //User to insert passengers to their corresponding flight
	bool removePassenger(const string &passengerName); //Removes passengers from a flight
	bool checkReservation(const string &str); //Checks whether or not a passenger has made a reservation for a flight 
	void printFlight(const int &num); //Prints a manifest for a specific flight
	void printManifest(); //Prints complete manifest for all flights

private:
	//Private Member Variables
	Node<FlightData> *head;
	Node<FlightData> *tail;

	//Private Member Functions
	bool containsFlight(const int &numToFind);
	int findFlight(const int &search_Data);
	bool containsPassenger(const string &nameToFind);
	string findPassenger(const string &search_Data);
};
#endif