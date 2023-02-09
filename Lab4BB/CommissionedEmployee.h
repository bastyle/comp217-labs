#pragma once
#include "Employee.h"
class CommissionedEmployee : public Employee
{
public:
	CommissionedEmployee(int employeeID, float baseSalary, float salesAmount, float rate);
	float calculateSalary();
private:
	float salesAmount;
	float rate;
};

