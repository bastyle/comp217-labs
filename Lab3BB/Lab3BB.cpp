// Lab3BB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SalaryCalculator.h"
#include "DiceRoller.h"
#include "Dynamic2DArray.h"
#include "NumberArray.h"

using namespace std;



int main()
{
    char option{};
    bool menu = true;
    SalaryCalculator calc;
    DiceRoller diceRoller;
    NumberArray numberArray;
    Dynamic2DArray<int> intArray(2, 2);
    Dynamic2DArray<char> charArray(2, 2);
    do
    {
        cout << "---------------------------------------------------" << endl;
    	cout << "Enter an option to execute {a,b,c,d,x} " << endl;
        cout << "A for\t Part A Part A (Salary Calculator)" << endl;
        cout << "B for\t Part B (Dice Roller)" << endl;
        cout << "C for\t Part C (Dynamic 2D Array)" << endl;
        cout << "D for\t Part D (Number Array)" << endl;
        cout << "X for\t Exit" << endl;
        cout << "---------------------------------------------------" << endl;
        cin >> option;
        switch (option)
        {
        case 'a':
            cout << "--------------------- Part A (Salary Calculator) ---------------------" << endl;
            calc.inputSalary();
            calc.updateSalaries();
            break;
        case 'b':
            cout << "--------------------- Part B (Dice Roller) ---------------------" << endl;
            diceRoller.rollDices();
            break;
        case 'c':
            cout << "--------------------- Part C (Dynamic 2D Array) ---------------------" << endl;
            cout << "Enter 4 elements for integer array: " << endl;
            intArray.input();
            intArray.display();
            cout << "Enter 4 elements for character array: " << endl;
            charArray.input();
            charArray.display();
            break;
        case 'd':
            cout << "--------------------- Part D (Number Array) ---------------------" << endl;
            numberArray.input();
            break;
        case 'x':
            menu = false;
            break;
        default:
            cout << "Enter a valid option. " << endl;
            break;
        }
        cout << endl;
        
    } while (menu);
    
	return 0;
}

