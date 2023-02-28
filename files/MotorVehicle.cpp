#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "MotorVehicle.h"

using namespace std;

namespace sdds
{
	MotorVehicle::MotorVehicle(const char* plate, int year)
	{
		this->m_year = year;
		strcpy(this->m_licensePlate, plate);
		strcpy(this->m_currentAddress, "Factory");
	}

	void MotorVehicle::moveTo(const char* address)
	{
		cout << "|" << right << setw(8) << this->m_licensePlate << "| |"
		     << setw(20) << right << this->m_currentAddress
		     << " ---> "
		     << setw(20) << left << address << "|\n";
		strcpy(this->m_currentAddress, address);
	}

	ostream& MotorVehicle::write(ostream& out) const
	{
		out << "| ";
		out << this->m_year;
		out << " | ";
		out << this->m_licensePlate;
		out << " | ";
		out << this->m_currentAddress;
		return out;
	}

	istream& MotorVehicle::read(istream& in)
	{
		cout << "Built year: ";
		in   >> this->m_year;
		cout << "License plate: ";
		in   >> this->m_licensePlate;
		cout << "Current location: ";
		in   >> this->m_currentAddress;
		return in;
	}

	ostream& operator<<(ostream& os, const MotorVehicle& theVehicle)
	{
		return theVehicle.write(os);
	}

	istream& operator>>(istream& in, MotorVehicle& theVehicle)
	{
		return theVehicle.read(in);
	}
}
