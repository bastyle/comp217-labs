// Lab3BB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SalaryCalculator.h"

using namespace std;

void calcSalary() {
    int salary[3];
    for (int i = 0; i < 3; ++i) {
        cout << "Enter Salary: ";
        cin >> salary[i];
    }
    cout << endl;
    cout << "Entered salaries are: " << endl;
    for (int i = 0; i < 3; ++i) {
        cout << salary[i] << " ";
    }
    cout << endl;
    cout << "Updated salaries are: " << endl;
    for (int i = 0; i < 3; ++i) {
        salary[i] = salary[i] + salary[i] / (i + 1);
        cout << salary[i] << " ";
    }
}

void calcSalaryArrayByPointerArithmetic() {
    int salary[3];
    int *ptr = salary;
    for (int i = 0; i < 3; ++i) {
        cout << "Enter Salary: ";
        cin >> *(ptr + i);
    }
    cout << endl;
    cout << "Entered salaries are: " << endl;
    for (int i = 0; i < 3; ++i) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
    cout << "Updated salaries are: " << endl;
    for (int i = 0; i < 3; ++i) {
        *(ptr + i) = *(ptr + i) + *(ptr + i) / (i + 1);
        cout << *(ptr + i) << " ";
    }
}

int main()
{
    calcSalaryArrayByPointerArithmetic();
    cout << endl;
    SalaryCalculator calc;
    calc.inputSalary();
    //calc.displaySalaries();
    calc.updateSalaries();
}

