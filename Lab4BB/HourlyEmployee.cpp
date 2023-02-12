#include "HourlyEmployee.h"

#include <iostream>
using namespace std;

HourlyEmployee::HourlyEmployee(int employeeID, float baseSalary, float extraHours, float payPerHour) :Employee(employeeID, baseSalary) {
	this->payPerHour = payPerHour;
	this->extraHours = extraHours;
	//cout << "HourlyEmployee constructor" << endl;
}

float HourlyEmployee::calculateSalary()
{
	cout << "HourlyEmployee calculateSalary" << endl;
	const float totalSalary = (payPerHour * extraHours) + baseSalary;
	return totalSalary;
}