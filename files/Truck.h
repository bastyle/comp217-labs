#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H
#include <iostream>
#include "MotorVehicle.h"

namespace sdds
{
	class Truck : public MotorVehicle
	{
		double m_capacity; // load capacity in KG
		double m_cargo;    // cargo loaded in the truck, in KG

	public:
		Truck(const char* plate, int year, double capacity, const char* address);

		bool addCargo(double cargo);
		bool unloadCargo();

		std::istream& read(std::istream& in);
		std::ostream& write(std::ostream& out) const;
	};

	std::istream& operator>>(std::istream& in, Truck& c);
	std::ostream& operator<<(std::ostream& out, const Truck& c);
}
#endif
