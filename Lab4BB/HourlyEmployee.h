#pragma once
#include "Employee.h"
class HourlyEmployee : public Employee
{
public:
	HourlyEmployee(int employeeID, float baseSalary, float extraHours, float payPerHour);
	float calculateSalary();
private:
	float payPerHour;
	float extraHours;
};

