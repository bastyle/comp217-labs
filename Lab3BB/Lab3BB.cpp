// Lab3BB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "SalaryCalculator.h"
#include "DiceRoller.h"
#include "Dynamic2DArray.h"
#include "NumberArray.h"

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

int rollDices() {
    srand(time(0));
    int tally[13] = { 0 };
    int *ptr = tally;
    for (int i = 0; i < 36000; ++i) {
        int die1 = rand() % 6 + 1;
        int die2 = rand() % 6 + 1;
        int sum = die1 + die2;
        *(ptr+sum)= *(ptr + sum)+1;
    }
    cout << "Dices Sum\tTally" << endl;
    for (int i = 2; i <= 12; ++i) {
        cout << i << "\t" << tally[i] << endl;
    }
    return 0;
}

int main()
{
   
    /*cout << "--------------------- Part A (Salary Calculator) ---------------------" << endl;
    SalaryCalculator calc;
    calc.inputSalary();
    calc.updateSalaries();

    cout << "--------------------- Part B (Dice Roller) ---------------------" << endl;
    //rollDices();
    DiceRoller diceRoller;
    diceRoller.rollDices();*/

    cout << "--------------------- Part C (Dynamic 2D Array) ---------------------" << endl;

    // create an object of Dynamic2DArray for integers
    /*Dynamic2DArray<int> intArray(2, 2);
    cout << "Enter elements for integer array: " << endl;
    intArray.input();
    intArray.display();
    // create an object of Dynamic2DArray for characters
    Dynamic2DArray<char> charArray(2, 2);
    cout << "Enter elements for character array: " << endl;
    charArray.input();
    charArray.display();*/

    cout << "--------------------- Part D (Dynamic 2D Array) ---------------------" << endl;
    
    NumberArray numberArray;
    numberArray.input();
    
    

    return 0;
}

