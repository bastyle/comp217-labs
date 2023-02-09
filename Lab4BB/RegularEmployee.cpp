#include "RegularEmployee.h"

#include <iostream>
using namespace std;

RegularEmployee::RegularEmployee(int employeeID, float baseSalary, float bonus) :Employee(employeeID, baseSalary) {
	this->bonus = bonus;	
}

float RegularEmployee::calculateSalary()
{
	cout << "RegularEmployee calculateSalary" << endl;
	const float totalSalary = this->bonus + baseSalary;
	return totalSalary;
}