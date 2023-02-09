#pragma once
class Employee
{
public:
	Employee();
	Employee(int employeeID, float baseSalary);
	float calculateSalary();
private:
	int employeeID;
	float baseSalary;
};

