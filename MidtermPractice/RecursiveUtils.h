#pragma once
#include <iostream>

class RecursiveUtils
{

public:
	void printPoints(int size)
	{
		if (size == 0)
			return;
		for(int i=0;i<size;i++)
		{
			std::cout << ".";
		}
		size--;
		std::cout << std::endl;
		printPoints(size);			
	}

	void printPoints2(int n, int i = 1) {
		// base case: when i is greater than n, stop recursion
		if (i > n) {
			return;
		}

		// print i dots
		std::cout << std::string(i, '.') << std::endl;

		// recursive call with i+1
		printPoints2(n, i + 1);		
		
	}

	int recursiveFormula(int n, int i = 1) {
		// base case: when i is greater than n, return 0
		if (i > n) {
			return 0;
		}

		// if i is odd, add i to the result
		if (i % 2 == 1) {
			std::cout << i << "+" << std::endl;
			return i + recursiveFormula(n, i + 1);
		}
		// if i is even, add 2i to the result
		else {
			std::cout << "2 * "<< i << std::endl;
			return 2 * i + recursiveFormula(n, i + 1);
		}
	}
};

