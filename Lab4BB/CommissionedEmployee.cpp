#include "CommissionedEmployee.h"

#include <iostream>
//#include <iomanip>
using namespace std;

CommissionedEmployee::CommissionedEmployee(int employeeID, float baseSalary, float salesAmount, float rate):Employee(employeeID, baseSalary) {		
	this->rate = rate;
	this->salesAmount = salesAmount;
	//cout << "Commissioned constructor" << endl;
}

float CommissionedEmployee::calculateSalary()
{
	cout << "Commissioned calculateSalary" << endl;
	const float totalSalary = (salesAmount * (rate / 100)) + baseSalary;
	//cout << floor(totalSalary) << endl;
	return totalSalary;
}