#pragma once
class Employee
{
public:
	//Employee();
	Employee(int employeeID, float baseSalary);
	virtual float calculateSalary();
	//float calculateSalary();
protected:
	int employeeID;
	float baseSalary;
};

