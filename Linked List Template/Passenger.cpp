#include "pch.h"
#include "Passenger.h"


Passenger::Passenger()
{
	string pNm;
	cin >> pNm;

	int pFlght;
	cin >> pFlght;

	flightNum = pFlght;
	name = pNm;
}

Passenger::Passenger(const Passenger& p)
{
	name = p.name;
	flightNum = p.flightNum;
}


Passenger::~Passenger()
{
}

bool Passenger::operator==(const Passenger &pass)
{
	if (this->name == pass.name && this->flightNum == pass.flightNum) //Both member varibles are the same so the instances are equal
		return true;
	else
		return false;
}

bool Passenger::operator!=(const Passenger &pass)
{
	if (this->name == pass.name && this->flightNum == pass.flightNum) //Both member varibles are the same so the instances are equal
		return false;
	else
		return true;
}

string Passenger::getName()const
{
	return name;
}

int Passenger::getFlightNum()const
{
	return flightNum;
}