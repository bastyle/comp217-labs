// Lab4BB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
#include "CommissionedEmployee.h";
int main()
{
    std::cout << "Hello World!\n";
    CommissionedEmployee E1(25, 5000, 1000, 10);
    // CASE 1 - derived Class Pointer pointing to Derived class object
    CommissionedEmployee* ptr;
    ptr = &E1;
    cout << " Commissioned Employee salary:" << ptr->calculateSalary();
    cout << endl;
    // CASE 2 - Base Class Pointer pointing to Derived class object
    Employee* eptr;
    eptr = &E1;
    cout << " Commissioned Employee salary:" << eptr->calculateSalary();
    cout << endl;
    CommissionedEmployee E2(25, 5000, 1000, 10);
    CommissionedEmployee E3(26, 5000, 2000, 10);
    HourlyEmployee H1(27, 5000, 10, 100);
    HourlyEmployee H2(28, 5000, 5, 100);
    RegularEmployee R1(29, 5000, 1000);
    RegularEmployee R2(29, 5000, 2000);
    Employee* list[6];
    list[0] = &E2;
    list[1] = &E3;
    list[2] = &H1;
    list[3] = &H2;
    list[4] = &R1;
    list[5] = &R2;
    for (int i = 0; i < 6; i++)
    {
        cout << "Employee " << i << " salary is : " << list[i] > calculateSalary();
        cout << endl;
    }
    return 0
}


