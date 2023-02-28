#pragma once
#include <iostream>
#include <string>
#include <sstream>

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

	int recursiveFormula2(int n) {
		// base case: when n is 0 or 1, return 0
		if (n <= 1) {
			return 0;
		}
		// recursive case: calculate the formula for n-1 and add (n-1)×n to the result
		else {
			return recursiveFormula2(n - 1) + ((n - 1) * n);
		}
	}

	int countLetterA(std::string str) {
		// base case: when the string is empty, return 0
		if (str.empty()) {
			return 0;
		}
		// recursive case: count the number of 'a's in the rest of the string and add 1 if the first character is 'a'
		else {
			int count = countLetterA(str.substr(1));
			if (str[0] == 'a') {
				count++;
			}
			return count;
		}
	}

	double sumArray(double arr[], int n) {
		// base case: when the array is empty, return 0
		if (n == 0) {
			return 0;
		}
		// recursive case: add the first element to the sum of the rest of the array
		else {
			return arr[0] + sumArray(arr + 1, n - 1);
		}
	}

	int countEvenRecursive(int arr[], int n) {
		// base case: if the array is empty, return 0
		if (n == 0) {
			return 0;
		}
		// recursive case: count the even numbers in the rest of the array and add 1 if the first element is even
		int count = countEvenRecursive(arr + 1, n - 1);
		if (arr[0] % 2 == 0) {
			count++;
		}
		return count;
	}

	void replaceSpacesWithDotRecursive(std::string str) {
		// base case: if the string is empty, return
		if (str.empty()) {
			return;
		}
		// recursive case: if the first character is a space, replace it with a dot and make a recursive call with the rest of the string
		if (str[0] == ' ') {
			str[0] = '.';
			replaceSpacesWithDotRecursive(str.substr(1));
		}
		// recursive case: if the first character is not a space, make a recursive call with the rest of the string
		else {
			replaceSpacesWithDotRecursive(str.substr(1));
		}
	}


	std::string replaceSpacesWithDotRecursive2(const std::string& str) {
		if (str.empty()) {
			return str;
		}
		else if (str[0] == ' ') {
			return "." + replaceSpacesWithDotRecursive2(str.substr(1));
		}
		else {
			return str[0] + replaceSpacesWithDotRecursive2(str.substr(1));
		}
	}

	void replaceNegativeRecursive(float arr[], int size, int index = 0) {
		if (index == size) { // base case
			return;
		}
		if (arr[index] < 0) {
			arr[index] = -arr[index];
		}
		replaceNegativeRecursive(arr, size, index + 1); // recursive call
	}

	int countDivisionsByTwoRecursive(int n) {
		// base case
		if (n % 2 != 0) {
			return 0;
		}
		// recursive case
		return 1 + countDivisionsByTwoRecursive(n / 2);
	}

	void printIntArrayRecursive(const int arr[], int size) {
		// base case
		if (size == 0) {
			return;
		}
		// print the first element
		std::cout << arr[0];
		// print the separator
		if (size > 1) {
			std::cout << ", ";
		}
		// recursive call with the rest of the array
		printIntArrayRecursive(arr + 1, size - 1);
	}

	// Recursive function that returns a string with all the integers from an array
// separated by comma (,).
	std::string arrayToStringRecursive(int arr[], int size) {
		if (size == 0) {
			// Base case: empty array returns empty string.
			return "";
		}
		else if (size == 1) {
			// Base case: array with one element returns the element as string.
			return std::to_string(arr[0]);
		}
		else {
			// Recursive case: concatenate the first element with the rest of the array
			// converted to string separated by comma.
			std::stringstream ss;
			ss << arr[0] << ",";
			return ss.str() + arrayToStringRecursive(arr + 1, size - 1);
		}
	}

	std::string arrayToStringRecursive2(int arr[], int size) {
		if (size == 0) {
			// Base case: empty array returns empty string.
			return "";
		}
		else if (size == 1) {
			// Base case: array with one element returns the element as string.
			return std::to_string(arr[0]);
		}
		else {
			// Recursive case: concatenate the first element with the rest of the array
			// converted to string separated by comma.
			std::string ss;
			ss += std::to_string(arr[0]) + ",";
			return ss + arrayToStringRecursive2(arr + 1, size - 1);
		}
	}

};

