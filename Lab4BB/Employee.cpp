#include "Employee.h"

#include <iostream>

using namespace std;

//Employee::Employee() {}
Employee::Employee(int employeeID, float baseSalary){
	this->employeeID = employeeID;
	this->baseSalary = baseSalary;
	//cout << "Employee constructor" << endl;
}

float Employee::calculateSalary()
{
	cout << "Employee calculateSalary" << endl;
	//const float totalSalary = ((salesAmount * rate) / 100) + baseSalary;
	return 0;
}