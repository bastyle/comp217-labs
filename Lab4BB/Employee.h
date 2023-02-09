#pragma once
class Employee
{
public:
	Employee();
	Employee(int employeeID, float baseSalary);
	float calculateSalary();
protected:
	int employeeID;
	float baseSalary;
};

