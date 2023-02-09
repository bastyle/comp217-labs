#pragma once
#include "Employee.h"
class RegularEmployee :  public Employee
{
public:
	RegularEmployee(int employeeID, float baseSalary, float bonus);
	float calculateSalary();
private:
	float bonus;	
};

