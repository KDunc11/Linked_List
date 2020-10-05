// Linked List Template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "FlightList.h"

using namespace std;

void driver(FlightList flights);
void hardCodedDriver();

int main()
{
	FlightList flights;

	driver(flights); //User Interface (UI)
	hardCodedDriver(); //Runs hardcode after UI is finsihed running
	return 0;
}


void driver(FlightList flights)
{
	bool run_Driver = true;

	while (run_Driver == true)
	{
		int decision;
		
		cout << "1. Reserve a ticket" << endl;
		cout << "2. Cancel a reservation" << endl;
		cout << "3. Check Reservation" << endl;
		cout << "4. View Flight" << endl;
		cout << "5. View Manifest for all Flights" << endl;
		cout << "0. Exit" << endl;
		cout << "\nEnter a Number:";
		cin >> decision;

		if (decision == 1)//Reserving a ticket
		{
			int flightNumber;
			cout << "\nWhat is the flight number of the flight you wish to book" << endl;
			cout << "Flight Number:";
			cin >> flightNumber; //User enters the flight number for the reservation

			while (flightNumber <= 0 || flightNumber > 10000)
			{
				cout << "Enter Flight Number: ";
				cin >> flightNumber;
			}

			flights.insertFlight(flightNumber); //Checks if a new flight needs to be created, if so a new flight is inserted into the list

			string name;
			cout << "\nWho is the reservation for?" << endl;
			cout << "Enter passenger's name (no spaces): ";
			cin >> name; //User enters passenger's name

			flights.insertPassenger(name, flightNumber); //Inserts passenger into correct flight
		}
		else if (decision == 2) //Cancelling a reservation
		{
			string name;
			cout << "\nWhat is the name of the passenger who has a reservation?" << endl;
			cout << "Enter passenger's name (no spaces): ";
			cin >> name; //User enters the name of the desired passenger's reservation to cancel 

			if (flights.checkReservation(name)) //Boolean checks if theres a reservation for the desired passenger
				flights.removePassenger(name); //Removes the passneger from the flight
			else
				cout << "No reservation found for " << name << endl;
		}
		else if (decision == 3) //Checking a reservation
		{
			string name;
			cout << "\nWhat is the name of the passenger with the reservation?" << endl;
			cout << "Enter Passenger's Name: ";
			cin >> name; //User enters the name of the desired passenger's reservation to check

			flights.checkReservation(name); //Looks for the passeneger's reservation and prints it if found
		}
		else if (decision == 4) //View a specific flight's manifest
		{
			int flightNumber;
			cout << "\nWhat is the flight number of the flight you would like to view?" << endl;
			cout << "Enter Flight Number: ";
			cin >> flightNumber; //User enters the flight number of the desired manifest to view

			while (flightNumber <= 0 || flightNumber > 10000)
			{
				cout << "Enter Flight Number: ";
				cin >> flightNumber;
			}

			flights.printFlight(flightNumber); //Prints the manifest the user wants to view if the flight exists
		}
		else if (decision == 5) //View all flight's manifest
			flights.printManifest(); //Prints the complete manifest
		else
			run_Driver = false; //Any other entry closes the driver
	}
}

void hardCodedDriver()
{
	FlightList flight_hardCode;

	cout << "\n\n\n\n\n" << endl;

	flight_hardCode.insertFlight(2430); //Creates a flight 2430
	flight_hardCode.insertPassenger("Hamilton, Dale", 2430);
	flight_hardCode.insertPassenger("Hamilton, Leslie", 2430);
	flight_hardCode.insertPassenger("Hamilton, Jonathan", 2430);
	flight_hardCode.insertPassenger("Hamilton, Nicholas", 2430);
	flight_hardCode.insertPassenger("Hamilton, Annalisa", 2430);
	flight_hardCode.insertFlight(2515); //Creates flight 2515 to Anchorage
	flight_hardCode.insertPassenger("Absorka, Thor", 2515);
	flight_hardCode.insertPassenger("Snowwisper, Nora", 2515);
	flight_hardCode.insertPassenger("The Mutt, Loki", 2515);

	cout << "\nManifest" << endl; //Printing all flight manifest
	flight_hardCode.printFlight(2430);
	flight_hardCode.printFlight(2515);
	
	if (flight_hardCode.checkReservation("The Mutt, Loki")) //Checks for the reservation
		flight_hardCode.removePassenger("The Mutt, Loki"); //Removes passenger from the flight

	flight_hardCode.insertFlight(2750); //Creates flight 2750 to Accapulco
	flight_hardCode.insertPassenger("The Mutt, Loki", 2750); //Adds passenger to flight

	//Prints flight manifest for 2515 and 2750 for Loki
	flight_hardCode.printFlight(2515);
	flight_hardCode.printFlight(2750);

	cin.ignore();
	cout << "Press Enter to end program" << endl;
	cin.ignore(); //Pauses so user can view hardcoding output on the console window
}