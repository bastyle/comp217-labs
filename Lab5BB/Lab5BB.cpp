// Lab5BB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Rational.h"


int main()
{
    Rational ratA = Rational(2, 5);
    // << operator
    //std::cout << "Rational A: ";
    std::cout << "Rational A: " << ratA << "\n";
    Rational ratB = Rational(2, 5);
    //std::cout << "Rational B: ";
    std::cout << "Rational B: " << ratB << "\n";
    //
    std::cout << "Addition A+B: " << (ratA + ratB) << "\n";
    std::cout << "Subtraction A-B: " << (ratA - ratB) << "\n";
    std::cout << "Multiplication A*B: " << (ratA * ratB) << "\n";
    std::cout << "Division A*B: " << (ratA / ratB) << "\n";
    //
    std::cout << "(A < B) ? " << ((ratA < ratB) == 1 ? "true" : "false") << "\n";
    std::cout << "(A > B) ? " << ((ratA > ratB) == 1 ? "true" : "false") << "\n";
    std::cout << "(A <= B) ? " << ((ratA <= ratB) == 1 ? "true" : "false") << "\n";
    std::cout << "(A >= B) ? " << ((ratA >= ratB) == 1 ? "true" : "false") << "\n";
    std::cout << "(A != B) ? " << ((ratA != ratB) == 1 ? "true" : "false") << "\n";
	std::cout << "(A == B) ? " << ((ratA == ratB) == 1 ? "true" : "false") << "\n";

    Rational ratC = Rational(2, 3);
    std::cout << "Rational C: " << ratC << "\n";
    std::cout << "(C++) " << (ratC++) << "\n";
    std::cout << "(++C) " << (++ratC) << "\n";

    std::cout << "(C--) " << (ratC--) << "\n";
    std::cout << "(--C) " << (--ratC) << "\n";

    Rational ratD = Rational(2, 1);
    std::cout << "Rational D: " << ratD << "\n";
    std::cout << "(C++) " << (ratD++) << "\n";
    std::cout << "(++C) " << (++ratD) << "\n";

    std::cout << "(C--) " << (ratD--) << "\n";
    std::cout << "(--C) " << (--ratD) << "\n";

    
}


