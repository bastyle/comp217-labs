#pragma once

#pragma once
#include <iostream>
#include <string>
#include <exception>
using namespace std;

class NumberArray {
private:
	char charArr[10];

	bool isDigit(char c)
	{
		return (c >= '0' && c <= '9');		
	}

public:
	NumberArray(){		
	}
	void process(char arr[], const int size)
	{
		cout << "--------------------- Process ---------------------" << endl;
		for(int i=0;i<size;i++)
		{
			cout << "position "<<i <<": " << arr[i] << endl;
		}
	}

	void input() {
		const int arraySize = std::size(charArr);
		for (int i = 0; i < arraySize; i++) {
			try
			{
				cout << "enter a number between 0 to 9: " << endl;
				std::cin >> charArr[i];			
				if (!isDigit(charArr[i]))
				{
					throw std::string("Array cannot be processed further.");
				}
			}
			catch (const std::string& e)
			{
				cout << e << endl;
				return;
			}			
		}
		this->process(charArr, arraySize);
	}
};