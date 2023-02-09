#pragma once
#include "Employee.h"
class HourlyEmployee : public Employee
{
public:
	HourlyEmployee(int employeeID, float baseSalary, float payPerHour, float extraHours);
	float calculateSalary();
private:
	float payPerHour;
	float extraHours;
};

