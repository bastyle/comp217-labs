#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H
#include<iostream>

namespace sdds
{
	class MotorVehicle
	{
		char m_licensePlate[32];
		char m_currentAddress[64];
		int m_year; // the year when was created

	public:
		MotorVehicle(const char* plate, int year);
		void moveTo(const char* address);

		std::istream& read(std::istream& in);
		std::ostream& write(std::ostream& os) const;
	
	};

	std::istream& operator>>(std::istream& in, MotorVehicle& v);
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& v);
}

#endif