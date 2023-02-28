#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "cstring.h"
#include "Truck.h"
#include "MotorVehicle.h"

using namespace std;

namespace sdds
{
	Truck::Truck(const char* plate, int year, double capacity, const char* address) : MotorVehicle(plate, year)
	{
		this->m_capacity = capacity;
		this->m_cargo = 0;
		this->moveTo(address);
	}

	bool Truck::addCargo(double cargo)
	{
		if (this->m_cargo < this->m_capacity)
		{
			if (this->m_cargo + cargo > this->m_capacity)
				this->m_cargo = this->m_capacity;
			else
				this->m_cargo += cargo;
			return true;
		}
		return false;
	}

	bool Truck::unloadCargo()
	{
		bool unload = this->m_cargo > 0;
		this->m_cargo = 0;
		return unload;
	}

	std::istream& Truck::read(std::istream& in)
	{
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> this->m_capacity;
		cout << "Cargo: ";
		in >> this->m_cargo;
		return in;
	}

	std::ostream& Truck::write(std::ostream& out) const
	{
		MotorVehicle::write(out);
		out << " | ";
		out << this->m_cargo << "/" << this->m_capacity;
		return out;
	}

	istream& operator>>(istream& in, Truck& theTruck)
	{
		return theTruck.read(in);
	}

	ostream& operator<<(ostream& os, const Truck& theTruck)
	{
		return theTruck.write(os);
	}
}
