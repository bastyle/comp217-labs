// Lab5BB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Rational.h"


int main()
{
    Rational ratA = Rational(2, 5);
    std::cout << ratA << "\n";
    Rational ratB = Rational(2, 5);
    std::cout << "sum; " << ratA+ratB << "\n";
    bool equal = ratA == ratB;
    std::cout << "equals? " << equal << "\n";
    Rational ra1(2,2);
    std::cout << ra1 << "\n";
    ra1++;
    std::cout << ra1 << "\n";
}


