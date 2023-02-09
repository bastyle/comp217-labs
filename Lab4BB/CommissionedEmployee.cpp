#include "CommissionedEmployee.h"


CommissionedEmployee::CommissionedEmployee(int employeeID, float baseSalary, float salesAmount, float rate) {
	Employee(employeeID, baseSalary);	
	this->rate = rate;
	this->salesAmount = salesAmount;
}