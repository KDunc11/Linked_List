#pragma once
#include <string>
#include <iostream>

using namespace std;

class Passenger
{
public:
	Passenger();
	Passenger(const Passenger& p);
	~Passenger();

	string getName()const;
	int getFlightNum()const;
	bool operator==(const Passenger &pass); //Checks if two passenger instances have are equivalent
	bool operator!=(const Passenger &pass); //Checks if two passenger instances are not equal

private:
	string name;
	int flightNum;
};

