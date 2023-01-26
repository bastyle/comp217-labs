// Lab2BB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "RecursiveTOH.h"
#include "IterativeTOH.h"


void basicRec(int n)
{
    std::cout << "n; " << n << std::endl;
	if(0==n)
	{
        std::cout << "return 0 " << n << std::endl;
        return;
	}
    std::cout << "calling; " << std::endl;
    basicRec(n - 1);
    std::cout << "finishing with; " << n << std::endl;
}


int main()
{
    //basicRec(3);
	int numberOfDiskToMove{0};
    constexpr char originalPeg{'1'};
    constexpr  char temporalPeg{ '2' };
    constexpr  char destinationPeg{ '3' };
    std::cout << "Enter the number of disks to move: ";
    std::cin >> numberOfDiskToMove;
    RecursiveTOH recToh{};
    std::cout << "------------------------ Recursive Approach ------------------------ " << endl;
    recToh.letsPlay(numberOfDiskToMove, originalPeg, destinationPeg, temporalPeg);
    std::cout << "------------------------ Iterative Approach ------------------------ "<<endl;
    IterativeTOH iteToh{};
    int totalMoves = pow(2, numberOfDiskToMove) - 1;
    std::cout << "moves to execute: " << totalMoves << endl;
    totalMoves = iteToh.letsPlay(numberOfDiskToMove, originalPeg, temporalPeg, destinationPeg);
    std::cout << "moves executed: " << totalMoves << endl;
    return 0;
}


